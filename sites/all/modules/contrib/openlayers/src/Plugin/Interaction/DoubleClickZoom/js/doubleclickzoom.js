Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:DoubleClickZoom',
  init: function(data) {
    return new ol.interaction.DoubleClickZoom(data.opt);
  }
});
