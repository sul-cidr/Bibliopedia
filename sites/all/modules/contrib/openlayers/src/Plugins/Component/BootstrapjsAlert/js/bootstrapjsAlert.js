Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:BoostrapjsAlert',
  init: function(data) {
    jQuery("#" + data.map.getTarget()).before("<div class='alert alert-success' data-dismiss='alert'><a href='#' class='close' data-dismiss='alert'>&times;</a>" + data.opt.message + "</div>");
  }
});
