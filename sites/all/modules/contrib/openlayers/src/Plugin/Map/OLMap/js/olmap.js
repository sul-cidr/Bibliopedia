Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Map:OLMap',
  init: function(data) {
    var options = jQuery.extend(true, {}, data.opt);
    var projection = ol.proj.get('EPSG:3857');
    var coord = ol.proj.transform([options.view.center.lat, options.view.center.lon], 'EPSG:4326', projection);

    var view_opts = {
      center: coord,
      rotation: options.view.rotation * (Math.PI / 180),
      zoom: options.view.zoom,
      projection: projection
    };

    if (options.view.limit_extent) {
      if (options.view.limit_extent == 'custom') {
        // Check if a extent boundaries are set.
        if (options.view.extent) {
          view_opts.extent = ol.proj.transform(options.view.extent.replace(/\s*/ig, '').split(','), 'EPSG:4326', projection);
        }
      }
      if (options.view.limit_extent == 'projection') {
        view_opts.extent = projection.getExtent();
      }
    }

    // Just use min / max zoom if set to a non 0 value to avoid problems.
    if (options.view.minZoom) {
      view_opts.minZoom = options.view.minZoom;
    }
    if (options.view.maxZoom) {
      view_opts.maxZoom = options.view.maxZoom;
    }

    options.view = new ol.View(view_opts);

    // Provide empty defaults to suppress Openlayers defaults that contains
    // all interactions and controls available.
    options.interactions = [];
    options.controls = [];
    options.target = data.opt.target;

    return new ol.Map(options);
  },
  detach: function (context, settings) {
    jQuery('.openlayers-map').removeOnce('openlayers-map', function () {
      var map_id = jQuery(this).attr('id');
      delete Drupal.openlayers.instances[map_id];
    });
  },
  attach: function(context, settings) {}
});
