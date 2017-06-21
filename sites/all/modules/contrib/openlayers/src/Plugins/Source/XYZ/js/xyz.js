Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:XYZ',
  init: function(data) {
    return new ol.source.XYZ(data.opt);
  }
});
