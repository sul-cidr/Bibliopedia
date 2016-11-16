Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:Stamen',
  init: function(data) {
    return new ol.source.Stamen(data.opt);
  }
});
