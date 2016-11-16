<?php
/**
 * @file
 * CTools Export UI plugin definition for interactions.
 */

/**
 * CTools Export UI plugin definition.
 */
function openlayers_ui_OpenlayersInteractions_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_interactions',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'interactions',
      'menu title' => 'Interactions',
      'menu description' => 'Administer Openlayers interactions.',
    ),

    'handler' => array(
      'class' => '\\Drupal\\openlayers_ui\\UI\\openlayersInteractions',
      'file' => 'OpenlayersInteractions.php',
    ),

    'export' => array(
      'admin_title' => 'name',
      'admin_description' => 'description',
    ),

    'use wizard' => TRUE,
    'form info' => array(
      'order' => array(
        'start' => t('Administrative settings'),
        'type' => t('Interaction type'),
        'options' => t('Interaction type options'),
      ),
      'forms' => array(
        'start' => array(
          'form id' => 'openlayers_interaction_form_start',
        ),
        'type' => array(
          'form id' => 'openlayers_interaction_form_type',
        ),
        'options' => array(
          'form id' => 'openlayers_interaction_form_options',
        ),
      ),
      'wrapper' => 'openlayers_objects_ui_form_wrapper',
    ),

    'title singular' => t('interaction'),
    'title plural' => t('interactions'),
    'title singular proper' => t('Openlayers interaction preset'),
    'title plural proper' => t('Openlayers interaction presets'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Interaction saved.'),
        ),
        'delete' => array(
          'success' => t('Interaction was deleted.'),
        ),
      ),
    ),
  );
}

/**
 * Interaction base config form handler.
 */
function openlayers_interaction_form_start($form, &$form_state) {
  $class = new \Drupal\openlayers_ui\UI\OpenlayersInteractions();
  $class->init($form_state['plugin']);
  $class->edit_form($form, $form_state);

  $options = array();
  foreach (\Drupal\openlayers\Openlayers::loadAllExportable('Map') as $machine_name => $map) {
    if (!is_object($map) || (property_exists($map, 'disabled') && ($map->disabled == 1 || $map->disabled == TRUE))) {
      continue;
    }
    $options[$machine_name] = $map->name;
  }

  $form['attachToMap'] = array(
    '#type' => 'select',
    '#title' => 'Add this to a map ?',
    '#empty_option' => t('- Do no attach -'),
    '#description' => 'Select the map to add this object to.',
    '#options' => $options,
    '#default_value' => isset($form_state['item']->attachToMap) ? $form_state['item']->attachToMap : '',
  );

  return $form;
}

/**
 * Interaction base config form validation handler.
 */
function openlayers_interaction_form_start_validate($form, &$form_state) {
  $class = new \Drupal\openlayers_ui\UI\OpenlayersInteractions();
  $class->init($form_state['plugin']);
  $class->edit_form_validate($form, $form_state);
}

/**
 * Interaction base config form submit handler.
 */
function openlayers_interaction_form_start_submit($form, &$form_state) {
  $class = new \Drupal\openlayers_ui\UI\OpenlayersInteractions();
  $class->init($form_state['plugin']);
  $class->edit_form_submit($form, $form_state);
}

/**
 * Interaction type config form handler.
 */
function openlayers_interaction_form_type($form, &$form_state) {
  $form['factory_service'] = array(
    '#type' => 'select',
    '#title' => t('Interaction Type'),
    '#empty_option' => t('- Select a @plugin type -', array('@plugin' => 'Interaction')),
    '#default_value' => isset($form_state['item']->factory_service) ? $form_state['item']->factory_service : '',
    '#description' => t('Select the type of interaction.'),
    '#options' => \Drupal\openlayers\Openlayers::getOLObjectsOptions('Interaction'),
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Interaction type config form submit handler.
 */
function openlayers_interaction_form_type_submit($form, &$form_state) {
  $form_state['item']->factory_service = $form_state['values']['factory_service'];
}

/**
 * Interaction options config form handler.
 */
function openlayers_interaction_form_options($form, &$form_state) {
  if (($interaction = \Drupal\openlayers\Openlayers::load('Interaction', $form_state['item'])) == TRUE) {
    $interaction->optionsForm($form, $form_state);
    $form['options']['#tree'] = TRUE;
  }

  return $form;
}

/**
 * Interaction options config form validation handler.
 */
function openlayers_interaction_form_options_validate($form, &$form_state) {
  if (($interaction = \Drupal\openlayers\Openlayers::load('Interaction', $form_state['item'])) == TRUE) {
    $interaction->optionsFormValidate($form, $form_state);
  }
}

/**
 * Interaction options config form submit handler.
 */
function openlayers_interaction_form_options_submit($form, &$form_state) {
  if (isset($form_state['values']['options'])) {
    $form_state['item']->options = array_merge((array) $form_state['item']->options, (array) $form_state['values']['options']);
  }

  if (($interaction = \Drupal\openlayers\Openlayers::load('Interaction', $form_state['item'])) == TRUE) {
    if (!empty($form_state['item']->attachToMap) && ($map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']->attachToMap)) == TRUE) {
      $map->getCollection()->append($interaction);
      \Drupal\openlayers\Openlayers::save($map);
      unset($form_state['item']->attachToMap);
    }

    $interaction->optionsFormSubmit($form, $form_state);
  }
}
