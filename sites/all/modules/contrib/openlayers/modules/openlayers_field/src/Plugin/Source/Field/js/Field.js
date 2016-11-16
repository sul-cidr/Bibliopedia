Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:Field',
  init: function(data) {
    if (data.opt.geojson_data !== undefined) {
      data.opt.features = new ol.format.GeoJSON().readFeatures(data.opt.geojson_data, {featureProjection: data.map.getView().getProjection()});
      return new ol.source.Vector(data.opt);
    }
  }
});
