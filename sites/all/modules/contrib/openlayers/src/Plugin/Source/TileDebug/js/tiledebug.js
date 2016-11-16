Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:TileDebug',
  init: function(data) {
    var options = {
      tileGrid: new ol.tilegrid.createXYZ({maxZoom: data.opt.maxZoom}),
      // todo: handle projection stuff
      projection: 'EPSG:3857'
    };
    return new ol.source.TileDebug(options);
  }
});
