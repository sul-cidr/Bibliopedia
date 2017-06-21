Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:Cluster',
  init: function(data) {
    if (goog.isDef(data.objects.sources[data.opt.source])) {
      var options = jQuery.extend(true, {}, data.opt);
      options.source = data.objects.sources[data.opt.source];
      return new ol.source.Cluster(options);
    }
  }
});
