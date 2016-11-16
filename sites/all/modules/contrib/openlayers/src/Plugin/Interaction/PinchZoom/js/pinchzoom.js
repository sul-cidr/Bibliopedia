Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:PinchZoom',
  init: function(data) {
    return new ol.interaction.PinchZoom(data.opt);
  }
});
