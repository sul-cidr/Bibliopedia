Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:GeofieldWidget',
  init: function(data) {
    var map = data.map;

    // make interactions global so they can later be removed
    var select_interaction, draw_interaction,
      modify_interaction,snap_interaction,
      translate_interaction;

    var vector_layer;
    var geofieldControl;
    var geofieldWrapper = jQuery('#openlayers-geofield-' + jQuery(data.map.getViewport()).parent().attr('id'));

    // Select the related source or fallback to a generic one.
    if (data.opt.editLayer !== undefined && data.objects.layers[data.opt.editLayer] !== undefined) {
      vector_layer = data.objects.layers[data.opt.editLayer];
      vector_layer.getSource().on('change', saveData);
    }

    if (data.opt.editStyle !== undefined && data.objects.styles[data.opt.editStyle] !== undefined) {
      var editStyle = data.objects.styles[data.opt.editStyle];
    }

    if (data.opt.editControl !== undefined && data.objects.controls[data.opt.editControl] !== undefined) {
      geofieldControl = data.objects.controls[data.opt.editControl];

      geofieldControl.element.addEventListener('change', function(event) {
        var options = event.detail.options;
        removeMapInteractions();

        if ((((options || {}).actions || {}).Clear || false) === true) {
          clearMap();
        }

        if ((((options || {}).actions || {}).Move || false) === true) {
          addSelectInteraction();
          addTranslateInteraction();
        }

        if ((((options || {}).actions || {}).Edit || false) === true) {
          addSelectInteraction();
          addModifyInteraction();
        }

        if (((options || {}).draw || false) !== false) {
          addDrawInteraction(options.draw);
        }

        if ((((options || {}).options || {}).Snap || false) === true) {
          addSnapInteraction();
        }

        this.options = event.detail.options;
      });
    }

    var data_type = jQuery('.data-type', geofieldWrapper);
    data_type.change(function(e) {
      clearMap();
      removeMapInteractions();
    });

    function removeMapInteractions() {
      map.removeInteraction(select_interaction);
      map.removeInteraction(draw_interaction);
      map.removeInteraction(modify_interaction);
      map.removeInteraction(snap_interaction);
      map.removeInteraction(translate_interaction);
    }

    function clearMap() {
      vector_layer.getSource().clear();
      saveData();
    }

    function addTranslateInteraction() {
      translate_interaction = new ol.interaction.Translate({
        features: select_interaction.getFeatures()
      });
      map.addInteraction(translate_interaction);
    }

    function addSnapInteraction() {
      snap_interaction = new ol.interaction.Snap({
        source: vector_layer.getSource()
      });
      map.addInteraction(snap_interaction);
    }

    function addSelectInteraction() {
      select_interaction = new ol.interaction.Select({
        // make sure only the desired layer can be selected
        layers: function(layer) {
          return layer === vector_layer;
        }
      });
      map.addInteraction(select_interaction);
    }

    // build up modify interaction
    function addModifyInteraction() {
      // grab the features from the select interaction to use in the modify interaction
      var selected_features = select_interaction.getFeatures();
      // when a feature is selected...
      selected_features.on('add', function(event) {
        // grab the feature
        var feature = event.element;
        // ...listen for changes and save them
        feature.on('change', saveData);
        // listen to pressing of delete key, then delete selected features
        jQuery(document).on('keyup', function (event) {
          if (event.keyCode === 46) {
            try {
              // remove from select_interaction
              selected_features.remove(feature);
              // remove from vector_layer
              vector_layer.getSource().removeFeature(feature);
              // save the changed data
            } catch (e) {
              // No matter what happened - ensure the data are written.
            }
            saveData();
            // remove listener
            jQuery(document).off('keyup');
          }
        });
      });

      // create the modify interaction
      modify_interaction = new ol.interaction.Modify({
        style: editStyle,
        features: selected_features,
        // delete vertices by pressing the SHIFT key
        deleteCondition: function(event) {
          return ol.events.condition.shiftKeyOnly(event) &&
            ol.events.condition.singleClick(event);
        }
      });
      // add it to the map
      map.addInteraction(modify_interaction);
    }

    // creates a draw interaction
    function addDrawInteraction(options) {
      var geometryFunction, maxPoints;
      var value = options;

      if (value === 'Square') {
        value = 'Circle';
        maxPoints = 4;
        geometryFunction = ol.interaction.Draw.createRegularPolygon(4);
      } else if (value === 'Box') {
        value = 'LineString';
        maxPoints = 2;
        geometryFunction = function(coordinates, geometry) {
          if (!geometry) {
            geometry = new ol.geom.Polygon(null);
          }
          var start = coordinates[0];
          var end = coordinates[1];
          geometry.setCoordinates([
            [start, [start[0], end[1]], end, [end[0], start[1]], start]
          ]);
          return geometry;
        };
      } else if (value === 'Circle') {
        geometryFunction = ol.interaction.Draw.createRegularPolygon(100);
      } else if (value === 'Triangle') {
        value = 'Circle';
        maxPoints = 3;
        geometryFunction = ol.interaction.Draw.createRegularPolygon(3);
      }

      // create the interaction
      draw_interaction = new ol.interaction.Draw({
        source: vector_layer.getSource(),
        type: /** @type {ol.geom.GeometryType} */ (value),
        geometryFunction: geometryFunction,
        maxPoints: maxPoints,
        style: editStyle
      });

      // add it to the map
      map.addInteraction(draw_interaction);
    }

    // shows data in textarea
    // replace this function by what you need
    function saveData() {
      // get the format the user has chosen
      // define a format the data shall be converted to
      var typeFormat = data_type.val();
      var features = vector_layer.getSource().getFeatures();

      var format = new ol.format[typeFormat]({splitCollection: true}),
//      var format = new ol.format[typeFormat]({splitCollection: true}),
      // this will be the data in the chosen format
        datas;
      try {
        if (data.opt.featureLimit && data.opt.featureLimit != -1 && data.opt.featureLimit < features.length) {
          if (confirm(Drupal.t('You can add a maximum of !limit features. Dou you want to replace the last feature by the new one?', {'!limit': data.opt.featureLimit}))) {
            var lastFeature = features[features.length - 2];
            vector_layer.getSource().removeFeature(lastFeature);
          } else {
            var lastFeature = features[features.length - 1];
            vector_layer.getSource().removeFeature(lastFeature);
          }
        }

        // convert the data of the vector_layer into the chosen format
        datas = format.writeFeatures(vector_layer.getSource().getFeatures(), {
          dataProjection: data.opt.dataProjection,
          featureProjection: data.map.getView().getProjection()
        });

        // Ensure an empty geometry collection doesn't write any data. That way
        // the original geofield validator will work and a required field is
        // properly detected as empty.
        if (datas === 'GEOMETRYCOLLECTION EMPTY') {
          datas = '';
        }

      } catch (e) {
        // at time of creation there is an error in the GPX format (18.7.2014)
        jQuery('.openlayers-geofield-data', geofieldWrapper).val(e.name + ": " + e.message);
        return;
      }
      jQuery('.openlayers-geofield-data', geofieldWrapper).val(datas);
    }
  }
});

/**
 * Ensures the  map is fully rebuilt on ajax request - e.g. geocoder.
 * Ensures that opening a collapsed fieldset will refresh the map.
 */
Drupal.behaviors.openlayersGeofieldWidget = (function($) {
  "use strict";
  return {
    attach: function (context, settings) {
      $('fieldset:has(.openlayers-map)', context).bind('collapsed', function (e) {
        // If not collapsed update the size of the map. But wait a moment so the
        // animation is done already.
        var fieldset = this;
        if (!e.value) {
          window.setTimeout(function() {
            jQuery('.openlayers-map', fieldset).each(function (index, elem) {
              var map = Drupal.openlayers.getMapById(jQuery(elem).attr('id'));
              if (map && map.map !== undefined) {
                map.map.updateSize();
              }
            });
          }, 1000);
        }
      });
    }
  };
})(jQuery);
