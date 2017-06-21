Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:Modify',
  init: function(data) {
    return new ol.interaction.Modify(data.opt);
  }
});
