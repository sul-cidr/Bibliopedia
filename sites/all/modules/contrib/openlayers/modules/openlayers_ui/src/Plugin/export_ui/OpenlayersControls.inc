<?php
/**
 * @file
 * CTools Export UI plugin definition for controls.
 */

/**
 * CTools Export UI plugin definition.
 */
function openlayers_ui_OpenlayersControls_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_controls',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'controls',
      'menu title' => 'Controls',
      'menu description' => 'Administer Openlayers controls.',
    ),

    'handler' => array(
      'class' => '\\Drupal\\openlayers_ui\\UI\\OpenlayersControls',
      'file' => 'OpenlayersControls.php',
    ),

    'export' => array(
      'admin_title' => 'name',
      'admin_description' => 'description',
    ),

    'use wizard' => TRUE,
    'form info' => array(
      'order' => array(
        'start' => t('Administrative settings'),
        'type' => t('Control type'),
        'options' => t('Control type options'),
      ),
      'forms' => array(
        'start' => array(
          'form id' => 'openlayers_control_form_start',
        ),
        'type' => array(
          'form id' => 'openlayers_control_form_type',
        ),
        'options' => array(
          'form id' => 'openlayers_control_form_options',
        ),
      ),
      'wrapper' => 'openlayers_objects_ui_form_wrapper',
    ),

    'title singular' => t('control'),
    'title plural' => t('controls'),
    'title singular proper' => t('Openlayers control preset'),
    'title plural proper' => t('Openlayers control presets'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Control saved.'),
        ),
        'delete' => array(
          'success' => t('Control was deleted.'),
        ),
      ),
    ),
  );
}

/**
 * Control base config form handler.
 */
function openlayers_control_form_start($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersControls();
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
 * Control base config form validation handler.
 */
function openlayers_control_form_start_validate($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersControls();
  $class->init($form_state['plugin']);
  $class->edit_form_validate($form, $form_state);
}

/**
 * Control base config form submit handler.
 */
function openlayers_control_form_start_submit($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersControls();
  $class->init($form_state['plugin']);
  $class->edit_form_submit($form, $form_state);
}

/**
 * Control type config form handler.
 */
function openlayers_control_form_type($form, &$form_state) {
  $form['factory_service'] = array(
    '#type' => 'select',
    '#title' => t('Control Type'),
    '#empty_option' => t('- Select a @plugin type -', array('@plugin' => 'Control')),
    '#default_value' => isset($form_state['item']->factory_service) ? $form_state['item']->factory_service : '',
    '#description' => t('Select the type of control.'),
    '#options' => \Drupal\openlayers\Openlayers::getOLObjectsOptions('Control'),
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Control type config form submit handler.
 */
function openlayers_control_form_type_submit($form, &$form_state) {
  $form_state['item']->factory_service = $form_state['values']['factory_service'];
}

/**
 * Control options config form handler.
 */
function openlayers_control_form_options($form, &$form_state) {
  if (($control = \Drupal\openlayers\Openlayers::load('Control', $form_state['item'])) == TRUE) {
    $control->optionsForm($form, $form_state);
    $form['options']['#tree'] = TRUE;
  }

  return $form;
}

/**
 * Control options config form validation handler.
 */
function openlayers_control_form_options_validate($form, &$form_state) {
  if (($control = \Drupal\openlayers\Openlayers::load('Control', $form_state['item'])) == TRUE) {
    $control->optionsFormValidate($form, $form_state);
  }
}

/**
 * Control options config form submit handler.
 */
function openlayers_control_form_options_submit($form, &$form_state) {
  if (isset($form_state['values']['options'])) {
    $form_state['item']->options = array_merge((array) $form_state['item']->options, (array) $form_state['values']['options']);
  }

  if (($control = \Drupal\openlayers\Openlayers::load('Control', $form_state['item'])) == TRUE) {
    if (!empty($form_state['item']->attachToMap) && ($map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']->attachToMap)) == TRUE) {
      $map->getCollection()->append($control);
      \Drupal\openlayers\Openlayers::save($map);
      unset($form_state['item']->attachToMap);
    }

    $control->optionsFormSubmit($form, $form_state);
  }
}
