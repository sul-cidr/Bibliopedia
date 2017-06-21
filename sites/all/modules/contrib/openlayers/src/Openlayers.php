<?php
/**
 * @file
 * Contains Openlayers
 */

use Drupal\service_container\DependencyInjection\CachedContainerBuilder;
use Drupal\service_container\DependencyInjection\ServiceProviderPluginManager;

/**
 * Static Service Container wrapper.
 *
 * Generally, code in Drupal should accept its dependencies via either
 * constructor injection or setter method injection. However, there are cases,
 * particularly in legacy procedural code, where that is infeasible. This
 * class acts as a unified global accessor to arbitrary services within the
 * system in order to ease the transition from procedural code to injected OO
 * code.
 */
class Openlayers extends ServiceContainer {

  /**
   * Gets an instance of the currently active container object.
   *
   * @param string $service
   *   The service to get an object from.
   * @param array $plugin
   *   The plugin definition.
   *
   * @return object
   *   Openlayers object instance.
   */
  public static function getOLObject($service, $plugin) {
    return static::$container->get('openlayers.' . $service)->createInstance($plugin);
  }

  /**
   * Gets a list of available plugin types.
   *
   * @param string $plugin
   *   The plugin .
   *
   * @return array
   *   Openlayers object instance.
   */
  public static function getOLObjectsOptions($plugin) {
    $options = array('' => t('<Choose the @plugin type>', array('@plugin' => $plugin)));
    $service_basename = 'openlayers.' . $plugin;
    foreach (\Drupal::service($service_basename)->getDefinitions() as $service => $data) {
      $name = isset($data['label']) ? $data['label'] : $data['id'];
      $options[$service_basename . ':' . $data['id']] = $name;
    }
    return $options;
  }

}
