<?php
/**
 * @file
 * CTools Export UI plugin definition for sources.
 */

/**
 * CTools Export UI plugin definition.
 */
function openlayers_ui_OpenlayersSources_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_sources',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'sources',
      'menu title' => 'Sources',
      'menu description' => 'Administer Openlayers sources.',
    ),

    'handler' => array(
      'class' => '\\Drupal\\openlayers_ui\\UI\\OpenlayersSources',
      'file' => 'OpenlayersSources.php',
    ),

    'export' => array(
      'admin_title' => 'name',
      'admin_description' => 'description',
    ),

    'use wizard' => TRUE,
    'form info' => array(
      'order' => array(
        'start' => t('Administrative settings'),
        'type' => t('Source type'),
        'options' => t('Source type options'),
      ),
      'forms' => array(
        'start' => array(
          'form id' => 'openlayers_source_form_start',
        ),
        'type' => array(
          'form id' => 'openlayers_source_form_type',
        ),
        'options' => array(
          'form id' => 'openlayers_source_form_options',
        ),
      ),
      'wrapper' => 'openlayers_objects_ui_form_wrapper',
    ),

    'title singular' => t('source'),
    'title plural' => t('sources'),
    'title singular proper' => t('Openlayers source preset'),
    'title plural proper' => t('Openlayers sources presets'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Source saved.'),
        ),
        'delete' => array(
          'success' => t('Source was deleted.'),
        ),
      ),
    ),
  );
}

/**
 * Source base config form handler.
 */
function openlayers_source_form_start($form, &$form_state) {
  $class = new \Drupal\openlayers_ui\UI\OpenlayersSources();
  $class->init($form_state['plugin']);
  $class->edit_form($form, $form_state);

  $options = array();
  foreach (\Drupal\openlayers\Openlayers::loadAllExportable('Layer') as $machine_name => $layer) {
    if (!is_object($layer) || (property_exists($layer, 'disabled') && ($layer->disabled == 1 || $layer->disabled == TRUE))) {
      continue;
    }
    $options[$machine_name] = $layer->name;
  }

  $form['attachToLayer'] = array(
    '#type' => 'select',
    '#title' => 'Add this to a layer ?',
    '#empty_option' => t('- Do no attach -'),
    '#description' => 'Select the layer to add this object to.',
    '#options' => $options,
    '#default_value' => isset($form_state['item']->attachToLayer) ? $form_state['item']->attachToLayer : '',
  );

  return $form;
}

/**
 * Source base config form validation handler.
 */
function openlayers_source_form_start_validate($form, &$form_state) {
  $class = new \Drupal\openlayers_ui\UI\OpenlayersSources();
  $class->init($form_state['plugin']);
  $class->edit_form_validate($form, $form_state);
}

/**
 * Source base config form submit handler.
 */
function openlayers_source_form_start_submit($form, &$form_state) {
  $class = new \Drupal\openlayers_ui\UI\OpenlayersSources();
  $class->init($form_state['plugin']);
  $class->edit_form_submit($form, $form_state);
}

/**
 * Source type config form handler.
 */
function openlayers_source_form_type($form, &$form_state) {
  $form['factory_service'] = array(
    '#type' => 'select',
    '#title' => t('Source Type'),
    '#empty_option' => t('- Select a @plugin type -', array('@plugin' => 'Source')),
    '#default_value' => isset($form_state['item']->factory_service) ? $form_state['item']->factory_service : '',
    '#description' => t('Select the type of source.'),
    '#options' => \Drupal\openlayers\Openlayers::getOLObjectsOptions('Source'),
    '#required' => TRUE,
  );

  $form['options'] = array(
    '#tree' => TRUE,
  );

  $form['options']['attributions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Attributions options'),
  );
  $form['options']['attributions']['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable attributions'),
    '#default_value' => isset($form_state['item']->options['attributions']) ? TRUE : FALSE,
    '#description' => t('Enable attributions ?'),
  );
  $form['options']['attributions']['data'] = array(
    '#type' => 'textfield',
    '#title' => t('Attributions'),
    '#default_value' => isset($form_state['item']->options['attributions']) ? $form_state['item']->options['attributions'] : '',
    '#description' => t('Attributions HTML text. Empty to disable.'),
    '#states' => array(
      'visible' => array(
        ':input[name="options[attributions][enabled]"]' => array('checked' => TRUE),
      ),
    ),
  );

  return $form;
}

/**
 * Source type config form submit handler.
 */
function openlayers_source_form_type_submit($form, &$form_state) {
  if (isset($form_state['values']['options'])) {
    $form_state['item']->options = array_merge((array) $form_state['item']->options, (array) $form_state['values']['options']);
  }

  if ((bool) $form_state['values']['options']['attributions']['enabled'] == FALSE) {
    unset($form_state['item']->options['attributions']);
  }
  else {
    unset($form_state['item']->options['attributions']['enabled']);
    $form_state['item']->options['attributions'] = $form_state['values']['options']['attributions']['data'];
  }

  $form_state['item']->factory_service = $form_state['values']['factory_service'];
}

/**
 * Source options config form handler.
 */
function openlayers_source_form_options($form, &$form_state) {
  if (($source = \Drupal\openlayers\Openlayers::load('Source', $form_state['item'])) == TRUE) {
    $source->optionsForm($form, $form_state);
    $form['options']['#tree'] = TRUE;
  }

  return $form;
}

/**
 * Source options config form validation handler.
 */
function openlayers_source_form_options_validate($form, &$form_state) {
  if (($source = \Drupal\openlayers\Openlayers::load('Source', $form_state['item'])) == TRUE) {
    $source->optionsFormValidate($form, $form_state);
  }
}

/**
 * Source options config form submit handler.
 */
function openlayers_source_form_options_submit($form, &$form_state) {
  if (isset($form_state['values']['options'])) {
    $form_state['item']->options = array_merge((array) $form_state['item']->options, (array) $form_state['values']['options']);
  }

  if (!empty($form_state['item']->attachToLayer) && ($layer = \Drupal\openlayers\Openlayers::load('layer', $form_state['item']->attachToLayer)) == TRUE) {
    // We should add the object to the Collection so JS and CSS files are
    // imported.
    $layer->setOption('source', $form_state['item']->machine_name);
    \Drupal\openlayers\Openlayers::save($layer);
    unset($form_state['item']->attachToLayer);
  }

  if (($source = \Drupal\openlayers\Openlayers::load('Source', $form_state['item'])) == TRUE) {
    $source->optionsFormSubmit($form, $form_state);
  }
}
