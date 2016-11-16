<?php
/**
 * @file
 * Component: ProgressBar.
 */

namespace Drupal\openlayers_library\Plugin\Component\ProgressBar;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class ProgressBar.
 *
 * @OpenlayersPlugin(
 *   id = "ProgressBar",
 *   description = "Display a loading bar on the bottom of the map when the layers are loading."
 * )
 */
class ProgressBar extends Component {
  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    $build['map_suffix'][$this->getPluginId()] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'progress-' . $context->getId(),
        'class' => array(
          'openlayers-progressbar',
        ),
      ),
    );
  }

}
