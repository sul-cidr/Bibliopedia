Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:Autopopup',
  init: function(data) {
    var map = data.map;
    var random = (new Date()).getTime();

    var container = jQuery('<div/>', {
      id: 'popup-' + random,
      'class': 'ol-popup'
    }).appendTo('body');
    var content = jQuery('<div/>', {
      id: 'popup-content-' + random
    }).appendTo('#popup-' + random);

    var container = document.getElementById('popup-' + random);
    var content = document.getElementById('popup-content-' + random);

    if (data.opt.closer !== undefined && data.opt.closer !== 0) {
      var closer = jQuery('<a/>', {
        href: '#',
        id: 'popup-closer-' + random,
        'class': 'ol-popup-closer'
      }).appendTo('#popup-' + random);

      var closer = document.getElementById('popup-closer-' + random);

      /**
       * Add a click handler to hide the popup.
       * @return {boolean} Don't follow the href.
       */
      closer.onclick = function() {
        container.style.display = 'none';
        closer.blur();
        return false;
      };
    }

    /**
     * Create an overlay to anchor the popup to the map.
     */
    var overlay = new ol.Overlay({
      element: container,
      positioning: data.opt.positioning
    });

    map.addOverlay(overlay);

    map.getLayers().forEach(function(layer) {
      var source = layer.getSource();
      if (source.mn === data.opt.source) {
        source.on('change', function(evt) {
          var feature = source.getFeatures()[0];
          var coordinates = feature.getGeometry().getFirstCoordinate();

          if (feature) {
            var name = feature.get('name') || '';
            var description = feature.get('description') || '';

            content.innerHTML = '<div class="ol-popup-name">' + name + '</div><div class="ol-popup-description">' + description + '</div>';
            container.style.display = 'block';
            overlay.setPosition(coordinates);

            if (data.opt.zoom !== 'disabled') {
              if (data.opt.enableAnimations == 1) {
                var pan = ol.animation.pan({duration: data.opt.animations.pan, source: map.getView().getCenter()});
                var zoom = ol.animation.zoom({duration: data.opt.animations.zoom, resolution: map.getView().getResolution()});
                map.beforeRender(pan, zoom);
              }
              var dataExtent = feature.getGeometry().getExtent();
              map.getView().fit(dataExtent, map.getSize());
              if (data.opt.zoom != 'auto') {
                map.getView().setZoom(data.opt.zoom);
              } else {
                map.getView().setZoom(map.getView().getZoom() - 1);
              }
            }
          }
        }, source);
        source.changed();
      }
    });
  }
});
