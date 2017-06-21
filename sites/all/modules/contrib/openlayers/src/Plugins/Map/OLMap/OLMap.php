<?php
/**
 * @file
 * Map: Map.
 */

namespace Drupal\openlayers\Plugins\Map\OLMap;

use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Config;
use Drupal\openlayers\Types\Map;

/**
 * Class OLMap.
 *
 * @Plugin(
 *  id = "OLMap"
 * )
 *
 */
class OLMap extends Map {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['ui'] = array(
      '#type' => 'fieldset',
      '#title' => t('User interface'),
      'width' => array(
        '#type' => 'textfield',
        '#title' => 'Width of the map',
        '#default_value' => $this->getOption('width', 'auto'),
        '#parents' => array('options', 'width'),
      ),
      'height' => array(
        '#type' => 'textfield',
        '#title' => t('Height of the map'),
        '#default_value' => $this->getOption('height', '300px'),
        '#parents' => array('options', 'height'),
      ),
    );

    $form['options']['view'] = array(
      '#type' => 'fieldset',
      '#title' => t('Center and rotation'),
      '#tree' => TRUE,
    );

    if ($this->machine_name != Config::get('openlayers.edit_view_map')) {
      $map = openlayers_object_load('Map', Config::get('openlayers.edit_view_map'));
      if ($view = $this->getOption('view')) {
        // Don't apply min / max zoom settings to this map to avoid lock-in.
        $view['minZoom'] = 0;
        $view['maxZoom'] = 0;
        // Same goes for limit extent.
        $view['limit_extent'] = 0;

        $map->setOption('view', $view);
      }

      $form['options']['view']['map'] = array(
        '#type' => 'openlayers',
        '#description' => $map->description,
        '#map' => $map,
      );
    }

    $form['options']['view']['center'] = array(
      '#tree' => TRUE,
      'lat' => array(
        '#type' => 'textfield',
        '#title' => t('Latitude'),
        '#default_value' => $this->getOption(array('view', 'center', 'lat'), 0),
      ),
      'lon' => array(
        '#type' => 'textfield',
        '#title' => t('Longitude'),
        '#default_value' => $this->getOption(array('view', 'center', 'lat'), 0),
      ),
    );
    $form['options']['view']['rotation'] = array(
      '#type' => 'textfield',
      '#title' => t('Rotation'),
      '#default_value' => $this->getOption(array('view', 'rotation'), 0),
    );
    $form['options']['view']['zoom'] = array(
      '#type' => 'textfield',
      '#title' => t('Zoom'),
      '#default_value' => $this->getOption(array('view', 'zoom'), 0),
    );
    $form['options']['view']['minZoom'] = array(
      '#type' => 'textfield',
      '#title' => t('Min zoom'),
      '#default_value' => $this->getOption(array('view', 'minZoom'), 0),
    );
    $form['options']['view']['maxZoom'] = array(
      '#type' => 'textfield',
      '#title' => t('Max zoom'),
      '#default_value' => $this->getOption(array('view', 'maxZoom'), 0),
    );
    $form['options']['view']['limit_extent'] = array(
      '#type' => 'checkbox',
      '#title' => t('Limit to extent'),
      '#description' => t('If enabled navigation on the map is limited to the give extent.'),
      '#default_value' => $this->getOption(array('view', 'limit_extent'), FALSE),
    );
    $form['options']['view']['extent'] = array(
      '#type' => 'textfield',
      '#title' => t('Extent [minx, miny, maxx, maxy]'),
      '#default_value' => $this->getOption(array('view', 'extent'), ''),
      '#states' => array(
        'invisible' => array(
          ':input[name="options[view][limit_extent]"]' => array('checked' => FALSE),
        ),
      ),
    );

    $form['options']['misc'] = array(
      '#type' => 'fieldset',
      '#title' => t('Miscellaneous options'),
    );
    $form['options']['misc']['renderer'] = array(
      '#type' => 'radios',
      '#title' => t('Renderer'),
      '#description' => t('Renderer by default. Canvas, DOM and WebGL renderers are tested for support in that order. Note that at present only the Canvas renderer support vector data.'),
      '#options' => array(
        'canvas' => t('Canvas'),
        'dom' => t('DOM'),
        'webgl' => t('WebGL'),
      ),
      '#default_value' => $this->getOption('renderer', 'canvas'),
      '#parents' => array('options', 'renderer'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function attached() {
    $attached = parent::attached();
    $variant = NULL;
    if (Config::get('openlayers.debug', FALSE) == TRUE) {
      $variant = 'debug';
    };
    $attached['libraries_load']['openlayers3'] = array('openlayers3', $variant);
    return $attached;
  }
}
