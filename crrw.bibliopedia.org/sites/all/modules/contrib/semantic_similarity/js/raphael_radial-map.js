// $Id: raphael_radial-map.js,v 1.2 2010/10/07 01:37:23 benoitborrel Exp $

/**
 * JS script which draws a radial/polar map as an SVG canvas
 */

/**
 * Draw radial map.
 *
 * @param <array> nids
 *   A keyed array of nids.
 * @param <string> id
 */
function drawRadialMap(nids, id) {
  var paper = Raphael("radialMap-" + id, 150, 150);
  drawRadialGrid(paper);
  drawRadialDots(paper, nids);
}

/**
 * Draw radial background and grid.
 *
 * @param <object> paper
 *   A Raphael object.
 */
function drawRadialGrid(paper) {
  // Draw background
  paper.circle(75, 75, 74).attr({fill: "r#fff:30-green:100"});
  // Draw grid (concentric circles)
  for (i = 1; i <= 4; i++) {
    paper.circle(75, 75, 15*i).attr({stroke: "black"});
  }
}

/**
 * Draw dots that represent nodes.
 *
 * @param <object> paper
 *   A Raphael object.
 * @param <array> nids
 *   A keyed array of nids.
 */
function drawRadialDots(paper, nids) {
  // Get array of nids passed from PHP as JSON string
  nids = deserialize(nids);

  // angle_step will ventilate equally the dots graphing the nids
  angle_step = 360 / nids.length;
  for(i in nids) {
    // Convert [-1;1] range into a [0;1] range
    nids[i]['distance'] = ((1 - nids[i]['score']) / 2);

    // Convert dot's polar coordinates into cartesian coordinates
    var cartesians = polarToCartesian(nids[i]['distance'], angle_step * i, 'degree');
    nids[i]['x'] = cartesians['x'];
    nids[i]['y'] = cartesians['y'];

    // Compute color and dot's screen cartesian coordinates
    color = Raphael.getColor();
    x = 75 + nids[i]['x'] * 75*6;
    y = 75 - nids[i]['y'] * 75*6;

    // Render path between pole and each dots
    //paper.path("M75 75L"+ x.toString() +" "+ y.toString()).attr({stroke: color});

    (function (x, y, color, nid) {
      // Render dot by translating usual cartesian coordinates into screen cartesian coordinates
      var dot = paper.circle(x, y, 4).attr({stroke: color, fill: color});
      var dot_mask = paper.circle(x, y, 8).attr({stroke: color, fill: "black", opacity: 0});
      // Render dot's label
      var label = paper.text(x, y, parseInt(nids[i]['score']*100)).attr({"font": '10px Fontin-Sans, Arial', stroke: "none", fill: "#fff"}).hide();
      dot_mask[0].onmouseover = function () {
        dot_mask.attr({opacity: .3});
        label.show();
      };
      dot_mask[0].onmouseout = function () {
        dot_mask.attr({opacity: 0});
        label.hide();
      };
      dot_mask[0].onclick = function () {
        var url = "/node/"+ nid;
        $(location).attr('href', url);
      };
    })(x, y, color, nids[i]['nid']);
  }
  // Render pole dot
  paper.circle(75, 75, 4).attr({stroke: "black", fill: "white"});
}

/**
 * Convert a JSON string into an object.
 *
 * @param string json_string
 *   A string representation of an object serialized with JSON.
 * @return object
 *   The deserialized object.
 */
function deserialize(json_string) {
  return eval("(" + json_string + ")");
}

/**
 * Convert polar (distance, angle) coordinates into cartesian (x,y) coordinates.
 *
 * @param <int> distance
 *   A distance from the pole.
 * @param <int> angle
 *   An angle from the polar axis. In radians.
 * @param <string> mode
 *   A computation mode. Either 'degree' or 'radian'. Default to 'radian'.
 * @return <array> cartesians
 *   The associative array of cartesian coordinates x and y.
 */
function polarToCartesian(distance, angle, mode) {
  // Default mode value
  if (mode == null) {
    mode = 'radian';
  }
  if (mode == 'degree') {
    angle *= Math.PI / 180;
  }

  var cartesians = new Array();
  cartesians['x'] = distance * Math.cos(angle);
  cartesians['y'] = distance * Math.sin(angle);

  return cartesians;
}
