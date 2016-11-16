<?php

/**
 * @file
 * Openlayers boxes plugin.
 */

/**
 * Class openlayers
 */
class openlayers extends boxes_box {
  /**
   * {@inheritdoc}
   */
  public function options_defaults() {
    return array(
      'map' => '',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form_state) {
    $form = array();

    // Map objects.
    $form['map'] = array(
      '#type' => 'select',
      '#title' => t('Openlayers map'),
      '#description' => t('Map to display.'),
      '#options' => \Drupal\openlayers\Openlayers::loadAllAsOptions('Map'),
      "#empty_option" => t('- Select a Map -'),
      // Todo: fix this.
      '#default_value' => $this->options['map'] ?
        $this->options['map'] : variable_get('openlayers_default_map', 'default'),
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function render() {
    $title = isset($this->title) ? check_plain($this->title) : NULL;

    $render = array(
      '#type' => 'openlayers',
      '#map' => $this->options['map'],
    );

    return array(
      'delta' => $this->delta,
      'title' => $title,
      'subject' => $title,
      'content' => drupal_render($render),
    );
  }

}
