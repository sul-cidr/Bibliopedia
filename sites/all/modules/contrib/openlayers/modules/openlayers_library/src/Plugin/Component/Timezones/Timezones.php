<?php
/**
 * @file
 * Component: Timezones.
 */

namespace Drupal\openlayers_library\Plugin\Component\Timezones;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Timezones.
 *
 * @OpenlayersPlugin(
 *   id = "Timezones"
 * )
 */
class Timezones extends Component {
  /**
   * {@inheritdoc}
   */
  public function dependencies() {
    return array(
      'bootstrap_library',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function attached() {
    $attached = parent::attached();
    $attached['libraries_load'][] = array('bootstrap');
    return $attached;
  }

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    $build['parameters'][$this->getPluginId()] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'info',
      ),
    );

    $build['description']['#description'] = 'This example is based on the <a href="http://openlayers.org/en/master/examples/kml-timezones.html">offical example</a>. You need the <em><a href="https://drupal.org/project/bootstrap_library">Bootstrap Library</a></em> module to get it working properly.';
  }
}
