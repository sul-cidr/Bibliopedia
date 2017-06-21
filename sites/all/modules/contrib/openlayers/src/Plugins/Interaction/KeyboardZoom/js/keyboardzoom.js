Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:KeyboardZoom',
  init: function(data) {
    return new ol.interaction.KeyboardZoom(data.opt);
  }
});
