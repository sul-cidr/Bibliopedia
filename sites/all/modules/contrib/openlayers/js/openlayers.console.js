/**
 * Logging implementation that logs using the browser's logging API.
 * Falls back to doing nothing in case no such API is available. Simulates
 * the presence of Firebug's console API in Drupal.openlayers.console.
 */
(function ($, Drupal) {

  "use strict";

  var api = {};
  var logger;

  if (((typeof console === 'object' && typeof console !== 'null') || typeof console === 'function') && typeof console.log === 'function') {
    logger = function () {
      // Use console.log as fallback for missing parts of API if present.
      console.log.apply(console, arguments);
    };
  }
  else {
    logger = function () {
      // Ignore call as no logging facility is available.
    };
  }
  $([
    "log",
    "debug",
    "info",
    "warn",
    "exception",
    "assert",
    "dir",
    "dirxml",
    "trace",
    "group",
    "groupEnd",
    "groupCollapsed",
    "profile",
    "profileEnd",
    "count",
    "clear",
    "time",
    "timeEnd",
    "timeStamp",
    "table",
    "error"
  ]).each(function (index, functionName) {
    if (console !== undefined && typeof console[functionName] !== 'function') {
      // Use fallback as browser does not provide implementation.
      api[functionName] = logger;
    }
    else {
      api[functionName] = function () {
        // Use browsers implementation.
        console[functionName].apply(console, arguments);
      };
    }
  });

  Drupal.openlayers.console = api;

}(jQuery, Drupal));
