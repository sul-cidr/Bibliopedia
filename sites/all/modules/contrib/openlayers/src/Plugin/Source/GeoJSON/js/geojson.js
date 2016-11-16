var openlayers_source_internal_geojson = {
  fs: 'openlayers.Source:GeoJSON',
  init: function(data) {
    data.opt.format = new ol.format.GeoJSON();

    //// If GeoJSON data is provided with the layer, use that.  Otherwise
    //// check if BBOX, then finally use AJAX method.
    if (data.opt.geojson_data) {
      data.opt.features = data.opt.format.readFeatures(data.opt.geojson_data, {featureProjection: data.map.getView().getProjection()});
      return new ol.source.Vector(data.opt);
    }
    else {
      if (data.opt.useBBOX) {
        data.opt.strategy = ol.loadingstrategy.bbox;
        data.opt.loader = this.getBboxLoader(data);
      }
    }

    // If reloading the features on state change is enabled we abuse the
    // strategy callback to implement a forced reload of features. This is
    // necessary since we can't overload the loadFeatures() function from the
    // source - it is not part of the API and thus isn't available in the
    // compiled version of ol.
    if ( (data.opt.reloadOnZoomChange !== undefined && data.opt.reloadOnZoomChange) || (data.opt.reloadOnExtentChange !== undefined && data.opt.reloadOnExtentChange) ) {
      data.opt.strategy = function (extent, resolution) {
        // If reloading the features is forced load them here. Otherwise just
        // return the extent of the standard loading strategy.
        if (this._forceReloadFeatures) {
          this._loadingFeatures = true;
          var projection = (this.getProjection()) ? this.getProjection() : data.map.getView().getProjection();
          data.opt.loader.call(this, extent, resolution, projection);
          // This has to be enabled / disabled before each loadFeatures
          // call.
          this._forceReloadFeatures = false;
          // Return an empty list - so the original loader is skipped.
          return [];
        }
        else {
          return ol.loadingstrategy.all;
        }
      };
    }

    var vectorSource = new ol.source.Vector(data.opt);
    this.configureVectorSource(vectorSource, data);
    return vectorSource;
  },

  /**
   * In some cases we need to adjust the load features handler.
   */
  configureVectorSource: function(vectorSource, data) {
    // @todo Add more strategies. Paging strategy would be really interesting
    //   to use with views_geojson.
    if (data.opt.useBBOX) {
      vectorSource._clearFeaturesOnLoad = false;
      vectorSource._loadingFeatures = false;

      if (data.opt.reloadOnExtentChange !== undefined) {
        vectorSource._clearFeaturesOnLoad = true;
        data.map.getView().on('change:center', function() {
          if (!vectorSource._loadingFeatures) {
            vectorSource._forceReloadFeatures = true;
          }
        });
      }
      if (data.opt.reloadOnZoomChange !== undefined) {
        vectorSource._clearFeaturesOnLoad = true;
        data.map.getView().on('change:resolution', function() {
          if (!vectorSource._loadingFeatures) {
            vectorSource._forceReloadFeatures = true;
          }
        });
      }
    }
    //else {
    //  // Fixed strategy.
    //  // @see http://dev.ol.org/releases/Openlayers-2.12/doc/apidocs/files/Openlayers/Strategy/Fixed-js.html
    //  if (data.opt.preload) {
    //    data.opt.strategies = [new ol.Strategy.Fixed({preload: true})];
    //  }
    //  else {
    //    data.opt.strategies = [new ol.Strategy.Fixed()];
    //  }
    //}
    //  if(data.opt.useScript){
    //    //use Script protocol to get around xss issues and 405 error
    //    data.opt.protocol = new ol.Protocol.Script({
    //      url: data.opt.url,
    //      callbackKey: data.opt.callbackKey,
    //      callbackPrefix: "callback:",
    //      filterToParams: function(filter, params) {
    //        // example to demonstrate BBOX serialization
    //        if (filter.type === ol.Filter.Spatial.BBOX) {
    //          params.bbox = filter.value.toArray();
    //          if (filter.projection) {
    //            params.bbox.push(filter.projection.getCode());
    //          }
    //        }
    //        return params;
    //      }
    //    });
    //  }
    //  else{
    //    data.opt.protocol = new ol.Protocol.HTTP({
    //      url: data.opt.url,
    //      format: new ol.Format.GeoJSON()
    //    });
    //  }
    //  var layer = new ol.Layer.Vector(title, options);
  },

  getBboxLoader: function(data) {
    return function(extent, resolution, projection) {
      // Ensure the bbox values are in the correct projection.
      var bbox = ol.proj.transformExtent(extent, data.map.getView().getProjection(), 'EPSG:4326');


      // Check if parameter forwarding is enabled.
      var params = {};
      if (data.opt.paramForwarding) {
        var get_params = location.search.substring(location.search.indexOf('?') + 1 ).split('&');
        jQuery.each(get_params, function(i, val){
          if (val.length) {
            var param = val.split('=');
            // Decode as these are encoded again. Manually handle + as this
            // isn't handled by decodeURIComponent.
            params[decodeURIComponent(param[0])] = (param[1] !== undefined) ? decodeURIComponent(param[1].replace(/\+/g, ' ')) : '';
          }
        })
      }
      params.bbox = bbox.join(',');
      params.zoom = data.map.getView().getZoom();

      var url = data.opt.url;
      jQuery(document).trigger('openlayers.bbox_pre_loading', [{'url': url, 'params': params, 'data':  data}]);

      var that = this;
      jQuery.ajax({
        url: url,
        data: params,
        success: function(data) {
          // If the _clearFeaturesOnLoad flag is set remove the current
          // features before adding the new ones.
          if (that._clearFeaturesOnLoad !== undefined) {
            // Clear features in this extent. We can't use that.clear()
            // because this causes some strange trouble afterwards. And we
            // can't use that.forEachFeature() or
            // that.forEachFeatureInExtent() because those functions won't
            // work with that.removeFeature().
            var features = that.getFeaturesInExtent(extent);
            jQuery(features).each(function (i, f) {
              that.removeFeature(f);
            });
          }
          var format = new ol.format.GeoJSON();
          var features = format.readFeatures(data, {featureProjection: projection});
          that.addFeatures(features);
          that._loadingFeatures = false;
        }
      });
    }
  }
};

Drupal.openlayers.pluginManager.register(openlayers_source_internal_geojson);
