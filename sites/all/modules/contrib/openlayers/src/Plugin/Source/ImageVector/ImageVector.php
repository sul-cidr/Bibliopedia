<?php
/**
 * @file
 * Source: ImageVector.
 */

namespace Drupal\openlayers\Plugin\Source\ImageVector;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Source;

/**
 * Class ImageVector.
 *
 * @OpenlayersPlugin(
 *  id = "ImageVector"
 * )
 */
class ImageVector extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['source'] = array(
      '#type' => 'select',
      '#title' => t('Source'),
      '#empty_option' => t('- Select a Source -'),
      '#default_value' => isset($form_state['item']->options['source']) ? $form_state['item']->options['source'] : '',
      '#description' => t('Select the source.'),
      '#options' => Openlayers::loadAllAsOptions('Source'),
      '#required' => TRUE,
    );
  }

}
