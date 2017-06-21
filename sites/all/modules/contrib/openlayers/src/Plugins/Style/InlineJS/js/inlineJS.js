Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Style:InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
    return style;
  }
});
