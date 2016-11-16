Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer:Vector',
  init: function(data) {

    var layer = new ol.layer.Vector(data.opt);
    // Check if this layer is activated for dedicated zoom levels.
    if (data.opt.zoomActivity) {
      var zoomSpecificVisibility = function() {
        layer.setVisible(data.opt.zoomActivity[data.map.getView().getZoom()] !== undefined);
      };
      data.map.getView().on('change:resolution', zoomSpecificVisibility);
    }

    return layer;
  }
});
