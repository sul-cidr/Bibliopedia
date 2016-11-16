Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:Graticule',
  init: function(data) {
    var graticule = new ol.Graticule({
      strokeStyle: new ol.style.Stroke({
        color: 'rgba(' + data.opt.rgba + ')',
        width: data.opt.width,
        lineDash: data.opt.lineDash.split(',').map(Number)
      }),
      map: data.map,
      projection: data.map.getView().getProjection()
    });
  }
});
