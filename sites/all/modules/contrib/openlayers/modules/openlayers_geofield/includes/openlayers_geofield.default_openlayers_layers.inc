<?php
/**
 * @file
 * Default layers.
 */

/**
 * Implements hook_default_layers().
 */
function openlayers_geofield_default_openlayers_layers() {
  $export = array();

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_geofield_layer_formatter';
  $ol_layer->name = 'Openlayers Geofield: Formatter layer';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'openlayers_geofield_source_vector',
    'style' => 'openlayers_style_default',
  );
  $export['openlayers_geofield_layer_formatter'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default ol_layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_geofield_layer_widget';
  $ol_layer->name = 'Openlayers Geofield: Widget layer';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Vector';
  $ol_layer->options = array(
    'source' => 'openlayers_geofield_source_vector',
    'style' => 'openlayers_geofield_style_edit',
  );
  $export['openlayers_geofield_layer_widget'] = $ol_layer;

  return $export;
}
