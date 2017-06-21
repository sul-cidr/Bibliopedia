Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:Popup',
  init: function(data) {
    var map = data.map;

    var container = jQuery('<div/>', {
      id: 'popup',
      'class': 'ol-popup'
    }).appendTo('body');
    var content = jQuery('<div/>', {
      id: 'popup-content'
    }).appendTo('#popup');
    var closer = jQuery('<a/>', {
      href: '#',
      id: 'popup-closer',
      'class': 'ol-popup-closer'
    }).appendTo('#popup');

    var container = document.getElementById('popup');
    var content = document.getElementById('popup-content');
    var closer = document.getElementById('popup-closer');

    /**
     * Add a click handler to hide the popup.
     * @return {boolean} Don't follow the href.
     */
    closer.onclick = function() {
      container.style.display = 'none';
      closer.blur();
      return false;
    };

    /**
     * Create an overlay to anchor the popup to the map.
     */

    var overlay = new ol.Overlay({
      element: container,
      positioning: data.opt.positioning,
      autoPan: data.opt.autoPan,
      autoPanAnimation: {
        duration: data.opt.autoPanAnimation
      },
      autoPanMargin: data.opt.autoPanMargin
    });

    map.addOverlay(overlay);

    map.on('click', function(evt) {
      var feature = map.forEachFeatureAtPixel(evt.pixel, function(feature, layer) {
        if (goog.isDef(data.opt.layers[layer.mn])) {
          return feature;
        }
      });
      if (feature) {
        // If this is a click to the same feature marker it's a close command.
        if (jQuery(container).data('feature-key') == feature[goog.UID_PROPERTY_]) {
          container.style.display = 'none';
          jQuery(container).data('feature-key', '');
          return;
        }
        jQuery(container).data('feature-key', feature[goog.UID_PROPERTY_]);

        var name = feature.get('name') || '';
        var description = feature.get('description') || '';

        overlay.setPosition(evt.coordinate);
        content.innerHTML = '<div class="ol-popup-name">' + name + '</div><div class="ol-popup-description">' + description + '</div>';
        container.style.display = 'block';
      }
    });
  }
});
