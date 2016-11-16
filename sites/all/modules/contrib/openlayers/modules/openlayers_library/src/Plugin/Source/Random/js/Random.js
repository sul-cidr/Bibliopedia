Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:Random',
  init: function(data) {
    var features = [];

    var randomProperty = function (obj) {
      var keys = Object.keys(obj);
      return obj[keys[ keys.length * Math.random() << 0]];
    };

    var getRandomCoordinates = function(count) {
      var e = 9000000;
      var coordinates = [];
      for (var c = 0; c < count; c++) {
        coordinates.push([2 * e * Math.random() - e, 2 * e * Math.random() - e]);
      }
      return coordinates;
    };

    for (var geometry_type in data.opt) {
      var count = data.opt[geometry_type].count;

      for (var i = 0; i < count; ++i) {
        switch (geometry_type) {
          case 'Point':
            var coordinates = getRandomCoordinates(1);
            geometry = new ol.geom.Point(coordinates[0]);
            break;
          case 'LineString':
            geometry = new ol.geom.LineString(getRandomCoordinates(2));
            break;
          case 'Polygon':
            coordinates = getRandomCoordinates(4);
            coordinates.push(coordinates[0]);
            geometry = new ol.geom.Polygon([coordinates]);
            break;
        }
        var feature = new ol.Feature(geometry);

        if (data.opt[geometry_type].setRandomStyle === 1) {
          if (data.opt[geometry_type].styles !== undefined) {
            var style = randomProperty(data.opt[geometry_type].styles);
            if (data.objects.styles[style] !== undefined) {
              if (typeof data.objects.styles[style] === 'function') {
                style = data.objects.styles[style](feature);
              } else {
                style = data.objects.styles[style];
              }
              feature.setStyle(style);
            }
          }
        }

        features.push(feature);
      }
    }

    return new ol.source.Vector({
      features: features
    });
  }
});
