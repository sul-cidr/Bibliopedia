Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:Zoom',
  init: function(data) {
    return new ol.control.Zoom(data.opt);
  }
});
