<?php
/**
 * @file
 * Control: MousePosition.
 */

namespace Drupal\openlayers\Plugin\Control\MousePosition;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Control;

/**
 * Class MousePosition.
 *
 * @OpenlayersPlugin(
 *  id = "MousePosition",
 *  description = "Provides 2D coordinates of the mouse cursor."
 * )
 */
class MousePosition extends Control {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['target'] = array(
      '#type' => 'textfield',
      '#title' => t('ID of the element.'),
      '#default_value' => $this->getOption('target'),
    );
    $form['options']['undefinedHTML'] = array(
      '#type' => 'textfield',
      '#title' => t('undefinedHTML'),
      '#default_value' => $this->getOption('undefinedHTML'),
      '#description' => t('Markup for undefined coordinates. Default is an empty string.'),
    );
  }

}
