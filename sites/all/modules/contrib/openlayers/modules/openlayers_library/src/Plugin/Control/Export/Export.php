<?php
/**
 * @file
 * Control: Attribution.
 */

namespace Drupal\openlayers_library\Plugin\Control\Export;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Control;

/**
 * Class Export.
 *
 * @OpenlayersPlugin(
 *  id = "Export",
 *  description = "Export button"
 * )
 */
class Export extends Control {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['exportTipLabel'] = array(
      '#type' => 'textfield',
      '#title' => 'Label',
      '#default_value' => $this->getOption('exportTipLabel', 'Export as image'),
    );
  }
}
