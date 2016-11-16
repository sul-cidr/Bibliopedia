Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:ProgressBar',
  init: function(data) {

    /**
     * Renders a progress bar.
     * @param {Element} el The target element.
     * @constructor
     */
    function Progress(el) {
      this.el = el;
      this.loading = 0;
      this.loaded = 0;
    }

    /**
     * Increment the count of loading tiles.
     */
    Progress.prototype.addLoading = function() {
      if (this.loading === 0) {
        this.show();
      }
      ++this.loading;
      this.update();
    };

    /**
     * Increment the count of loaded tiles.
     */
    Progress.prototype.addLoaded = function() {
      setTimeout(function() {
        ++this.loaded;
        this.update();
      }.bind(this), 100);
    };

    /**
     * Update the progress bar.
     */
    Progress.prototype.update = function() {
      var width = (this.loaded / this.loading * 100).toFixed(1) + '%';
      this.el.style.width = width;
      if (this.loading === this.loaded) {
        this.loading = 0;
        this.loaded = 0;
        setTimeout(this.hide.bind(this), 500);
      }
    };

    /**
     * Show the progress bar.
     */
    Progress.prototype.show = function() {
      this.el.style.visibility = 'visible';
    };

    /**
     * Hide the progress bar.
     */
    Progress.prototype.hide = function() {
      if (this.loading === this.loaded) {
        this.el.style.visibility = 'hidden';
        this.el.style.width = 0;
      }
    };

    var progress = new Progress(document.getElementById('progress-' + data.map.get('target')));

    for (var i in data.objects.layers) {
      var layer = data.objects.layers[i];

      if (!(layer instanceof ol.layer.Group)) {
        var source = layer.getSource();
        source.on('tileloadstart', function (event) {
          progress.addLoading();
        });
        source.on('tileloadend', function (event) {
          progress.addLoaded();
        });
        source.on('tileloaderror', function (event) {
          progress.addLoaded();
        });
      }
    }
  }
});
