<?php
/**
 * @file
 * Style: Icon.
 */

namespace Drupal\openlayers\Plugin\Style\Icon;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Style;

/**
 * Class Icon.
 *
 * @OpenlayersPlugin(
 *  id = "Icon"
 * )
 */
class Icon extends Style {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['path'] = array(
      '#type' => 'textfield',
      '#title' => 'Path',
      '#default_value' => $this->getOption('path', ''),
    );
    $form['options']['scale'] = array(
      '#type' => 'textfield',
      '#title' => 'Path',
      '#default_value' => $this->getOption('scale', ''),
    );
    $form['options']['anchor']['x'] = array(
      '#type' => 'textfield',
      '#title' => 'Anchor X',
      '#default_value' => $this->getOption(array('anchor', 'x'), 0.5),
    );
    $form['options']['anchor']['y'] = array(
      '#type' => 'textfield',
      '#title' => 'Anchor Y',
      '#default_value' => $this->getOption(array('anchor', 'y'), 0.5),
    );
  }

}
