<?php
/**
 * @file
 * Provide default controls.
 */

/**
 * Implements hook_default_openlayers_controls().
 */
function openlayers_default_openlayers_controls() {
  $export = array();

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_control_attribution';
  $ol_control->name = 'Attribution';
  $ol_control->description = 'Attribution control description';
  $ol_control->factory_service = 'openlayers.Control:Attribution';
  $ol_control->options = array(
    'collapsible' => 1,
  );
  $export['openlayers_control_attribution'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_control_fullscreen';
  $ol_control->name = 'Fullscreen';
  $ol_control->description = 'Fullscreen control description';
  $ol_control->factory_service = 'openlayers.Control:FullScreen';
  $ol_control->options = array();
  $export['openlayers_control_fullscreen'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_control_mouseposition';
  $ol_control->name = 'Mouse position';
  $ol_control->description = 'Mouse position control description';
  $ol_control->factory_service = 'openlayers.Control:MousePosition';
  $ol_control->options = array();
  $export['openlayers_control_mouseposition'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_control_rotate';
  $ol_control->name = 'Rotate';
  $ol_control->description = 'Rotate control description';
  $ol_control->factory_service = 'openlayers.Control:Rotate';
  $ol_control->options = array();
  $export['openlayers_control_rotate'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_control_scaleline';
  $ol_control->name = 'Scaleline';
  $ol_control->description = 'Scaleline control description';
  $ol_control->factory_service = 'openlayers.Control:ScaleLine';
  $ol_control->options = array();
  $export['openlayers_control_scaleline'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_control_zoom';
  $ol_control->name = 'Zoom';
  $ol_control->description = 'Zoom control description';
  $ol_control->factory_service = 'openlayers.Control:Zoom';
  $ol_control->options = array();
  $export['openlayers_control_zoom'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_control_overviewmap';
  $ol_control->name = 'OverviewMap';
  $ol_control->description = 'Create a new control with a map acting as an overview map for an other defined map.';
  $ol_control->factory_service = 'openlayers.Control:OverviewMap';
  $export['openlayers_control_overviewmap'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_control_zoomslider';
  $ol_control->name = 'Zoom slider';
  $ol_control->description = 'Zoom slider control description';
  $ol_control->factory_service = 'openlayers.Control:ZoomSlider';
  $ol_control->options = array();
  $export['openlayers_control_zoomslider'] = $ol_control;

  $ol_control = new stdClass();
  $ol_control->api_version = 1;
  $ol_control->machine_name = 'openlayers_control_zoomtoextent';
  $ol_control->name = 'Zoom to extent';
  $ol_control->description = 'Zoom to extent control description';
  $ol_control->factory_service = 'openlayers.Control:ZoomToExtent';
  $ol_control->options = array();
  $export['openlayers_control_zoomtoextent'] = $ol_control;

  return $export;
}
