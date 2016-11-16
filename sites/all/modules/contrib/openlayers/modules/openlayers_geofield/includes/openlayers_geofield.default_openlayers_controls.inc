<?php
/**
 * @file
 * Default controls.
 */

/**
 * Implements hook_default_openlayers_controls().
 */
function openlayers_geofield_default_openlayers_controls() {
  $export = array();

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_geofield_control_geofield';
  $ol_control->name = 'Openlayers Geofield toolbar';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:Geofield';
  $ol_control->options = array(
    'draw' => array(
      'Point' => 'Point',
      'LineString' => 'LineString',
      'Polygon' => 'Polygon',
      'Triangle' => 'Triangle',
      'Square' => 'Square',
      'Circle' => 'Circle',
      'Box' => 'Box',
      'MultiPoint' => 0,
      'MultiLineString' => 0,
      'MultiPolygon' => 0,
    ),
    'actions' => array(
      'Edit' => 'Edit',
      'Move' => 'Move',
      'Clear' => 'Clear',
    ),
    'options' => array(
      'Snap' => 'Snap',
    ),
  );
  $export['openlayers_geofield_control_geofield'] = $ol_control;

  return $export;
}
