Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:MapQuest',
  init: function(data) {
    return new ol.source.MapQuest(data.opt);
  }
});
