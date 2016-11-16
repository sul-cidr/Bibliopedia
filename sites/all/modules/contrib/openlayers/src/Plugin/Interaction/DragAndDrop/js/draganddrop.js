Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:DragAndDrop',
  init: function(data) {
    return new ol.interaction.DragAndDrop(data.opt);
  }
});
