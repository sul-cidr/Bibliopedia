Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:XYZ',
  init: function(data) {
    if (data.opt.crossOrigin !== undefined) {
      if (data.opt.crossOrigin === 'null') {
        data.opt.crossOrigin = null;
      }
    }
    return new ol.source.XYZ(data.opt);
  }
});
