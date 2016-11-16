(function ($, Drupal) {

  "use strict";

  Drupal.openlayers = {
    instances: {},
    processMap: function (map_id, context) {
      var settings = $.extend({}, {
        layer: [],
        style: [],
        control: [],
        interaction: [],
        source: [],
        projection: [],
        component: []
      }, Drupal.settings.openlayers.maps[map_id]);
      var map = false;

      // If already processed just return the instance.
      if (Drupal.openlayers.instances[map_id] !== undefined) {
        return Drupal.openlayers.instances[map_id].map;
      }

      $(document).trigger('openlayers.build_start', [
        {
          'type': 'objects',
          'settings': settings,
          'context': context
        }
      ]);

      try {
        $(document).trigger('openlayers.map_pre_alter', [
          {
            context: context,
            settings: settings,
            map_id: map_id
          }
        ]);
        map = Drupal.openlayers.getObject(context, 'maps', settings.map, map_id);
        $(document).trigger('openlayers.map_post_alter', [{map: Drupal.openlayers.instances[map_id].map}]);

        if (settings.style.length > 0) {
          $(document).trigger('openlayers.styles_pre_alter', [
            {
              styles: settings.style,
              map_id: map_id
            }
          ]);
          settings.style.map(function (data) {
            Drupal.openlayers.getObject(context, 'styles', data, map_id);
          });
          $(document).trigger('openlayers.styles_post_alter', [
            {
              styles: settings.style,
              map_id: map_id
            }
          ]);
        }

        if (settings.source.length > 0) {
          $(document).trigger('openlayers.sources_pre_alter', [
            {
              sources: settings.source,
              map_id: map_id
            }
          ]);
          settings.source.map(function (data) {
            if (data.opt !== undefined && data.opt.attributions !== undefined) {
              data.opt.attributions = [
                new ol.Attribution({
                  'html': data.opt.attributions
                })
              ];
            }
            Drupal.openlayers.getObject(context, 'sources', data, map_id);
          });
          $(document).trigger('openlayers.sources_post_alter', [
            {
              sources: settings.source,
              map_id: map_id
            }
          ]);
        }

        if (settings.interaction.length > 0) {
          $(document).trigger('openlayers.interactions_pre_alter', [
            {
              interactions: settings.interaction,
              map_id: map_id
            }
          ]);
          settings.interaction.map(function (data) {
            var interaction = Drupal.openlayers.getObject(context, 'interactions', data, map_id);
            if (interaction) {
              map.addInteraction(interaction);
            }
          });
          $(document).trigger('openlayers.interactions_post_alter', [
            {
              interactions: settings.interaction,
              map_id: map_id
            }
          ]);
        }

        if (settings.layer.length > 0) {
          $(document).trigger('openlayers.layers_pre_alter', [
            {
              layers: settings.layer,
              map_id: map_id
            }
          ]);

          var groups = {};
          var layers = {};

          settings.layer.map(function (data, key) {
            if (data.fs === 'openlayers.Layer:Group') {
              groups[data.mn] = data;
            }
            else {
              layers[data.mn] = data;
            }
          });

          for (var i in layers) {
            var data = jQuery.extend(true, {}, layers[i]);
            data.opt.source = Drupal.openlayers.instances[map_id].sources[data.opt.source];
            if (data.opt.style !== undefined && Drupal.openlayers.instances[map_id].styles[data.opt.style] !== undefined) {
              data.opt.style = Drupal.openlayers.instances[map_id].styles[data.opt.style];
            }
            var layer = Drupal.openlayers.getObject(context, 'layers', data, map_id);

            if (layer) {
              if (data.opt.name !== undefined) {
                layer.set('title', data.opt.name);
              }
              layers[i] = layer;
            }
          }

          for (var i in groups) {
            data = jQuery.extend(true, {}, groups[i]);
            var candidates = [];
            data.opt.grouplayers.map(function (layer_machine_name) {
              candidates.push(layers[layer_machine_name]);
              delete layers[layer_machine_name];
            });
            data.opt.grouplayers = candidates;
            layer = Drupal.openlayers.getObject(context, 'layers', data, map_id);

            if (layer) {
              groups[i] = layer;
            }
          }

          $.map(layers, function (layer) {
            map.addLayer(layer);
          });

          // Todo: See why it's not ordered properly automatically.
          var groupsOrdered = [];
          for (var i in groups) {
            groupsOrdered.push(groups[i]);
          }
          groupsOrdered.reverse().map(function (layer) {
            map.addLayer(layer);
          });

          $(document).trigger('openlayers.layers_post_alter', [
            {
              layers: settings.layer,
              map_id: map_id
            }
          ]);
        }

        if (settings.control.length > 0) {
          $(document).trigger('openlayers.controls_pre_alter', [
            {
              controls: settings.control,
              map_id: map_id
            }
          ]);
          settings.control.map(function (data) {
            var control = Drupal.openlayers.getObject(context, 'controls', data, map_id);
            if (control) {
              map.addControl(control);
            }
          });
          $(document).trigger('openlayers.controls_post_alter', [
            {
              controls: settings.control,
              map_id: map_id
            }
          ]);
        }

        if (settings.component.length > 0) {
          $(document).trigger('openlayers.components_pre_alter', [{components: settings.component}]);
          settings.component.map(function (data) {
            Drupal.openlayers.getObject(context, 'components', data, map_id);
          });
        }

      } catch (e) {
        $('#' + map_id).empty();
        $(document).trigger('openlayers.build_failed', [
          {
            'error': e,
            'settings': settings,
            'context': context
          }
        ]);
        map = false;
      }

      $(document).trigger('openlayers.build_stop', [
        {
          'type': 'objects',
          'settings': settings,
          'context': context
        }
      ]);

      return map;
    },

    /**
     * Return the map instance collection of a map_id.
     *
     * @param map_id
     *   The id of the map.
     * @returns object/false
     *   The object or false if not instantiated yet.
     */
    getMapById: function (map_id) {
      if (Drupal.settings.openlayers.maps[map_id] !== undefined) {
        // Return map if it is instantiated already.
        if (Drupal.openlayers.instances[map_id]) {
          return Drupal.openlayers.instances[map_id];
        }
      }
      return false;
    },

    // Holds dynamic created asyncIsReady callbacks for every map id.
    // The functions are named by the cleaned map id. Everything besides 0-9a-z
    // is replaced by an underscore (_).
    asyncIsReadyCallbacks: {},
    asyncIsReady: function (map_id) {
      if (Drupal.settings.openlayers.maps[map_id] !== undefined) {
        Drupal.settings.openlayers.maps[map_id].map.opt.async--;
        if (!Drupal.settings.openlayers.maps[map_id].map.opt.async) {
          $('#' + map_id).once('openlayers-map', function () {
            Drupal.openlayers.processMap(map_id, document);
          });
        }
      }
    },

    /**
     * Get an object of a map.
     *
     * If it isn't instantiated yet the instance is created.
     */
    getObject: (function (context, type, data, map_id) {
      // If the type is maps the structure is slightly different.
      var instances_type = type;
      if (type == 'maps') {
        instances_type = 'map';
      }
      // Prepare instances cache.
      if (Drupal.openlayers.instances[map_id] === undefined) {
        Drupal.openlayers.instances[map_id] = {
          map: null,
          layers: {},
          styles: {},
          controls: {},
          interactions: {},
          sources: {},
          projections: {},
          components: {}
        };
      }

      // Check if we've already an instance of this object for this map.
      if (Drupal.openlayers.instances[map_id] !== undefined && Drupal.openlayers.instances[map_id][instances_type] !== undefined) {
        if (instances_type !== 'map' && Drupal.openlayers.instances[map_id][instances_type][data.mn] !== undefined) {
          return Drupal.openlayers.instances[map_id][instances_type][data.mn];
        }
        else
          if (instances_type === 'map' && Drupal.openlayers.instances[map_id][instances_type]) {
            return Drupal.openlayers.instances[map_id][instances_type];
          }
      }

      var object = null;
      // Make sure that data.opt exist even if it's empty.
      data.opt = $.extend({}, {}, data.opt);
      if (Drupal.openlayers.pluginManager.isRegistered(data['fs'])) {
        $(document).trigger('openlayers.object_pre_alter', [
          {
            'type': type,
            'mn': data.mn,
            'data': data,
            'map': Drupal.openlayers.instances[map_id].map,
            'objects': Drupal.openlayers.instances[map_id],
            'context': context,
            'map_id': map_id
          }
        ]);
        object = Drupal.openlayers.pluginManager.createInstance(data['fs'], {
          'data': data,
          'opt': data.opt,
          'map': Drupal.openlayers.instances[map_id].map,
          'objects': Drupal.openlayers.instances[map_id],
          'context': context,
          'map_id': map_id
        });
        $(document).trigger('openlayers.object_post_alter', [
          {
            'type': type,
            'mn': data.mn,
            'data': data,
            'map': Drupal.openlayers.instances[map_id].map,
            'objects': Drupal.openlayers.instances[map_id],
            'context': context,
            'object': object,
            'map_id': map_id
          }
        ]);

        // Store object to the instances cache.
        if (type == 'maps') {
          Drupal.openlayers.instances[map_id][instances_type] = object;
        }
        else {
          Drupal.openlayers.instances[map_id][instances_type][data.mn] = object;
        }
        return object;
      }
      else {
        $(document).trigger('openlayers.object_error', [
          {
            'type': type,
            'mn': data.mn,
            'data': data,
            'map': Drupal.openlayers.instances[map_id].map,
            'objects': Drupal.openlayers.instances[map_id],
            'context': context,
            'object': object,
            'map_id': map_id
          }
        ]);
      }
    }),
    log: function (string) {
      if (Drupal.openlayers.console !== undefined) {
        Drupal.openlayers.console.log(string);
      }
    }
};
}(jQuery, Drupal));
