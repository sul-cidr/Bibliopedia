<?php
/**
 * @file
 * Default maps.
 */

/**
 * Implements hook_default_openlayers_maps().
 */
function openlayers_examples_default_openlayers_maps() {
  $export = array();

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_earthquake';
  $ol_map->name = 'Openlayers examples: 2012 Earthquakes, tooltips and popups.';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_stamen3',
      1 => 'openlayers_examples_layer_vector_kml_earthquakes_heatmap',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_earthquake_style',
      1 => 'openlayers_examples_component_simple_popup_earthquakes',
      2 => 'openlayers_examples_component_tooltip_earthquakes',
    ),
  );
  $export['openlayers_examples_map_earthquake'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_geojson_cities';
  $ol_map->name = 'Openlayers examples: GeoJSON Cities';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_tile_mapbox_example3',
      1 => 'openlayers_examples_layer_vector_geojson_cities',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_geojson_cities'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_geojson_cities_heatmap';
  $ol_map->name = 'Openlayers examples: GeoJSON Cities Heatmap';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_tile_mapbox_example3',
      1 => 'openlayers_examples_layer_vector_geojson_cities_heatmap',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_geojson_cities_heatmap'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_geolocation';
  $ol_map->name = 'Openlayers examples: Geolocation';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap_mapnik',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_geolocation',
    ),
  );
  $export['openlayers_examples_map_geolocation'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapquest_views_geojson';
  $ol_map->name = 'Openlayers examples: Features from Views';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_mapquest_sat',
      1 => 'openlayers_examples_layer_views_geojson',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_zoomslider',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_zoom_to_source',
    ),
  );
  $export['openlayers_examples_map_mapquest_views_geojson'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_geojson_cluster';
  $ol_map->name = 'Openlayers examples: Cluster';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'layers' => array(
      0 => 'openlayers_layer_tile_mapquest_osm',
      1 => 'openlayers_examples_layer_cluster_cities',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_zoomslider',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_simple_popup_cities',
    ),
  );
  $export['openlayers_examples_map_geojson_cluster'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_popup_autozoom';
  $ol_map->name = 'Openlayers examples: Simple popup overlay and autozoom.';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'layers' => array(
      0 => 'openlayers_layer_tile_mapquest_osm',
      1 => 'openlayers_examples_layer_views_geojson_popup',
    ),
    'controls' => array(
      0 => 'openlayers_control_attribution',
      1 => 'openlayers_control_scaleline',
      2 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_simple_popup',
      1 => 'openlayers_examples_component_zoom_to_source',
    ),
  );
  $export['openlayers_examples_map_popup_autozoom'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_blocklayerswitcher';
  $ol_map->name = 'Openlayers examples: Layer switcher in a block';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_mapbox_geography_class',
      1 => 'openlayers_examples_layer_mapquest_hyb',
      2 => 'openlayers_examples_layer_mapquest_sat',
      3 => 'openlayers_examples_layer_stamen3',
      4 => 'openlayers_layer_tile_mapquest_osm',
      5 => 'openlayers_examples_layer_openstreetmap_mapnik',
      6 => 'openlayers_examples_layer_vector_kml_earthquakes',
      7 => 'openlayers_examples_layer_views_geojson',
      8 => 'openlayers_examples_layer_vector_geojson_cities_heatmap',
      9 => 'openlayers_examples_layer_vector_kml_earthquakes_heatmap',
      10 => 'openlayers_examples_layer_vector_geojson_cities',
      11 => 'openlayers_examples_layer_cluster_cities',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_blocklayerswitcher',
    ),
  );
  $export['openlayers_examples_map_blocklayerswitcher'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapquest_openstreetmap';
  $ol_map->name = 'Openlayers examples: MapQuest OpenStreetMap';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_layer_tile_mapquest_osm',
    ),
    'controls' => array(
      0 => 'openlayers_control_rotate',
      1 => 'openlayers_control_scaleline',
      2 => 'openlayers_control_zoom',
      3 => 'openlayers_control_zoomslider',
      4 => 'openlayers_control_zoomtoextent',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotate',
      3 => 'openlayers_interaction_keyboardpan',
      4 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_mapquest_openstreetmap'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapquest_hybrid';
  $ol_map->name = 'Openlayers examples: MapQuest Hybrid';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_mapquest_sat',
      1 => 'openlayers_examples_layer_mapquest_hyb',
    ),
    'controls' => array(
      0 => 'openlayers_control_attribution',
      1 => 'openlayers_control_rotate',
      2 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotateandzoom',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_mapquest_hybrid'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapquest_satellite';
  $ol_map->name = 'Openlayers examples: MapQuest Satellite';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_mapquest_sat',
    ),
    'controls' => array(
      0 => 'openlayers_control_mouseposition',
      1 => 'openlayers_control_scaleline',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotateandzoom',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_mapquest_satellite'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_ec_europa_osm';
  $ol_map->name = 'Openlayers examples: EC Europa';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap_mapnik',
      1 => 'openlayers_examples_layer_openstreetmap_europa',
    ),
    'controls' => array(
      0 => 'openlayers_examples_control_simple_layer_switcher',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_ec_europa_osm'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_osm';
  $ol_map->name = 'Openlayers examples: OpenStreetMap';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'renderer' => 'canvas',
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap_bw',
      2 => 'openlayers_examples_layer_openmapsurfer_roadsg',
      3 => 'openlayers_examples_layer_openmapsurfer_roads',
      4 => 'openlayers_examples_layer_opencyclemap_landscape',
      5 => 'openlayers_examples_layer_opencyclemap_transport',
      6 => 'openlayers_examples_layer_opencyclemap_thunderforest',
      7 => 'openlayers_examples_layer_openstreetmap_europa',
      8 => 'openlayers_examples_layer_opencyclemap_outdoors',
      9 => 'openlayers_examples_layer_opencyclemap',
      10 => 'openlayers_examples_layer_openstreetmap_hot',
      11 => 'openlayers_layer_tile_mapquest_osm',
      12 => 'openlayers_examples_layer_openstreetmap_de',
      13 => 'openlayers_examples_layer_openstreetmap_mapnik',
    ),
    'controls' => array(
      0 => 'openlayers_control_attribution',
      1 => 'openlayers_control_fullscreen',
      2 => 'openlayers_control_rotate',
      3 => 'openlayers_control_zoom',
      4 => 'openlayers_examples_control_osm_layer_switcher',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotate',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_osm'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_openstreetmap_tiledebug';
  $ol_map->name = 'Openlayers examples: OpenStreetMap with tile debug.';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap_mapnik',
      1 => 'openlayers_examples_layer_tiledebug',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_openstreetmap_tiledebug'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_stamen';
  $ol_map->name = 'Openlayers examples: Stamen';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_stamen3',
      1 => 'openlayers_examples_layer_stamen2',
      2 => 'openlayers_examples_layer_stamen1',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_examples_stamen_layer_switcher',
      2 => 'openlayers_control_attribution',
      3 => 'openlayers_control_fullscreen',
      4 => 'openlayers_control_mouseposition',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_stamen'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_esri';
  $ol_map->name = 'Openlayers examples: ESRI examples';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'renderer' => 'canvas',
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_esri_worldstreetmap',
      1 => 'openlayers_examples_layer_esri_delorme',
      2 => 'openlayers_examples_layer_esri_natgeoworldmap',
      3 => 'openlayers_examples_layer_esri_oceanbasemap',
      4 => 'openlayers_examples_layer_esri_worldimagery',
      5 => 'openlayers_examples_layer_esri_worldshadedrelief',
      6 => 'openlayers_examples_layer_esri_worldterrainbase',
      7 => 'openlayers_examples_layer_esri_worldtopomap',
    ),
    'controls' => array(
      0 => 'openlayers_examples_control_esri_layer_switcher',
      1 => 'openlayers_control_attribution',
      2 => 'openlayers_control_fullscreen',
      3 => 'openlayers_control_rotate',
      4 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotate',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_esri'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_googlemaps';
  $ol_map->name = 'Openlayers examples: Google Maps';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideBlockLayerSwitcher' => 0,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_googlemaps',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_googlemaps'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_symbols_webgl';
  $ol_map->name = 'Openlayers examples: Symbols with WebGL';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'renderer' => 'webgl',
    'width' => 'auto',
    'height' => '300px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '5',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_symbols_webgl',
    ),
    'controls' => array(
      0 => 'openlayers_control_fullscreen',
      1 => 'openlayers_control_rotate',
      2 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotateandzoom',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_symbols_webgl'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_icon_sprite';
  $ol_map->name = 'Openlayers examples: Icon sprites with WebGL';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'renderer' => 'webgl',
    'width' => 'auto',
    'height' => '300px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '5',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'controls' => array(
      0 => 'openlayers_control_fullscreen',
      1 => 'openlayers_control_rotate',
      2 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotateandzoom',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_icon_sprite'
    ),
  );
  $export['openlayers_examples_map_icon_sprite'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_openweather';
  $ol_map->name = 'Openlayers examples: OpenWeather';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'renderer' => 'canvas',
    'width' => 'auto',
    'height' => '300px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_mapquest_sat',
      1 => 'openlayers_examples_layer_openweather_precipitation',
      2 => 'openlayers_examples_layer_openweather_precipitation_cls',
      3 => 'openlayers_examples_layer_openweather_clouds',
      4 => 'openlayers_examples_layer_openweather_clouds_cls',
      5 => 'openlayers_examples_layer_openweather_pressure',
      6 => 'openlayers_examples_layer_openweather_pressure_cntr',
      7 => 'openlayers_examples_layer_openweather_rain',
      8 => 'openlayers_examples_layer_openweather_rain_cls',
      9 => 'openlayers_examples_layer_openweather_temp',
      10 => 'openlayers_examples_layer_openweather_snow',
      11 => 'openlayers_examples_layer_openweather_wind',
    ),
    'controls' => array(
      0 => 'openlayers_control_fullscreen',
      1 => 'openlayers_control_rotate',
      2 => 'openlayers_control_zoom',
      3 => 'openlayers_examples_control_openweather_layer_switcher',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotateandzoom',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_openweather'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_mapbox';
  $ol_map->name = 'Openlayers examples: Mapbox';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'renderer' => 'canvas',
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_tile_mapbox_example1',
      1 => 'openlayers_examples_layer_tile_mapbox_example2',
      2 => 'openlayers_examples_layer_tile_mapbox_example3',
      3 => 'openlayers_examples_layer_mapbox_geography_class',
      4 => 'openlayers_examples_layer_mapbox_natural_earth_hypso_bathy',
      5 => 'openlayers_examples_layer_mapbox_geography_class_utfgrid',
    ),
    'controls' => array(
      0 => 'openlayers_control_attribution',
      1 => 'openlayers_control_fullscreen',
      2 => 'openlayers_control_rotate',
      3 => 'openlayers_control_zoom',
      4 => 'openlayers_examples_control_mapbox_layer_switcher',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotate',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_tileutfgrid'
    ),
  );
  $export['openlayers_examples_map_mapbox'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_swipe';
  $ol_map->name = 'Openlayers examples: Swipe';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'provideBlockLayerSwitcher' => 0,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => 0,
      'zoom' => '2',
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_layer_tile_mapquest_osm',
      1 => 'openlayers_examples_layer_mapquest_sat',
    ),
    'controls' => array(
      0 => 'openlayers_control_attribution',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_swipe',
    ),
  );
  $export['openlayers_examples_map_swipe'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_timezones';
  $ol_map->name = 'Openlayers examples: Timezones';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'provideBlockLayerSwitcher' => 0,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'renderer' => 'canvas',
    'components' => array(
      0 => 'openlayers_examples_component_timezones',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_fullscreen',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_mousewheelzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_doubleclickzoom',
      3 => 'openlayers_interaction_dragrotateandzoom',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_stamen3',
      1 => 'openlayers_examples_layer_vector_kml_timezones',
    ),
    'styles' => array(
      0 => 'openlayers_examples_style_timezones',
      1 => 'openlayers_style_default',
    ),
  );
  $export['openlayers_examples_map_timezones'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_fractal';
  $ol_map->name = 'Openlayers examples: Fractal';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => 0,
      'zoom' => '1',
    ),
    'renderer' => 'canvas',
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_fractal',
    ),
  );
  $export['openlayers_examples_map_fractal'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_logistic';
  $ol_map->name = 'Openlayers examples: Logistic';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'view' => array(
      'center' => array(
        'lat' => '26.94',
        'lon' => '4.48',
      ),
      'rotation' => 0,
      'zoom' => '5',
    ),
    'renderer' => 'webgl',
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_fullscreen',
      2 => 'openlayers_control_mouseposition',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_logistic',
    ),
  );
  $export['openlayers_examples_map_logistic'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_julia';
  $ol_map->name = 'Openlayers examples: Julia/Mandelbrot set';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => 0,
      'zoom' => '5',
    ),
    'renderer' => 'webgl',
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_fullscreen',
      2 => 'openlayers_control_mouseposition',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_julia',
    ),
  );
  $export['openlayers_examples_map_julia'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_image_static';
  $ol_map->name = 'Openlayers examples: Image static';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '0',
      'minZoom' => '0',
      'maxZoom' => '0',
    ),
    'renderer' => 'canvas',
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_fullscreen',
      2 => 'openlayers_control_rotate',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_mousewheelzoom',
      1 => 'openlayers_interaction_doubleclickzoom',
      2 => 'openlayers_interaction_dragpan',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_image',
    ),
  );
  $export['openlayers_examples_map_image_static'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_graticule';
  $ol_map->name = 'Openlayers examples: Graticule';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap_mapnik',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_fullscreen',
      2 => 'openlayers_control_rotate',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_mousewheelzoom',
      1 => 'openlayers_interaction_doubleclickzoom',
      2 => 'openlayers_interaction_dragpan',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_graticule',
    ),
  );
  $export['openlayers_examples_map_graticule'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE;
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_ui_default_debug';
  $ol_map->name = 'Openlayers examples: Default UI Map with Debug';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '400px',
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
    ),
    'contextualLinks' => 0,
    'provideBlock' => 0,
    'provideIframe' => 1,
    'layers' => array(
      0 => 'openlayers_layer_tile_mapquest_osm',
    ),
    'controls' => array(
      0 => 'openlayers_control_rotate',
      1 => 'openlayers_control_zoom',
      2 => 'openlayers_control_zoomslider',
      3 => 'openlayers_control_fullscreen',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_dragpan',
      1 => 'openlayers_interaction_dragrotate',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_debug'
      )
  );
  $export['openlayers_examples_map_ui_default_debug'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_layerclipping';
  $ol_map->name = 'Openlayers examples: Layer clipping';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'contextualLinks' => 1,
    'provideBlock' => 1,
    'provideIframe' => 1,
    'view' => array(
      'center' => array(
        'lat' => '0',
        'lon' => '0',
      ),
      'rotation' => '0',
      'zoom' => '2',
    ),
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap_de',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_examples_component_layerclipping',
    ),
  );
  $export['openlayers_examples_map_layerclipping'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_tilewms';
  $ol_map->name = 'Openlayers examples: TileWMS';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'provideBlockLayerSwitcher' => 0,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
      'minZoom' => 0,
      'maxZoom' => 0,
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_layer_tile_mapquest_osm',
      1 => 'openlayers_examples_layer_tilewms',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_tilewms'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_ol3layerswitcher';
  $ol_map->name = 'Openlayers examples: OL3 LayerSwitcher';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
      'minZoom' => 0,
      'maxZoom' => 0,
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_examples_layer_group_overlay',
      1 => 'openlayers_examples_layer_group_base',
    ),
    'controls' => array(
      0 => 'openlayers_examples_control_ol3layerswitcher',
      1 => 'openlayers_control_attribution',
      2 => 'openlayers_control_fullscreen',
      3 => 'openlayers_control_overviewmap',
      4 => 'openlayers_control_rotate',
      5 => 'openlayers_control_zoom',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragrotate',
      2 => 'openlayers_interaction_dragpan',
    ),
  );
  $export['openlayers_examples_map_ol3layerswitcher'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_features_interactions';
  $ol_map->name = 'Openlayers examples: Features & Interactions';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
      'minZoom' => 0,
      'maxZoom' => 0,
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap_mapnik',
      1 => 'openlayers_examples_layer_random_features',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_fullscreen',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_dragpan',
      1 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_features_interactions'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_jsgeocoder';
  $ol_map->name = 'Openlayers examples: Simple JS Geocoder';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
      'minZoom' => 0,
      'maxZoom' => 0,
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_examples_layer_openstreetmap_de',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_examples_control_jsgeocoder',
      2 => 'openlayers_control_attribution',
      3 => 'openlayers_control_fullscreen',
      4 => 'openlayers_control_overviewmap',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotate',
    ),
  );
  $export['openlayers_examples_map_jsgeocoder'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_export';
  $ol_map->name = 'Openlayers examples: Export as image';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
      'minZoom' => 0,
      'maxZoom' => 0,
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_examples_layer_opencyclemap',
    ),
    'controls' => array(
      0 => 'openlayers_examples_control_export',
      1 => 'openlayers_control_zoom',
      2 => 'openlayers_control_attribution',
      3 => 'openlayers_control_overviewmap',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotate',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_export'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_examples_map_opentopomap';
  $ol_map->name = 'Openlayers examples: Opentopomap';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '300px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
      'minZoom' => 0,
      'maxZoom' => 0,
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_examples_layer_opentopomap',
    ),
    'controls' => array(
      0 => 'openlayers_control_zoom',
      1 => 'openlayers_control_attribution',
      2 => 'openlayers_control_overviewmap',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_doubleclickzoom',
      1 => 'openlayers_interaction_dragpan',
      2 => 'openlayers_interaction_dragrotate',
      3 => 'openlayers_interaction_mousewheelzoom',
    ),
  );
  $export['openlayers_examples_map_opentopomap'] = $ol_map;

  return $export;
}
