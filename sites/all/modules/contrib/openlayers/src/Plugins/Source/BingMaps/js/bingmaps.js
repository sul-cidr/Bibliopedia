Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:BingMaps',
  init: function(data) {
    return new ol.source.BingMaps(data.opt);
  }
});
