Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Style:Timezones',
  init: function(data) {
    return function(feature, resolution) {
      var offset = 0;
      var name = feature.get('name'); // e.g. GMT -08:30
      var match = name.match(/([\-+]\d{2}):(\d{2})$/);
      if (match) {
        var hours = parseInt(match[1], 10);
        var minutes = parseInt(match[2], 10);
        offset = 60 * hours + minutes;
      }
      var date = new Date();
      var local = new Date(date.getTime() +
        (date.getTimezoneOffset() + offset) * 60000);
      // offset from local noon (in hours)
      var delta = Math.abs(12 - local.getHours() + (local.getMinutes() / 60));
      if (delta > 12) {
        delta = 24 - delta;
      }
      var opacity = 0.75 * (1 - delta / 12);
      return [new ol.style.Style({
        fill: new ol.style.Fill({
          color: [0xff, 0xff, 0x33, opacity]
        }),
        stroke: new ol.style.Stroke({
          color: '#ffffff'
        })
      })];
    };
  }
});
