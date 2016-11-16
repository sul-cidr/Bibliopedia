<?php
/**
 * @file
 * CTools Export UI plugin definition for styles.
 */

/**
 * CTools Export UI plugin definition.
 */
function openlayers_ui_OpenlayersStyles_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_styles',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'styles',
      'menu title' => 'Styles',
      'menu description' => 'Administer Openlayers styles.',
    ),

    'handler' => array(
      'class' => '\\Drupal\\openlayers_ui\\UI\\OpenlayersStyles',
      'file' => 'OpenlayersStyles.php',
    ),

    'export' => array(
      'admin_title' => 'name',
      'admin_description' => 'description',
    ),

    'use wizard' => TRUE,
    'form info' => array(
      'order' => array(
        'start' => t('Administrative settings'),
        'type' => t('Style type'),
        'options' => t('Style options'),
      ),
      'forms' => array(
        'start' => array(
          'form id' => 'openlayers_style_form_start',
        ),
        'type' => array(
          'form id' => 'openlayers_style_form_type',
        ),
        'options' => array(
          'form id' => 'openlayers_style_form_options',
        ),
      ),
      'wrapper' => 'openlayers_objects_ui_form_wrapper',
    ),

    'title singular' => t('style'),
    'title plural' => t('styles'),
    'title singular proper' => t('Openlayers style preset'),
    'title plural proper' => t('Openlayers styles presets'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Style saved.'),
        ),
        'delete' => array(
          'success' => t('Style was deleted.'),
        ),
      ),
    ),
  );
}

/**
 * Style base config form handler.
 */
function openlayers_style_form_start($form, &$form_state) {
  $class = new \Drupal\openlayers_ui\UI\OpenlayersStyles();
  $class->init($form_state['plugin']);
  $class->edit_form($form, $form_state);

  return $form;
}

/**
 * Style base config form validation handler.
 */
function openlayers_style_form_start_validate($form, &$form_state) {
  $class = new \Drupal\openlayers_ui\UI\OpenlayersStyles();
  $class->init($form_state['plugin']);
  $class->edit_form_validate($form, $form_state);
}

/**
 * Style base config form submit handler.
 */
function openlayers_style_form_start_submit($form, &$form_state) {
  $class = new \Drupal\openlayers_ui\UI\OpenlayersStyles();
  $class->init($form_state['plugin']);
  $class->edit_form_submit($form, $form_state);
}

/**
 * Style type config form handler.
 */
function openlayers_style_form_type($form, &$form_state) {
  $form['factory_service'] = array(
    '#type' => 'select',
    '#title' => t('Style type'),
    '#empty_option' => t('- Select a @plugin type -', array('@plugin' => 'Style')),
    '#default_value' => isset($form_state['item']->factory_service) ? $form_state['item']->factory_service : '',
    '#description' => t('Select the type of style.'),
    '#options' => \Drupal\openlayers\Openlayers::getOLObjectsOptions('Style'),
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Style type config form submit handler.
 */
function openlayers_style_form_type_submit($form, &$form_state) {
  if (isset($form_state['values']['options'])) {
    $form_state['item']->options = array_merge((array) $form_state['item']->options, (array) $form_state['values']['options']);
  }

  $form_state['item']->factory_service = $form_state['values']['factory_service'];
}

/**
 * Style options config form handler.
 */
function openlayers_style_form_options($form, &$form_state) {
  if (($style = \Drupal\openlayers\Openlayers::load('Style', $form_state['item'])) == TRUE) {
    $style->optionsForm($form, $form_state);
    $form['options']['#tree'] = TRUE;
  }

  return $form;
}

/**
 * Style options config form validation handler.
 */
function openlayers_style_form_options_validate($form, &$form_state) {
  if (($style = \Drupal\openlayers\Openlayers::load('Style', $form_state['item'])) == TRUE) {
    $style->optionsFormValidate($form, $form_state);
  }
}

/**
 * Style options config form submit handler.
 */
function openlayers_style_form_options_submit($form, &$form_state) {
  if (isset($form_state['values']['options'])) {
    $form_state['item']->options = array_merge((array) $form_state['item']->options, (array) $form_state['values']['options']);
  }
  if (($style = \Drupal\openlayers\Openlayers::load('Style', $form_state['item'])) == TRUE) {
    $style->optionsFormSubmit($form, $form_state);
  }
}
