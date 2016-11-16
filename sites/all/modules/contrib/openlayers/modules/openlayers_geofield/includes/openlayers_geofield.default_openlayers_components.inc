<?php
/**
 * @file
 * Default components.
 */

/**
 * Implements hook_default_components().
 */
function openlayers_geofield_default_openlayers_components() {
  $export = array();

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_geofield_component_geofield_widget';
  $ol_component->name = 'Openlayers Geofield: Widget component';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:GeofieldWidget';
  $ol_component->options = array(
    'featureLimit' => 0,
    'showInputField' => 0,
    'inputFieldName' => 'geom',
    'initialData' => '',
    'dataProjection' => 'EPSG:4326',
    'editStyle' => 'openlayers_geofield_style_edit',
    'editLayer' => 'openlayers_geofield_layer_widget',
    'editControl' => 'openlayers_geofield_control_geofield',
  );
  $export['openlayers_geofield_component_geofield_widget'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_geofield_component_zoom_to_source';
  $ol_component->name = 'Openlayers Geofield: Zoom to Source';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:ZoomToSource';
  $ol_component->options = array(
    'source' => array(
      'openlayers_geofield_source_vector' => 'openlayers_geofield_source_vector',
    ),
    'animations' => array(
      'pan' => 500,
      'zoom' => 500,
    ),
    'zoom' => 'auto',
    'enableAnimations' => 1,
    'process_once' => 1,
    'max_zoom' => 5,
  );
  $export['openlayers_geofield_component_zoom_to_source'] = $ol_component;

  return $export;
}
