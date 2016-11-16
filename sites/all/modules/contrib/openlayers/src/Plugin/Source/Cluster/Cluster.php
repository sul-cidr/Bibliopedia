<?php
/**
 * @file
 * Source: Cluster.
 */

namespace Drupal\openlayers\Plugin\Source\Cluster;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Source;

/**
 * Class Cluster.
 *
 * @OpenlayersPlugin(
 *  id = "Cluster"
 * )
 */
class Cluster extends Source {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['source'] = array(
      '#type' => 'select',
      '#title' => t('Source'),
      '#empty_option' => t('- Select a Source -'),
      '#default_value' => $this->getOption('source', ''),
      '#description' => t('Select the source.'),
      '#options' => Openlayers::loadAllAsOptions('Source'),
      '#required' => TRUE,
    );

    $form['options']['distance'] = array(
      '#type' => 'textfield',
      '#title' => t('Cluster distance'),
      '#default_value' => isset($form_state['item']->options['distance']) ? $form_state['item']->options['distance'] : 50,
      '#description' => t('Cluster distance.'),
    );

    $zoomDistance = $this->getOption('zoomDistance', array());
    $zoomDistance = array_map(function($v, $k) {
      return $k . ':' . $v;
    }, $zoomDistance, array_keys($zoomDistance));

    $form['options']['zoomDistance'] = array(
      '#title' => t('Set cluster distance per zoom level'),
      '#description' => t('Define a zoom level / cluster distance per line. Use the notation zoom:distance. If no value is given for a zoom level it falls back to the default distance.'),
      '#type' => 'textarea',
      '#default_value' => implode(PHP_EOL, array_values($zoomDistance)),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit(array $form, array &$form_state) {
    if (!empty($form_state['values']['options']['zoomDistance'])) {
      $zoom_distance = array();
      foreach (explode("\n", $form_state['values']['options']['zoomDistance']) as $data) {
        $data = array_map('trim', explode(':', trim($data), 2));
        if (!empty($data)) {
          $zoom_distance[(int) $data[0]] = (int) (isset($data[1]) ? $data[1] : $data[0]);
        }
      }
      $form_state['values']['options']['zoomDistance'] = $zoom_distance;
    }
    parent::optionsFormSubmit($form, $form_state);
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
