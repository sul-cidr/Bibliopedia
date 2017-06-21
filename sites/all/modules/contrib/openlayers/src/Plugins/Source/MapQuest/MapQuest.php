<?php
/**
 * @file
 * Source: Mapquest.
 */

namespace Drupal\openlayers\Plugins\Source\MapQuest;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Types\Source;

/**
 * Class MapQuest.
 *
 * @Plugin(
 *  id = "MapQuest"
 * )
 *
 */
class MapQuest extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $layer_types = array(
      'osm' => 'OpenStreetMap',
      'sat' => 'Satellite',
      'hyb' => 'Hybrid',
    );

    $form['options']['layer'] = array(
      '#title' => t('Source type'),
      '#type' => 'select',
      '#default_value' => $this->getOption('layer', 'osm'),
      '#options' => $layer_types,
    );
  }

}
