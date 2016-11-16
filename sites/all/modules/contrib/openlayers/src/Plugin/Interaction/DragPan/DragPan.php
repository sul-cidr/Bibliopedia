<?php
/**
 * @file
 * Interaction: DragPan.
 */

namespace Drupal\openlayers\Plugin\Interaction\DragPan;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Interaction;

/**
 * Class DragPan.
 *
 * @OpenlayersPlugin(
 *  id = "DragPan",
 *  description = "Allows the user to pan the map by dragging the map."
 * )
 */
class DragPan extends Interaction {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['decay'] = array(
      '#type' => 'textfield',
      '#title' => t('Decay'),
      '#default_value' => $this->getOption('decay', -0.005),
      '#description' => t('Rate of decay (must be negative).'),
    );
    $form['options']['minVelocity'] = array(
      '#type' => 'textfield',
      '#title' => t('Minimum velocity'),
      '#default_value' => $this->getOption('minVelocity', 0.05),
      '#description' => t('Minimum velocity (pixels/millisecond).'),
    );
    $form['options']['delay'] = array(
      '#type' => 'textfield',
      '#title' => t('Delay'),
      '#default_value' => $this->getOption('delay', 100),
      '#description' => t('Delay to consider to calculate the kinetic.'),
    );
  }

}
