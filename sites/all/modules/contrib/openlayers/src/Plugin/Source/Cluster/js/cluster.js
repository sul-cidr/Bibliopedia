Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:Cluster',
  init: function(data) {
    if (data.objects.sources[data.opt.source] !== undefined) {
      var options = jQuery.extend(true, {}, data.opt);
      options.source = data.objects.sources[data.opt.source];

      // Check if zoom based distance handling is configured.
      if (data.opt.zoomDistance !== undefined) {
        var zoomLevelDistanceHandler = function() {
          var distance = options.distance;
          if (data.opt.zoomDistance[data.map.getView().getZoom()] !== undefined) {
            distance = data.opt.zoomDistance[data.map.getView().getZoom()];
          }
          if (clusterSource.get('distance') != distance) {
            clusterSource.set('distance', distance);
            clusterSource.changed();
          }
        };
        // Change intial distance if it overwrites the default.
        if (data.opt.zoomDistance[data.map.getView().getZoom()] !== undefined) {
          options.distance = data.opt.zoomDistance[data.map.getView().getZoom()];
        }
      }

      var clusterSource = new ol.source.Cluster(options);
      // Attach event handler to source if zoom distances are enabled.
      if (zoomLevelDistanceHandler !== undefined) {
        data.map.getView().on('change:resolution', zoomLevelDistanceHandler);
      }
      return clusterSource;
    }
  }
});
