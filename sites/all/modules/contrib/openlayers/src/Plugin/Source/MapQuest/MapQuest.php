<?php
/**
 * @file
 * Source: Mapquest.
 */

namespace Drupal\openlayers\Plugin\Source\MapQuest;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Source;

/**
 * Class MapQuest.
 *
 * @OpenlayersPlugin(
 *  id = "MapQuest"
 * )
 */
class MapQuest extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
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
