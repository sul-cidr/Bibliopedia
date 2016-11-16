<?php
/**
 * @file
 * Source: XYZ.
 */

namespace Drupal\openlayers\Plugin\Source\XYZ;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Source;

/**
 * Class XYZ.
 *
 * @OpenlayersPlugin(
 *  id = "XYZ"
 * )
 */
class XYZ extends Source {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['url'] = array(
      '#title' => t('URL(s)'),
      '#type' => 'textarea',
      '#default_value' => $this->getOption('url', ''),
    );
    $form['options']['crossOrigin'] = array(
      '#title' => t('crossOrigin'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('crossOrigin', NULL),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit(array $form, array &$form_state) {
    if ($form_state['values']['options']['url'] == '') {
      unset($form_state['item']->options['url']);
    }
    if ($form_state['values']['options']['crossOrigin'] == '') {
      unset($form_state['item']->options['crossOrigin']);
    }
    parent::optionsFormSubmit($form, $form_state);
  }
}
