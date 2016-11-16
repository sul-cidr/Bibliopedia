<?php
/**
 * @file
 * Class openlayers_config.
 */

namespace Drupal\openlayers;

/**
 * Class openlayers_config.
 */
class Config {

  /**
   * Get default configuration.
   *
   * @param string $key
   *   Key to get. If not provided, returns the full array.
   *
   * @return array|null
   *   Returns the array or if a key is provided, it's value.
   */
  static protected function defaults($key = NULL) {
    $defaults = array(
      'openlayers.js_css.group' => 'openlayers',
      'openlayers.js_css.weight' => 20,
      'openlayers.js_css.media' => 'screen',
      'openlayers.edit_view_map' => 'openlayers_map_view_edit_form',
      'openlayers.default_ui_map' => 'openlayers_map_ui_default',
      'openlayers.variant' => 'local:3.11.2',
      'openlayers.debug' => 0,
    );
    if ($key == NULL) {
      return $defaults;
    }

    return isset($defaults[$key]) ? $defaults[$key] : NULL;
  }

  /**
   * Fetches a configuration value.
   *
   * @param string|array $parents
   *   The path to the configuration value. Strings use dots as path separator.
   * @param string|array $default_value
   *   The default value to use if the config value isn't set.
   *
   * @return mixed
   *   The configuration value.
   */
  static public function get($parents, $default_value = NULL) {
    $options = \Drupal::service('variable')->get('openlayers_config');

    if (is_string($parents)) {
      $parents = explode('.', $parents);
    }

    if (is_array($parents)) {
      $notfound = FALSE;
      foreach ($parents as $parent) {
        if (isset($options[$parent])) {
          $options = $options[$parent];
        }
        else {
          $notfound = TRUE;
          break;
        }
      }
      if (!$notfound) {
        return $options;
      }
    }

    if ($value = Config::defaults(implode('.', $parents))) {
      return $value;
    }

    if (is_null($default_value)) {
      return FALSE;
    }

    return $default_value;
  }

  /**
   * Sets a configuration value.
   *
   * @param string|array $parents
   *   The path to the configuration value. Strings use dots as path separator.
   * @param mixed $value
   *   The  value to set.
   *
   * @return array
   *   The configuration array.
   */
  static public function set($parents, $value) {
    $config = \Drupal::service('variable')->get('openlayers_config', array());

    if (is_string($parents)) {
      $parents = explode('.', $parents);
    }

    $ref = &$config;
    foreach ($parents as $parent) {
      if (isset($ref) && !is_array($ref)) {
        $ref = array();
      }
      $ref = &$ref[$parent];
    }
    $ref = $value;

    \Drupal::service('variable')->set('openlayers_config', $config);
    return $config;
  }

  /**
   * Removes a configuration value.
   *
   * @param string|array $parents
   *   The path to the configuration value. Strings use dots as path separator.
   *
   * @return array
   *   The configuration array.
   */
  static public function clear($parents) {
    $config = \Drupal::service('variable')->get('openlayers_config', array());
    $ref = &$config;

    if (is_string($parents)) {
      $parents = explode('.', $parents);
    }

    $last = end($parents);
    reset($parents);
    foreach ($parents as $parent) {
      if (isset($ref) && !is_array($ref)) {
        $ref = array();
      }
      if ($last == $parent) {
        unset($ref[$parent]);
      }
      else {
        if (isset($ref[$parent])) {
          $ref = &$ref[$parent];
        }
        else {
          break;
        }
      }
    }
    \Drupal::service('variable')->set('openlayers_config', $config);
    return $config;
  }

}
