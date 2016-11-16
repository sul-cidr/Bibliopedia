<?php
/**
 * @file
 * Default styles.
 */

/**
 * Implements hook_default_openlayers_styles().
 */
function openlayers_examples_default_openlayers_styles() {
  $export = array();

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_style_icon_marker';
  $ol_style->name = 'Openlayers examples: Icon marker';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Icon';
  $ol_style->options = array(
    'path' => '/sites/all/modules/openlayers/modules/openlayers_examples/assets/marker-icon.png',
    'scale' => 1,
    'anchor' => array(
      0 => 0.5,
      1 => 1,
    ),
  );
  $export['openlayers_examples_style_icon_marker'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_style_green';
  $ol_style->name = 'Openlayers examples: Green marker';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Circle';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'radius' => 5,
        'fill' => array(
          'color' => '0, 255, 0, 0.4',
        ),
        'stroke' => array(
          'color' => '0, 255, 0, 1',
          'width' => 1.25,
          'lineDash' => '0,0',
        ),
      ),
      'stroke' => array(
        'color' => '0, 255, 0, 1',
        'width' => 1.25,
        'lineDash' => '0,0',
      ),
      'fill' => array(
        'color' => '0, 255, 0, 0.4',
      ),
    ),
  );
  $export['openlayers_examples_style_green'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_style_red';
  $ol_style->name = 'Openlayers examples: Red marker';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Circle';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'radius' => 5,
        'fill' => array(
          'color' => '255, 0, 0, 0.4',
        ),
        'stroke' => array(
          'color' => '255, 0, 0, 1',
          'width' => 1.25,
          'lineDash' => '0,0',
        ),
      ),
      'stroke' => array(
        'color' => '255, 0, 0, 1',
        'width' => 1.25,
        'lineDash' => '0,0',
      ),
      'fill' => array(
        'color' => '255, 0, 0, 0.4',
      ),
    ),
  );
  $export['openlayers_examples_style_red'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_style_blue';
  $ol_style->name = 'Openlayers examples: Blue marker';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Circle';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'radius' => 5,
        'fill' => array(
          'color' => '0, 0, 255, 0.4',
        ),
        'stroke' => array(
          'color' => '0, 0, 255, 1',
          'width' => 1.25,
          'lineDash' => '0,0',
        ),
      ),
      'stroke' => array(
        'color' => '0, 0, 255, 1',
        'width' => 1.25,
        'lineDash' => '0,0',
      ),
      'fill' => array(
        'color' => '0, 0, 255, 0.4',
      ),
    ),
  );
  $export['openlayers_examples_style_blue'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_style_cluster';
  $ol_style->name = 'Openlayers examples: Cluster';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Cluster';
  $ol_style->options = array();
  $export['openlayers_examples_style_cluster'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_style_timezones';
  $ol_style->name = 'Openlayers examples: Timezones';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:Timezones';
  $ol_style->options = array();
  $export['openlayers_examples_style_timezones'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_style_regularshape_square';
  $ol_style->name = 'Openlayers examples: Square';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:RegularShape';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'points' => 4,
        'radius' => 10,
        'angle' => 45,
        'rotation' => 0,
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
  $export['openlayers_examples_style_regularshape_square'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_style_regularshape_star';
  $ol_style->name = 'Openlayers examples: Star';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:RegularShape';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'points' => 5,
        'radius' => 10,
        'radius2' => 4,
        'angle' => 0,
        'rotation' => 0,
        'fill' => array(
          'color' => '255,255,255,1',
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
  $export['openlayers_examples_style_regularshape_star'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_style_regularshape_triangle';
  $ol_style->name = 'Openlayers examples: Triangle';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:RegularShape';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'points' => 3,
        'radius' => 10,
        'angle' => 0,
        'rotation' => 60,
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
  $export['openlayers_examples_style_regularshape_triangle'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_style_regularshape_cross';
  $ol_style->name = 'Openlayers examples: Cross';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:RegularShape';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'points' => 4,
        'radius' => 10,
        'radius1' => 0,
        'radius2' => 0,
        'angle' => 45,
        'rotation' => 0,
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
  $export['openlayers_examples_style_regularshape_cross'] = $ol_style;

  $ol_style = new stdClass();
  $ol_style->disabled = FALSE; /* Edit this to true to make a default ol_style disabled initially */
  $ol_style->api_version = 1;
  $ol_style->machine_name = 'openlayers_examples_style_regularshape_plus';
  $ol_style->name = 'Openlayers examples: Plus';
  $ol_style->description = '';
  $ol_style->factory_service = 'openlayers.Style:RegularShape';
  $ol_style->options = array(
    'default' => array(
      'image' => array(
        'points' => 4,
        'radius' => 10,
        'radius1' => 0,
        'radius2' => 0,
        'angle' => 0,
        'rotation' => 0,
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
  $export['openlayers_examples_style_regularshape_plus'] = $ol_style;

  return $export;
}

/**
 * Implements hook_default_openlayers_styles_alter().
 */
function openlayers_examples_default_openlayers_styles_alter(&$exports) {
  $exports['openlayers_examples_style_icon_marker']->options['path'] = file_create_url(drupal_get_path('module', 'openlayers_examples') . '/assets/marker-icon.png');
}
