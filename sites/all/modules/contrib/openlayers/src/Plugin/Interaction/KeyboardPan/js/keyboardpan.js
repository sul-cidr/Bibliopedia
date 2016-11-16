Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:KeyboardPan',
  init: function(data) {
    return new ol.interaction.KeyboardPan(data.opt);
  }
});
