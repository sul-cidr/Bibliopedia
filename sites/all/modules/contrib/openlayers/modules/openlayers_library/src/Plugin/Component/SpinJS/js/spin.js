(function ($) {
  Drupal.behaviors.openlayers_spinjs = {
    attach: function (context, settings) {
      for (var map_id in settings.spinjs) {
        var target = document.getElementById('map-container-' + map_id);
        var spinner = new Spinner(settings.spinjs[map_id]).spin(target);
        setTimeout(function() {
          $(spinner.el).fadeOut('slow', function() {
            spinner.stop();
          });
        }, 1000);
      }
    }
  }
}(jQuery));
