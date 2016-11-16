Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:Geofield',
  init: function(data) {
    return new ol.control.Geofield(data.opt);
  }
});


