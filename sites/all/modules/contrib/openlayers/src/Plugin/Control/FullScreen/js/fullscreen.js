Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:FullScreen',
  init: function(data) {
    return new ol.control.FullScreen(data.opt);
  }
});
