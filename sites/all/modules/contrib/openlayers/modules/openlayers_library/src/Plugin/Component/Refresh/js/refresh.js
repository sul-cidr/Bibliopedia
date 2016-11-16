Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:Refresh',
  init: function(data) {
    var map = data.map;

    var update = function() {
      map.getLayers().forEach(function(layer) {
        var source = layer.getSource();
        if (source instanceof ol.source.Vector) {
          source.clear(true);

          var features = source.getFeatures();
          //source.dispatchEvent('change');
          //source.changed();
          //map.updateSize();
          //source.addFeatures(features);
        }
      });

      //map.changed();

      //console.log('Refreshing...');
    };

    setInterval(update, 10000);
  }
});
