<?php
/**
 * @file
 * Source: TileUTFGrid.
 */

namespace Drupal\openlayers\Plugins\Source\TileUTFGrid;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Types\Source;

/**
 * Class TileUTFGrid.
 *
 * @Plugin(
 *  id = "TileUTFGrid"
 * )
 *
 */
class TileUTFGrid extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['url'] = array(
      '#title' => t('URL'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('url'),
    );
  }

}
