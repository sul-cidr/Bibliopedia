<?php
/**
 * @file
 * Default sources.
 */

/**
 * Implements hook_default_openlayers_sources().
 */
function openlayers_examples_default_openlayers_sources() {
  $export = array();

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapbox_example1';
  $ol_source->name = 'Openlayers examples: MapBox example 1';
  $ol_source->description = 'Source MapBox example 1';
  $ol_source->factory_service = 'openlayers.Source:TileJSON';
  $ol_source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/examples.map-i86nkdio.jsonp',
  );
  $export['openlayers_examples_source_mapbox_example1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapbox_example2';
  $ol_source->name = 'Openlayers examples: MapBox example 2';
  $ol_source->description = 'Source MapBox example 2';
  $ol_source->factory_service = 'openlayers.Source:TileJSON';
  $ol_source->options = array(
    'url' => '//api.tiles.mapbox.com/v3/examples.c7d2024a.jsonp',
  );
  $export['openlayers_examples_source_mapbox_example2'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapbox_example3';
  $ol_source->name = 'Openlayers examples: MapBox example 3';
  $ol_source->description = 'Source MapBox example 3, used by ft.com.';
  $ol_source->factory_service = 'openlayers.Source:TileJSON';
  $ol_source->options = array(
    'url' => '//api.tiles.mapbox.com/v3/financialtimes.map-w7l4lfi8.jsonp',
  );
  $export['openlayers_examples_source_mapbox_example3'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapbox_geography_class';
  $ol_source->name = 'Openlayers examples: MapBox Geography Class';
  $ol_source->description = 'Source MapBox Geography Class description';
  $ol_source->factory_service = 'openlayers.Source:TileJSON';
  $ol_source->options = array(
    'url' => '//api.tiles.mapbox.com/v3/mapbox.geography-class.jsonp',
  );
  $export['openlayers_examples_source_mapbox_geography_class'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapbox_geography_class_utfgrid';
  $ol_source->name = 'Openlayers examples: MapBox Geography Class UTFgrid';
  $ol_source->description = 'Source MapBox Geography Class UTFgrid description';
  $ol_source->factory_service = 'openlayers.Source:TileUTFGrid';
  $ol_source->options = array(
    'url' => '//api.tiles.mapbox.com/v3/mapbox.geography-class.json',
  );
  $export['openlayers_examples_source_mapbox_geography_class_utfgrid'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapbox_natural_earth_hypso_bathy';
  $ol_source->name = 'Openlayers examples: MapBox Natural Earth Hypso Bathy';
  $ol_source->description = 'Source MapBox Natural Hearth Hypso Bathy description';
  $ol_source->factory_service = 'openlayers.Source:TileJSON';
  $ol_source->options = array(
    'url' => '//api.tiles.mapbox.com/v3/mapbox.natural-earth-hypso-bathy.jsonp',
  );
  $export['openlayers_examples_source_mapbox_natural_earth_hypso_bathy'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_googlemaps';
  $ol_source->name = 'Openlayers examples: Google Maps';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:GoogleMaps';
  $ol_source->options = array(
    'key' => '',
    'client' => '',
    'channel' => '',
    'mapTypeId' => 'ROADMAP',
    'sensor' => 0,
  );
  $export['openlayers_examples_source_googlemaps'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openstreetmap_europa';
  $ol_source->name = 'Openlayers examples: EC OpenStreetMap Europa Webtools';
  $ol_source->description = 'Source from European Commission webtools based on OSM, with some modifications.';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => 'http://webtools.ec.europa.eu/road-maps/tiles/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openstreetmap_europa'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_geojson_file';
  $ol_source->name = 'Openlayers examples: Cities GeoJSON';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:GeoJSON';
  $ol_source->options = array(
    'url' => file_create_url(drupal_get_path('module', 'openlayers_examples') . '/assets/cities.json'),
  );
  $export['openlayers_examples_source_geojson_file'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_kml_earthquakes';
  $ol_source->name = 'Openlayers examples: 2012 Earthquakes';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:KML';
  $ol_source->options = array(
    'url' => file_create_url(drupal_get_path('module', 'openlayers_examples') . '/assets/2012_Earthquakes_Mag5.kml'),
  );
  $export['openlayers_examples_source_kml_earthquakes'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_kml_timezones';
  $ol_source->name = 'Openlayers examples: Timezones (KML)';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:KML';
  $ol_source->options = array(
    'url' => file_create_url(drupal_get_path('module', 'openlayers_examples') . '/assets/timezones.kml'),
  );
  $export['openlayers_examples_source_kml_timezones'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_cluster';
  $ol_source->name = 'Openlayers examples: Cluster cities';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:Cluster';
  $ol_source->options = array(
    'source' => 'openlayers_examples_source_geojson_file',
    'distance' => '50',
  );
  $export['openlayers_examples_source_cluster'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_opencyclemap';
  $ol_source->name = 'Openlayers examples: OpenCycleMap';
  $ol_source->description = 'Source OpenCycleMap description';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'crossOrigin' => 'anonymous',
    'url' => '//{a-c}.tile.opencyclemap.org/cycle/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_opencyclemap'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openstreetmap_mapnik';
  $ol_source->name = 'Openlayers examples: OpenStreetMap Mapnik';
  $ol_source->description = 'OpenStreetMap Mapnik source';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'crossOrigin' => 'anonymous',
    'attributions' => '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>',
  );
  $export['openlayers_examples_source_openstreetmap_mapnik'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openstreetmap_bw';
  $ol_source->name = 'Openlayers examples: OpenStreetMap black and white';
  $ol_source->description = 'OpenStreetMap black and white source';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'crossOrigin' => 'null',
    'url' => '//{a-c}.tiles.wmflabs.org/bw-mapnik/{z}/{x}/{y}.png',
    'attributions' => '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
  );
  $export['openlayers_examples_source_openstreetmap_bw'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openstreetmap_de';
  $ol_source->name = 'Openlayers examples: OpenStreetMap DE';
  $ol_source->description = 'Source OpenStreetMap DE description';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'url' => '//{a-c}.tile.openstreetmap.de/tiles/osmde/{z}/{x}/{y}.png',
    'attributions' => '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
  );
  $export['openlayers_examples_source_openstreetmap_de'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openstreetmap_hot';
  $ol_source->name = 'Openlayers examples: OpenStreetMap Hot';
  $ol_source->description = 'OpenStreetMap Hot source';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'url' => '//{a-c}.tile.openstreetmap.fr/hot/{z}/{x}/{y}.png',
    'attributions' => '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>, Tiles courtesy of <a href="http://hot.openstreetmap.org/" target="_blank">Humanitarian OpenStreetMap Team</a>'
  );
  $export['openlayers_examples_source_openstreetmap_hot'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_opencyclemap_thunderforest';
  $ol_source->name = 'Openlayers examples: OpenCycleMap Thunderforest';
  $ol_source->description = 'OpenCycleMap Thunderforest source';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'url' => '//{a-c}.tile.thunderforest.com/cycle/{z}/{x}/{y}.png',
    'attributions' => '&copy; <a href="http://www.opencyclemap.org">OpenCycleMap</a>, &copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
  );
  $export['openlayers_examples_source_opencyclemap_thunderforest'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_opencyclemap_transport';
  $ol_source->name = 'Openlayers examples: OpenCycleMap Transport';
  $ol_source->description = 'OpenCycleMap Transport source';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'url' => '//{a-c}.tile.thunderforest.com/transport/{z}/{x}/{y}.png',
    'attributions' => '&copy; <a href="http://www.opencyclemap.org">OpenCycleMap</a>, &copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
  );
  $export['openlayers_examples_source_opencyclemap_transport'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_opencyclemap_landscape';
  $ol_source->name = 'Openlayers examples: OpenCycleMap Landscape';
  $ol_source->description = 'OpenCycleMap Landscape source';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'url' => '//{a-c}.tile.thunderforest.com/landscape/{z}/{x}/{y}.png',
    'attributions' => '&copy; <a href="http://www.opencyclemap.org">OpenCycleMap</a>, &copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
  );
  $export['openlayers_examples_source_opencyclemap_landscape'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_opencyclemap_outdoors';
  $ol_source->name = 'Openlayers examples: OpenCycleMap Outdoors';
  $ol_source->description = 'OpenCycleMap Outdoors source';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'url' => '//{a-c}.tile.thunderforest.com/outdoors/{z}/{x}/{y}.png',
    'attributions' => '&copy; <a href="http://www.opencyclemap.org">OpenCycleMap</a>, &copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
  );
  $export['openlayers_examples_source_opencyclemap_outdoors'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openmapsurfer_roads';
  $ol_source->name = 'Openlayers examples: OpenMapSurfer Roads';
  $ol_source->description = 'OpenMapSurfer Roads source';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'crossOrigin' => 'null',
    'url' => '//korona.geog.uni-heidelberg.de/tiles/roads/x={x}&y={y}&z={z}',
    'attributions' => 'Imagery from <a href="http://giscience.uni-hd.de/">GIScience Research Group @ University of Heidelberg</a> &mdash; Map data &copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
  );
  $export['openlayers_examples_source_openmapsurfer_roads'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openmapsurfer_roadsg';
  $ol_source->name = 'Openlayers examples: OpenMapSurfer Roads grayscale';
  $ol_source->description = 'OpenMapSurfer Roads grayscale source';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'crossOrigin' => 'null',
    'url' => '//korona.geog.uni-heidelberg.de/tiles/roadsg/x={x}&y={y}&z={z}',
    'attributions' => 'Imagery from <a href="http://giscience.uni-hd.de/">GIScience Research Group @ University of Heidelberg</a> &mdash; Map data &copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
  );
  $export['openlayers_examples_source_openmapsurfer_roadsg'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openmapsurfer_adminb';
  $ol_source->name = 'Openlayers examples: OpenMapSurfer admin borders';
  $ol_source->description = 'OpenMapSurfer admin borders source';
  $ol_source->factory_service = 'openlayers.Source:OSM';
  $ol_source->options = array(
    'crossOrigin' => 'null',
    'url' => '//korona.geog.uni-heidelberg.de/tiles/adminb/x={x}&y={y}&z={z}',
    'attributions' => 'Imagery from <a href="http://giscience.uni-hd.de/">GIScience Research Group @ University of Heidelberg</a> &mdash; Map data &copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
  );
  $export['openlayers_examples_source_openmapsurfer_adminb'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_bingmaps';
  $ol_source->name = 'Openlayers examples: Bing Maps';
  $ol_source->description = 'Source Bingmaps description';
  $ol_source->factory_service = 'openlayers.Source:BingMaps';
  $ol_source->options = array();
  $export['openlayers_examples_source_bingmaps'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapquest_sat';
  $ol_source->name = 'Openlayers examples: MapQuest Satellite';
  $ol_source->description = 'Source MapQuest Satellite description';
  $ol_source->factory_service = 'openlayers.Source:MapQuest';
  $ol_source->options = array(
    'layer' => 'sat',
  );
  $export['openlayers_examples_source_mapquest_sat'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_mapquest_hyb';
  $ol_source->name = 'Openlayers examples: MapQuest Hybrid';
  $ol_source->description = 'Source MapQuest Hybrid';
  $ol_source->factory_service = 'openlayers.Source:MapQuest';
  $ol_source->options = array(
    'layer' => 'hyb',
  );
  $export['openlayers_examples_source_mapquest_hyb'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_imagestatic';
  $ol_source->name = 'Openlayers examples: Image Static';
  $ol_source->description = 'Source Image Static description';
  $ol_source->factory_service = 'openlayers.Source:ImageStatic';
  $ol_source->options = array(
    'url' => file_create_url(drupal_get_path('module', 'openlayers_examples') . '/assets/druplicon.png'),
  );
  $export['openlayers_examples_source_imagestatic'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_tiledebug';
  $ol_source->name = 'Openlayers examples: Tile debug';
  $ol_source->description = 'A pseudo tile source, which does not fetch tiles from a server, but renders a grid outline for the tile grid/projection along with the coordinates for each tile.';
  $ol_source->factory_service = 'openlayers.Source:TileDebug';
  $ol_source->options = array(
    'maxZoom' => 22,
  );
  $export['openlayers_examples_source_tiledebug'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_stamen1';
  $ol_source->name = 'Openlayers examples: Stamen terrain labels';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:Stamen';
  $ol_source->options = array(
    'layer' => 'terrain-labels',
  );
  $export['openlayers_examples_source_stamen1'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_stamen2';
  $ol_source->name = 'Openlayers examples: Stamen watercolor';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:Stamen';
  $ol_source->options = array(
    'layer' => 'watercolor',
  );
  $export['openlayers_examples_source_stamen2'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_stamen3';
  $ol_source->name = 'Openlayers examples: Stamen toner';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:Stamen';
  $ol_source->options = array(
    'layer' => 'toner',
  );
  $export['openlayers_examples_source_stamen3'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_esri_worldtopomap';
  $ol_source->name = 'Openlayers examples: ESRI World Topo Map';
  $ol_source->description = 'ESRI World Topo Map source';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//server.arcgisonline.com/ArcGIS/rest/services/World_Topo_Map/MapServer/tile/{z}/{y}/{x}',
    'attributions' => 'Tiles &copy; Esri &mdash; Source: Esri, DeLorme, NAVTEQ, USGS, Intermap, iPC, NRCAN, Esri Japan, METI, Esri China (Hong Kong), Esri (Thailand), TomTom, 2012'
  );
  $export['openlayers_examples_source_esri_worldtopomap'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_esri_worldstreetmap';
  $ol_source->name = 'Openlayers examples: ESRI World Street Map';
  $ol_source->description = 'ESRI World Street Map source';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//server.arcgisonline.com/ArcGIS/rest/services/World_Street_Map/MapServer/tile/{z}/{y}/{x}',
    'attributions' => 'Tiles &copy; Esri &mdash; Source: Esri, DeLorme, NAVTEQ, USGS, Intermap, iPC, NRCAN, Esri Japan, METI, Esri China (Hong Kong), Esri (Thailand), TomTom, 2012'
  );
  $export['openlayers_examples_source_esri_worldstreetmap'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_esri_delorme';
  $ol_source->name = 'Openlayers examples: ESRI Delorme';
  $ol_source->description = 'ESRI Delorme source';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//server.arcgisonline.com/ArcGIS/rest/services/Specialty/DeLorme_World_Base_Map/MapServer/tile/{z}/{y}/{x}',
    'attributions' => 'Tiles &copy; Esri &mdash; Source: Esri, DeLorme, NAVTEQ, USGS, Intermap, iPC, NRCAN, Esri Japan, METI, Esri China (Hong Kong), Esri (Thailand), TomTom, 2012'
  );
  $export['openlayers_examples_source_esri_delorme'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_esri_worldimagery';
  $ol_source->name = 'Openlayers examples: ESRI World Imagery';
  $ol_source->description = 'ESRI World Imagery source';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//server.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/{z}/{y}/{x}',
    'attributions' => 'Tiles &copy; Esri &mdash; Source: Esri, DeLorme, NAVTEQ, USGS, Intermap, iPC, NRCAN, Esri Japan, METI, Esri China (Hong Kong), Esri (Thailand), TomTom, 2012'
  );
  $export['openlayers_examples_source_esri_worldimagery'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_esri_worldterrainbase';
  $ol_source->name = 'Openlayers examples: ESRI Terrain Base';
  $ol_source->description = 'ESRI Terrain Base source';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//server.arcgisonline.com/ArcGIS/rest/services/World_Terrain_Base/MapServer/tile/{z}/{y}/{x}',
    'attributions' => 'Tiles &copy; Esri &mdash; Source: USGS, Esri, TANA, DeLorme, and NPS'
  );
  $export['openlayers_examples_source_esri_worldterrainbase'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_esri_worldshadedrelief';
  $ol_source->name = 'Openlayers examples: ESRI Shaded Relief Base';
  $ol_source->description = 'ESRI Shaded Relief source';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//server.arcgisonline.com/ArcGIS/rest/services/World_Shaded_Relief/MapServer/tile/{z}/{y}/{x}',
    'attributions' => 'Tiles &copy; Esri &mdash; Source: Esri'
  );
  $export['openlayers_examples_source_esri_worldshadedrelief'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_esri_oceanbasemap';
  $ol_source->name = 'Openlayers examples: ESRI Ocean Basemap';
  $ol_source->description = 'ESRI Ocean Basemap source';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//server.arcgisonline.com/ArcGIS/rest/services/Ocean_Basemap/MapServer/tile/{z}/{y}/{x}',
    'attributions' => 'Tiles &copy; Esri &mdash; Sources: GEBCO, NOAA, CHS, OSU, UNH, CSUMB, National Geographic, DeLorme, NAVTEQ, and Esri'
  );
  $export['openlayers_examples_source_esri_oceanbasemap'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_esri_natgeoworldmap';
  $ol_source->name = 'Openlayers examples: ESRI National Geographic World Map';
  $ol_source->description = 'ESRI National Geographic World Map source';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//server.arcgisonline.com/ArcGIS/rest/services/NatGeo_World_Map/MapServer/tile/{z}/{y}/{x}',
    'attributions' => 'Tiles &copy; Esri &mdash; National Geographic, Esri, DeLorme, NAVTEQ, UNEP-WCMC, USGS, NASA, ESA, METI, NRCAN, GEBCO, NOAA, iPC'
  );
  $export['openlayers_examples_source_esri_natgeoworldmap'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_symbols_webgl';
  $ol_source->name = 'Openlayers examples: Symbols Webgl';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:InlineJS';
  $ol_source->options = array(
    'javascript' => 'var atlasManager = new ol.style.AtlasManager({
  // we increase the initial size so that all symbols fit into
  // a single atlas image
  initialSize: 512
});

var symbolInfo = [{
  opacity: 1.0,
  scale: 1.0,
  fillColor: \'rgba(255, 153, 0, 0.4)\',
  strokeColor: \'rgba(255, 204, 0, 0.2)\'
}, {
  opacity: 0.75,
  scale: 1.25,
  fillColor: \'rgba(70, 80, 224, 0.4)\',
  strokeColor: \'rgba(12, 21, 138, 0.2)\'
}, {
  opacity: 0.5,
  scale: 1.5,
  fillColor: \'rgba(66, 150, 79, 0.4)\',
  strokeColor: \'rgba(20, 99, 32, 0.2)\'
}, {
  opacity: 1.0,
  scale: 1.0,
  fillColor: \'rgba(176, 61, 35, 0.4)\',
  strokeColor: \'rgba(145, 43, 20, 0.2)\'
}];

var radiuses = [3, 6, 9, 15, 19, 25];
var symbolCount = symbolInfo.length * radiuses.length * 2;
var symbols = [];
var i, j;
for (i = 0; i < symbolInfo.length; ++i) {
  var info = symbolInfo[i];
  for (j = 0; j < radiuses.length; ++j) {
    // circle symbol
    symbols.push(new ol.style.Circle({
      opacity: info.opacity,
      scale: info.scale,
      radius: radiuses[j],
      fill: new ol.style.Fill({
        color: info.fillColor
      }),
      stroke: new ol.style.Stroke({
        color: info.strokeColor,
        width: 1
      }),
      // by passing the atlas manager to the symbol,
      // the symbol will be added to an atlas
      atlasManager: atlasManager
    }));

    // star symbol
    symbols.push(new ol.style.RegularShape({
      points: 8,
      opacity: info.opacity,
      scale: info.scale,
      radius: radiuses[j],
      radius2: radiuses[j] * 0.7,
      angle: 1.4,
      fill: new ol.style.Fill({
        color: info.fillColor
      }),
      stroke: new ol.style.Stroke({
        color: info.strokeColor,
        width: 1
      }),
      atlasManager: atlasManager
    }));
  }
}

var featureCount = 50000;
var features = new Array(featureCount);
var feature, geometry;
var e = 25000000;
for (i = 0; i < featureCount; ++i) {
  geometry = new ol.geom.Point(
      [2 * e * Math.random() - e, 2 * e * Math.random() - e]);
  feature = new ol.Feature(geometry);
  feature.setStyle(
      new ol.style.Style({
        image: symbols[i % symbolCount]
      })
  );
  features[i] = feature;
}

var source = new ol.source.Vector({
  features: features
});',
  );
  $export['openlayers_examples_source_symbols_webgl'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openweather_precipitation';
  $ol_source->name = 'Openlayers examples: OWM Precipitation';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//tile.openweathermap.org/map/precipitation/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openweather_precipitation'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openweather_precipitation_cls';
  $ol_source->name = 'Openlayers examples: OWM Precipitation classic';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//tile.openweathermap.org/map/precipitation_cls/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openweather_precipitation_cls'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openweather_clouds';
  $ol_source->name = 'Openlayers examples: OWM Clouds';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//www.tile.openweathermap.org/map/clouds/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openweather_clouds'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openweather_clouds_cls';
  $ol_source->name = 'Openlayers examples: OWM Clouds classic';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//tile.openweathermap.org/map/clouds_cls/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openweather_clouds_cls'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openweather_pressure';
  $ol_source->name = 'Openlayers examples: OWM Pressure';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//tile.openweathermap.org/map/pressure/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openweather_pressure'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openweather_pressure_cntr';
  $ol_source->name = 'Openlayers examples: OWM Pressure contour';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//tile.openweathermap.org/map/pressure_cntr/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openweather_pressure_cntr'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openweather_temp';
  $ol_source->name = 'Openlayers examples: OWM Temp';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//www.tile.openweathermap.org/map/temp/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openweather_temp'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openweather_rain';
  $ol_source->name = 'Openlayers examples: OWM Rain';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//tile.openweathermap.org/map/rain/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openweather_rain'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openweather_rain_cls';
  $ol_source->name = 'Openlayers examples: OWM Rain classic';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//tile.openweathermap.org/map/rain_cls/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openweather_rain_cls'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openweather_snow';
  $ol_source->name = 'Openlayers examples: OWM Snow';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//www.tile.openweathermap.org/map/snow/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openweather_snow'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_openweather_wind';
  $ol_source->name = 'Openlayers examples: OWM Wind';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//www.tile.openweathermap.org/map/wind/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_openweather_wind'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_tilewms';
  $ol_source->name = 'Openlayers examples: TileWMS';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:TileWMS';
  $ol_source->options = array(
    'url' => 'http://services.nationalmap.gov/arcgis/services/transportation/MapServer/WMSServer',
    'wms_layers' => '1,2,3,4,5,6,7,8,9',
    'version' => '',
    'params' => array(
      'LAYERS' => '1,2,3,4,5,6,7,8,9',
    ),
  );
  $export['openlayers_examples_source_tilewms'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_random_features';
  $ol_source->name = 'Openlayers examples: Random features';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:Random';
  $ol_source->options = array(
    'Point' => array(
      'count' => 50,
    ),
    'LineString' => array(
      'count' => 20,
    ),
    'Polygon' => array(
      'count' => 2,
    ),
  );
  $export['openlayers_examples_source_random_features'] = $ol_source;

  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'openlayers_examples_source_opentopomap';
  $ol_source->name = 'Openlayers examples: Opentopomap';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => '//opentopomap.org/tiles/{z}/{x}/{y}.png',
  );
  $export['openlayers_examples_source_opentopomap'] = $ol_source;

  return $export;
}
