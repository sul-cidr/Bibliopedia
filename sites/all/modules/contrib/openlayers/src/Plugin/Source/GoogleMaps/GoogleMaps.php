<?php
/**
 * @file
 * Google maps API integration based on the example here:
 * http://openlayers.org/en/v3.0.0/examples/google-map.html
 * http://bl.ocks.org/elemoine/e82c7dd4b1d0ef45a9a4
 *
 * TODO: https://github.com/mapgears/ol3-google-maps/
 */

namespace Drupal\openlayers\Plugin\Source\GoogleMaps;
use Drupal\openlayers\Types\ObjectInterface;
use Drupal\openlayers\Types\Source;

/**
 * Class GoogleMaps.
 *
 * @OpenlayersPlugin(
 *  id = "GoogleMaps"
 * )
 */
class GoogleMaps extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $layer_types = array(
      'ROADMAP',
      'SATELLITE',
      'HYBRID',
      'TERRAIN',
    );

    $form['options']['key'] = array(
      '#title' => t('Key'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('key', ''),
    );
    $form['options']['client'] = array(
      '#title' => t('Client'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('client', ''),
    );
    $form['options']['channel'] = array(
      '#title' => t('Channel'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('client', ''),
    );
    $form['options']['mapTypeId'] = array(
      '#title' => t('Mapy Type'),
      '#type' => 'select',
      '#default_value' => $this->getOption('mapTypeId', 'ROADMAP'),
      '#options' => array_combine($layer_types, $layer_types),
    );
    $form['options']['sensor'] = array(
      '#title' => t('Sensor'),
      '#type' => 'checkbox',
      '#default_value' => $this->getOption('sensor', FALSE),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $map = NULL) {
    $styles = implode(array_map(function ($key) use ($map) {
      return $key . ':' . $map->getOption($key) . ';';
    }, array('width', 'height')));

    $build['map_suffix']['gmap'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'gmap-' . $map->getId(),
        'class' => array('openlayers', 'gmap-map'),
        'style' => $styles,
      ),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function isAsynchronous() {
    return TRUE;
  }
}
