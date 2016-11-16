<?php
/**
 * @file
 * Source: Random.
 */

namespace Drupal\openlayers_library\Plugin\Source\Random;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Source;

/**
 * Class Random.
 *
 * @OpenlayersPlugin(
 *  id = "Random"
 * )
 */
class Random extends Source {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    foreach (Openlayers::getGeometryTypes() as $geometry_type => $geometry) {
      if (!in_array($geometry_type, array('Point', 'LineString', 'Polygon'))) {
        continue;
      }
      $enabled = (bool) $this->getOption(array($geometry_type, 'count'), FALSE);
      $form['options'][$geometry_type] = array(
        '#type' => 'fieldset',
        '#title' => t('Geometry @geometry', array('@geometry' => $geometry)),
        '#collapsible' => TRUE,
        '#collapsed' => !$enabled,
      );
      $form['options'][$geometry_type]['count'] = array(
        '#type' => 'textfield',
        '#title' => t('Number of features'),
        '#default_value' => $this->getOption(array($geometry_type, 'count'), 0),
        '#required' => TRUE,
      );
      $form['options'][$geometry_type]['setRandomStyle'] = array(
        '#type' => 'checkbox',
        '#title' => t('Set random style on features ?'),
        '#default_value' => $this->getOption(array($geometry_type, 'setRandomStyle'), 0),
      );
      $form['options'][$geometry_type]['styles'] = array(
        '#type' => 'select',
        '#title' => t('Styles'),
        '#empty_option' => t('- Select the Styles -'),
        '#default_value' => $this->getOption(array($geometry_type, 'styles'), array()),
        '#description' => t('Select the styles.'),
        '#options' => Openlayers::loadAllAsOptions('Style'),
        '#multiple' => TRUE,
        '#states' => array(
          'visible' => array(
            'input[name="options[' . $geometry_type . '][setRandomStyle]"' => array('checked' => TRUE),
          ),
        ),
      );
    }
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit(array $form, array &$form_state) {
    parent::optionsFormSubmit($form, $form_state);

    $options = $this->getOptions();
    foreach ($options as $geometry_type => $data) {
      if ($data['setRandomStyle'] != 1) {
        unset($options[$geometry_type]['styles']);
        unset($options[$geometry_type]['setRandomStyle']);
      }
      if ($data['count'] == 0) {
        unset($options[$geometry_type]);
      }
    }

    $this->setOptions($options);
    $form_state['values']['options'] = $options;
    parent::optionsFormSubmit($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    foreach ($this->getOptions() as $geometry_type => $data) {
      if ($styles = $this->getOption(array($geometry_type, 'styles'), array())) {
        foreach ($styles as $style) {
          $style = Openlayers::load('style', $style);

          // This source is a dependency of the current one,
          // we need a lighter weight.
          $this->setWeight($style->getWeight() + 1);
          $import = array_merge($style->getCollection()->getFlatList(), $import);
        }
      }
    }

    return $import;
  }

}
