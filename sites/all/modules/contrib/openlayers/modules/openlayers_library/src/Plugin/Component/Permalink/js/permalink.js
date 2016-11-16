Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:Permalink',
  init: function(data) {
    var map = data.map;

    if (window.location.hash !== '') {
      // try to restore center, zoom-level and rotation from the URL
      var parts = window.location.hash.split(/z|lat|lng|rot/);
      if (parts.length === 5 && parts[0] == '#') {
        zoom = parseInt(parts[1], 10);
        center = [
          parseFloat(parts[2]),
          parseFloat(parts[3])
        ];
        rotation = parseFloat(parts[4]);

        map.setView(new ol.View({
          center: center,
          zoom: zoom,
          rotation: rotation
        }));
      }

    }

    var shouldUpdate = true;
    var view = map.getView();
    var updatePermalink = function() {
      if (!shouldUpdate) {
        // do not update the URL when the view was changed in the 'popstate' handler
        shouldUpdate = true;
        return;
      }

      var center = view.getCenter();
      var hash =
        'z' + view.getZoom() +
        'lat' + Math.round(center[0] * 100) / 100 +
        'lng' + Math.round(center[1] * 100) / 100 +
        'rot' + view.getRotation();
      var state = {
        zoom: view.getZoom(),
        center: view.getCenter(),
        rotation: view.getRotation()
      };
      window.history.pushState(state, 'openlayers_map', '#' + hash);
    };

    map.on('moveend', updatePermalink);

    // restore the view state when navigating through the history, see
    // https://developer.mozilla.org/en-US/docs/Web/API/WindowEventHandlers/onpopstate
    window.addEventListener('popstate', function(event) {
      if (event.state === null) {
        return;
      }
      map.getView().setCenter(event.state.center);
      map.getView().setZoom(event.state.zoom);
      map.getView().setRotation(event.state.rotation);
      shouldUpdate = false;
    });

  }
});
