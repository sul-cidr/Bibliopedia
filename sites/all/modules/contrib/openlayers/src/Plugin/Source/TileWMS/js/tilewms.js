Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:TileWMS',
  init: function(data) {
    return new ol.source.TileWMS(data.opt);
  }
});
