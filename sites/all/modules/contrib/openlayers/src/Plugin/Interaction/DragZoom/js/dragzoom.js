Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:DragZoom',
  init: function(data) {
    return new ol.interaction.DragZoom(data.opt);
  }
});
