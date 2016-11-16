Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:PinchRotate',
  init: function(data) {
    return new ol.interaction.PinchRotate(data.opt);
  }
});
