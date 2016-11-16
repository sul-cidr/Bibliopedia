<?php
/**
 * @file
 * Source: TileJson.
 */

namespace Drupal\openlayers\Plugin\Source\TileJSON;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Source;

/**
 * Class TileJSON.
 *
 * @OpenlayersPlugin(
 *  id = "TileJSON"
 * )
 */
class TileJSON extends Source {

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
