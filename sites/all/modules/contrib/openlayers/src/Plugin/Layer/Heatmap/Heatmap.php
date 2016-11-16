<?php
/**
 * @file
 * Layer: Heatmap.
 */

namespace Drupal\openlayers\Plugin\Layer\Heatmap;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Layer;

/**
 * Class Heatmap.
 *
 * @OpenlayersPlugin(
 *  id = "Heatmap"
 * )
 */
class Heatmap extends Layer {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['opacity'] = array(
      '#type' => 'textfield',
      '#description' => 'Opacity (0, 1). Default is 1.',
      '#default_value' => $this->getOption('opacity', 1),
    );
    $form['options']['preload'] = array(
      '#type' => 'textfield',
      '#description' => 'Preload. Load low-resolution tiles up to preload levels. By default preload is 0, which means no preloading.',
      '#default_value' => $this->getOption('preload', 1),
    );
    $form['options']['radius'] = array(
      '#type' => 'textfield',
      '#description' => 'Radius size in pixels. Default is 8.',
      '#default_value' => $this->getOption('radius', 8),
    );
    $form['options']['blur'] = array(
      '#type' => 'textfield',
      '#description' => 'Blur size in pixels. Default is 15.',
      '#default_value' => $this->getOption('blur', 15),
    );
    $form['options']['shadow'] = array(
      '#type' => 'textfield',
      '#description' => 'Shadow size in pixels. Default is 250.',
      '#default_value' => $this->getOption('shadow', 250),
    );
  }

}
