Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Interaction:InlineJS',
  init: function(data) {
    eval(data.opt.javascript);
    return interaction;
  }
});
