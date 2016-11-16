<?php
/**
 * @file
 * Default components.
 */

/**
 * Implements hook_default_openlayers_components().
 */
function openlayers_examples_default_openlayers_components() {
  $export = array();

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_ajax_values';
  $ol_component->name = 'Openlayers examples: openlayers_examples_component_ajax_values';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:SetValues';
  $ol_component->options = array(
    'latitude' => 'lat',
    'longitude' => 'lon',
    'rotation' => 'rot',
    'zoom' => 'zoom',
    'extent' => 'extent',
  );
  $export['openlayers_examples_component_ajax_values'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_geolocation';
  $ol_component->name = 'Openlayers examples: Geolocation';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Geolocation';
  $ol_component->options = array(
    'checkboxID' => 'trackPosition',
    'positionAccuracyID' => 'positionAccuracy',
    'altitudeID' => 'altitude',
    'altitudeAccuracyID' => 'altitudeAccuracy',
    'headingID' => 'heading',
    'speedID' => 'speed',
  );
  $export['openlayers_examples_component_geolocation'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_graticule';
  $ol_component->name = 'Openlayers examples: Graticule';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Graticule';
  $ol_component->options = array(
    'rgba' => '255,120,0,0.9',
    'width' => '2',
    'lineDash' => '0.5, 4',
  );
  $export['openlayers_examples_component_graticule'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_zoom_to_source';
  $ol_component->name = 'Openlayers examples: Zoom To Source';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:ZoomToSource';
  $ol_component->options = array(
    'source' => 'views_geojson_openlayers_examples_geojson_feed_2',
    'animations' => array(
      'pan' => '500',
      'zoom' => '500',
    ),
    'zoom' => 'disabled',
    'enableAnimations' => 1,
  );
  $export['openlayers_examples_component_zoom_to_source'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_autopopup';
  $ol_component->name = 'Openlayers examples: Autopopup';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Autopopup';
  $ol_component->options = array(
    'source' => 'views_geojson_openlayers_examples_geojson_feed_2',
    'zoom' => 'auto',
    'enableAnimations' => 1,
    'animations' => array(
      'pan' => '500',
      'zoom' => '500',
    ),
    'positioning' => 'top-right',
  );
  $export['openlayers_examples_component_autopopup'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_tooltip_earthquakes';
  $ol_component->name = 'Openlayers examples: Earthquakes tooltip';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Tooltip';
  $ol_component->options = array(
    'layer' => 'openlayers_examples_layer_vector_kml_earthquakes_heatmap',
    'positioning' => 'top-right',
  );
  $export['openlayers_examples_component_tooltip_earthquakes'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_simple_popup';
  $ol_component->name = 'Openlayers examples: Simple popup';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Popup';
  $ol_component->options = array(
    'layers' => array(
      'openlayers_examples_layer_views_geojson_popup' => 'openlayers_examples_layer_views_geojson_popup',
    ),
    'positioning' => 'top-right',
    'autoPan' => TRUE,
    'autoPanAnimation' => 1000,
    'autoPanMargin' => 20
  );
  $export['openlayers_examples_component_simple_popup'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_simple_popup_cities';
  $ol_component->name = 'Openlayers examples: Simple popup for layer cities';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Popup';
  $ol_component->options = array(
    'layers' => array(
      'openlayers_examples_layer_cluster_cities' => 'openlayers_examples_layer_cluster_cities',
    ),
    'positioning' => 'top-right',
    'autoPan' => TRUE,
    'autoPanAnimation' => 1000,
    'autoPanMargin' => 20,
    'closer' => TRUE,
  );
  $export['openlayers_examples_component_simple_popup_cities'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_earthquake_style';
  $ol_component->name = 'Openlayers examples: Earthquake style';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:InlineJS';
  $ol_component->options = array(
    'javascript' => 'var map = data.map;

var styleCache = {};
var styleFunction = function(feature, resolution) {
  // 2012_Earthquakes_Mag5.kml stores the magnitude of each earthquake in a
  // standards-violating <magnitude> tag in each Placemark.  We extract it from
  // the Placemark\'s name instead.
  var name = feature.get(\'name\');
  var magnitude = parseFloat(name.substr(2));
  var radius = 5 + 20 * (magnitude - 5);
  var style = styleCache[radius];
  if (!style) {
    style = [new ol.style.Style({
      image: new ol.style.Circle({
        radius: radius,
        fill: new ol.style.Fill({
          color: \'rgba(255, 153, 0, 0.4)\'
        }),
        stroke: new ol.style.Stroke({
          color: \'rgba(255, 204, 0, 0.2)\',
          width: 1
        })
      })
    })];
    styleCache[radius] = style;
  }
  return style;
};

map.getLayers().forEach(function(layer){
   var source = layer.getSource();
   if (source.mn == \'openlayers_examples_source_kml_earthquakes\') {
       layer.setStyle(styleFunction);
   }
});',
  );
  $export['openlayers_examples_component_earthquake_style'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_simple_popup_earthquakes';
  $ol_component->name = 'Openlayers examples: Earthquakes popup';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Popup';
  $ol_component->options = array(
    'layers' => array(
      'openlayers_examples_layer_vector_kml_earthquakes_heatmap' => 'openlayers_examples_layer_vector_kml_earthquakes_heatmap',
    ),
    'positioning' => 'top-right',
    'autoPan' => TRUE,
    'autoPanAnimation' => 1000,
    'autoPanMargin' => 20
  );
  $export['openlayers_examples_component_simple_popup_earthquakes'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_blocklayerswitcher';
  $ol_component->name = 'Openlayers examples: Block Layer Switcher';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:BlockLayerSwitcher';
  $export['openlayers_examples_component_blocklayerswitcher'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_bootstrapjs_popup';
  $ol_component->name = 'Bootstrap JS popup';
  $ol_component->description = 'Bootstrap JS popup component is a component who allows you to display popup when clicking on a feature. It requires the bootstrapjs module to work.';
  $ol_component->factory_service = 'openlayers.Component:BootstrapjsPopup';
  $ol_component->options = array();
  $export['openlayers_examples_component_bootstrapjs_popup'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_bootstrapjs_alert';
  $ol_component->name = 'Openlayers examples: Bootstrap JS alert';
  $ol_component->description = 'Display an alert on the top of the map.';
  $ol_component->factory_service = 'openlayers.Component:BootstrapjsAlert';
  $ol_component->options = array(
    'message' => '<strong>Success !</strong>The map has been loaded.',
  );
  $export['openlayers_examples_component_bootstrapjs_alert'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_tileutfgrid';
  $ol_component->name = 'Openlayers examples: TileUTFGrid';
  $ol_component->description = 'Example based on http://openlayers.org/en/v3.1.0/examples/tileutfgrid.html.';
  $ol_component->factory_service = 'openlayers.Component:InlineJS';
  $ol_component->options = array(
    'javascript' => 'var map = data.map;

var gridSource = data.objects.sources[\'openlayers_examples_source_mapbox_geography_class_utfgrid\'];

var element1 = jQuery(\'<div/>\', {
  id: \'country-info\',
    }).appendTo(\'body\');
var element2 = jQuery(\'<div/>\', {
  id: \'country-name\',
}).appendTo(\'#country-info\');
var element3 = jQuery(\'<img/>\', {
  id: \'country-flag\'
}).appendTo(\'#country-info\');

var infoElement = document.getElementById(\'country-info\');
var flagElement = document.getElementById(\'country-flag\');
var nameElement = document.getElementById(\'country-name\');

var infoOverlay = new ol.Overlay({
  element: infoElement,
  offset: [15, 15],
  stopEvent: false
});
map.addOverlay(infoOverlay);

var displayCountryInfo = function(coordinate) {
  var viewResolution = /** @type {number} */ (map.getView().getResolution());
  gridSource.forDataAtCoordinateAndResolution(coordinate, viewResolution,
      function(data) {
        // If you want to use the template from the TileJSON,
        //  load the mustache.js library separately and call
        //  info.innerHTML = Mustache.render(gridSource.getTemplate(), data);
        if (data) {
          /* jshint -W069 */
          flagElement.src = \'data:image/png;base64,\' + data[\'flag_png\'];
          nameElement.innerHTML = data[\'admin\'];
          /* jshint +W069 */
        }
        infoOverlay.setPosition(data ? coordinate : undefined);
      });
};

jQuery(map.getViewport()).on(\'mousemove\', function(evt) {
  var coordinate = map.getEventCoordinate(evt.originalEvent);
  displayCountryInfo(coordinate);
});

map.on(\'click\', function(evt) {
  displayCountryInfo(evt.coordinate);
});',
  );
  $export['openlayers_examples_component_tileutfgrid'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_swipe';
  $ol_component->name = 'Openlayers examples: Swipe';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Swipe';
  $export['openlayers_examples_component_swipe'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_timezones';
  $ol_component->name = 'Openlayers examples: Timezones';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Timezones';
  $export['openlayers_examples_component_timezones'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_fractal';
  $ol_component->name = 'Openlayers examples: Fractal';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Fractal';
  $export['openlayers_examples_component_fractal'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_logistic';
  $ol_component->name = 'Openlayers examples: Logistic';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Logistic';
  $export['openlayers_examples_component_logistic'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_julia';
  $ol_component->name = 'Openlayers examples: Julia/Mandelbrot';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Julia';
  $export['openlayers_examples_component_julia'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_icon_sprite';
  $ol_component->name = 'Openlayers examples: Icon sprites WebGL';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:IconSprites';
  $export['openlayers_examples_component_icon_sprite'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_debug';
  $ol_component->name = 'Openlayers examples: Debug';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Debug';
  $export['openlayers_examples_component_debug'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_viewsync';
  $ol_component->name = 'Openlayers examples: ViewSync';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:ViewSync';
  $ol_component->options = array(
    'group' => 'openlayers_examples',
  );
  $export['openlayers_examples_component_viewsync'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_spinjs';
  $ol_component->name = 'Openlayers examples: SpinJS';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:SpinJS';
  $ol_component->options = array(
    'lines' => 12,
    'length' => 15,
    'width' => 8,
    'radius' => 30,
    'scale' => 1,
    'corners' => 1,
    'color' => '#000',
    'opacity' => 0.25,
    'rotate' => 0,
    'direction' => 1,
    'speed' => 2,
    'trail' => 100,
    'fps' => 20,
    'zIndex' => 0,
    'className' => 'spinner',
    'top' => '50%',
    'left' => '50%',
    'shadow' => FALSE,
    'hwaccel' => FALSE,
    'position' => 'relative',
  );
  $export['openlayers_examples_component_spinjs'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_progressbar';
  $ol_component->name = 'Openlayers examples: Progress bar';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:ProgressBar';
  $export['openlayers_examples_component_progressbar'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_permalink';
  $ol_component->name = 'Openlayers examples: Permalink';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:Permalink';
  $export['openlayers_examples_component_permalink'] = $ol_component;

  $ol_component = new stdClass();
  $ol_component->disabled = FALSE; /* Edit this to true to make a default ol_component disabled initially */
  $ol_component->api_version = 1;
  $ol_component->machine_name = 'openlayers_examples_component_layerclipping';
  $ol_component->name = 'Openlayers examples: Layer clipping';
  $ol_component->description = '';
  $ol_component->factory_service = 'openlayers.Component:InlineJS';
  $ol_component->options = array(
    'javascript' => 'var draw = function(ctx) {
    ctx.save();
    ctx.translate((ctx.canvas.width / 2) - 100, (ctx.canvas.height / 2) + 50);
    ctx.scale(1, 1);

    ctx.lineCap = \'butt\';
    ctx.lineJoin = \'miter\';
    ctx.miterLimit = 4;

    ctx.beginPath();
    ctx.moveTo(115.298, -6.622);
    ctx.bezierCurveTo(86.173, -6.622, 62.567, 16.984, 62.567, 46.102);
    ctx.bezierCurveTo(62.567, 75.202, 86.167, 98.80199999999999, 115.267, 98.80199999999999);
    ctx.bezierCurveTo(144.378, 98.80199999999999, 167.98399999999998, 75.192, 167.98399999999998, 46.07399999999999);
    ctx.bezierCurveTo(168.016, 17, 144.409, -6.622, 115.298, -6.622);

    ctx.moveTo(180.858, -16.681);
    ctx.bezierCurveTo(196.48000000000002, -0.3810000000000002, 206.058, 21.718999999999998, 206.058, 46.101);
    ctx.bezierCurveTo(206.058, 76.958, 190.648, 104.205, 167.123, 120.601);
    ctx.bezierCurveTo(210.605, 107.185, 246.58299999999997, 74.50200000000001, 262.68899999999996, 34.913);
    ctx.bezierCurveTo(284.95899999999995, -19.847, 264.224, -61.068, 229.41099999999997, -98.437);
    ctx.bezierCurveTo(230.47099999999998, -93.637, 231.11099999999996, -88.53699999999999, 231.11099999999996, -83.437);
    ctx.bezierCurveTo(231.105, -51.728, 209.855, -25.012, 180.858, -16.681);

    ctx.moveTo(121.316, -83.42);
    ctx.bezierCurveTo(121.316, -61.120000000000005, 139.416, -43.120000000000005, 161.61599999999999, -43.089);
    ctx.bezierCurveTo(183.81599999999997, -43.05799999999999, 201.98, -61.146, 201.98, -83.42);
    ctx.bezierCurveTo(201.98, -105.69, 183.92499999999998, -123.745, 161.653, -123.745);
    ctx.bezierCurveTo(139.381, -123.745, 121.316, -105.69, 121.316, -83.42);

    ctx.moveTo(45.84, 104.572);
    ctx.bezierCurveTo(32.52, 88.771, 24.494000000000003, 68.382, 24.494000000000003, 46.101000000000006);
    ctx.bezierCurveTo(24.494000000000003, -0.377999999999993, 59.42700000000001, -38.67199999999999, 104.462, -44.028);
    ctx.bezierCurveTo(96.734, -55.226, 92.196, -68.793, 92.196, -83.42);
    ctx.bezierCurveTo(92.196, -121.77199999999999, 123.287, -152.868, 161.654, -152.868);
    ctx.bezierCurveTo(164.821, -152.868, 167.954, -152.668, 170.954, -152.268);
    ctx.bezierCurveTo(148.233, -171.877, 125.56200000000001, -191.764, 107.667, -213.508);
    ctx.bezierCurveTo(116.807, -118.29100000000001, 20.947000000000003, -152.889, -14.489000000000004, -65.14700000000002);
    ctx.bezierCurveTo(-38.243, -6.232, -16.81, 66.5, 45.8, 104.572);
    ctx.restore();
    ctx.clip();
};

var osm = data.objects.layers[Object.keys(data.objects.layers)[0]];

osm.on(\'precompose\', function(event) {
  var ctx = event.context;
  draw(ctx);
});

osm.on(\'postcompose\', function(event) {
  var ctx = event.context;
  ctx.restore();
});',
  );
  $export['openlayers_examples_component_layerclipping'] = $ol_component;

  return $export;
}
