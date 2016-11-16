<?php
/**
 * @file
 * Source: TileWMS.
 */

namespace Drupal\openlayers\Plugin\Source\TileWMS;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Source;

/**
 * Class TileWMS.
 *
 * @OpenlayersPlugin(
 *  id = "TileWMS",
 *  description = "Layer source for tile data from WMS servers."
 * )
 */
class TileWMS extends Source {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['url'] = array(
      '#type' => 'textarea',
      '#title' => t('Base URL (template)'),
      '#default_value' => $this->getOption('url') ? implode("\n", (array) $this->getOption('url')) : '',
    );
    $form['options']['wms_layers'] = array(
      '#type' => 'textarea',
      '#title' => t('WMS Layers (comma-separated list)'),
      '#default_value' => $this->getOption('wms_layers') ? $this->getOption('wms_layers') : '',
    );
    $form['options']['version'] = array(
      '#type' => 'textfield',
      '#title' => t('Version'),
      '#description' => t('Leave blank to use the Openlayers default.'),
      '#default_value' => $this->getOption('version') ? $this->getOption('version') : '',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit(array $form, array &$form_state) {
    // If an options array is not set, create it.
    if (!isset($form_state['item']->options)) {
      $form_state['item']->options = array();
    }

    // If the URL is blank, unset it in the options.
    if ($form_state['values']['options']['url'] == '') {
      unset($form_state['item']->options['url']);
    }

    // Create a parameters array if it doesn't already exist.
    if (!isset($form_state['item']->options['params'])) {
      $form_state['item']->options['params'] = array();
    }

    // Copy parameters into the params array.
    $param_keys = array(
      'wms_layers' => 'LAYERS',
      'version' => 'VERSION',
    );
    foreach ($param_keys as $key => $param) {
      if (!empty($form_state['values']['options'][$key])) {
        $form_state['item']->options['params'][$param] = check_plain($form_state['values']['options'][$key]);
      }
    }
  }

}
