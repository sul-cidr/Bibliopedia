<?php
/**
 * @file
 * Provide default controls.
 */

/**
 * Implements hook_default_openlayers_controls().
 */
function openlayers_examples_default_openlayers_controls() {
  $export = array();

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_examples_stamen_layer_switcher';
  $ol_control->name = 'Openlayers examples: Stamen layer switcher';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:LayerSwitcher';
  $ol_control->options = array(
    'label' => 'Layers',
    'layers' => array(
      'openlayers_examples_layer_stamen1' => 'openlayers_examples_layer_stamen1',
      'openlayers_examples_layer_stamen2' => 'openlayers_examples_layer_stamen2',
      'openlayers_examples_layer_stamen3' => 'openlayers_examples_layer_stamen3',
    ),
    'multiselect' => 1,
  );
  $export['openlayers_examples_stamen_layer_switcher'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_examples_control_simple_layer_switcher';
  $ol_control->name = 'Openlayers examples: Simple layer switcher';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:LayerSwitcher';
  $ol_control->options = array(
    'label' => 'Layers',
    'layers' => array(
      'openlayers_examples_layer_openstreetmap_europa' => 'openlayers_examples_layer_openstreetmap_europa',
      'openlayers_examples_layer_openstreetmap_mapnik' => 'openlayers_examples_layer_openstreetmap_mapnik',
    ),
    'multiselect' => 0,
  );
  $export['openlayers_examples_control_simple_layer_switcher'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_examples_control_openweather_layer_switcher';
  $ol_control->name = 'Openlayers examples: OpenWeather Layer Switcher';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:LayerSwitcher';
  $ol_control->options = array(
    'label' => 'Layers',
    'layers' => array(
      'openlayers_examples_layer_openweather_clouds' => 'openlayers_examples_layer_openweather_clouds',
      'openlayers_examples_layer_openweather_clouds_cls' => 'openlayers_examples_layer_openweather_clouds_cls',
      'openlayers_examples_layer_openweather_precipitation' => 'openlayers_examples_layer_openweather_precipitation',
      'openlayers_examples_layer_openweather_precipitation_cls' => 'openlayers_examples_layer_openweather_precipitation_cls',
      'openlayers_examples_layer_openweather_pressure' => 'openlayers_examples_layer_openweather_pressure',
      'openlayers_examples_layer_openweather_pressure_cntr' => 'openlayers_examples_layer_openweather_pressure_cntr',
      'openlayers_examples_layer_openweather_rain' => 'openlayers_examples_layer_openweather_rain',
      'openlayers_examples_layer_openweather_rain_cls' => 'openlayers_examples_layer_openweather_rain_cls',
      'openlayers_examples_layer_openweather_temp' => 'openlayers_examples_layer_openweather_temp',
      'openlayers_examples_layer_openweather_snow' => 'openlayers_examples_layer_openweather_snow',
      'openlayers_examples_layer_openweather_wind' => 'openlayers_examples_layer_openweather_wind',
    ),
    'multiselect' => 1,
  );
  $export['openlayers_examples_control_openweather_layer_switcher'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_examples_control_esri_layer_switcher';
  $ol_control->name = 'Openlayers examples: ESRI layer switcher';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:LayerSwitcher';
  $ol_control->options = array(
    'label' => 'Layers',
    'layers' => array(
      'openlayers_examples_layer_esri_delorme' => 'openlayers_examples_layer_esri_delorme',
      'openlayers_examples_layer_esri_natgeoworldmap' => 'openlayers_examples_layer_esri_natgeoworldmap',
      'openlayers_examples_layer_esri_oceanbasemap' => 'openlayers_examples_layer_esri_oceanbasemap',
      'openlayers_examples_layer_esri_worldimagery' => 'openlayers_examples_layer_esri_worldimagery',
      'openlayers_examples_layer_esri_worldshadedrelief' => 'openlayers_examples_layer_esri_worldshadedrelief',
      'openlayers_examples_layer_esri_worldstreetmap' => 'openlayers_examples_layer_esri_worldstreetmap',
      'openlayers_examples_layer_esri_worldterrainbase' => 'openlayers_examples_layer_esri_worldterrainbase',
      'openlayers_examples_layer_esri_worldtopomap' => 'openlayers_examples_layer_esri_worldtopomap',
    ),
    'multiselect' => 0,
  );
  $export['openlayers_examples_control_esri_layer_switcher'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_examples_control_osm_layer_switcher';
  $ol_control->name = 'Openlayers examples: OSM layer switcher';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:LayerSwitcher';
  $ol_control->options = array(
    'label' => 'Layers',
    'layers' => array(
      'openlayers_examples_layer_openstreetmap_europa' => 'openlayers_examples_layer_openstreetmap_europa',
      'openlayers_examples_layer_opencyclemap' => 'openlayers_examples_layer_opencyclemap',
      'openlayers_examples_layer_opencyclemap_landscape' => 'openlayers_examples_layer_opencyclemap_landscape',
      'openlayers_examples_layer_opencyclemap_outdoors' => 'openlayers_examples_layer_opencyclemap_outdoors',
      'openlayers_examples_layer_opencyclemap_thunderforest' => 'openlayers_examples_layer_opencyclemap_thunderforest',
      'openlayers_examples_layer_opencyclemap_transport' => 'openlayers_examples_layer_opencyclemap_transport',
      'openlayers_examples_layer_openmapsurfer_roads' => 'openlayers_examples_layer_openmapsurfer_roads',
      'openlayers_examples_layer_openmapsurfer_roadsg' => 'openlayers_examples_layer_openmapsurfer_roadsg',
      'openlayers_examples_layer_openstreetmap_bw' => 'openlayers_examples_layer_openstreetmap_bw',
      'openlayers_examples_layer_openstreetmap_de' => 'openlayers_examples_layer_openstreetmap_de',
      'openlayers_examples_layer_openstreetmap_hot' => 'openlayers_examples_layer_openstreetmap_hot',
      'openlayers_examples_layer_openstreetmap_mapnik' => 'openlayers_examples_layer_openstreetmap_mapnik',
      'openlayers_layer_tile_mapquest_osm' => 'openlayers_layer_tile_mapquest_osm',
    ),
    'multiselect' => 0,
  );
  $export['openlayers_examples_control_osm_layer_switcher'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_examples_control_mapbox_layer_switcher';
  $ol_control->name = 'Openlayers examples: Mapbox layer switcher';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:LayerSwitcher';
  $ol_control->options = array(
    'label' => 'Layers',
    'layers' => array(
      'openlayers_examples_layer_mapbox_geography_class' => 'openlayers_examples_layer_mapbox_geography_class',
      'openlayers_examples_layer_mapbox_natural_earth_hypso_bathy' => 'openlayers_examples_layer_mapbox_natural_earth_hypso_bathy',
      'openlayers_examples_layer_tile_mapbox_example1' => 'openlayers_examples_layer_tile_mapbox_example1',
      'openlayers_examples_layer_tile_mapbox_example2' => 'openlayers_examples_layer_tile_mapbox_example2',
      'openlayers_examples_layer_tile_mapbox_example3' => 'openlayers_examples_layer_tile_mapbox_example3',
    ),
    'multiselect' => 0,
  );
  $export['openlayers_examples_control_mapbox_layer_switcher'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_examples_control_ol3layerswitcher';
  $ol_control->name = 'Openlayers examples: Control OL3 LayerSwitcher';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:OL3LayerSwitcher';
  $export['openlayers_examples_control_ol3layerswitcher'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_examples_control_jsgeocoder';
  $ol_control->name = 'Openlayers examples: Geocoder JS';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:JSGeocoder';
  $ol_control->options = array(
    'placeholder' => 'Search with Google...',
    'loadingPlaceholder' => 'Loading...',
    'zoom' => 13,
  );
  $export['openlayers_examples_control_jsgeocoder'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_examples_control_autozoom';
  $ol_control->name = 'Openlayers examples: AutoZoom';
  $ol_control->description = '';
  $ol_control->options = array(
    'zoom' => 'disabled',
    'max_zoom' => 0,
    'process_once' => 0,
    'enableAnimations' => 1,
    'animations' => array(
      'pan' => 500,
      'zoom' => 500,
    ),
  );
  $ol_control->factory_service = 'openlayers.Control:AutoZoom';
  $export['openlayers_examples_control_autozoom'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->disabled = FALSE; /* Edit this to true to make a default ol_control disabled initially */
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_examples_control_export';
  $ol_control->name = 'Openlayers examples: Export as image';
  $ol_control->description = '';
  $ol_control->factory_service = 'openlayers.Control:Export';
  $ol_control->options = array(
    'exportTipLabel' => 'Export as image',
  );
  $export['openlayers_examples_control_export'] = $ol_control;

  return $export;
}
