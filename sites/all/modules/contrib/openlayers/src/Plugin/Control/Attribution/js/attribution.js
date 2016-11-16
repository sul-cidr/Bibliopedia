Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:Attribution',
  init: function(data) {
    return new ol.control.Attribution(data.opt);
  }
});
