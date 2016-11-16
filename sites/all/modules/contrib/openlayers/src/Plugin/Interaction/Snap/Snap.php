<?php

/**
 * @file
 * Interaction: Snap.
 */

namespace Drupal\openlayers\Plugin\Interaction\Snap;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Interaction;

/**
 * Class Snap.
 *
 * @OpenlayersPlugin(
 *  id = "Snap"
 * )
 */
class Snap extends Interaction {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['pixelTolerance'] = array(
      '#type' => 'textfield',
      '#title' => 'Pixel tolerance',
      '#description' => 'Pixel tolerance for considering the pointer close enough to a segment or vertex for editing. Default is 10 pixels.',
      '#default_value' => $this->getOption('pixelTolerance', 10),
    );
    $form['options']['source'] = array(
      '#type' => 'select',
      '#title' => t('Source'),
      '#empty_option' => t('- Select a Source -'),
      '#default_value' => $this->getOption('source', ''),
      '#description' => t('Select the vector source.'),
      '#options' => Openlayers::loadAllAsOptions('Source'),
      '#required' => TRUE,
    );
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    if ($source = $this->getOption('source')) {
      $source = Openlayers::load('source', $source);

      // This source is a dependency of the current one,
      // we need a lighter weight.
      $this->setWeight($source->getWeight() + 1);
      $import = array_merge($source->getCollection()->getFlatList(), $import);
    }

    return $import;
  }
}
