Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:JSGeocoder',
  init: function(data) {
    return new ol.control.JSGeocoder(data.opt);
  }
});
