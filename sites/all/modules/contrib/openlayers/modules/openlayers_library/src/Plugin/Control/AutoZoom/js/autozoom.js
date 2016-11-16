Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:AutoZoom',
  init: function(data) {
    return new ol.control.AutoZoom(data.opt);
  }
});
