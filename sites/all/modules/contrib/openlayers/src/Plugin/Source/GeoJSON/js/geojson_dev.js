// Register developer mode functions.
// Overwrite the original init handling.
openlayers_source_internal_geojson.orgInit = openlayers_source_internal_geojson.init;
openlayers_source_internal_geojson.init = function(data) {

  //var vectorSource = jQuery.proxy(openlayers_source_internal_geojson.orgInit, this, data)();
  var vectorSource = this.orgInit(data);

  // If development mode is enabled add the development dialog.
  if (data.opt.devMode) {
    var map_container_id = 'openlayers-container-' + data.map_id;
    var dialog_selector = '#' + map_container_id + '-ol-dev-dialog';

    // Just add once.
    if (!jQuery(dialog_selector).length) {
      jQuery('#' + map_container_id).append(
        '<div id="' + map_container_id + '-ol-dev-dialog" class="ol-dev-dialog" title="Openlayers Development: GeoJson Sources">' +
        '  <label for="ol_devel_source">Source</label><select name="ol_devel_source">' +
        '    <option value="' + data.data.mn + '">' + data.data.mn + '</option>' +
        '  </select>' +
        data.opt.devDialog +
        '</div>'
      );

      var dialogOptions = {
        closeOnEscape: false,
        beforeClose: function( event, ui ) {
          jQuery(dialog_selector).toggle();
          return false;
        },
        dragStop: function( event, ui ) {
          jQuery.cookie('Drupal.openlayers.devDialog.position', JSON.stringify(ui.offset), {
            path: Drupal.settings.basePath,
            // The cookie expires in one year.
            expires: 365
          });
        },
        resizeStop: function( event, ui ) {
          jQuery.cookie('Drupal.openlayers.devDialog.size', JSON.stringify(ui.size), {
            path: Drupal.settings.basePath,
            // The cookie expires in one year.
            expires: 365
          });
        },
        open: function( event, ui ) {
          if (jQuery.cookie('Drupal.openlayers.devDialog.position')) {
            var pos = jQuery.parseJSON(jQuery.cookie('Drupal.openlayers.devDialog.position'));
            jQuery(this).parent().offset(pos);
          }
        },
        buttons: [
          {
            text: Drupal.t('Update'),
            click: function() {
              var map = Drupal.openlayers.getMapById(data.map_id);
              var source = jQuery(dialog_selector + ' select').val();
              var source_conf = openlayers_source_internal_geojson.getSourceConf(data.map_id, source);

              // Update the configuration.
              source_conf.opt.url = jQuery(dialog_selector + ' [name="url"]').val();
              if (!source_conf.opt.url.length) {
                delete source_conf.opt.url;
              }
              source_conf.opt.useBBOX = jQuery(dialog_selector + ' [name="useBBOX"]')[0].checked;
              source_conf.opt.paramForwarding = jQuery(dialog_selector + ' [name="paramForwarding"]')[0].checked;
              source_conf.opt.reloadOnZoomChange = jQuery(dialog_selector + ' [name="reloadOnZoomChange"]')[0].checked;
              source_conf.opt.reloadOnExtentChange = jQuery(dialog_selector + ' [name="reloadOnExtentChange"]')[0].checked;
              source_conf.opt.geojson_data = jQuery(dialog_selector + ' [name="geojson_data"]').val();

              openlayers_source_internal_geojson.updateSource(data, source);
            }
          },
          {
            text: Drupal.t('Remove features'),
            click: function() {
              var map = Drupal.openlayers.getMapById(data.map_id);
              var source = jQuery(dialog_selector + ' select').val();
              map.sources[source].clear();
            }
          }
        ]
      };

      if (jQuery.cookie('Drupal.openlayers.devDialog.size')) {
        var size = jQuery.parseJSON(jQuery.cookie('Drupal.openlayers.devDialog.size'));
        dialogOptions.width = size.width;
        dialogOptions.height = size.height;
      }

      jQuery(dialog_selector).dialog(dialogOptions);

      // Source change action.
      jQuery(dialog_selector + ' select').change(function () {
        var source = jQuery(dialog_selector + ' select').val();
        var source_conf = openlayers_source_internal_geojson.getSourceConf(data.map_id, source);
        jQuery(dialog_selector + ' [name="url"]').val(source_conf.opt.url);
        jQuery(dialog_selector + ' [name="useBBOX"]')[0].checked = source_conf.opt.useBBOX;
        jQuery(dialog_selector + ' [name="paramForwarding"]')[0].checked = source_conf.opt.paramForwarding;
        jQuery(dialog_selector + ' [name="reloadOnZoomChange"]')[0].checked = source_conf.opt.reloadOnZoomChange;
        jQuery(dialog_selector + ' [name="reloadOnExtentChange"]')[0].checked = source_conf.opt.reloadOnExtentChange;
        jQuery(dialog_selector + ' [name="geojson_data"]').val(source_conf.opt.geojson_data);
      })
        // Trigger a change initialy to ensure the proper settings are pre-set.
        .trigger('change');
    }
    else {
      // Add the source as option for the source selection in the dialog.
      jQuery(dialog_selector + ' select').append('<option value="' + data.data.mn + '">' + data.data.mn + '</option>');
    }
  }
  return vectorSource;
};

/**
 * Returns the source configuration of a map / source combination.
 *
 * @param map_id
 * @param mn
 * @returns {*}
 */
openlayers_source_internal_geojson.getSourceConf = function(map_id, mn) {
  for (var i in Drupal.settings.openlayers.maps[map_id].source) {
    if (Drupal.settings.openlayers.maps[map_id].source[i].mn == mn) {
      return Drupal.settings.openlayers.maps[map_id].source[i];
    }
  }
};

/**
 * Updates a source with the current settings.
 *
 * @param data
 * @param source
 */
openlayers_source_internal_geojson.updateSource = function(data, source) {
  var map = Drupal.openlayers.instances[data.map_id];
  var source_conf = openlayers_source_internal_geojson.getSourceConf(data.map_id, source);

  // If we use geojson text data parse and load them.
  // If our own loader is registered it uses the data.url. If it is the
  // default loader we rebuild it using the new url.
  if (source_conf.opt.geojson_data) {
    map.sources[source].clear();
    source_conf.opt.features = source_conf.opt.format.readFeatures(source_conf.opt.geojson_data, {featureProjection: map.map.getView().getProjection()});
    map.sources[source].addFeatures(source_conf.opt.features);
    return;
  }
  else if (source_conf.opt.loader !== undefined) {
    var instance_data = {
      'data': source_conf,
      'opt': source_conf.opt,
      'map': map.map,
      'objects': Drupal.openlayers.instances[data.map_id],
      'context': data.context,
      'map_id': data.map_id
    };
    openlayers_source_internal_geojson.configureVectorSource(map.sources[source], instance_data);
  }
  else if (source_conf.opt.url !== undefined) {
    map.sources[source].loader_ = ol.featureloader.xhr(source_conf.opt.url, source_conf.opt.format);
  }

  map.sources[source].clear();
  map.sources[source].changed();
};
