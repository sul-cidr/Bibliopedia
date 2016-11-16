<?php

/**
 * @file
 * Openlayers quicktab plugin.
 */

/**
 * Class for tab content of type "openlayers_map".
 *
 * This is for rendering a map as tab content.
 */
class OpenlayersMap extends QuickContent {

  /**
   * {@inheritdoc}
   */
  public static function getType() {
    return 'Openlayers-map';
  }

  /**
   * {@inheritdoc}
   */
  public function optionsForm($delta, $qt) {
    $tab = $this->settings;
    $form = array();

    $form['Openlayers-map']['map'] = array(
      '#type' => 'select',
      '#title' => t('Openlayers map'),
      '#options' => \Drupal\openlayers\Openlayers::loadAllAsOptions('Map'),
      "#empty_option" => t('- Select a map -'),
      '#default_value' => isset($tab['openlayers_map']) ? $tab['openlayers_map'] : '',
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function render($hide_empty = FALSE, $args = array()) {
    if ($this->rendered_content) {
      return $this->rendered_content;
    }
    $item = $this->settings;

    $output = array(
      '#type' => 'openlayers',
      '#map' => $item['map'],
    );

    $this->rendered_content = $output;
    return $output;
  }

  /**
   * {@inheritdoc}
   */
  public function getAjaxKeys() {
    return array('Openlayers-map');
  }
}
