Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:MouseWheelZoom',
  init: function(data) {
    return new ol.interaction.MouseWheelZoom(data.opt);
  }
});
