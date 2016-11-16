<?php
/**
 * @file
 * Control: Attribution.
 */

namespace Drupal\openlayers_library\Plugin\Control\AutoZoom;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Plugin\Component\ZoomToSource\ZoomToSource;
use Drupal\openlayers\Types\Control;
use Drupal\openlayers\Types\ControlInterface;

/**
 * Class AutoZoom.
 *
 * @OpenlayersPlugin(
 *  id = "AutoZoom",
 *  description = "Autozoom button"
 * )
 */
class AutoZoom extends ZoomToSource implements ControlInterface {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    parent::optionsForm($form, $form_state);

    unset($form['options']['source']);
  }

}
