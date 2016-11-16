goog.provide('ol.control.AutoZoom');

goog.require('ol.control.Control');

ol.control.AutoZoom = function(opt_options) {
  var options = goog.isDef(opt_options) ? opt_options : {};
  var className = goog.isDef(options.className) ? options.className : 'ol-autozoom';

  var autozoomLabel = goog.isDef(options.autozoomLabel) ?
    options.autozoomLabel : 'A';
  var autozoomTipLabel = goog.isDef(options.autozoomInTipLabel) ?
    options.autozoomTipLabel : 'Autozoom';
  var autozoomElement = goog.dom.createDom(goog.dom.TagName.BUTTON, {
    'class': className + '-autozoom',
    'type' : 'button',
    'title': autozoomTipLabel
  }, autozoomLabel);
  goog.events.listen(autozoomElement,
    goog.events.EventType.CLICK, goog.partial(
      ol.control.AutoZoom.prototype.handleClick_, 'AutoZoom'), false, this);
  ol.control.Control.bindMouseOutFocusOutBlur(autozoomElement);

  var cssClasses = className + ' ' + ol.css.CLASS_CONTROL;

  var element = goog.dom.createDom(goog.dom.TagName.DIV, cssClasses, autozoomElement);

  goog.base(this, {
    element: element,
    target: options.target
  });

  this.options_ = options;
};
goog.inherits(ol.control.AutoZoom, ol.control.Control);

ol.control.AutoZoom.prototype.handleClick_ = function(type, event) {
  var options = this.options_;
  var map = this.getMap();

  function getLayersFromObject(object) {
    var layersInside = new ol.Collection();

    object.getLayers().forEach(function (layer) {
      if (layer instanceof ol.layer.Group) {
        layersInside.extend(getLayersFromObject(layer).getArray());
      }
      else {
        if (typeof layer.getSource === 'function') {
          layersInside.push(layer);
        }
      }
    });

    return layersInside;
  }

  var calculateMaxExtent = function() {
    var maxExtent = ol.extent.createEmpty();

    getLayersFromObject(map).forEach(function (layer) {
      var source = layer.getSource();
      if (typeof source.getFeatures === 'function') {
        if (source.getFeatures().length !== 0) {
          ol.extent.extend(maxExtent, source.getExtent());
        }
      }
    });

    return maxExtent;
  };

  var zoomToSource = function(source) {
    if (!options.process_once || !options.processed_once) {
      options.processed_once = true;

      if (options.enableAnimations === 1) {
        var animationPan = ol.animation.pan({
          duration: options.animations.pan,
          source: map.getView().getCenter()
        });
        var animationZoom = ol.animation.zoom({
          duration: options.animations.zoom,
          resolution: map.getView().getResolution()
        });
        map.beforeRender(animationPan, animationZoom);
      }

      var maxExtent = calculateMaxExtent();
      if (!ol.extent.isEmpty(maxExtent)) {
        map.getView().fit(maxExtent, map.getSize());
      }

      if (options.zoom !== 'disabled') {
        if (options.zoom !== 'auto') {
          map.getView().setZoom(options.zoom);
        } else {
          var zoom = map.getView().getZoom() - 1;
          if (goog.isDef(options.max_zoom) && options.max_zoom > 0 && zoom > options.max_zoom) {
            zoom = options.max_zoom;
          }
          map.getView().setZoom(zoom);
        }
      }
    }
  };

  zoomToSource.call();
};
