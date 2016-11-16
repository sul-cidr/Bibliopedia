Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:Logistic',
  init: function(data) {
    var features = [],
      map = data.map,
      start = document.getElementById('start'),
      end = document.getElementById('end'),
      initial = document.getElementById('initial'),
      iterations = document.getElementById('iterations'),
      density = document.getElementById('density'),
      layer = new ol.layer.Vector({
        source: new ol.source.Vector({
          features: []
        }),
        style: new ol.style.Style({
          stroke: new ol.style.Stroke({
            color: 'rgba(0,0,0,0.05)',
            width: 1
          }),
          fill: new ol.style.Fill({
            color: 'rgba(0,0,0,0.05)'
          }),
          image: new ol.style.Circle({
            fill: new ol.style.Fill({
              color: 'rgba(0,0,0,0.05)'
            }),
            stroke: new ol.style.Stroke({
              color: 'rgba(0,0,0,0.05)',
              width: 0
            }),
            radius: 0.3
          })
        })
      }),
      fx = function (x1, r) {
        return r * x1 * (1 - x1);
      },
      it = function (r, iter, init) {
        var idx = 0,
          x = init;
        while (idx++ < iter) {
          x = fx(x, r);
        }
        return [r*1000000, x*1000000];
      },
      makeGraph = function(start, end, initial, iterations, density) {
        layer.getSource().clear();
        features = [];

        for (i = 1; i < iterations; i++) {
          var coordinates = [];
          for (r = start; r < end; r += (1/density)) {
            coordinates.push(it(r, i, initial));
          }

          features.push(new ol.Feature(new ol.geom.MultiPoint(coordinates)));
        }

        layer.getSource().addFeatures(features);
      },
      update = function() {
        makeGraph(
          Number(start.value),
          Number(end.value),
          Number(initial.value),
          Number(iterations.value),
          Number(density.value)
        );
      };

    map.addLayer(layer);

    initial.onchange = function() {
      update();
    };
    start.onchange = function() {
      update();
    };
    end.onchange = function() {
      update();
    };
    iterations.onchange = function() {
      update();
    };
    density.onchange = function() {
      update();
    };

    update();
  }
});
