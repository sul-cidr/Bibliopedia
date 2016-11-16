(function ($, Drupal) {

  "use strict";

  var plugins = [];

  Drupal.openlayers.pluginManager = {
    attach: function (context, settings) {
      for (var i in plugins) {
        var plugin = plugins[i];
        if (typeof plugin.attach === 'function') {
          plugin.attach(context, settings);
        }
      }
    },
    detach: function (context, settings) {
      for (var i in plugins) {
        var plugin = plugins[i];
        if (typeof plugin.detach === 'function') {
          plugin.detach(context, settings);
        }
      }
    },
    alter: function () {
      // @todo: alter hook
    },
    getPlugin: function (factoryService) {
      if (this.isRegistered(factoryService)) {
        return plugins[factoryService];
      }
      return false;
    },
    getPlugins: function () {
      return Object.keys(plugins);
    },
    register: function (plugin) {
      if ((typeof plugin !== 'object') || (plugin === null)) {
        return false;
      }

      if (typeof plugin.init !== 'function') {
        return false;
      }

      if (!plugin.hasOwnProperty('fs')) {
        return false;
      }

      plugins[plugin.fs] = plugin;
    },
    createInstance: function (factoryService, data) {
      if (!this.isRegistered(factoryService)) {
        return false;
      }

      try {
        var obj = plugins[factoryService].init(data);
      } catch (e) {
        if (console !== undefined) {
          Drupal.openlayers.console.log(e.message);
          Drupal.openlayers.console.log(e.stack);
        }
        else {
          $(this).text('Error during map rendering: ' + e.message);
          $(this).text('Stack: ' + e.stack);
        }
      }

      var objType = typeof obj;
      if ((objType === 'object') && (objType !== null) || (objType === 'function')) {
        obj.mn = data.data.mn;
        return obj;
      }

      return false;
    },
    isRegistered: function (factoryService) {
      return (factoryService in plugins);
    }
  };

}(jQuery, Drupal));
