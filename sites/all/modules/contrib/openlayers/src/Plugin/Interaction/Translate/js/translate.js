Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:Translate',
  init: function(data) {
    var options = jQuery.extend(true, {}, data.opt);

    if (options.select !== undefined) {
      if (data.objects.interactions[options.select] !== undefined) {
        options.select = data.objects.interactions[options.select];
      } else {
        delete options.select;
      }
    }

    return new ol.interaction.Translate({
      features: options.select.getFeatures()
    });
  }
});
