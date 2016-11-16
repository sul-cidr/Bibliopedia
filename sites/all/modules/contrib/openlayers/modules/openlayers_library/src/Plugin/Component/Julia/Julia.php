<?php
/**
 * @file
 * Component: Julia.
 */

namespace Drupal\openlayers_library\Plugin\Component\Julia;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Julia.
 *
 * @OpenlayersPlugin(
 *   id = "Julia"
 * )
 */
class Julia extends Component {
  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    $build = array(
      'map' => $build,
      'Julia' => array(
        '#type' => 'fieldset',
        '#title' => 'Common fractal parameters',
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        'fractaltype' => array(
          '#type' => 'select',
          '#title' => 'Type of fractal',
          '#description' => t(''),
          '#options' => array(
            'julia' => 'Julia',
            'mandelbrot' => 'Mandelbrot'
          ),
          '#value' => 'mandelbrot',
          '#default_value' => 'mandelbrot',
          '#attributes' => array(
            'id' => 'fractaltype',
          ),
        ),
        'resolution' => array(
          '#type' => 'rangefield',
          '#title' => 'Resolution',
          '#description' => t('Size of a point. Default is 25. Higher values means more calculation.'),
          '#min' => 0,
          '#max' => 49,
          '#step' => 1,
          '#value' => 40,
          '#attributes' => array(
            'id' => 'resolution',
            'style' => 'width: 100%;',
          ),
        ),
        'iterations' => array(
          '#type' => 'rangefield',
          '#title' => 'Iterations',
          '#description' => 'Value of iterations. Default is 32. Higher values means more calculation.',
          '#min' => 1,
          '#max' => 128,
          '#step' => 1,
          '#value' => 64,
          '#attributes' => array(
            'id' => 'iterations',
            'style' => 'width: 100%;',
          ),
        ),
        'mandelbroot' => array(
          '#type' => 'fieldset',
          '#collapsible' => TRUE,
          '#collapsed' => TRUE,
          '#title' => 'Mandelbroot set options',
          'fractalmode' => array(
            '#type' => 'select',
            '#title' => 'Fractal mode',
            '#description' => t('Draw the inside of the fractal or the outside ?'),
            '#options' => array(
              'in' => 'Draw inside',
              'out' => 'Draw outside'
            ),
            '#value' => 'out',
            '#default_value' => 'out',
            '#attributes' => array(
              'id' => 'fractalmode',
            ),
          ),
        ),
        'julia' => array(
          '#type' => 'fieldset',
          '#collapsible' => TRUE,
          '#collapsed' => TRUE,
          '#title' => 'Julia set options',
          'initialvaluex' => array(
            '#type' => 'numberfield',
            '#title' => 'Initial value of Rc',
            '#description' => t('In the equation <em>F<sub>c</sub>(z) = z<sup>2</sup> + c</em>, <em>Rc</em> is the real part of <em>c</em>'),
            '#step' => 0.01,
            '#value' => 0.5,
            '#default_value' => 0.5,
            '#attributes' => array(
              'id' => 'initialvaluex',
            ),
          ),
          'initialvaluei' => array(
            '#type' => 'numberfield',
            '#title' => 'Initial value of Ri',
            '#description' => t('In the equation <em>F<sub>c</sub>(z) = z<sup>2</sup> + c</em>, <em>Ic</em> is the imaginary part of <em>c</em>'),
            '#step' => 0.01,
            '#value' => 0.5,
            '#default_value' => 0.5,
            '#attributes' => array(
              'id' => 'initialvaluei',
            ),
          ),
        ),
      ),
    );
  }
}
