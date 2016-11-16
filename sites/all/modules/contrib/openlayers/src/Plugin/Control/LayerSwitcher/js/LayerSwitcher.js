Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:LayerSwitcher',
  init: function(data) {
    var element = jQuery(data.opt.element);

    jQuery('input[name=layer]', element).change(function() {
      data.map.getLayers().forEach(function(layer, index, array) {
        // If this layer is exposed in the control check its state.
        if (jQuery('input[value=' + layer.mn + ']', element).length) {
          var visible = jQuery('input[value=' + layer.mn + ']', element).is(':checked');
          // If the layer has the zoom activity property get a valid zoom level.
          var zoomActivity = layer.get('zoomActivity');
          if (visible && zoomActivity !== undefined && zoomActivity[data.map.getView().getZoom()] === undefined) {
            var firstActiveZoomLevel = zoomActivity[Object.keys(zoomActivity)[0]];
            data.map.getView().setZoom(firstActiveZoomLevel);
          }
          layer.setVisible(visible);
        }
      });
    });

    // Register visibility change events. The layerswitcher check's if it's ok
    // to be visible first. This e.g. ensures that the zoomActivity feature of
    // layers respects the layerswitcher state.
    data.map.getLayers().forEach(function(layer, index) {
      // If this layer is exposed in the control check its state.
      if (jQuery('input[value=' + layer.mn + ']', element).length) {
        layer.on('change:visible', function (e) {
          var visibility = e.target.get(e.key);
          // Keep invisible if layer isn't activated in layerswitcher.
          if (visibility && !jQuery('input[value=' + e.target.mn + ']', element).is(':checked')) {
            e.target.setVisible(false);
            if (e.stopPropagation !== undefined) {
              e.stopPropagation();
            }
            if (e.preventDefault !== undefined) {
              e.preventDefault();
            }
          }
          else if (jQuery('input[value=' + layer.mn + ']', element).prop('checked') != visibility) {
            jQuery('input[value=' + layer.mn + ']', element)
              .prop('checked', visibility)
              .change();
          }
        });
      }
    });
    
    return new ol.control.Control({
      element: element[0]
    });
  }
});
