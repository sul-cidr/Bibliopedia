Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:ZoomToSource',
  init: function(data) {
    var map = data.map;

    map.getLayers().forEach(function(layer) {
      var source = layer.getSource();
      if (source && source.mn === data.opt.source) {
        var zoomToSource = function() {
          if (!data.opt.process_once || !data.opt.processed_once) {
            data.opt.processed_once = true;
            if (data.opt.enableAnimations == 1) {
              var pan = ol.animation.pan({
                duration: data.opt.animations.pan,
                source: map.getView().getCenter()
              });
              var zoom = ol.animation.zoom({
                duration: data.opt.animations.zoom,
                resolution: map.getView().getResolution()
              });
              map.beforeRender(pan, zoom);
            }
            var dataExtent = source.getExtent();
            map.getView().fitExtent(dataExtent, map.getSize());
            if (data.opt.zoom != 'auto') {
              map.getView().setZoom(data.opt.zoom);
            } else {
              var zoom = map.getView().getZoom() - 1;
              if (goog.isDef(data.opt.max_zoom) && data.opt.max_zoom > 0 && zoom > data.opt.max_zoom) {
                zoom = data.opt.max_zoom;
              }
              map.getView().setZoom(zoom);
            }
          }
        };
        source.on('change', zoomToSource, source);

        // Ensure the initial zoom to source is done if there are already
        // features. If this is a remote source there are no features yet and
        // the initial zoom is needed later. This ensures that this also works
        // properly when process_once is enabled.
        if (source.getFeatures().length) {
          zoomToSource.call(source);
        }
      }
    });
  }
});
