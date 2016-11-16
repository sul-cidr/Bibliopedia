<?php
/**
 * @file
 * Component: IconSprites.
 */

namespace Drupal\openlayers_library\Plugin\Component\IconSprites;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class IconSprites.
 *
 * @OpenlayersPlugin(
 *   id = "IconSprites"
 * )
 */
class IconSprites extends Component {
  /**
   * {@inheritdoc}
   */
  public function getJS() {
    $js = parent::getJS();
    $js['opt']['url'] = file_create_url(drupal_get_path('module', 'openlayers_examples') . '/assets/Butterfly.png');

    return $js;
  }
}
