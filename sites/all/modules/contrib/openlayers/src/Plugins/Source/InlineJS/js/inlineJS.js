Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Source:InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
    return source;
  }
});
