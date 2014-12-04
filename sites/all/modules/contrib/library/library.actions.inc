<?php

/**
 * @file
 * Hooks into core Drupal actions module
 */

/**
 * Implementation of hook_hook_info()
 */
function library_trigger_info() {
  $triggers = array();
  foreach (library_actions() as $aid => $action) {
    $triggers['library_after_' . library_clean_action_name($action['name'])] = array('label' => t('After a ' . $action['name']));
  }

  return array(
    'library' => $triggers
  );
}

/**
 * Implementation of hook_action_info().
 */
function library_action_info() {
  $triggers = array();
  foreach (library_actions() as $aid => $action) {
    $triggers[] = 'library_after_' . library_clean_action_name($action['name']);
  }

  return array(
    'library_send_email_action' => array(
      'label' => t('Send Library e-mail'),
      'type' => 'library',
      'configurable' => TRUE,
      'triggers' => $triggers
    ),
    'library_renew_action' => array(
      'label' => t('Extend Library Item Due Date'),
      'type' => 'library',
      'configurable' => FALSE,
      'triggers' => $triggers
    ),
  );
}

/**
* Implementation of a Drupal action.
* Renews a library item if it is checked out and due dates are enabled.
*/

function library_renew_action(&$object, $context = array()) {
  $patron = $context['patron'];
  $item = $context['item'];
  $item_obj = library_load($item['id']);
  if ($item_obj && !empty($item_obj->last_transaction_id) && !empty($item_obj->last_transaction_name) && !empty($item_obj->last_patron_uid) && !empty($item_obj->last_due_date) &&
      $item_obj->last_patron_uid == $patron['uid'] && $item_obj->in_circulation == LIBRARY_CIRCULATION && $item_obj->library_status == LIBRARY_ITEM_UNAVAILABLE) {

    $type = $item_obj->type;
    $clean = library_clean_action_name($item_obj->last_transaction_name);
    $period = variable_get('library_period_for_' . $type . '_' . $clean, 0);
    if ($period > 0) {
      $duedate = library_get_due_date(REQUEST_TIME, $clean, $type);
      if ($duedate) {
        db_update('library_transactions')
          ->fields(array('duedate' => $duedate))
          ->condition('tid', $item_obj->last_transaction_id)
          ->execute();
        watchdog('library', '%name renewed %item [ID: %item_id ].', array('%name' => check_plain($patron['name']), '%item' => check_plain($item['title']), '%item_id' => $item['id']));
      }
    }
  }
}

/**
 * Implementation of hook_mail()
 */
function library_mail($key, &$message, $params) {
  $language = $message['language'];
  switch ($key) {
    case 'notify_overdue':
      $variables = library_mail_tokens($params, $language);
      $message['subject'] .= _library_mail_text($key . '_subject', $language, $variables);
      $message['body'][] = _library_mail_text($key . '_body', $language, $variables);
      break;
    case 'action_send_email':
      $context = $params['context'];
      $variables = array(
        '%site_name' => variable_get('site_name', 'Drupal'),
        '%patron_name' => $context['patron']['name'],
        '%patron_email' => $context['patron']['mail'],
        '%patron_uid' => $context['patron']['uid'],
        '%node_url' => url('node/' . $context['item']['nid'], array('absolute' => TRUE)),
        '%node_type' => $context['item']['node_type'],
        '%title' => $context['item']['title'],
        '%item_id' => $context['item']['id'],
        '%barcode' => $context['item']['barcode'],
        '%transaction_name' => $context['transaction']['action_name'],
        '%notes' => $context['transaction']['notes'],
      );
      $subject = strtr($context['subject'], $variables);
      $body = strtr($context['message'], $variables);
      $message['subject'] .= str_replace(array("\r", "\n"), '', $subject);
      $message['body'][] = drupal_html_to_text($body);
      break;
  }
}


/**
 * Return a form definition so the Send email action can be configured.
 *
 * @see library_send_email_action_validate()
 * @see library_send_email_action_submit()
 * @param $context
 *   Default values (if we are editing an existing action instance).
 * @return
 *   Form definition.
 */
function library_send_email_action_form($context) {
  // Set default values for form.
  if (!isset($context['recipient'])) {
    $context['recipient'] = '';
  }
  if (!isset($context['subject'])) {
    $context['subject'] = '';
  }
  if (!isset($context['message'])) {
    $context['message'] = '';
  }

  $form['recipient'] = array(
    '#type' => 'textfield',
    '#title' => t('Recipient'),
    '#default_value' => $context['recipient'],
    '#maxlength' => '254',
    '#description' => t('The email address to which the message should be sent.'),
  );
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $context['subject'],
    '#maxlength' => '254',
    '#description' => t('The subject of the message.'),
  );
  $form['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#default_value' => $context['message'],
    '#cols' => '80',
    '#rows' => '20',
    '#description' => t('The message that should be sent. You may include the following variables: %site_name, %patron_name, %patron_mail, %patron_uid, %node_url, %item_id, %node_type, %title, %barcode, %transaction_name, %notes. Not all variables will be available in all contexts.'),
  );
  return $form;
}

/**
 * Validate library_send_email_action form submissions.
 */
function library_send_email_action_validate($form, $form_state) {
  $form_values = $form_state['values'];
  // Validate the configuration form.
  if (!valid_email_address($form_values['recipient']) && $form_values['recipient'] != '%patron_mail') {
    // We want the literal %patron_mail placeholder to be emphasized in the error message.
    form_set_error('recipient', t('Please enter a valid email address or %patron_mail.', array('%patron_mail' => '%patron_mail')));
  }
}

/**
 * Process library_send_email_action form submissions.
 */
function library_send_email_action_submit($form, $form_state) {
  $form_values = $form_state['values'];
  // Process the HTML form to store configuration. The keyed array that
  // we return will be serialized to the database.
  $params = array(
    'recipient' => $form_values['recipient'],
    'subject'   => $form_values['subject'],
    'message'   => $form_values['message'],
  );
  return $params;
}

/**
 * Implementation of a configurable Drupal action. Sends an email.
 */
function library_send_email_action(&$object, $context) {

  $recipient = $context['recipient'];
  $patron = $context['patron'];

  $account = user_load($patron->uid);
  $language = user_preferred_language($account);

  if ($recipient == '%patron_mail') {
      $recipient = $context['patron']['mail'];
  }

  $params = array('context' => $context);

  if (drupal_mail('library', 'action_send_email', $recipient, $language, $params)) {
    watchdog('library', 'Sent email to %recipient', array('%recipient' => $recipient));
  }
  else {
    watchdog('error', 'Unable to send email to %recipient', array('%recipient' => $recipient));
  }
}

function library_mail_tokens($params, $language) {
  $items = '';
  foreach ($params['items'] as $id => $values) {
    $items .= $values['item_name'] . ' (Due ' . format_date($values['due_date'], 'short') . ') ';
  }
  $tokens = array(
    '!patronname' => $params['patron']['patron_name'],
    '!site' => variable_get('site_name', 'Drupal'),
    '!items' => $items,
  );
  return $tokens;
}

/**
 */
function library_email_form_submit($form, &$form_state) {
  if ($form_state['values']['op'] == t('Send E-mail')) {

    drupal_set_message(t('The email has been sent.'));
  }
  $form_state['redirect'] = 'library-items';
  return;
}
