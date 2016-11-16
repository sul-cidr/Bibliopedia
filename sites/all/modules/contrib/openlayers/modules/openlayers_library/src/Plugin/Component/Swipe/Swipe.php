<?php
/**
 * @file
 * Component: Swipe.
 */

namespace Drupal\openlayers_library\Plugin\Component\Swipe;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Swipe.
 *
 * @OpenlayersPlugin(
 *   id = "Swipe"
 * )
 */
class Swipe extends Component {
  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    $build['parameters'][$this->getPluginId()] = array(
      '#type' => 'fieldset',
      '#title' => 'Example Swipe component',
      'swipe' => array(
        '#type' => 'rangefield',
        '#attributes' => array(
          'id' => 'swipe',
          'style' => 'width: 100%;',
        ),
      ),
    );

    $build['description']['#description'] = 'This example is based on the <a href="http://openlayers.org/en/master/examples/layer-swipe.html">offical swipe example</a>. You need the <em><a href="https://drupal.org/project/elements">elements</a></em> module to get it working properly.';
  }
}
