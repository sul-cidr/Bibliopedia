Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
  }
});
