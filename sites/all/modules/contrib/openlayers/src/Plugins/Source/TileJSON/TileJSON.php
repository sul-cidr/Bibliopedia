<?php
/**
 * @file
 * Source: TileJson.
 */

namespace Drupal\openlayers\Plugins\Source\TileJSON;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Types\Source;

/**
 * Class TileJSON.
 *
 * @Plugin(
 *  id = "TileJSON"
 * )
 *
 */
class TileJSON extends Source {

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
