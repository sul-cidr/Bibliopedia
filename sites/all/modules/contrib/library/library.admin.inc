<?php

/**
 * @file
 * Administrative settings for the library module
 */

/**
 * Menu callback: Edit Library Settings.
 */
function library_admin_settings() {
  $form = array();
  $form['library_item_barcodes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Barcodes/Unique Identifiers for Library Items'),
    '#default_value' => variable_get('library_item_barcodes', 0),
    '#return_value' => 1,
    '#description' => t('This is recommended if you have multiple copies of an item. However, you must have unique identifiers for every instance.  If you have multiple copies but do not use barcodes, library management will be against whether any copy is available and will not track any specific copy.'),
  );
  $form['library_disable_patron_autocomplete'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable Patron Autocomplete on Transactions'),
    '#default_value' => variable_get('library_disable_patron_autocomplete', 0),
    '#return_value' => 1,
    '#description' => t('This allows patron for a transaction to be selected without autocompletion. Will only work with Drupal username, so make sure the username is the barcode if using a barcode scanner.'),
  );
  $form['library_status_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Library Status'),
    '#default_value' => variable_get('library_status_display', 0),
    '#return_value' => 1,
    '#description' => t('To display library status on individual library nodes, check this box.'),
  );

  $form['library_action_display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Action Links to Display'),
    '#description' => t("Select which actions can be taken given a library item's status. If no actions are selected for a given status, no action links will be displayed on items with that status."),
  );

  $when_available = array();
  $when_unavailable = array();
  $when_reference = array();
  foreach (library_actions() as $aid => $action) {
    switch ($action['status_change']) {
      case LIBRARY_ACTION_NO_CHANGE:
        $when_available[$aid] = $action['name'];
        $when_unavailable[$aid] = $action['name'];
        $when_reference[$aid] = $action['name'];
        break;
      case LIBRARY_ACTION_TYPE_UNAVAILABLE:
        $when_available[$aid] = $action['name'];
        break;
      case LIBRARY_ACTION_TYPE_AVAILABLE:
        $when_unavailable[$aid] = $action['name'];
        break;
    }
  }
  $form['library_action_display']['library_links_display_available'] = array(
    '#type' => 'checkboxes',
    '#title' => t('On Available Items'),
    '#default_value' => variable_get('library_links_display_available', array()),
    '#options' => $when_available,
  );
  $form['library_action_display']['library_links_display_unavailable'] = array(
    '#type' => 'checkboxes',
    '#title' => t('On Unavailable Items'),
    '#default_value' => variable_get('library_links_display_unavailable', array()),
    '#options' => $when_unavailable,
  );
  $form['library_action_display']['library_links_display_reference'] = array(
    '#type' => 'checkboxes',
    '#title' => t('On Reference Only Items'),
    '#default_value' => variable_get('library_links_display_reference', array()),
    '#options' => $when_reference,
  );
  $form['library_item_list_display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Library Default List Display'),
    '#description' => t('The columns chosen below will be added to the node fields that you have selected to display. Note: consider using a custom view from the views module for this instead.'),
  );
  $form['library_item_list_display']['library_quantity_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Quantity'),
    '#default_value' => variable_get('library_quantity_display', 0),
  );
  $form['library_item_list_display']['library_list_status_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Status'),
    '#default_value' => variable_get('library_list_status_display', 0),
  );
  if (module_exists('taxonomy')) {
    $vocabularies = array();
    $vocabs = taxonomy_get_vocabularies();
    if ($vocabs) {
      foreach ($vocabs as $vid => $vocab) {
        $vocabularies[$vid] = $vocab->name;
      }
      $form['library_item_list_display']['library_taxonomy_display'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Display Associated Taxonomy Terms in Library View'),
        '#default_value' => variable_get('library_taxonomy_display', array()),
        '#options' => $vocabularies,
        '#description' => t('Select the vocabularies from which you would like to display taxonomy terms. If no vocabularies are selected, terms will not be displayed.'),
      );
    }
  }
  $form['library_text_display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Library Text'),
    '#description' => t('Customize the text display.'),
  );
  $form['library_text_display']['library_available_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Available Status Text'),
    '#default_value' => variable_get('library_available_text', 'AVAILABLE'),
    '#size' => 20,
    '#maxlength' => 20,
    '#description' => t("Examples: in, checked in"),
  );
  $form['library_text_display']['library_unavailable_noduedates_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Unavailable Status Text (Without Due Dates)'),
    '#default_value' => variable_get('library_unavailable_noduedates_text', 'UNAVAILABLE'),
    '#size' => 20,
    '#maxlength' => 20,
    '#description' => t("Examples: out, checked out"),
  );
  $form['library_text_display']['library_reference_only_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Reference Only Status Text'),
    '#default_value' => variable_get('library_reference_only_text', 'REFERENCE ONLY'),
    '#size' => 20,
    '#maxlength' => 20,
  );

  if (module_exists('profile')) {
    $form['library_profile'] = array(
      '#type' => 'fieldset',
      '#title' => t('Core Profile Fields'),
      '#description' => t('Choose profile fields to be used when using autocomplete to select a patron. Note: since profile fields do not allow for unique values, whatever unique identifier you are using (such as a barcode) should be the Drupal username. Barcode values below are included only to prevent data loss from previous versions of this module.'),
    );
    $result = db_query("select title, name from {profile_fields} where type = :type", array(':type' => 'textfield'));
    foreach ($result as $field) {
      $form['library_profile']['library_profile_' . $field->name] = array(
        '#type' => 'checkbox',
        '#title' => t($field->title . ' (' . $field->name . ')'),
        '#default_value' => variable_get('library_profile_' . $field->name, 0),
        '#return_value' => 1,
      );
    }
  }

  return system_settings_form($form);
}


/**
 * Menu callback: Edit Library Overdue Settings.
 */
function library_admin_settings_overdue() {
  $form = array();
  foreach (library_get_item_types() as $type) {
    foreach (library_actions() as $aid => $action) {
      if ($action['status_change'] == LIBRARY_ACTION_TYPE_UNAVAILABLE) {
        $clean = library_clean_action_name($action['name']);
        $input_name = 'library_period_for_' . $type . '_' . $clean;
        $form[$input_name] = array(
          '#type' => 'fieldset',
          '#title' => t($type . ' ' . $action['name'] . ' Period'),
          '#description' => t('The maximum time a patron may %action a %type . Days and hours are combined into one value. Enter a whole number greater than 0 in days or hours if you want to have duedates for this item type with this action.', array('%type' => $type, '%action' => $action['name'])),
          '#attributes' => array('class' => array('check-out-period-fieldset')),
        );
        $input_name_days = 'library_days_for_' . $type . '_' . $clean;
        $form[$input_name][$input_name_days] = array(
          '#type' => 'textfield',
          '#title' => t('Days'),
          '#default_value' => variable_get('' . $input_name_days, 0),
          '#size' => 3,
          '#maxlength' => 3,
        );
        $input_name_hours = 'library_hours_for_' . $type . '_' . $clean;
        $form[$input_name][$input_name_hours] = array(
          '#type' => 'textfield',
          '#title' => t('Hours'),
          '#default_value' => variable_get('' . $input_name_hours, 0),
          '#size' => 3,
          '#maxlength' => 3,
        );
      }
    }
  }
  $form['library_send_automatic_email'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send Automatic Overdue Reminder Emails'),
    '#default_value' => variable_get('library_send_automatic_email', 0),
    '#description' => t('If this option is checked and due dates are enabled, Drupal will send a reminder email to each patron with overdue items the day after an item becomes overdue.'),
    '#return_value' => 1,
  );
  // Patron e-mail settings.
  $form['email'] = array(
    '#type' => 'fieldset',
    '#title' => t('Patron Overdue Items Notification e-mail'),
    '#description' => t('Customize email sent to library patrons with overdue items. Available variables are: !patronname, !site, and !items.'),
  );
  $form['email']['library_mail_notify_overdue_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => _library_mail_text('notify_overdue_subject'),
    '#maxlength' => 180,
  );
  $form['email']['library_mail_notify_overdue_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => _library_mail_text('notify_overdue_body'),
    '#rows' => 15,
  );

  return system_settings_form($form);
}

function library_admin_settings_overdue_validate($form, &$form_state) {
  foreach (library_get_item_types() as $type) {
    $duedates_enabled = 0;
    foreach (library_actions() as $aid => $action) {
      if ($action['status_change'] == LIBRARY_ACTION_TYPE_UNAVAILABLE) {
        $clean = library_clean_action_name($action['name']);
        $input_name_days = 'library_days_for_' . $type . '_' . $clean;
        $input_name_hours = 'library_hours_for_' . $type . '_' . $clean;
        if (!is_numeric($form_state['values'][$input_name_days])) {
          form_set_error($input_name_days, t('Days must be a number.'));
        }
        if (!is_numeric($form_state['values'][$input_name_hours])) {
          form_set_error($input_name_hours, t('Hours must be a number.'));
        }
        $day_sec = $form_state['values'][$input_name_days] * 24 * 60 * 60;
        $hour_sec = $form_state['values'][$input_name_hours] * 60 * 60;
        $total = $day_sec + $hour_sec;
        if ($total > 0) {
          $duedates_enabled = 1;
        }
        variable_set('library_period_for_' . $type . '_' . $clean, $total);
      }
    }
    variable_set('library_' . $type . '_due_dates', $duedates_enabled);
  }
}

/**
 * Menu callback: Edit Library Action.
 *
 * @see library_admin_action_validate()
 * @see library_admin_action_submit()
 * @see theme_library_admin_new_action()
 */
function library_admin_action() {
  $aid = arg(6);
  if ($aid) {
    // Display the edit action form.
    $action = library_get_action($aid);
    $show_delete = TRUE;
    if ($action && ($action->status_change > 0)) {
      //Make sure the library always has at least one check in and one check out action
      $row_number = db_query("SELECT aid FROM {library_actions} WHERE aid <> :aid AND status_change = :change", array(':aid' => $action->aid, ':change' => $action->status_change))->rowCount();
      if ($row_number == 0) {
        $show_delete = FALSE;
      }
    }

    $form['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Action name'),
      '#default_value' => $action->name,
      '#size' => 20,
      '#required' => TRUE,
      '#maxlength' => 60,
      '#description' => t('The name for this action.'),
    );
    $form['status_change'] = array(
      '#type' => 'radios',
      '#title' => t('Status Change'),
      '#description' => t('How this action changes the status of a library item.'),
      '#default_value' => isset($action->status_change) ? $action->status_change : 0,
      '#options' => array(LIBRARY_ACTION_NO_CHANGE => t('No Change'), LIBRARY_ACTION_TYPE_UNAVAILABLE => t('Unavailable'), LIBRARY_ACTION_TYPE_AVAILABLE => t('Available'))
    );
    $form['aid'] = array(
      '#type' => 'value',
      '#value' => $aid,
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save action'),
    );
    if ($show_delete) {
      $form['delete'] = array(
        '#type' => 'submit',
        '#value' => t('Delete action'),
      );
    }
  }
  else {
    $form['name'] = array(
      '#type' => 'textfield',
      '#size' => 20,
      '#maxlength' => 60,
    );
    $form['status_change'] = array(
      '#type' => 'radios',
      '#default_value' => 0,
      '#options' => array(LIBRARY_ACTION_NO_CHANGE => t('No Change'), LIBRARY_ACTION_TYPE_UNAVAILABLE => t('Unavailable'), LIBRARY_ACTION_TYPE_AVAILABLE => t('Available'))
    );
    $form['submit'] = array(
      '#type' => 'submit',

      '#value' => t('Add action'),
    );
    $form['#submit'][] = 'library_admin_action_submit';
    $form['#validate'][] = 'library_admin_action_validate';
  }
  return $form;
}

/**
 * Menu callback: Edit Library Action.
 *
 * @see library_admin_action()
 * @see library_admin_action_submit()
 * @see theme_library_admin_new_action()
 */
function library_admin_action_validate($form, &$form_state) {
  if ($form_state['values']['name']) {
    if ($form_state['values']['op'] == t('Save action')) {
      $row_number = db_query("SELECT aid FROM {library_actions} WHERE aid <> :aid AND name = :name", array(':aid' => $form_state['values']['aid'], ':name' => $form_state['values']['name']))->rowCount();
      if ($row_number > 0) {
        form_set_error('name', t('The action name %name already exists. Please choose another action name.', array('%name' => $form_state['values']['name'])));
      }
    }
    elseif ($form_state['values']['op'] == t('Add action')) {
      $row_number = db_query("SELECT aid FROM {library_actions} WHERE name = :name", array(':name' => $form_state['values']['name']))->rowCount();
      if ($row_number > 0) {
        form_set_error('name', t('The action name %name already exists. Please choose another action name.', array('%name' => $form_state['values']['name'])));
      }
    }
  }
  else {
    form_set_error('name', t('You must specify a valid action name.'));
  }
}

/**
 * Menu callback: Edit Library Action.
 *
 * @see library_admin_action()
 * @see library_admin_action_validate()
 * @see theme_library_admin_new_action()
 */
function library_admin_action_submit($form, &$form_state) {
  if ($form_state['values']['op'] == t('Save action')) {
    db_update('library_actions')
      ->fields(array(
        'name' => check_plain($form_state['values']['name']),
        'status_change' => $form_state['values']['status_change'],
      ))
      ->condition('aid', $form_state['values']['aid'])
      ->execute();
    drupal_set_message(t('The action has been renamed.'));
  }
  elseif ($form_state['values']['op'] == t('Delete action')) {
    db_delete('library_actions')
      ->condition('aid', $form_state['values']['aid'])
      ->execute();
    db_delete('library_transactions')
      ->condition('action_aid', $form_state['values']['aid'])
      ->execute();
    $available_display = variable_get('library_links_display_available', array());
    $unavailable_display = variable_get('library_links_display_unavailable', array());
    $reference_display = variable_get('library_links_display_reference', array());
    $key = array_search($form_state['values']['aid'], $available_display);
    if ($key !== FALSE) {
      unset($available_display[$key]);
      variable_set('library_links_display_available', $available_display);
    }
    $key2 = array_search($form_state['values']['aid'], $unavailable_display);
    if ($key2 !== FALSE) {
      unset($unavailable_display[$key2]);
      variable_set('library_links_display_unavailable', $unavailable_display);
    }
    $key3 = array_search($form_state['values']['aid'], $reference_display);
    if ($key3 !== FALSE) {
      unset($reference_display[$key3]);
      variable_set('library_links_display_reference', $reference_display);
    }
    drupal_set_message(t('The action has been deleted.'));
  }
  elseif ($form_state['values']['op'] == t('Add action')) {
    db_insert('library_actions')
      ->fields(array(
        'name' => check_plain($form_state['values']['name']),
        'status_change' => $form_state['values']['status_change'],
      ))
      ->execute();
    drupal_set_message(t('The action has been added.'));
  }
  $form_state['redirect'] = 'admin/config/workflow/library/actions';
  return;
}

/**
 * Retrieve a pipe delimited string of autocomplete suggestions for library items
 */
function library_autocomplete($string) {
  $matches = array();
  if (variable_get('library_item_barcodes', LIBRARY_NO_BARCODES) == LIBRARY_BARCODES) {
    $select = db_select('library', 'l')
      ->join('node', 'n', 'n.nid = l.nid')
      ->fields('l', array('id', 'barcode'))
      ->fields('n', array('title'))
      ->condition('n.status', 1)
      ->condition('l.barcode', '', '<>')
      ->condition('l.barcode', db_like(check_plain($string)) . '%', 'LIKE')
      ->orderBy('l.barcode')
      ->range(0, 10);
    $results = $select->execute()->fetchAll();
    foreach ($results as $item) {
      $matches[$item->barcode . ' [title:' . $item->title . '] [id:' . $item->id . ']'] = check_plain($item->barcode);
    }
  }
  else {
    $select = db_select('library', 'l')
      ->join('node', 'n', 'n.nid = l.nid')
      ->fields('l', array('id'))
      ->fields('n', array('title'))
      ->condition('n.status', 1)
      ->condition('n.title', db_like(check_plain($string)) . '%', 'LIKE')
      ->orderBy('n.title')
      ->distinct()
      ->range(0, 10);
    $results = $select->execute()->fetchAllAssoc('nid');
    foreach ($results as $item) {
      $my_key = $item->title . ' [id:' . $item->id . ']';
      $matches[$my_key] = check_plain($my_key);
    }
  }
  print drupal_json_encode($matches);
  exit();
}

/*
 * Send email to patrons with overdue items
 */
function library_notify_overdue() {
  if (library_duedates_enabled()) {
    $records = library_get_overdue_items();
    if (empty($records)) {
      drupal_set_message(t('No patrons with overdue items at this time.'));
    }
    else {
      $num_emails = 0;
      foreach ($records as $patron_uid => $record) {
        $params = $record;
        drupal_mail('library', 'notify_overdue', $params['patron']['patron_email'], language_default(), $params);
        watchdog('library', 'Overdue notice sent to %email', array('%email' => $params['patron']['patron_email']));
        $num_emails++;
      }
      drupal_set_message(t('@number email(s) sent successfully.', array('@number' => $num_emails)));
      watchdog('library', '%number overdue email notifications sent successfully.', array('%number' => $num_emails));
    }
  }
  else {
    drupal_set_message(t('Library due dates are not enabled.'));
  }
  drupal_goto('library-items/overdue');
}
