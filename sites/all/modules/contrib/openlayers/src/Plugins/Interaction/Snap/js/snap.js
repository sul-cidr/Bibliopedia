Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:Snap',
  init: function(data) {
    if (goog.isDef(data.opt) && goog.isDef(data.opt.source) && goog.isDef(data.objects.sources[data.opt.source])) {
      data.opt.source = data.objects.sources[data.opt.source];
    }

    return new ol.interaction.Snap(data.opt);
  }
});
