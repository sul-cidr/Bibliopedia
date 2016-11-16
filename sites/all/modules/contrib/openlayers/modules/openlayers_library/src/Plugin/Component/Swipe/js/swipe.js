Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:Swipe',
  init: function(data) {
    var map = data.map;
    var swipe = document.getElementById('swipe');

    // Get the last layer of the map.
    layer = map.getLayers().item(map.getLayers().getLength() - 1);

    layer.on('precompose', function(event) {
      var ctx = event.context;
      var width = ctx.canvas.width * (swipe.value / 100);

      ctx.save();
      ctx.beginPath();
      ctx.rect(width, 0, ctx.canvas.width - width, ctx.canvas.height);
      ctx.clip();
    });

    layer.on('postcompose', function(event) {
      var ctx = event.context;
      ctx.restore();
    });

    swipe.addEventListener('input', function() {
      map.render();
    }, false);
  }
});
