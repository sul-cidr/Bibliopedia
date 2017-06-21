Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Layer:InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
    return layer;
  }
});
