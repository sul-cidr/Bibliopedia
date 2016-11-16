Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer:Image',
  init: function(data) {
    return new ol.layer.Image(data.opt);
  }
});
