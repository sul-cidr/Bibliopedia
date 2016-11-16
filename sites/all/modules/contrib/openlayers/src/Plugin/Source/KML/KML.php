<?php
/**
 * @file
 * Source: KML.
 */

namespace Drupal\openlayers\Plugin\Source\KML;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Source;

/**
 * Class KML.
 *
 * @OpenlayersPlugin(
 *  id = "KML"
 * )
 */
class KML extends Source {

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
