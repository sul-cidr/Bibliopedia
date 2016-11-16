Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Style:RegularShape',
  init: function(data) {
    return function (feature, resolution) {
      if (!(feature instanceof ol.Feature)) {
        return null;
      }
      var geometry = feature.getGeometry().getType();
      var geometry_style = data.opt[geometry] || data.opt['default'];

      var options = {
        fill: new ol.style.Fill({
          color: 'rgba(' + geometry_style.image.fill.color + ')'
        }),
        stroke: new ol.style.Stroke({
          width: geometry_style.image.stroke.width,
          color: 'rgba(' + geometry_style.image.stroke.color + ')',
          lineDash: geometry_style.image.stroke.lineDash.split(',')
        })
      };

      if (geometry_style.image.radius !== undefined) {
        options.radius = geometry_style.image.radius;
      }
      if (geometry_style.image.points !== undefined) {
        options.points = geometry_style.image.points;
      }
      if (geometry_style.image.radius1 !== undefined) {
        options.radius1 = geometry_style.image.radius1;
      }
      if (geometry_style.image.radius2 !== undefined) {
        options.radius2 = geometry_style.image.radius2;
      }
      if (geometry_style.image.angle !== undefined) {
        options.angle = geometry_style.image.angle * Math.PI / 180;
      }
      if (geometry_style.image.rotation !== undefined) {
        options.rotation = geometry_style.image.rotation * Math.PI / 180;
      }
      return [
        new ol.style.Style({
          image: new ol.style.RegularShape(options),
          fill: new ol.style.Fill({
            color: 'rgba(' + geometry_style.fill.color + ')'
          }),
          stroke: new ol.style.Stroke({
            width: geometry_style.stroke.width,
            color: 'rgba(' + geometry_style.stroke.color + ')',
            lineDash: geometry_style.stroke.lineDash.split(',')
          })
        })
      ];
    };
  }
});
