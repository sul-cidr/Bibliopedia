<?php
/**
 * @file
 * Source: ImageVector.
 */

namespace Drupal\openlayers\Plugins\Source\ImageVector;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Types\Source;

/**
 * Class ImageVector.
 *
 * @Plugin(
 *  id = "ImageVector"
 * )
 *
 */
class ImageVector extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['source'] = array(
      '#type' => 'select',
      '#title' => t('Source'),
      '#default_value' => isset($form_state['item']->options['source']) ? $form_state['item']->options['source'] : '',
      '#description' => t('Select the source.'),
      '#options' => openlayers_source_options(),
      '#required' => TRUE,
    );
  }
}
