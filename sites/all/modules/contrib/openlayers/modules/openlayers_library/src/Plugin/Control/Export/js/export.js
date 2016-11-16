Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:Export',
  init: function(data) {
    return new ol.control.Export(data.opt);
  }
});
