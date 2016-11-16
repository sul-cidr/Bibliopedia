<?php
/**
 * @file
 * Component: Debug.
 */

namespace Drupal\openlayers\Plugin\Component\Debug;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Debug.
 *
 * @OpenlayersPlugin(
 *  id = "Debug"
 * )
 */
class Debug extends Component {
  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    $alternative_template = 'openlayers--' . str_replace('_', '-', $context->getMachineName()) . '.tpl.php';

    $build['parameters'][$this->getPluginId()] = array(
      '#type' => 'fieldset',
      '#title' => 'Map debug',
      '#description' => 'Here\'s a quick view of all the objects in the map.',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      'theme' => array(
        '#weight' => 20,
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#title' => 'Theming information',
        'template_content' => array(
          '#title' => 'Openlayers map template',
          '#type' => 'textarea',
          '#default_value' => file_get_contents(drupal_get_path('module', 'openlayers') . '/theme/openlayers.tpl.php'),
          '#description' => t('The default Openlayers template is <strong>openlayers.tpl.php</strong> for all the maps. You may override it by creating a file with the same name in your theme template\'s directory. You can also name it <em>openlayers--[map_machine_name].tpl.php</em> if you want to alter the display of this particular map only. For example: <strong>@template</strong>.', array('@template' => $alternative_template)),
        ),
      ),
    );

    foreach ($context->getCollection()->getObjects() as $type => $objects) {
      $build['parameters'][$this->getPluginId()][$type] = array(
        '#type' => 'fieldset',
        '#title' => 'Plugin type: ' . $type,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );

      foreach ($objects as $object) {
        $build['parameters'][$this->getPluginId()][$type][$object->getMachineName()] = array(
          '#type' => 'fieldset',
          '#collapsible' => TRUE,
          '#collapsed' => TRUE,
          '#title' => $object->getMachineName(),
          'configuration' => $this->getInfo($object),
        );
      }
    }
  }

  /**
   * Return the markup for a table.
   *
   * @param array $data
   *   The values of the table.
   *
   * @return string
   *   The HTML.
   */
  protected function toInfoArrayMarkup($data) {
    $rows = array();
    foreach ($data as $name => $value) {
      if (is_array($value)) {
        $value = $this->toInfoArrayMarkup($value);
      }
      else {
        $value = htmlspecialchars($value);
      }

      $rows[] = array(
        'data' => array(
          '<code>' . $name . '</code>',
          '<code>' . $value . '</code>',
        ),
        'no_striping' => TRUE,
      );
    }

    $table = array(
      '#type' => 'table',
      '#rows' => $rows,
    );

    return drupal_render($table);
  }

  /**
   * Array containing basic information about an OL Object.
   *
   * @param \Drupal\openlayers\Types\ObjectInterface $object
   * @return array
   */
  protected function getInfo(ObjectInterface $object) {
    $js = $object->getJS();

    $info = array(
      'mn' => array(
        '#type' => 'item',
        '#title' => 'Machine name:',
        '#markup' => $object->getMachineName(),
      ),
      'fs' => array(
        '#type' => 'item',
        '#title' => 'Factory service:',
        '#markup' => $object->getFactoryService(),
      ),
    );

    $plugin_description = $object->getPluginDescription();
    if (!empty($plugin_description)) {
      $info['pd'] = array(
        '#type' => 'item',
        '#title' => 'Plugin description:',
        '#markup' => $plugin_description,
      );
    }

    if (isset($js['opt'])) {
      $info['opt'] = array(
        '#type' => 'item',
        '#title' => 'Options:',
        'options' => array(
          '#markup' => $this->toInfoArrayMarkup($js['opt']),
        )
      );
    }

    return $info;
  }
}
