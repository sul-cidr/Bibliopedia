Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer:Group',
  init: function(data) {
    return new ol.layer.Group({
      title: data.opt.grouptitle,
      layers: data.opt.grouplayers.reverse()
    });
  }
});
