<?php
/**
 * @file
 * Source: TileUTFGrid.
 */

namespace Drupal\openlayers\Plugin\Source\TileUTFGrid;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Source;

/**
 * Class TileUTFGrid.
 *
 * @OpenlayersPlugin(
 *  id = "TileUTFGrid"
 * )
 */
class TileUTFGrid extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['url'] = array(
      '#title' => t('URL'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('url'),
    );
  }

}
