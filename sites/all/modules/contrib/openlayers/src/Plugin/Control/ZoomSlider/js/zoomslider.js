Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:ZoomSlider',
  init: function(data) {
    return new ol.control.ZoomSlider(data.opt);
  }
});
