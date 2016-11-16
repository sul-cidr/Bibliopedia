Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:Fractal',
  init: function(data) {
    var radius = 10e6;
    var cos30 = Math.cos(Math.PI / 6);
    var sin30 = Math.sin(Math.PI / 6);
    var rise = radius * sin30;
    var run = radius * cos30;

    var triangle = new ol.geom.LineString([
      [0, radius], [run, -rise], [-run, -rise], [0, radius]
    ]);

    var feature = new ol.Feature(triangle);

    var layer = new ol.layer.Vector({
      source: new ol.source.Vector({
        features: [feature]
      })
    });

    var map = data.map;
    map.addLayer(layer);

    function makeFractal(depth) {
      var geometry = /** @type {ol.geom.LineString} */ (triangle.clone());
      var graph = coordsToGraph(geometry.getCoordinates());
      for (var i = 0; i < depth; ++i) {
        var node = graph;
        while (node.next) {
          var next = node.next;
          injectNodes(node);
          node = next;
        }
      }
      var coordinates = graphToCoords(graph);
      document.getElementById('count').innerHTML = coordinates.length - 1;
      document.getElementById('length').innerHTML = graphToLength(graph);
      geometry.setCoordinates(coordinates);
      feature.setGeometry(geometry);
    }

    function injectNodes(startNode) {
      var endNode = startNode.next;

      var start = startNode.point;
      var end = startNode.next.point;
      var dx = end[0] - start[0];
      var dy = end[1] - start[1];

      // first point at 1/3 along the segment
      var firstNode = {
        point: [start[0] + dx / 3, start[1] + dy / 3]
      };

      // second point at peak of _/\_
      var r = Math.sqrt(dx * dx + dy * dy) / (2 * cos30);
      var a = Math.atan2(dy, dx) + Math.PI / 6;
      var secondNode = {
        point: [start[0] + r * Math.cos(a), start[1] + r * Math.sin(a)]
      };

      // third point at 2/3 along the segment
      var thirdNode = {
        point: [end[0] - dx / 3, end[1] - dy / 3]
      };

      startNode.next = firstNode;
      firstNode.next = secondNode;
      secondNode.next = thirdNode;
      thirdNode.next = endNode;
    }


    function coordsToGraph(coordinates) {
      var graph = {
        point: coordinates[0]
      };
      var length = coordinates.length;
      for (var level = 0, node = graph; level < length - 1; ++level) {
        node.next = {
          point: coordinates[level + 1]
        };
        node = node.next;
      }
      return graph;
    }

    function graphToCoords(graph) {
      var coordinates = [graph.point];
      for (var node = graph, i = 1; node.next; node = node.next, ++i) {
        coordinates[i] = node.next.point;
      }
      return coordinates;
    }

    function graphToLength(graph) {
      var depthInput = document.getElementById('depth').value;
      return 3 * Math.pow(4/3, (depthInput));
    }

    var depthInput = document.getElementById('depth');

    function update() {
      makeFractal(Number(depthInput.value));
    }

    depthInput.onchange = function() {
      update();
    };

    update();
  }
});
