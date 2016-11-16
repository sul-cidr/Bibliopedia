ol.control.Export = function(opt_options) {
  var options = opt_options || {};


  var this_ = this;
  var handleClick_ = function(e) {
    this_.handleClick_(e);
  };


  var exportTipLabel = options.exportTipLabel || '';

  var button = document.createElement('button');
  button.innerHTML = '\u2193';
  button.title = exportTipLabel;
  button.className = 'ol-export-export';
  button.type = 'button';
  button.download = 'map.png';

  var link = document.createElement('a');
  link.className = 'ol-hidden';

  var element = document.createElement('div');
  element.className = 'ol-export ol-unselectable ol-control';
  element.appendChild(link);
  element.appendChild(button);

  ol.control.Control.call(this, {
    element: element,
    target: options.target
  });

  button.addEventListener('click', handleClick_, false);
  this.options = options;
};
ol.inherits(ol.control.Export, ol.control.Control);

/**
 * @param {event} event Browser event.
 */
ol.control.Export.prototype.handleClick_ = function(event) {
  event.target.blur();
  var link = this.element.children[0];
  this.getMap().once('postcompose', function(event) {
    var canvas = event.context.canvas;
    link.download = 'map-' + Date.now() + '.png';
    link.href = canvas.toDataURL('image/png');
    link.click();
  });
  this.getMap().renderSync();
};
