<?php
/**
 * @file
 * Allow to render an openlayers map as ctools content.
 */

$plugin = array(
  'title' => t('Openlayers Map'),
  'single' => TRUE,
  'description' => t('Openlayers Map'),
  'category' => t('Miscellaneous'),
  'icon' => 'openlayers.png',
  'defaults' => array(
    'map' => NULL,
  ),
);

/**
 * Output function for the 'openlayers' content type.
 */
function openlayers_openlayers_content_type_render($subtype, $conf, $panel_args, $contexts) {
  try {
    if ($map = openlayers_object_load('Map', $conf['map'])) {
      return (object) array(
        'title' => NULL,
        'content' => $map->build(),
      );
    }
  }
  catch (Exception $e) {
    // Avoids that this takes down the whole page because of a failing map.
  }
}

/**
 * Define the settings.
 */
function openlayers_openlayers_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'] + $form_state['plugin']['defaults'];

  // Hide title handling.
  $form['override_title']['#access'] = FALSE;
  $form['override_title_text']['#access'] = FALSE;
  $form['override_title_heading']['#access'] = FALSE;
  $form['override_title_markup']['#access'] = FALSE;

  $form['conf']['#tree'] = TRUE;
  $all_maps = ctools_export_crud_load_all('openlayers_maps');
  $options = array();
  foreach ($all_maps as $machine_name => $map) {
    $options[$machine_name] = $map->name;
  }
  $form['conf']['map'] = array(
    '#type' => 'select',
    '#title' => t('Map'),
    '#options' => $options,
    '#default_value' => $conf['map'],
  );

  return $form;
}

/**
 * Store the configuration settings.
 */
function openlayers_openlayers_content_type_edit_form_submit($form, &$form_state) {
  // Generic handling.
  $conf = $form_state['conf'] + $form_state['plugin']['defaults'];
  foreach ($form_state['plugin']['defaults'] as $key => $value) {
    if (is_array($value)) {
      // Ensure it's a complete array.
      $form_state['values']['conf'][$key] += $conf[$key];
    }
    if (isset($form_state['values']['conf'][$key])) {
      $form_state['conf'][$key] = $form_state['values']['conf'][$key];
    }
  }
}

/**
 * Returns the administrative info for a map.
 */
function openlayers_openlayers_content_type_admin_info($subtype, $conf, $contexts) {
  $map_name = t('Unknown');
  try {
    /** @var Drupal\openlayers\Types\Map $map */
    if ($map = openlayers_object_load('Map', $conf['map'])) {
      $map_name = $map->name;
    }
  }
  catch (Exception $e) {
    // Avoids that this takes down the whole page because of a failing map.
  }
  $block = new stdClass();
  $block->title = t('Map: %map', array('%map' => $map_name));
  $block->content = '';
  return $block;
}
