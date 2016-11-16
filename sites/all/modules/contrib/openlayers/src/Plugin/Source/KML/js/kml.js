Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:KML',
  init: function(data) {
    data.opt.format = new ol.format.KML({
      extractStyles: false
    });
    return new ol.source.Vector(data.opt);
  }
});
