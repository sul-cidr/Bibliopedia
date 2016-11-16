Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:Timezones',
  init: function(data) {
    var map = data.map;

    var info = jQuery('#info');
    info.tooltip({
      animation: false,
      trigger: 'manual'
    });

    var displayFeatureInfo = function(pixel) {
      info.css({
        left: pixel[0] + 'px',
        top: (pixel[1] + 20) + 'px'
      });
      var feature = map.forEachFeatureAtPixel(pixel, function(feature, layer) {
        return feature;
      });
      if (feature) {
        info.tooltip('hide')
          .attr('data-original-title', feature.get('name'))
          .tooltip('fixTitle')
          .tooltip('show');
      } else {
        info.tooltip('hide');
      }
    };

    map.on('pointermove', function(evt) {
      if (evt.dragging) {
        info.tooltip('hide');
        return;
      }
      displayFeatureInfo(map.getEventPixel(evt.originalEvent));
    });

    map.on('click', function(evt) {
      displayFeatureInfo(evt.pixel);
    });
  }
});


