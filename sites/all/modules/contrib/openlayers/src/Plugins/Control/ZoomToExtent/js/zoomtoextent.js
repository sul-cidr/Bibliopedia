Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:ZoomToExtent',
  init: function(data) {
    return new ol.control.ZoomToExtent(data.opt);
  }
});
