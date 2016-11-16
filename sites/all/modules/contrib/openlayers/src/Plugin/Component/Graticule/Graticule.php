<?php
/**
 * @file
 * Component: Graticule.
 */

namespace Drupal\openlayers\Plugin\Component\Graticule;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Component;

/**
 * Class Graticule.
 *
 * @OpenlayersPlugin(
 *  id = "Graticule"
 * )
 */
class Graticule extends Component {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['rgba'] = array(
      '#type' => 'textfield',
      '#title' => t('RGBA'),
      '#default_value' => $this->getOption('rgba', '0, 0, 0, 0.2'),
      '#description' => t('RGBA, a string of 4 numbers, separated by a comma.'),
    );
    $form['options']['width'] = array(
      '#type' => 'textfield',
      '#title' => t('Width'),
      '#default_value' => $this->getOption('width', 2),
      '#description' => t('Width'),
    );
    $form['options']['lineDash'] = array(
      '#type' => 'textfield',
      '#title' => t('Line dash'),
      '#default_value' => $this->getOption('lineDash', '0.5, 4'),
      '#description' => t('Line dash, a string of 2 numbers, separated by a comma.'),
    );
  }

}
