<?php
/**
 * @file
 * Default sources.
 */

/**
 * Implements hook_default_sources().
 */
function openlayers_geofield_default_openlayers_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_geofield_source_vector';
  $ol_source->name = 'Openlayers Geofield: Vector source placeholder';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:Vector';
  $ol_source->options = array();
  $export['openlayers_geofield_source_vector'] = $ol_source;

  return $export;
}
