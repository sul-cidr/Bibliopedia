<?php
/**
 * @file
 * Component: SpinJS.
 * Author: http://fgnass.github.io/spin.js/
 */

namespace Drupal\openlayers_library\Plugin\Component\SpinJS;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class SpinJS.
 *
 * @OpenlayersPlugin(
 *   id = "SpinJS",
 *   description = "Provides a JS Spinner when the map is loading."
 * )
 */
class SpinJS extends Component {
  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, ObjectInterface $context = NULL) {
    $build['spinjs']['#attached']['js'][] = array(
      'data' => array(
        'spinjs' => array(
          $context->getId() => $this->getOptions(),
        ),
      ),
      'type' => 'setting',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['lines'] = array(
      '#type' => 'textfield',
      '#title' => 'Lines',
      '#description' => 'The number of lines to draw',
      '#default_value' => $this->getOption('lines', 12),
    );
    $form['options']['length'] = array(
      '#type' => 'textfield',
      '#title' => 'Length',
      '#description' => 'The length of each line',
      '#default_value' => $this->getOption('length', 7),
    );
    $form['options']['width'] = array(
      '#type' => 'textfield',
      '#title' => 'Width',
      '#description' => 'The line thickness',
      '#default_value' => $this->getOption('width', 5),
    );
    $form['options']['radius'] = array(
      '#type' => 'textfield',
      '#title' => 'Radius',
      '#description' => 'The radius of the inner circle',
      '#default_value' => $this->getOption('radius', 10),
    );
    $form['options']['scale'] = array(
      '#type' => 'textfield',
      '#title' => 'Scale',
      '#description' => 'Scales overall size of the spinner',
      '#default_value' => $this->getOption('scale', 1.0),
    );
    $form['options']['corners'] = array(
      '#type' => 'textfield',
      '#title' => 'Corners',
      '#description' => 'Corner roundness (0..1)',
      '#default_value' => $this->getOption('corners', 1),
    );
    $form['options']['color'] = array(
      '#type' => 'textfield',
      '#title' => 'Color',
      '#description' => '#rgb or #rrggbb',
      '#default_value' => $this->getOption('color', '#000'),
    );
    $form['options']['opacity'] = array(
      '#type' => 'textfield',
      '#title' => 'Opacity',
      '#description' => 'Opacity',
      '#default_value' => $this->getOption('opacity', 0.25),
    );
    $form['options']['rotate'] = array(
      '#type' => 'textfield',
      '#title' => 'Rotate',
      '#description' => 'Rotation offset',
      '#default_value' => $this->getOption('rotate', 0),
    );
    $form['options']['direction'] = array(
      '#type' => 'textfield',
      '#title' => 'Direction',
      '#description' => '1: clockwise, -1: counterclockwise',
      '#default_value' => $this->getOption('direction', 1),
    );
    $form['options']['speed'] = array(
      '#type' => 'textfield',
      '#title' => 'Speed',
      '#description' => 'Rounds per second',
      '#default_value' => $this->getOption('speed', 1),
    );
    $form['options']['trail'] = array(
      '#type' => 'textfield',
      '#title' => 'Trail',
      '#description' => 'Afterglow percentage',
      '#default_value' => $this->getOption('trail', 100),
    );
    $form['options']['fps'] = array(
      '#type' => 'textfield',
      '#title' => 'FPS',
      '#description' => 'Frames per second when using setTimeout()',
      '#default_value' => $this->getOption('fps', 20),
    );
    $form['options']['zIndex'] = array(
      '#type' => 'textfield',
      '#title' => 'z-index',
      '#description' => 'Use a high z-index by default',
      '#default_value' => $this->getOption('zIndex', 0),
    );
    $form['options']['className'] = array(
      '#type' => 'textfield',
      '#title' => 'Classname',
      '#description' => 'Use a high z-index by default',
      '#default_value' => $this->getOption('className', 'spinner'),
    );
    $form['options']['top'] = array(
      '#type' => 'textfield',
      '#title' => 'Top',
      '#description' => 'Center vertically',
      '#default_value' => $this->getOption('top', '50%'),
    );
    $form['options']['left'] = array(
      '#type' => 'textfield',
      '#title' => 'Left',
      '#description' => 'Center horizontally',
      '#default_value' => $this->getOption('left', '50%'),
    );
    $form['options']['shadow'] = array(
      '#type' => 'checkbox',
      '#title' => 'Shadow',
      '#description' => 'Whether to render a shadow',
      '#default_value' => $this->getOption('shadow', FALSE),
    );
    $form['options']['hwaccel'] = array(
      '#type' => 'checkbox',
      '#title' => 'Hardware acceleration',
      '#description' => 'Whether to use hardware acceleration (might be buggy)',
      '#default_value' => $this->getOption('hwaccel', FALSE),
    );
    $form['options']['position'] = array(
      '#type' => 'textfield',
      '#title' => 'Position',
      '#description' => 'Element positioning',
      '#default_value' => $this->getOption('position', 'absolute'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit(array $form, array &$form_state) {
    $form_state['values']['options']['shadow'] = (bool) $form_state['values']['options']['shadow'];
    $form_state['values']['options']['hwaccel'] = (bool) $form_state['values']['options']['hwaccel'];
    parent::optionsFormSubmit($form, $form_state);
  }

}
