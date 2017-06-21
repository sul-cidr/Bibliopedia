<?php
/**
 * @file
 * Component: LazyProcessing.
 */

namespace Drupal\openlayers\Plugins\Component\LazyProcessing;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Types\Component;

/**
 * Class LazyProcessing.
 *
 * @Plugin(
 *  id = "LazyProcessing"
 * )
 *
 */
class LazyProcessing extends Component {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['documentation'] = array(
      '#type' => 'fieldset',
      '#title' => t('How to use'),
      '#description' => t('If this component is attached to a map you need to start the map processing / display manually by executing following code from a custom javascript: <pre>Drupal.openlayers.asyncIsReady("[map_id]");</pre>'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function isAsynchronous() {
    return TRUE;
  }
}
