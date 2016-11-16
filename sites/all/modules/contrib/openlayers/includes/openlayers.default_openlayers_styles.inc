<?php
/**
 * @file
 * Provide default styles.
 */

/**
 * Implements hook_default_openlayers_styles().
 */
function openlayers_default_openlayers_styles() {
  $export = array();

  $ol_style = new stdClass();
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_style_default';
  $ol_style->name = 'Openlayers: Default';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Circle';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'radius' => 5,
        'fill' => array(
          'color' => '255,255,255,0.4',
        ),
        'stroke' => array(
          'color' => '51,153,204,1',
          'width' => 1.25,
          'lineDash' => '0,0',
        ),
      ),
      'stroke' => array(
        'color' => '51,153,204,1',
        'width' => 1.25,
        'lineDash' => '0,0',
      ),
      'fill' => array(
        'color' => '51,153,204,1',
      ),
    ),
  );
  $export['openlayers_style_default'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_style_select';
  $ol_style->name = 'Openlayers: Default select';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Circle';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'radius' => 5,
        'fill' => array(
          'color' => '51,153,204,0.7',
        ),
        'stroke' => array(
          'color' => '51,153,204,1',
          'width' => 3,
          'lineDash' => '0,0',
        ),
      ),
      'stroke' => array(
        'color' => '51,153,204,1',
        'width' => 3,
        'lineDash' => '0,0',
      ),
      'fill' => array(
        'color' => '51,153,204,0.7',
      ),
    ),
  );
  $export['openlayers_style_select'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_style_drag';
  $ol_style->name = 'Openlayers: Default drag';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Circle';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'radius' => 5,
        'fill' => array(
          'color' => '255,0,0,0.7',
        ),
        'stroke' => array(
          'color' => '255,0,0,1',
          'width' => 3,
          'lineDash' => '0,0',
        ),
      ),
      'stroke' => array(
        'color' => '255,0,0,1',
        'width' => 3,
        'lineDash' => '0,0',
      ),
      'fill' => array(
        'color' => '255,0,0,0.7',
      ),
    ),
  );
  $export['openlayers_style_drag'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_style_invisible';
  $ol_style->name = 'Openlayers: Invisible';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Invisible';
  $export['openlayers_style_invisible'] = $ol_style;

  return $export;
}
