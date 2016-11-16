Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:Popup',
  init: function(data) {
    var map = data.map;
    var random = (new Date()).getTime();

    /**
     * Name for unique ID property. Initialized in a way to help avoid collisions
     * with other closure JavaScript on the same page.
     * @type {string}
     * @private
     */
    UID_PROPERTY_ = 'closure_uid_' + ((Math.random() * 1e9) >>> 0);

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
        if (data.opt.frontend_layers[layer.mn] !== undefined) {
          return feature;
        }
      });
      if (feature) {
        jQuery(container).data('feature-key', feature[UID_PROPERTY_]);

        // If the feature is a cluster, then create a list of names and add it
        // to the overall feature's description. Wrap it in a container with
        // a max-height and overflow: scroll so it doesn't get too big.
        var features = feature.get('features');
        if (features !== undefined) {
          var names = [];
          features.forEach(function (item) {
            if (item.get('name') !== undefined) {
              names.push(item.get('name'));
            }
          });
          if (names.length != 0) {
            feature.set('description', '<ul><li>' + names.join('</li><li>') + '</li></ul>');
          }
          feature.set('name', names.length + ' item(s):');
        }

        var name = feature.get('name') || '';
        var description = feature.get('description') || '';

        if (name != '' || description != '') {
          content.innerHTML = '<div class="ol-popup-content"><div class="ol-popup-name">' + name + '</div><div class="ol-popup-description">' + description + '</div></div>';
          container.style.display = 'block';
          overlay.setPosition(evt.coordinate);
        }
      }
    });
  }
});
