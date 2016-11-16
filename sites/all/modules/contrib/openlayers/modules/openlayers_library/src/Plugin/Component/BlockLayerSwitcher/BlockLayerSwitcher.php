<?php
/**
 * @file
 * Component: Block Layer Switcher.
 */

namespace Drupal\openlayers_library\Plugin\Component\BlockLayerSwitcher;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\MapInterface;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class BlockLayerSwitcher.
 *
 * @OpenlayersPlugin(
 *   id = "BlockLayerSwitcher"
 * )
 */
class BlockLayerSwitcher extends Component {

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    if ($context instanceof MapInterface) {
      $olebs_blockswitcher_form = drupal_get_form('olebs_blockswitcher_form', $context);
      // This can rely in the id of the map instead of the css class.
      $olebs_blockswitcher_form['map']['#value'] = $context->getId();
      $build['parameters'][$this->getPluginId()] = array(
        '#type' => 'fieldset',
        '#title' => 'Layer Switcher',
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        'form' => $olebs_blockswitcher_form,
      );
    }
  }

}
