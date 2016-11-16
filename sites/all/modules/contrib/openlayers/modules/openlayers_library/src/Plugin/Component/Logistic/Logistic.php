<?php
/**
 * @file
 * Component: Logistic.
 */

namespace Drupal\openlayers_library\Plugin\Component\Logistic;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Logistic.
 *
 * @OpenlayersPlugin(
 *   id = "Logistic"
 * )
 */
class Logistic extends Component {
  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    $build['parameters'][$this->getPluginId()] = array(
      '#type' => 'fieldset',
      '#title' => 'Logistic map parameters',
      'intro' => array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#title' => 'About',
        'info' => array(
          '#markup' => '<p>Bifurcation diagram of the logistic map. The attractor for any value of the parameter <em>r</em> is shown on the vertical line at that <em>r</em>.</p><p>The bifurcation parameter <em>r</em> is shown on the horizontal axis of the plot and the vertical axis shows the possible long-term population values of the logistic function. More info on <a href="https://en.wikipedia.org/wiki/Bifurcation_diagram">Wikipedia</a>.</p><p>Formula: <em>x<sub>n+1</sub> = rx<sub>n</sub>(1-x<sub>n</sub>)</em></p><p>In this plot, <em>r</em> values are on X-axis, <em>Lim<sub>1 &#8594; n</sub>(x<sub>n+1</sub> = rx<sub>n</sub>(1-x<sub>n</sub>))</em> are on Y-axis.</p>',
        ),
      ),
      'start' => array(
        '#type' => 'rangefield',
        '#title' => 'Start (Lowest value of <em>r</em>)',
        '#description' => t('From -2 to 4. Default is 2.'),
        '#min' => -2,
        '#max' => 4,
        '#step' => 0.1,
        '#value' => 2,
        '#attributes' => array(
          'id' => 'start',
          'style' => 'width: 100%;',
        ),
      ),
      'end' => array(
        '#type' => 'rangefield',
        '#title' => 'End (Highest value of <em>r</em>)',
        '#description' => t('From -2 to 4. Default is 4.'),
        '#min' => -2,
        '#max' => 4,
        '#step' => 0.1,
        '#value' => 4,
        '#attributes' => array(
          'id' => 'end',
          'style' => 'width: 100%;',
        ),
      ),
      'initial' => array(
        '#type' => 'rangefield',
        '#title' => t('Initial value of <em>x</em>'),
        '#description' => t('From 0 to 1. Default is 0.5.'),
        '#min' => 0,
        '#max' => 1,
        '#step' => 0.01,
        '#value' => 0.5,
        '#attributes' => array(
          'id' => 'initial',
          'style' => 'width: 100%;',
        ),
      ),
      'iterations' => array(
        '#type' => 'rangefield',
        '#title' => 'Iterations',
        '#description' => 'Value of <em>n</em>. Default is 200.',
        '#min' => 10,
        '#max' => 1000,
        '#step' => 10,
        '#value' => 200,
        '#attributes' => array(
          'id' => 'iterations',
          'style' => 'width: 100%;',
        ),
      ),
      'density' => array(
        '#type' => 'rangefield',
        '#title' => 'Step',
        '#description' => 'On each loop, <em>r</em> increase by this <em>value<sup>-1</sup></em>. Default is 500.',
        '#min' => 10,
        '#max' => 1000,
        '#step' => 10,
        '#value' => 500,
        '#attributes' => array(
          'id' => 'density',
          'style' => 'width: 100%;',
        ),
      ),
    );

  }
}
