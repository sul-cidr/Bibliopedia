Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer:Heatmap',
  init: function(data) {
    return new ol.layer.Heatmap(data.opt);
  }
});
