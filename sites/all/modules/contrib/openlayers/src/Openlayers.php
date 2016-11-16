<?php
/**
 * @file
 * Contains Openlayers.
 */

namespace Drupal\openlayers;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Openlayers.
 */
class Openlayers {

  /**
   * Gets a list of available plugin types.
   *
   * @param string $object_type
   *   The plugin type.
   *
   * @return array
   *   Openlayers objects types options.
   */
  public static function getOLObjectsOptions($object_type) {
    $options = array();
    $service_basename = 'openlayers.' . $object_type;
    foreach (\Drupal::service($service_basename)->getDefinitions() as $data) {
      $name = isset($data['label']) ? $data['label'] : $data['id'];
      $options[$service_basename . ':' . $data['id']] = $name;
    }
    asort($options);
    return $options;
  }

  /**
   * Gets a list of Openlayers exportable.
   *
   * @param string $type
   *   The plugin .
   *
   * @return array
   *   Openlayers object instance.
   */
  public static function loadAllAsOptions($type = NULL) {
    $options = array();
    $type = drupal_ucfirst(drupal_strtolower($type));
    foreach (Openlayers::loadAllExportable($type) as $machine_name => $data) {
      if (is_object($data)) {
        $options[$machine_name] = $data->name;
      }
    }
    return $options;
  }

  /**
   * Gets all available OL objects.
   *
   * @param string $type
   *   The plugin type.
   *
   * @return array
   *   Array of Openlayers CTools object instances. (stdClass)
   */
  public static function loadAllExportable($type = NULL) {
    ctools_include('export');
    $exports = ctools_export_crud_load_all('openlayers_' . drupal_strtolower(check_plain($type)) . 's');
    uasort($exports, function($a, $b) {
      return strcasecmp($a->name, $b->name);
    });
    return $exports;
  }

  /**
   * Load all objects.
   *
   * @param string $object_type
   *   Type of object to load:
   *   map|layer|source|control|interaction|style|component.
   *
   * @return \Drupal\openlayers\Types\ObjectInterface[]
   *   The array of objects.
   */
  public static function loadAll($object_type = NULL) {
    $objects = array();
    foreach (Openlayers::loadAllExportable($object_type) as $exportable) {
      if (is_object($exportable)) {
        $objects[$exportable->machine_name] = Openlayers::load($object_type, $exportable);
      }
    }
    return $objects;
  }

  /**
   * Create an object instance for an export.
   *
   * @param string $object_type
   *   The object type to look up. See openlayers_object_types() for a list of
   *   available object types.
   * @param array|string|object $export
   *   The exported object.
   *
   * @return ObjectInterface|Error
   *   Returns the instance of the requested object or an instance of
   *   Error on error.
   */
  public static function load($object_type = NULL, $export) {
    /** @var \Drupal\openlayers\Types\ObjectInterface $object */
    $object = NULL;
    $configuration = array();
    $object_type = drupal_ucfirst(drupal_strtolower(check_plain($object_type)));

    if (is_array($export)) {
      $configuration = $export;
    }
    if (is_object($export) && ($export instanceof \StdClass)) {
      $array_object = new \ArrayObject($export);
      $configuration = $array_object->getArrayCopy();
    }
    if (is_object($export) && ($export instanceof ObjectInterface)) {
      return $export;
    }
    if (is_string($export)) {
      $configuration = (array) Openlayers::loadExportable($object_type, $export);
    }

    if (is_array($configuration) && isset($configuration['factory_service'])) {
      // Bail out if the base service can't be found - likely due a registry
      // rebuild.
      if (!\Drupal::hasService('openlayers.Types')) {
        return NULL;
      }
      list($plugin_manager_id, $plugin_id) = explode(':', $configuration['factory_service'], 2);
      if (\Drupal::hasService($plugin_manager_id)) {
        $plugin_manager = \Drupal::service($plugin_manager_id);
        if ($plugin_manager->hasDefinition($plugin_id)) {
          $object = $plugin_manager->createInstance($plugin_id, $configuration);
        }
        else {
          $configuration += array(
            'type' => $object_type,
            'errorMessage' => 'Unable to load @type @machine_name',
          );
          $object = \Drupal::service('openlayers.Types')->createInstance('Error', $configuration);
        }
      }
      else {
        $configuration += array(
          'type' => $object_type,
          'errorMessage' => 'Service <em>@service</em> doesn\'t exists, unable to load @type @machine_name',
        );
        $object = \Drupal::service('openlayers.Types')->createInstance('Error', $configuration);
      }
    }
    else {
      $configuration += array(
        'type' => $object_type,
        'name' => 'Error',
        'description' => 'Error',
        'factory_service' => '',
        'machine_name' => $export,
        'errorMessage' => 'Unable to load CTools exportable @type @machine_name.',
      );
      $object = \Drupal::service('openlayers.Types')->createInstance('Error', $configuration);
    }

    if (isset($configuration['disabled']) && (bool) $configuration['disabled'] == 1) {
      $object->disabled = 1;
    }

    return $object->init();
  }

  /**
   * Load a CTools exportable.
   *
   * @param string $object_type
   *   Type of object to load:
   *   map|layer|source|control|interaction|style|component .
   * @param string $export_id
   *   The exportable id.
   *
   * @return array
   *   The exported object.
   */
  public static function loadExportable($object_type, $export_id) {
    ctools_include('export');
    return ctools_export_crud_load('openlayers_' . drupal_strtolower(check_plain($object_type)) . 's', $export_id);
  }

  /**
   * Save an object in the database.
   *
   * @param ObjectInterface $object
   *   The object to save.
   */
  public static function save(ObjectInterface $object) {
    ctools_include('export');
    $configuration = $object->getConfiguration();
    $export = $object->getExport();
    ctools_export_crud_save($configuration['table'], $export);
  }

  /**
   * Return the list of Openlayers plugins type this module provides.
   *
   * @param array $filter
   *   The values to filter out of the result array.
   *
   * @return string[]
   *   Return an array of strings. Those strings are the plugin type name
   *   in lowercase.
   */
  public static function getPluginTypes(array $filter = array()) {
    $plugins = array();

    foreach (\Drupal::getContainer()->getDefinitions() as $id => $definition) {
      $id = explode(".", drupal_strtolower($id));
      if (count($id) == 2) {
        if ($id[0] == 'openlayers') {
          if (isset($definition['tags']) && (0 === strpos($definition['tags'][0]['plugin_manager_definition']['directory'], 'Plugin/'))) {
            $plugins[$id[1]] = $id[1];
          }
        }
      }
    }

    asort($plugins);

    return array_udiff(array_values($plugins), $filter, 'strcasecmp');
  }

  /**
   * Return information about the Openlayers 3 if installed.
   *
   * @return array|false
   *   Return an array from hook_libraries_info() if the library is found,
   *   otherwise return False.
   */
  public static function getLibrary() {
    return libraries_detect('openlayers3');
  }

  /**
   * Return the version of the Openlayers library in use.
   *
   * @return string
   *   Return the version of the Openlayers library set in the configuration.
   */
  public static function getLibraryVersion() {
    $variant = \Drupal\openlayers\Config::get('openlayers.variant');

    if (strpos($variant, 'local-') !== FALSE) {
      $version = self::getLocalLibraryVersion();
    }
    else {
      $version = \Drupal\openlayers\Config::get('openlayers.variant', NULL);
    }

    return $version;
  }

  /**
   * Return the version of the Openlayers library in use.
   *
   * @return string
   *   Return the version of the Openlayers library in the filesystem.
   */
  public static function getLocalLibraryVersion() {
    $version = FALSE;
    if ($path = libraries_get_path('openlayers3')) {
      $library = libraries_detect('openlayers3');
      $options = array(
        'file' => 'build/ol.js',
        'pattern' => '@Version: (.*)@',
        'lines' => 3,
      );
      $library['library path'] = $path;
      if ($version = libraries_get_version($library, $options)) {
        $version = substr($version, 1);
      }
    }

    return $version;
  }

  /**
   * Apply a function recursively to all the value of an array.
   *
   * @param callable $func
   *   Function to call.
   * @param array $arr
   *   The array to process.
   *
   * @return array
   *   The processed array
   */
  public static function array_map_recursive($func, array $arr) {
    /*
    // This is the PHP Version >= 5.5
    // $func must be a callable.
    array_walk_recursive($arr, function(&$v) use ($func) {
      $v = $func($v);
    });
    return $arr;
    */
    foreach ($arr as $key => $value) {
      if (is_array($arr[$key])) {
        $arr[$key] = self::array_map_recursive($func, $arr[$key]);
      }
      else {
        $arr[$key] = call_user_func($func, $arr[$key]);
      }
    }
    return $arr;
  }

  /**
   * Ensures a value is of type float or integer if it is a numeric value.
   *
   * @param mixed $var
   *   The value to type cast if possible.
   *
   * @return float|mixed
   *   The variable - casted to type float if possible.
   */
  public static function floatval_if_numeric($var) {
    if (is_numeric($var)) {
      return is_float($var + 0) ? floatval($var) : intval($var);
    }
    return $var;
  }

  /**
   * Recursively removes empty values from an array.
   *
   * Empty means empty($value) AND not 0.
   *
   * @param array $array
   *   The array to clean.
   *
   * @return array
   *   The cleaned array.
   */
  public static function removeEmptyElements(array $array) {
    foreach ($array as $key => $value) {
      if ($value === '' && $value !== 0) {
        unset($array[$key]);
      }
      elseif (is_array($value)) {
        $array[$key] = self::removeEmptyElements($value);
      }
    }

    return $array;
  }

  /**
   * Returns an array with positioning options.
   *
   * @return string[]
   *   Array with positioning options.
   */
  public static function positioningOptions() {
    return array(
      'bottom-left' => t('bottom-left'),
      'bottom-center' => t('bottom-center'),
      'bottom-right' => t('bottom-right'),
      'center-left' => t('center-left'),
      'center-center' => t('center-center'),
      'center-right' => t('center-right'),
      'top-left' => t('top-left'),
      'top-center' => t('top-center'),
      'top-right' => t('top-right'),
    );
  }

  /**
   * The list of geometries available.
   *
   * @return string[]
   *   The list of geometries.
   */
  public static function getGeometryTypes() {
    return array(
      'Point' => t('Point'),
      'MultiPoint' => t('MultiPoint'),
      'LineString' => t('LineString'),
      'LinearRing' => t('LinearRing'),
      'MultiLineString' => t('MultiLineString'),
      'Polygon' => t('Polygon'),
      'MultiPolygon' => t('MultiPolygon'),
      'GeometryCollection' => t('GeometryCollection'),
      'Circle' => t('Circle'),
    );
  }

  /**
   * Returns the list of files libraries or js/css files needed according to
   * the settings.
   *
   * @return array
   */
  public static function getAttached() {
    $attached = array();

    $attached['libraries_load'] = array(
      'openlayers3' => array('openlayers3', Config::get('openlayers.variant', NULL)),
    );

    if (Config::get('openlayers.debug', FALSE)) {
      $attached['libraries_load']['openlayers3_integration'] = array('openlayers3_integration', 'debug');
    };

    return $attached;
  }

}
