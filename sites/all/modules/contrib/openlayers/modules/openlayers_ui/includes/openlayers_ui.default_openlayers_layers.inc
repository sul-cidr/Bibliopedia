<?php
/**
 * @file
 * Default layers.
 */

/**
 * Implements hook_default_openlayers_layers().
 */
function openlayers_ui_default_openlayers_layers() {
  $export = array();

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_ui_layer_style_demo';
  $ol_layer->name = 'Openlayers UI layer style demo ';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'openlayers_ui_source_style_demo',
    'visible' => 1,
    'style' => 'openlayers_style_default',
  );
  $export['openlayers_ui_layer_style_demo'] = $ol_layer;

  return $export;
}
