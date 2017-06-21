Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer:Geofield',
  init: function(data) {
    return new ol.layer.Vector(data.opt);
  }
});
