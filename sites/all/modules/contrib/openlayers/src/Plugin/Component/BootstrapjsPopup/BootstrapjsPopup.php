<?php
/**
 * @file
 * Component: Bootstap JS Popup.
 */

namespace Drupal\openlayers\Plugin\Component\BootstrapjsPopup;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Component;

/**
 * Class BootstrapjsPopup.
 *
 * @OpenlayersPlugin(
 *  id = "BootstrapjsPopup"
 * )
 */
class BootstrapjsPopup extends Component {

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
  public function dependencies() {
    return array(
      'bootstrap_library',
    );
  }

}
