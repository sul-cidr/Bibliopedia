<?php
/**
 * @file
 * Provide default interactions.
 */

/**
 * Implements hook_default_openlayers_interactions().
 */
function openlayers_default_openlayers_interactions() {
  $export = array();

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_doubleclickzoom';
  $ol_interaction->name = 'DoubleClickZoom';
  $ol_interaction->description = 'DoubleClickZoom interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:DoubleClickZoom';
  $ol_interaction->options = array();
  $export['openlayers_interaction_doubleclickzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_draganddrop';
  $ol_interaction->name = 'DragAndDrop';
  $ol_interaction->description = 'DragAndDrop interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:DragAndDrop';
  $ol_interaction->options = array();
  $export['openlayers_interaction_draganddrop'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_dragbox';
  $ol_interaction->name = 'DragBox';
  $ol_interaction->description = 'DragBox interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:DragBox';
  $ol_interaction->options = array();
  $export['openlayers_interaction_dragbox'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_dragpan';
  $ol_interaction->name = 'DragPan';
  $ol_interaction->description = 'DragPan interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:DragPan';
  $ol_interaction->options = array(
    'decay' => -0.005,
    'minVelocity' => 0.05,
    'delay' => 100,
  );
  $export['openlayers_interaction_dragpan'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_dragrotate';
  $ol_interaction->name = 'DragRotate';
  $ol_interaction->description = 'DragRotate interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:DragRotate';
  $ol_interaction->options = array();
  $export['openlayers_interaction_dragrotate'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_dragrotateandzoom';
  $ol_interaction->name = 'DragRotateAndZoom';
  $ol_interaction->description = 'DragRotateAndZoom interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:DragRotateAndZoom';
  $ol_interaction->options = array();
  $export['openlayers_interaction_dragrotateandzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_dragzoom';
  $ol_interaction->name = 'DragZoom';
  $ol_interaction->description = 'DragZoom interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:DragZoom';
  $ol_interaction->options = array();
  $export['openlayers_interaction_dragzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_draw';
  $ol_interaction->name = 'Draw';
  $ol_interaction->description = 'Draw interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:Draw';
  $ol_interaction->options = array();
  $export['openlayers_interaction_draw'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_keyboardpan';
  $ol_interaction->name = 'KeyboardPan';
  $ol_interaction->description = 'KeyboardPan interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:KeyboardPan';
  $ol_interaction->options = array();
  $export['openlayers_interaction_keyboardpan'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_keyboardzoom';
  $ol_interaction->name = 'KeyboardZoom';
  $ol_interaction->description = 'KeyboardZoom interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:KeyboardZoom';
  $ol_interaction->options = array();
  $export['openlayers_interaction_keyboardzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_modify';
  $ol_interaction->name = 'Modify';
  $ol_interaction->description = 'Modify interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:Modify';
  $ol_interaction->options = array();
  $export['openlayers_interaction_modify'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_mousewheelzoom';
  $ol_interaction->name = 'MouseWheelZoom';
  $ol_interaction->description = 'MouseWheelZoom interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:MouseWheelZoom';
  $ol_interaction->options = array();
  $export['openlayers_interaction_mousewheelzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_pinchrotate';
  $ol_interaction->name = 'PinchRotate';
  $ol_interaction->description = 'PinchRotate interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:PinchRotate';
  $ol_interaction->options = array();
  $export['openlayers_interaction_pinchrotate'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_pinchzoom';
  $ol_interaction->name = 'PinchZoom';
  $ol_interaction->description = 'PinchZoom interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:PinchZoom';
  $ol_interaction->options = array();
  $export['openlayers_interaction_pinchzoom'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_pointer';
  $ol_interaction->name = 'Pointer';
  $ol_interaction->description = 'Pointer interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:Pointer';
  $ol_interaction->options = array();
  $export['openlayers_interaction_pointer'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_select';
  $ol_interaction->name = 'Select';
  $ol_interaction->description = 'Select interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:Select';
  $ol_interaction->options = array(
    'style' => 'openlayers_style_select',
  );
  $export['openlayers_interaction_select'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_snap';
  $ol_interaction->name = 'Snap';
  $ol_interaction->description = 'Snap interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:Snap';
  $ol_interaction->options = array();
  $export['openlayers_interaction_snap'] = $ol_interaction;

  $ol_interaction = new stdClass();
  $ol_interaction->disabled = FALSE;
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_interaction_translate';
  $ol_interaction->name = 'Translate';
  $ol_interaction->description = 'Translate interaction description';
  $ol_interaction->factory_service = 'openlayers.Interaction:Translate';
  $ol_interaction->options = array();
  $export['openlayers_interaction_translate'] = $ol_interaction;

  return $export;
}
