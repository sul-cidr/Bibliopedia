Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:LayerSwitcher',
  init: function(data) {
    var element = jQuery(data.opt.element);

    jQuery('input[name=layer]', element).change(function() {
      data.map.getLayers().forEach(function(layer, index, array) {
        // If this layer is exposed in the control check its state.
        if (jQuery('input[value=' + layer.mn + ']', element).length) {
          layer.setVisible(jQuery('input[value=' + layer.mn + ']', element).is(':checked'));
        }
      });
    });

    // Register visibility change events. The layerswitcher check's if it's ok
    // to be visible first. This e.g. ensures that the zoomActivity feature of
    // layers respects the layerswitcher state.
    jQuery(document).on('openlayers.layers_post_alter', function(event, layer_data) {
      if (data.map_id == layer_data.map_id) {
        var map = Drupal.openlayers.getMapById(layer_data.map_id);
        for (var i in layer_data.layers) {
          // If this layer is exposed in the control check its state.
          if (jQuery('input[value=' + layer_data.layers[i].mn + ']', element).length) {
            map.layers[layer_data.layers[i].mn].on('change:visible', function (e) {
              var visibility = e.target.get(e.key);
              // Keep invisible if layer isn't activated in layerswitcher.
              if (visibility && !jQuery('input[value=' + e.target.mn + ']', element).is(':checked')) {
                e.target.setVisible(false);
                e.stopPropagation();
              }
            });
          }
        }
      }
    });


    return new ol.control.Control({
      element: element[0]
    });
  }
});
