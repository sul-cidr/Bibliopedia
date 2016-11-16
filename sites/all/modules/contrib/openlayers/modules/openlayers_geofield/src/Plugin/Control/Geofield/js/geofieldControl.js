ol.control.Geofield = function(opt_options) {
  var options = opt_options || {};
  var className = options.className || 'ol-geofield';
  this.options = options;

  var this_ = this;
  var handleDrawClick_ = function(e) {
    this_.handleDrawClick_(e);
  };
  var handleActionsClick_ = function(e) {
    this_.handleActionsClick_(e);
  };
  var handleOptionsClick_ = function(e) {
    this_.handleOptionsClick_(e);
  };

  draw = options.draw || {};
  actions = options.actions || {};
  options = options.options || {};

  drawElements = new ol.Collection();
  actionsElements = new ol.Collection();
  optionsElements = new ol.Collection();

  if (draw.Point) {
    var pointLabel = options.pointLabel || '\u25CF';
    var pointTipLabel = options.pointTipLabel || 'Draw a point';
    var pointElement = document.createElement('button');
    pointElement.className = className + '-point';
    pointElement.type = 'button';
    pointElement.draw = 'Point';
    pointElement.title = pointTipLabel;
    pointElement.innerHTML = pointLabel;
    pointElement.addEventListener('click', handleDrawClick_, false);
    drawElements.push(pointElement);
  }

  if (draw.MultiPoint) {
    var multipointLabel = options.multipointLabel || '\u25CF';
    var multipointTipLabel = options.multipointTipLabel || 'Draw a multipoint';
    var multipointElement = document.createElement('button');
    multipointElement.className = className + '-multipoint';
    multipointElement.type = 'button';
    multipointElement.draw = 'MultiPoint';
    multipointElement.title = multipointTipLabel;
    multipointElement.innerHTML = multipointLabel;
    multipointElement.addEventListener('click', handleDrawClick_, false);
    drawElements.push(multipointElement);
  }

  if (draw.LineString) {
    var linestringLabel = options.pointLabel || '\u2500';
    var linestringTipLabel = options.pointTipLabel || 'Draw a linestring, hold [shift] for free hand.';
    var linestringElement = document.createElement('button');
    linestringElement.className = className + '-linestring';
    linestringElement.type = 'button';
    linestringElement.draw = 'LineString';
    linestringElement.title = linestringTipLabel;
    linestringElement.innerHTML = linestringLabel;
    linestringElement.addEventListener('click', handleDrawClick_, false);
    drawElements.push(linestringElement);
  }

  if (draw.MultiLineString) {
    var multilinestringLabel = options.pointLabel || '\u2500';
    var multilinestringTipLabel = options.pointTipLabel || 'Draw a multilinestring, hold [shift] for free hand.';
    var multilinestringElement = document.createElement('button');
    multilinestringElement.className = className + '-multilinestring';
    multilinestringElement.type = 'button';
    multilinestringElement.draw = 'MultiLineString';
    multilinestringElement.title = multilinestringTipLabel;
    multilinestringElement.innerHTML = multilinestringLabel;
    multilinestringElement.addEventListener('click', handleDrawClick_, false);
    drawElements.push(multilinestringElement);
  }

  if (draw.Triangle) {
    var triangleLabel = options.triangleLabel || '\u25B3';
    var triangleTipLabel = options.triangleTipLabel || 'Draw a triangle';
    var triangleElement = document.createElement('button');
    triangleElement.className = className + '-triangle';
    triangleElement.type = 'button';
    triangleElement.draw = 'Triangle';
    triangleElement.title = triangleTipLabel;
    triangleElement.innerHTML = triangleLabel;
    triangleElement.addEventListener('click', handleDrawClick_, false);
    drawElements.push(triangleElement);
  }

  if (draw.Square) {
    var squareLabel = options.squareLabel || '\u25FB';
    var squareTipLabel = options.squareTipLabel || 'Draw a square';
    var squareElement = document.createElement('button');
    squareElement.className = className + '-square';
    squareElement.type = 'button';
    squareElement.draw = 'Square';
    squareElement.title = squareTipLabel;
    squareElement.innerHTML = squareLabel;
    squareElement.addEventListener('click', handleDrawClick_, false);
    drawElements.push(squareElement);
  }

  if (draw.Box) {
    var boxLabel = options.boxLabel || '\u25AF';
    var boxTipLabel = options.boxTipLabel || 'Draw a box';
    var boxElement = document.createElement('button');
    boxElement.className = className + '-box';
    boxElement.type = 'button';
    boxElement.draw = 'Box';
    boxElement.title = boxTipLabel;
    boxElement.innerHTML = boxLabel;
    boxElement.addEventListener('click', handleDrawClick_, false);
    drawElements.push(boxElement);
  }

  if (draw.Circle) {
    var circleLabel = options.circleLabel || '\u25EF';
    var circleTipLabel = options.circleTipLabel || 'Draw a circle';
    var circleElement = document.createElement('button');
    circleElement.className = className + '-circle';
    circleElement.type = 'button';
    circleElement.draw = 'Circle';
    circleElement.title = circleTipLabel;
    circleElement.innerHTML = circleLabel;
    circleElement.addEventListener('click', handleDrawClick_, false);
    drawElements.push(circleElement);
  }

  if (draw.Polygon) {
    var polygonLabel = options.polygonLabel || '\u2B1F';
    var polygonTipLabel = options.polygonTipLabel || 'Draw a polygon';
    var polygonElement = document.createElement('button');
    polygonElement.className = className + '-polygon';
    polygonElement.type = 'button';
    polygonElement.draw = 'Polygon';
    polygonElement.title = polygonTipLabel;
    polygonElement.innerHTML = polygonLabel;
    polygonElement.addEventListener('click', handleDrawClick_, false);
    drawElements.push(polygonElement);
  }

  if (draw.MultiPolygon) {
    var multipolygonLabel = options.multipolygonLabel || '\u2B1F';
    var multipolygonTipLabel = options.multipolygonTipLabel || 'Draw a multipolygon';
    var multipolygonElement = document.createElement('button');
    multipolygonElement.className = className + '-multipolygon';
    multipolygonElement.type = 'button';
    multipolygonElement.draw = 'MultiPolygon';
    multipolygonElement.title = multipolygonTipLabel;
    multipolygonElement.innerHTML = multipolygonLabel;
    multipolygonElement.addEventListener('click', handleDrawClick_, false);
    drawElements.push(multipolygonElement);
  }

  if (actions.Edit) {
    var editLabel = options.editLabel || '\u270D';
    var editTipLabel = options.editTipLabel || 'Edit features';
    var editElement = document.createElement('button');
    editElement.className = className + '-edit';
    editElement.type = 'button';
    editElement.action = 'Edit';
    editElement.title = editTipLabel;
    editElement.innerHTML = editLabel;
    editElement.addEventListener('click', handleActionsClick_, false);
    actionsElements.push(editElement);
  }

  if (actions.Move) {
    var moveLabel = options.moveLabel || '\u27A4';
    var moveTipLabel = options.moveTipLabel || 'Move features';
    var moveElement = document.createElement('button');
    moveElement.className = className + '-move';
    moveElement.type = 'button';
    moveElement.action = 'Move';
    moveElement.title = moveTipLabel;
    moveElement.innerHTML = moveLabel;
    moveElement.addEventListener('click', handleActionsClick_, false);
    actionsElements.push(moveElement);
  }

  if (actions.Clear) {
    var clearLabel = options.clearLabel || 'X';
    var clearTipLabel = options.clearTipLabel || 'Clear features';
    var clearElement = document.createElement('button');
    clearElement.className = className + '-clear';
    clearElement.type = 'button';
    clearElement.action = 'Clear';
    clearElement.title = clearTipLabel;
    clearElement.innerHTML = clearLabel;
    clearElement.addEventListener('click', handleActionsClick_, false);
    actionsElements.push(clearElement);
  }

  if (options.Snap) {
    var snapLabel = options.snapLabel || '\u25CE';
    var snapTipLabel = options.snapTipLabel || 'Snap to features';
    var snapElement = document.createElement('button');
    snapElement.className = className + '-snap';
    snapElement.type = 'button';
    snapElement.option = 'Snap';
    snapElement.title = snapTipLabel;
    snapElement.innerHTML = snapLabel;
    snapElement.addEventListener('click', handleOptionsClick_, false);
    optionsElements.push(snapElement);
  }

  var cssClasses = className + ' ' + 'ol-control';

  var drawElement = document.createElement('div');
  drawElement.className = 'draw ol-control-group';
  drawElements.forEach(function(element) {
    drawElement.appendChild(element);
  });

  var actionsElement = document.createElement('div');
  actionsElement.className = 'actions ol-control-group';
  actionsElements.forEach(function(element) {
    actionsElement.appendChild(element);
  });

  var optionsElement = document.createElement('div');
  optionsElement.className = 'options ol-control-group';
  optionsElements.forEach(function(element) {
    optionsElement.appendChild(element);
  });

  var controlsElement = document.createElement('div');
  controlsElement.className = 'ol-geofield-controls';
  controlsElement.appendChild(drawElement);
  controlsElement.appendChild(actionsElement);
  controlsElement.appendChild(optionsElement);

  var element = document.createElement('div');
  element.className = cssClasses;
  element.appendChild(controlsElement);

  ol.control.Control.call(this, {
    element: element,
    target: options.target
  });
};
ol.inherits(ol.control.Geofield, ol.control.Control);

ol.control.Geofield.prototype.handleDrawClick_ = function(event) {
  var options = this.options;

  // Disable actions buttons.
  var divs = this.element.getElementsByClassName('actions')[0];
  [].map.call(divs.children, function(element) {
    element.classList.remove('enable');
  });
  delete options.actions;

  // Disable other draw buttons.
  divs = this.element.getElementsByClassName('draw')[0];
  [].map.call(divs.children, function(element) {
    element.classList.remove('enable');
  });
  event.target.classList.toggle('enable');

  if (event.target.classList.contains('enable')) {
    options.draw = event.target.draw;
  } else {
    options.draw = false;
  }

  this.options = options;
  this.element.dispatchEvent(new CustomEvent('change', {'detail': this }));
};

ol.control.Geofield.prototype.handleActionsClick_ = function(event) {
  var options = this.options;

  // Disable draw buttons.
  var divs = this.element.getElementsByClassName('draw')[0];
  [].map.call(divs.children, function(element) {
    element.classList.remove('enable');
  });
  options.draw = false;

  // Disable other draw buttons.
  divs = this.element.getElementsByClassName('actions')[0];
  [].map.call(divs.children, function(element) {
    if (event.target !== element) {
      element.classList.remove('enable');
    }
  });
  event.target.classList.toggle('enable');

  if (event.target.classList.contains('enable')) {
    options.actions = options.actions || {};
    options.actions[event.target.action] = true;
  } else {
    options.actions[event.target.action] = false;
  }

  this.options = options;
  this.element.dispatchEvent(new CustomEvent('change', {'detail': this }));
};

ol.control.Geofield.prototype.handleOptionsClick_ = function(event) {
  var options = this.options;
  event.target.classList.toggle('enable');

  if (event.target.classList.contains('enable')) {
    options.options = options.options || {};
    options.options[event.target.option] = true;
  } else {
    options.options[event.target.option] = false;
    event.target.blur();
  }

  this.options = options;
  this.element.dispatchEvent(new CustomEvent('change', {'detail': this }));
};
