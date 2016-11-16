Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:ScaleLine',
  init: function(data) {
    return new ol.control.ScaleLine(data.opt);
  }
});
