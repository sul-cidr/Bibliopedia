Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:ImageVector',
  init: function(data) {
    if (data.objects.sources[data.opt.source] !== undefined) {
      var options = jQuery.extend(true, {}, data.opt);
      options.source = data.objects.sources[data.opt.source];
      return new ol.source.ImageVector(options);
    }
  }
});
