<?php
/**
 * @file
 * Source: TileDebug.
 */

namespace Drupal\openlayers\Plugins\Source\TileDebug;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Types\Source;

/**
 * Class TileDebug.
 *
 * @Plugin(
 *  id = "TileDebug"
 * )
 *
 */
class TileDebug extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['maxZoom'] = array(
      '#title' => t('Maxzoom'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('maxZoom', 22),
    );
  }

}
