(function ($, Drupal) {

  "use strict";

  $(document).on('openlayers.build_start', function (event, objects) {
    Drupal.openlayers.console.time('Total building time');
    Drupal.openlayers.console.groupCollapsed("********************* Starting build of " + objects.settings.map.mn + " *********************");
  });
  $(document).on('openlayers.map_pre_alter', function (event, objects) {
    Drupal.openlayers.console.groupCollapsed("Building map");
    Drupal.openlayers.console.time('Building map');
  });
  $(document).on('openlayers.map_post_alter', function (event, objects) {
    Drupal.openlayers.console.timeEnd('Building map');
    Drupal.openlayers.console.groupEnd();
  });
  $(document).on('openlayers.sources_pre_alter', function (event, objects) {
    Drupal.openlayers.console.groupCollapsed("Building sources");
    Drupal.openlayers.console.time('Building sources');
  });
  $(document).on('openlayers.sources_post_alter', function (event, objects) {
    Drupal.openlayers.console.timeEnd('Building sources');
    Drupal.openlayers.console.groupEnd();
  });
  $(document).on('openlayers.controls_pre_alter', function (event, objects) {
    Drupal.openlayers.console.groupCollapsed("Building controls");
    Drupal.openlayers.console.time('Building controls');
  });
  $(document).on('openlayers.controls_post_alter', function (event, objects) {
    Drupal.openlayers.console.timeEnd('Building controls');
    Drupal.openlayers.console.groupEnd();
  });
  $(document).on('openlayers.interactions_pre_alter', function (event, objects) {
    Drupal.openlayers.console.groupCollapsed("Building interactions");
    Drupal.openlayers.console.time('Building interactions');
  });
  $(document).on('openlayers.interactions_post_alter', function (event, objects) {
    Drupal.openlayers.console.timeEnd('Building interactions');
    Drupal.openlayers.console.groupEnd();
  });
  $(document).on('openlayers.styles_pre_alter', function (event, objects) {
    Drupal.openlayers.console.groupCollapsed("Building styles");
    Drupal.openlayers.console.time('Building styles');
  });
  $(document).on('openlayers.styles_post_alter', function (event, objects) {
    Drupal.openlayers.console.timeEnd('Building styles');
    Drupal.openlayers.console.groupEnd();
  });
  $(document).on('openlayers.layers_pre_alter', function (event, objects) {
    Drupal.openlayers.console.groupCollapsed("Building layers");
    Drupal.openlayers.console.time('Building layers');
  });
  $(document).on('openlayers.layers_post_alter', function (event, objects) {
    Drupal.openlayers.console.timeEnd('Building layers');
    Drupal.openlayers.console.groupEnd();
  });
  $(document).on('openlayers.components_pre_alter', function (event, objects) {
    Drupal.openlayers.console.groupCollapsed("Building components");
    Drupal.openlayers.console.time('Building components');
  });
  $(document).on('openlayers.components_post_alter', function (event, objects) {
    Drupal.openlayers.console.timeEnd('Building components');
    Drupal.openlayers.console.groupEnd();
  });
  $(document).on('openlayers.object_pre_alter', function (event, objects) {
    Drupal.openlayers.console.groupCollapsed(objects.data.mn);
    Drupal.openlayers.console.info('Object data');
    Drupal.openlayers.console.debug(objects.data);
    Drupal.openlayers.console.time('Time');
  });
  $(document).on('openlayers.object_post_alter', function (event, objects) {
    var objType = typeof objects.object;
    if (((objType !== 'object' && objType !== 'function') || objects.object == null) && objects.type !== 'components') {
      Drupal.openlayers.console.error('Failed to create object.');
      Drupal.openlayers.console.error(objects);
    }
    Drupal.openlayers.console.timeEnd('Time');
    Drupal.openlayers.console.groupEnd();
  });
  $(document).on('openlayers.build_stop', function (event, objects) {
    Drupal.openlayers.console.timeEnd('Total building time');
    Drupal.openlayers.console.groupEnd();
    Drupal.openlayers.console.groupEnd();
  });
  $(document).on('openlayers.object_error', function (event, objects) {
    Drupal.openlayers.console.info('Object ' + objects.data.mn + ' of type ' + objects.type + ' does not provide JS plugin.');
    Drupal.openlayers.console.info('Object data');
    Drupal.openlayers.console.debug(objects.data);
  });
  $(document).on('openlayers.build_failed', function (event, objects) {
    Drupal.openlayers.console.timeEnd('Total building time');
    Drupal.openlayers.console.groupEnd();
    Drupal.openlayers.console.error(objects.error.message);
    Drupal.openlayers.console.error(objects.error.stack);
    $('#' + objects.settings.map.map_id).html('<pre><b>Error during map rendering:</b> ' + objects.error.message + '</pre>');
    $('#' + objects.settings.map.map_id).append('<pre>' + objects.error.stack + '</pre>');
  });
}(jQuery, Drupal));
