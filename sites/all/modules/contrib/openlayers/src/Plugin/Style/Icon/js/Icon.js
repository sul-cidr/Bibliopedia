Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Style:Icon',
  init: function(data) {
    return new ol.style.Style({
      image: new ol.style.Icon(({
        scale: data.opt.scale,
        anchor: data.opt.anchor,
        anchorXUnits: 'fraction',
        anchorYUnits: 'fraction',
        src: data.opt.path
      }))
    });
  }
});
