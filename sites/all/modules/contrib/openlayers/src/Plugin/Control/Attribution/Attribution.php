<?php
/**
 * @file
 * Control: Attribution.
 */

namespace Drupal\openlayers\Plugin\Control\Attribution;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Control;

/**
 * Class Attribution.
 *
 * @OpenlayersPlugin(
 *  id = "Attribution",
 *  description = "Provides a control to show all the attributions associated with the layer sources in the map."
 * )
 */
class Attribution extends Control {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['collapsible'] = array(
      '#type' => 'checkbox',
      '#title' => t('Collapsible'),
      '#default_value' => $this->getOption('collapsible'),
    );
  }

}
