ol.control.JSGeocoder = function(opt_options) {
  var options = opt_options || {};
  var className = options.className || 'ol-jsgeocoder';
  var this_ = this;

  window.OlControlJSGeocoderGoogleWrapper = function() {
    this_.enableInput(this_);
  };

  function debounce(fn, delay) {
    var timer = null;
    return function () {
      var context = this, args = arguments;
      clearTimeout(timer);
      timer = setTimeout(function () {
        fn.apply(context, args);
      }, delay);
    };
  }

  var handleChange_ = debounce(function(event) {
    ol.control.JSGeocoder.prototype.handleChange_(event, this_);
  }, options.timeout || 500);

  var script = document.createElement('script');
  script.type = 'text/javascript';
  script.src = 'https://maps.googleapis.com/maps/api/js?v=3.exp' +
    '&signed_in=true&callback=OlControlJSGeocoderGoogleWrapper';
  document.body.appendChild(script);

  var textInput = document.createElement('input');
  textInput.className = 'ol-jsgeocoder-textinput';
  textInput.type = 'text';
  textInput.disabled = true;
  textInput.placeholder = options.loadingPlaceholder || '';
  textInput.size = options.size || 25;

  var element = document.createElement('div');
  element.className = className + ' ol-unselectable ol-control';
  element.appendChild(textInput);

  ol.control.Control.call(this, {
    element: element,
    target: options.target
  });

  textInput.addEventListener('keypress', handleChange_, false);
  this.options = options;
};
ol.inherits(ol.control.JSGeocoder, ol.control.Control);

/**
 * @param {event} event Browser event.
 */
ol.control.JSGeocoder.prototype.handleChange_ = function(event, control) {
  this.geocodeAddress(event, control);
};

ol.control.JSGeocoder.prototype.enableInput = function(control) {
  var child=(this.element.firstElementChild||this.element.firstChild);
  child.disabled = false;
  child.placeholder = control.options.placeholder || '';
  this.geocoder = new google.maps.Geocoder();
};

ol.control.JSGeocoder.prototype.geocodeAddress = function(event, control) {
  var address = event.target.value;
  var geocoder = control.geocoder;
  geocoder.geocode({'address': address}, function(results, status) {
    if (status == google.maps.GeocoderStatus.OK) {
      control.updateMap(results, control);
    }
  });
};

ol.control.JSGeocoder.prototype.updateMap = function(results, control) {
  var map = control.getMap();
  var child=(control.element.firstElementChild||control.element.firstChild);

  if (control.options.autocomplete !== undefined && control.options.autocomplete == 1) {
    child.value = results[0].formatted_address;
  }

  var coordinates = ol.proj.transform([results[0].geometry.location.lng(), results[0].geometry.location.lat()], 'EPSG:4326', 'EPSG:3857');

  var animationPan = ol.animation.pan({
    duration: 500,
    source: map.getView().getCenter()
  });
  var animationZoom = ol.animation.zoom({
    duration: 500,
    resolution: map.getView().getResolution()
  });
  map.beforeRender(animationPan, animationZoom);

  map.getView().setCenter(coordinates);
  if (control.options.zoom !== undefined && control.options.zoom !== 0) {
    map.getView().setZoom(control.options.zoom);
  }
};
