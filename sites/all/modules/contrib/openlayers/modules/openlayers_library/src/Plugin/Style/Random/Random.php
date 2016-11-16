<?php
/**
 * @file
 * Style: Random.
 */

namespace Drupal\openlayers_library\Plugin\Style\Random;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Style;

/**
 * Class Random.
 *
 * @OpenlayersPlugin(
 *  id = "Random"
 * )
 */
class Random extends Style {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['style'] = array(
      '#type' => 'select',
      '#title' => t('Styles'),
      '#empty_option' => t('- Select the Styles -'),
      '#default_value' => $this->getOption('style', array()),
      '#description' => t('Select the source.'),
      '#options' => Openlayers::loadAllAsOptions('Style'),
      '#required' => TRUE,
      '#multiple' => TRUE,
    );
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    if ($styles = $this->getOption('style', array())) {
      foreach ($styles as $style) {
        $style = Openlayers::load('style', $style);

        // This source is a dependency of the current one,
        // we need a lighter weight.
        $this->setWeight($style->getWeight() + 1);
        $import = array_merge($style->getCollection()->getFlatList(), $import);
      }
    }

    return $import;
  }
}
