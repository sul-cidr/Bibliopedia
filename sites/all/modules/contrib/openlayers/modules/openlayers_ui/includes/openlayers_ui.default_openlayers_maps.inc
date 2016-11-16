<?php
/**
 * @file
 * Provide default maps.
 */

/**
 * Implements hook_default_maps().
 */
function openlayers_ui_default_openlayers_maps() {
  $export = array();

  $ol_map = new stdClass();
  $ol_map->disabled = FALSE;
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_map_ui_default';
  $ol_map->name = 'Default UI Map';
  $ol_map->description = 'Map used if there are no other maps defined';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '400px',
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
    ),
    'contextualLinks' => 0,
    'provideBlock' => 0,
    'provideIframe' => 1,
    'layers' => array(
      0 => 'openlayers_layer_tile_mapquest_osm',
    ),
    'controls' => array(
      0 => 'openlayers_control_attribution',
      1 => 'openlayers_control_rotate',
      2 => 'openlayers_control_zoom',
      3 => 'openlayers_control_overviewmap',
      4 => 'openlayers_control_fullscreen',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_dragpan',
      1 => 'openlayers_interaction_dragrotate',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'capabilities' => array(
      'enabled' => 1,
      'options' => array(
        'container_type' => 'fieldset',
        'title' => 'Map capabilities',
        'description' => '',
        'collapsible' => 1,
        'collapsed' => 0,
        'table' => array(
          'openlayers_control_attribution' => 'Provides a control to show all the attributions associated with the layer sources in the map.',
          'openlayers_control_rotate' => 'Provides a button control to reset rotation to 0.',
          'openlayers_control_fullscreen' => 'Provides a button that when clicked fills up the full screen with the map. When in full screen mode, a close button is shown to exit full screen mode.',
          'openlayers_control_zoom' => 'Provides a button, one for zoom in and one for zoom out.',
          'openlayers_control_overviewmap' => 'Create a new control with a map acting as an overview map for an other defined map.',
          'openlayers_interaction_mousewheelzoom' => 'Allows the user to zoom the map by scrolling the mouse wheel.',
          'openlayers_interaction_dragrotate' => 'Allows the user to rotate the map by clicking and dragging on the map when the [ALT] and [SHIFT] keys are held down. This interaction is only supported for mouse devices.',
          'openlayers_interaction_dragpan' => 'Allows the user to pan the map by dragging the map.',
        ),
      ),
    ),
  );
  $export['openlayers_map_ui_default'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = TRUE;
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_map_view_edit_form';
  $ol_map->name = 'Map view edit form';
  $ol_map->description = 'Map used in the the map edit form to get center and zoom. You can drag this map with your mouse, click to center and you can hold alt and shift key to rotate. Min & max zoom as well as "Limit to extent" settings are not applied to this map.';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => 'auto',
    'height' => '400px',
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
    ),
    'contextualLinks' => 0,
    'provideBlock' => 0,
    'layers' => array(
      0 => 'openlayers_layer_tile_mapquest_osm',
    ),
    'controls' => array(
      0 => 'openlayers_control_rotate',
      1 => 'openlayers_control_zoom',
      2 => 'openlayers_control_zoomslider',
      3 => 'openlayers_control_zoomtoextent',
    ),
    'interactions' => array(
      0 => 'openlayers_interaction_dragpan',
      1 => 'openlayers_interaction_dragrotate',
      2 => 'openlayers_interaction_mousewheelzoom',
    ),
    'components' => array(
      0 => 'openlayers_component_map_edit_form_values',
      1 => 'openlayers_component_map_edit_form_setcenter',
    ),
    'capabilities' => array(
      'enabled' => 1,
      'options' => array(
        'container_type' => 'fieldset',
        'title' => 'Map capabilities',
        'description' => '',
        'collapsible' => 1,
        'collapsed' => 0,
        'table' => array(
          'openlayers_control_rotate' => 'Display a small icon that indicates the map\'s orientation, it get reset to 0 when clicked.',
          'openlayers_control_zoom' => 'Provides a button, one for zoom in and one for zoom out.',
          'openlayers_control_zoomslider' => 'Provides a slider for zooming.',
          'openlayers_control_zoomtoextent' => 'A button control which, when pressed, changes the map view to a specific extent.',
          'openlayers_interaction_dragpan' => 'Allows the user to pan the map by dragging the map.',
          'openlayers_interaction_dragrotate' => 'Allows the user to rotate the map by clicking and dragging on the map when the [ALT] and [SHIFT] keys are held down. This interaction is only supported for mouse devices.',
          'openlayers_interaction_mousewheelzoom' => 'Allows the user to zoom the map by scrolling the mouse wheel.',
          'openlayers_component_map_edit_form_values' => 'Extract values from the map and fill in the edit form with them.',
          'openlayers_component_map_edit_form_setcenter' => 'Center the map at the location of the mouseclick.',
        ),
      ),
    ),
  );
  $export['openlayers_map_view_edit_form'] = $ol_map;

  $ol_map = new stdClass();
  $ol_map->disabled = TRUE; /* Edit this to true to make a default ol_map disabled initially */
  $ol_map->api_version = 1;
  $ol_map->machine_name = 'openlayers_ui_map_style_demo';
  $ol_map->name = 'Openlayers UI style demo';
  $ol_map->description = '';
  $ol_map->factory_service = 'openlayers.Map:OLMap';
  $ol_map->options = array(
    'width' => '100px',
    'height' => '100px',
    'provideBlock' => 0,
    'provideBlockLayerSwitcher' => 0,
    'contextualLinks' => 0,
    'provideIframe' => 0,
    'view' => array(
      'center' => array(
        'lat' => 0,
        'lon' => 0,
      ),
      'rotation' => 0,
      'zoom' => 2,
      'minZoom' => 0,
      'maxZoom' => 0,
    ),
    'renderer' => 'canvas',
    'layers' => array(
      0 => 'openlayers_ui_layer_style_demo',
    ),
  );
  $export['openlayers_ui_map_style_demo'] = $ol_map;

  return $export;
}
