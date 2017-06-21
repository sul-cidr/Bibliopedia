Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer:Tile',
  init: function(data) {
    return new ol.layer.Tile(data.opt);
  }
});
