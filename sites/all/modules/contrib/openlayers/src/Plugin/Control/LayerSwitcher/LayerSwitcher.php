<?php
/**
 * @file
 * Control: LayerSwitcher.
 *
 * Proof of concept based on http://geocre.github.io/ol3/layerswitcher.html .
 */

namespace Drupal\openlayers\Plugin\Control\LayerSwitcher;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Control;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class LayerSwitcher.
 *
 * @OpenlayersPlugin(
 *  id = "LayerSwitcher",
 *  description = "Provides a layer switcher control."
 * )
 */
class LayerSwitcher extends Control {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['label'] = array(
      '#type' => 'textfield',
      '#title' => t('Title of the control'),
      '#default_value' => $this->getOption('label', 'Layers'),
    );
    $form['options']['layers'] = array(
      '#type' => 'select',
      '#title' => t('Layers'),
      '#empty_option' => t('- Select a Layer -'),
      '#multiple' => TRUE,
      '#default_value' => $this->getOption('layers'),
      '#options' => Openlayers::loadAllAsOptions('Layer'),
    );
    $form['options']['multiselect'] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow selecting multiple layers'),
      '#default_value' => $this->getOption('multiselect', FALSE),
    );

    $form['options']['layer_labels_hint'] = array(
      '#markup' => t('You need to save the configuration before being able to set custom layer labels.'),
    );

    $labels = $this->getOption('layer_labels', array());
    foreach ((array) $this->getOption('layers') as $i => $machine_name) {
      if (($map_layer = Openlayers::load('Layer', $machine_name)) == TRUE) {
        $label = check_plain($map_layer->getName());
        if (isset($labels[$machine_name])) {
          $label = $labels[$machine_name];
        }
        $form['options']['layer_labels'][$machine_name] = array(
          '#type' => 'textfield',
          '#title' => t('Label for layer @label:', array('@label' => $map_layer->getName())),
          '#default_value' => $label,
        );
      }
    }
    // @TODO Add configuration for initial visibility. (Adjust JS accordingly)
    // @TODO Add configuration for ordering?
  }

  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, ObjectInterface $context = NULL) {
    $map_id = $context->getId();
    $layers = $this->getOption('layers', array());
    $items = array();
    $map_layers = $context->getObjects('layer');

    $element_type = ($this->getOption('multiselect', FALSE)) ? 'checkbox' : 'radio';

    // Only handle layers available in the map and configured in the control.
    // @TODO: use Form API (with form_process_* and stuff)
    $labels = $this->getOption('layer_labels', array());
    foreach ($map_layers as $i => $map_layer) {
      if (isset($layers[$map_layer->getMachineName()])) {
        $classes = array(drupal_html_class($map_layer->getMachineName()));
        $checked = '';
        if ($element_type == 'checkbox') {
          if ($map_layer->getOption('visible', 1)) {
            $checked = 'checked ';
            $classes[] = 'active';
          }
        }
        $label = $map_layer->getName();
        if (isset($labels[$map_layer->getMachineName()])) {
          $label = openlayers_i18n_string('openlayers:layerswitcher:' . $this->getMachineName() . ':' . $map_layer->getMachineName() . ':label', $labels[$map_layer->getMachineName()], array('sanitize' => TRUE));
        }
        $items[] = array(
          'data' => '<label><input type="' . $element_type . '" name="layer" ' . $checked . 'value="' . $map_layer->getMachineName() . '">' . $label . '</label>',
          'id' => drupal_html_id($map_id . '-' . $map_layer->getMachineName()),
          'class' => $classes,
        );
      }
    }

    $title = openlayers_i18n_string('openlayers:layerswitcher:' . $this->getMachineName() . ':title', $this->getOption('label', 'Layers'), array('sanitize' => TRUE));
    $layerswitcher = array(
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#title' => $title,
      '#items' => $items,
      '#attributes' => array(
        'id' => drupal_html_id($this->getMachineName() . '-items'),
      ),
    );
    $this->setOption('element', '<div id="' . drupal_html_id($this->getMachineName()) . '" class="' . drupal_html_class($this->getMachineName()) . ' layerswitcher">' . drupal_render($layerswitcher) . '</div>');

    // Allow the parent class to perform it's pre-build actions.
    parent::preBuild($build, $context);
  }

  /**
   * {@inheritdoc}
   */
  public function i18nStringsRefresh() {
    // Ensure just labels of active layers are stored.
    $labels = $this->getOption('layer_labels', array());
    $layers = $this->getOption('layers', array());
    $existing_layers = array_intersect_key($labels, $layers);
    $removed_layers = array_diff_key($layers, $labels);
    // Handle translatable values.
    // Remove / register string translations.
    foreach ($removed_layers as $layer) {
      openlayers_i18n_string_remove('openlayers:layerswitcher:' . $this->getMachineName() . ':' . $layer . ':label');
    }
    foreach ($existing_layers as $layer => $label) {
      openlayers_i18n_string_update('openlayers:layerswitcher:' . $this->getMachineName() . ':' . $layer . ':label', $label);
    }
    // Register string in i18n string if possible.
    openlayers_i18n_string_update('openlayers:layerswitcher:' . $this->getMachineName() . ':title', $this->getOption('label', 'Layers'));
  }
}
