Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Control:OL3LayerSwitcher',
  init: function(data) {
    return new ol.control.LayerSwitcher({
      tipLabel: 'Légende' // Optional label for button
    });
  }
});
