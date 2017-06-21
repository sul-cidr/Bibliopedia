<?php
/**
 * @file
 * Component: Bootstap JS Popup.
 */

namespace Drupal\openlayers\Plugins\Component\BootstrapjsPopup;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Types\Component;

/**
 * Class BootstrapjsPopup.
 *
 * @Plugin(
 *  id = "BootstrapjsPopup"
 * )
 *
 */
class BootstrapjsPopup extends Component {

  /**
   * {@inheritdoc}
   */
  public function attached() {
    $attached = parent::attached();
    $attached['libraries_load'][] = array('bootstrapjs');
    return $attached;
  }

  /**
   * {@inheritdoc}
   */
  public function dependencies() {
    return array(
      'bootstrapjs',
    );
  }

}
