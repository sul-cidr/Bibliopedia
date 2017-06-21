Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:DragBox',
  init: function(data) {
    return new ol.interaction.DragBox(data.opt);
  }
});
