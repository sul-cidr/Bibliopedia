Drupal.openlayers.pluginManager.register({
  fs: 'openlayers.Component:ViewSync',
  init: function (data) {
    var map = data.map;

    var ViewSyncGroup = map.get('ViewSyncGroup');
    if (typeof ViewSyncGroup === 'undefined') {
      ViewSyncGroup = [data.opt.group];
    }
    else {
      ViewSyncGroup.push(data.opt.group);
    }
    map.set('ViewSyncGroup', ViewSyncGroup);

    map.on('moveend', function (evt) {
      for (map_id in Drupal.openlayers.instances) {
        var candidate_map = Drupal.openlayers.instances[map_id].map;
        if (evt.map.get('target') !== candidate_map.get('target') && candidate_map.get('ViewSyncGroup') !== undefined) {
          for (sync in evt.map.get('ViewSyncGroup')) {
            var sync = evt.map.get('ViewSyncGroup')[sync];
            if (candidate_map.get('ViewSyncGroup').indexOf(sync) >= 0) {
              if (evt.target.get('target') !== candidate_map.get('target')) {
                candidate_map.setView(evt.map.getView());
              }
            }
          }
        }
      }
    });
  }
});
