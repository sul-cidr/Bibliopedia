Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:Julia',
  init: function(data) {
    var features = [],
        map = data.map,
        resolution = document.getElementById('resolution'),
        iterations = document.getElementById('iterations'),
        fractalType = document.getElementById('fractaltype'),
        fractalMode = document.getElementById('fractalmode'),
        initialvaluex = document.getElementById('initialvaluex'),
        initialvaluei = document.getElementById('initialvaluei'),
        fractalInColor = '#FFFFFF',
        layer = new ol.layer.Vector({
          source: new ol.source.Vector({
            features: features
          }),
          style: function(feature) {
            return [new ol.style.Style({
              image: new ol.style.RegularShape({
                points: 4,
                angle: Math.PI / 4,
                radius: feature.get('fractalResolution'),
                fill: new ol.style.Fill({
                  color: feature.get('fractalColor')
                }),
                stroke: new ol.style.Stroke({
                  color: feature.get('fractalColor'),
                  width: 0
                })
              })
            })];
          }
        }),
        getFractalValues = function (x, y, cx, cy, iterations) {
          var xx = 0, yy = 0, xy = 0, i = 0;

          // Escap time algorithm
          while (xx + yy < 4 && i <= iterations) {
            xy = x * y;
            xx = x * x;
            yy = y * y;
            x = xx - yy + cx;
            y = 2 * xy + cy;
            // Optimisation: Periodicity checking (Mandelbrot only)
            if (x*x == xx && y*y == yy) {
              i = iterations;
              break;
            }
            i++;
          }

          // Continuous (smooth) coloring.
          if (i <= iterations) {
            i = i + 1 - Math.log(Math.log(xx + yy) / 2/Math.log(2)) / Math.log(2);
          }

          return [xx+yy, i];
        },
        getFractalColor = function(length, iterations) {
          if (length >= iterations || length <= 1) {
            return fractalInColor;
          }
          var n = ((length * 360 / iterations)) % 360;
          return 'hsl(' + n + ',100%,50%)';
        },
        makeGraph = function(fractaltype, fractalmode, resolution, iterations, initialvaluex, initialvaluei) {
          layer.getSource().clear();
          features = [];
          var i = 0;
          var width = map.getSize()[0];
          var height = map.getSize()[1];
          var extent = map.getView().calculateExtent([width, height]);

          xmin= extent[0];
          xmax= extent[2];
          ymin= extent[1];
          ymax= extent[3];

          for (var y = 0; y < height; y += resolution) {
            var zy = Math.round(ymin + (ymax - ymin) * y / height);
            for (var x = 0; x < width; x += resolution) {
              var zx = Math.round(xmin + (xmax - xmin) * x / width);

              if (fractaltype === 'mandelbrot') {
                if (zx < -2 * 1000000 || zx > 0.5 * 1000000) {
                  continue;
                }

                if (zy < -1 * 1000000 || zy > 1 * 1000000) {
                  continue;
                }

                i = getFractalValues(0, 0, zx/1000000, zy/1000000, iterations);

                if (fractalmode == 'in') {
                  if (i[0] < 4) {
                    features.push(new ol.Feature({
                          geometry: new ol.geom.MultiPoint([[zx, zy]]),
                          fractalColor: fractalInColor,
                          fractalResolution: resolution
                        })
                    );
                  }
                } else {
                  if (i[0] >= 4 || fractalInColor !== '#FFFFFF') {
                    features.push(new ol.Feature({
                          geometry: new ol.geom.MultiPoint([[zx, zy]]),
                          fractalColor: getFractalColor(i[1], iterations),
                          fractalResolution: resolution
                        })
                    );
                  }
                }
              }

              if (fractaltype === 'julia') {
                if (zx < -2 * 1000000 || zx > 2 * 1000000) {
                  continue;
                }

                if (zy < -2 * 1000000 || zy > 2 * 1000000) {
                  continue;
                }

                i = getFractalValues(zx/1000000, zy/1000000, initialvaluex, initialvaluei, iterations);
                if (i[1] > 0) {
                  features.push(new ol.Feature({
                        geometry: new ol.geom.MultiPoint([[zx, zy]]),
                        fractalColor: getFractalColor(i[1], iterations),
                        fractalResolution: resolution
                      })
                  );
                }
              }
            }
          }

          layer.getSource().addFeatures(features);
        },
        update = function() {
          makeGraph(
              fractalType.value,
              fractalMode.value,
              50 - Number(resolution.value),
              Number(iterations.value),
              Number(initialvaluex.value),
              Number(initialvaluei.value)
          );
        };

    map.addLayer(layer);

    resolution.onchange = function() {
      update();
    };
    iterations.onchange = function() {
      update();
    };
    fractalType.onchange = function() {
      update();
    };
    fractalMode.onchange = function() {
      update();
    };
    initialvaluex.onchange = function() {
      update();
    };
    initialvaluei.onchange = function() {
      update();
    };

    map.getView().on('change:resolution', function() {
      update();
    });

    map.on('moveend', function() {
      update();
    });

    update();
  }
});
