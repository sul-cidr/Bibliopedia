<?php
/**
 * @file
 * Component: Popup.
 */

namespace Drupal\openlayers\Plugins\Component\Popup;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Types\Component;

/**
 * Class Popup.
 *
 * @Plugin(
 *  id = "Popup"
 * )
 */
class Popup extends Component {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['layers'] = array(
      '#type' => 'select',
      '#title' => t('Layers'),
      '#default_value' => isset($form_state['item']->options['layers']) ? $form_state['item']->options['layers'] : '',
      '#description' => t('Select the layers.'),
      '#options' => openlayers_layer_options(),
      '#required' => TRUE,
      '#multiple' => TRUE,
    );
    $form['options']['positioning'] = array(
      '#type' => 'select',
      '#title' => t('Positioning'),
      '#default_value' => isset($form_state['item']->options['positioning']) ? $form_state['item']->options['positioning'] : 'top-left',
      '#description' => t('Defines how the overlay is actually positioned. Default is top-left.'),
      '#options' => openlayers_positioning_options(),
      '#required' => TRUE,
    );
    $form['options']['autoPan'] = array(
      '#type' => 'checkbox',
      '#title' => t('Autopan'),
      '#description' => t('If set to true the map is panned when calling setPosition, so that the overlay is entirely visible in the current viewport. The default is false.'),
      '#default_value' => $this->getOption('autoPan', FALSE),
    );
    $form['options']['autoPanAnimation'] = array(
      '#type' => 'textfield',
      '#title' => t('Autopan animation duration'),
      '#default_value' => $this->getOption('autoPanAnimation', 1000),
      '#description' => t('The options used to create a ol.animation.pan animation. This animation is only used when autoPan is enabled. By default the default options for ol.animation.pan are used. If set to zero the panning is not animated. The duration of the animation is in milliseconds. Default is 1000.'),
    );
    $form['options']['autoPanMargin'] = array(
      '#type' => 'textfield',
      '#title' => t('Autopan Animation'),
      '#default_value' => $this->getOption('autoPanMargin', 20),
      '#description' => t('The margin (in pixels) between the overlay and the borders of the map when autopanning. The default is 20.'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit($form, &$form_state) {
    $form_state['values']['options']['autoPan'] = (bool) $form_state['values']['options']['autoPan'];
  }


  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, \Drupal\openlayers\Types\ObjectInterface $context = NULL) {
    $layers = $this->getOption('layers', array());
    $map_layers = $context->getLayers();
    // Only handle layers available in the map and configured in the control.
    // Ensures maximum performance on client side while having maximum
    // configuration flexibility.
    $frontend_layers = array();
    foreach ($map_layers as $map_layer) {
      if (isset($layers[$map_layer->machine_name])) {
        $frontend_layers[$map_layer->machine_name] = $map_layer->machine_name;
      }
    }
    $this->setOption('layers', $frontend_layers);
  }
}
