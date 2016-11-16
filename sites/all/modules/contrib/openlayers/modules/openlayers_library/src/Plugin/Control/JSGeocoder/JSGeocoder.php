<?php
/**
 * @file
 * Control: JSGeocoder.
 */

namespace Drupal\openlayers_library\Plugin\Control\JSGeocoder;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Control;

/**
 * Class JSGeocoder.
 *
 * @OpenlayersPlugin(
 *  id = "JSGeocoder",
 *  description = "JSGeocoder input to geocode addresses to coordinates using Google services."
 * )
 */
class JSGeocoder extends Control {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['placeholder'] = array(
      '#type' => 'textfield',
      '#title' => 'Placeholder',
      '#default_value' => $this->getOption('placeholder', 'Search with Google...'),
    );
    $form['options']['loadingPlaceholder'] = array(
      '#type' => 'textfield',
      '#title' => 'Placeholder to display while loading the Google libraries',
      '#default_value' => $this->getOption('loadingPlaceholder', 'Loading the Google awesomeness...'),
    );
    $form['options']['size'] = array(
      '#type' => 'textfield',
      '#title' => 'Size of the textbox',
      '#default_value' => $this->getOption('size', 25),
    );
    $form['options']['autocomplete'] = array(
      '#type' => 'checkbox',
      '#title' => 'Autocomplete the text input when a result is found ?',
      '#default_value' => $this->getOption('autocomplete', FALSE),
    );
    $form['options']['timeout'] = array(
      '#type' => 'textfield',
      '#title' => 'Debounce timeout',
      '#default_value' => $this->getOption('timeout', 500),
      '#description' => 'Time in milliseconds before the input is submitted to Google.',
    );
    $form['options']['zoom'] = array(
      '#type' => 'textfield',
      '#title' => 'Zoom to apply in when a result is found ?',
      '#default_value' => $this->getOption('zoom', '0'),
      '#description' => 'Zoom to set the map to when Google return a successful result. 0 to disable.',
    );
  }
}
