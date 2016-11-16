Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:OSM',
  init: function(data) {
    if (data.opt.crossOrigin !== undefined) {
      if (data.opt.crossOrigin === 'null') {
        data.opt.crossOrigin = null;
      }
    }
    return new ol.source.OSM(data.opt);
  }
});
