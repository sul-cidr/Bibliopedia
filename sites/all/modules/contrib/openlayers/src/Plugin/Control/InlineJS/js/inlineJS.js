Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
    return control;
  }
});
