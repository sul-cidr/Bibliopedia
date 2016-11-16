<?php
/**
 * @file
 * Component: MapSwitcher.
 */

namespace Drupal\openlayers_library\Plugin\Component\MapSwitcher;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class MapSwitcher.
 *
 * @OpenlayersPlugin(
 *   id = "MapSwitcher"
 * )
 */
class MapSwitcher extends Component {
  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    parent::postBuild($build, $context);

    $options = array();
    foreach (\Drupal\openlayers\Openlayers::loadAllExportable('Map') as $machine_name => $data) {
      if (!is_object($data) || (property_exists($data, 'disabled') && ($data->disabled == 1 || $data->disabled == TRUE))) {
        continue;
      }
      $options[$machine_name] = $data->name;
    }

    $wrapper = 'wrapper-' . $context->getId();

    $build['openlayers_default_map'] = array(
      '#type' => 'select',
      '#title' => 'Chose a map',
      '#multiple' => FALSE,
      '#options' => $options,
      '#ajax' => array(
        'callback' => '_openlayers_ajax_reload_default_map',
        'method' => 'replace',
        'wrapper' => $wrapper,
        'effect' => 'fade',
      ),
    );

    $build['form'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => $wrapper,
      ),
    );

    $build['form'][$context->getId()]['map'] = $build['map'];
    unset($build['map']);
  }

}
