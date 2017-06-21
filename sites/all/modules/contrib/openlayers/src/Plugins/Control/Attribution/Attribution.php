<?php
/**
 * @file
 * Control: Attribution.
 */

namespace Drupal\openlayers\Plugins\Control\Attribution;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Types\Control;

/**
 * Class Attribution.
 *
 * @Plugin(
 *  id = "Attribution"
 * )
 *
 */
class Attribution extends Control {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['collapsible'] = array(
      '#type' => 'checkbox',
      '#title' => t('Collapsible'),
      '#default_value' => $this->getOption('collapsible'),
    );
  }

}
