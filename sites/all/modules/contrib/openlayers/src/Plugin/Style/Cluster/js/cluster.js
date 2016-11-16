Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Style:Cluster',
  init: function(data) {
    var styleCache = {};
    var clusterStyle = function(feature, resolution) {
      var features = feature.get('features');
      if (features.length !== undefined) {
        var size = features.length;
        var style = styleCache[size];
        if (!style) {
          style = [new ol.style.Style({
            image: new ol.style.Circle({
              radius: 10,
              stroke: new ol.style.Stroke({
                color: '#fff'
              }),
              fill: new ol.style.Fill({
                color: '#3399CC'
              })
            }),
            text: new ol.style.Text({
              text: size.toString(),
              fill: new ol.style.Fill({
                color: '#fff'
              })
            })
          })];
          styleCache[size] = style;
        }
      }
      return style;
    };
    return clusterStyle;
  }
});
