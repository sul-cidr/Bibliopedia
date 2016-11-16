Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:OverviewMap',
  init: function(data) {
    return new ol.control.OverviewMap();
  }
});
