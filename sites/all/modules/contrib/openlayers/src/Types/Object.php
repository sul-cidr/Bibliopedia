<?php
/**
 * @file
 * Class Object.
 */

namespace Drupal\openlayers\Types;
use Drupal\Component\Plugin\PluginBase;
use Drupal\openlayers\Config;
use Drupal\openlayers\Types\Collection;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Object.
 */
abstract class Object extends PluginBase implements ObjectInterface {

  /**
   * The unique machine name.
   *
   * @var string
   */
  public $machine_name;

  /**
   * The human readable name.
   *
   * @var string
   */
  public $name;

  /**
   * A short description.
   *
   * @var string
   */
  public $description;

  /**
   * @var string
   */
  public $class;

  /**
   * @var array
   */
  public $options = array();

  /**
   * @var string
   */
  public $factory_service = NULL;

  /**
   * @var Collection
   */
  protected $collection;

  /**
   * Holds all the attachment used by this object.
   *
   * @var array
   */
  protected $attached = array(
    'js' => array(),
    'css' => array(),
    'library' => array(),
    'libraries_load' => array(),
  );

  /**
   * {@inheritdoc}
   */
  public function defaultProperties() {
    return array(
      'machine_name' => NULL,
      'name' => NULL,
      'description' => NULL,
      'options' => array(),
      'factory_service' => NULL,
    );
  }

  /**
   * {@inheritdoc}
   */
  public function init(array $data) {
    // Mash the provided configuration with the defaults.
    foreach ($this->defaultProperties() as $property => $value) {
      if (isset($data[$property])) {
        $this->{$property} = $data[$property];
      }
    }

    // If there are options ensure the provided ones overwrite the defaults.
    if (isset($data['options'])) {
      $this->options = array_replace_recursive((array) $this->options, (array) $data['options']);
    }

    // We need to ensure the object has a proper machine name.
    if (empty($this->machine_name)) {
      $this->machine_name = drupal_html_id($this->getType() . '-' . time());
    }
  }

  /**
   * {@inheritdoc}
   *
   * @TODO What is this return? If it is the form, why is form by reference?
   */
  public function optionsForm(&$form, &$form_state) {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormValidate($form, &$form_state) {

  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit($form, &$form_state) {

  }

  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, ObjectInterface $context = NULL) {
    foreach ($this->getCollection()->getFlatList() as $object) {
      if ($object !== $this) {
        $object->preBuild($build, $this);
      }
    }

    drupal_alter('openlayers_object_preprocess', $build, $this);
  }

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    foreach ($this->getCollection()->getFlatList() as $object) {
      if ($object !== $this) {
        $object->postBuild($build, $context);
      }
    }

    drupal_alter('openlayers_object_postprocess', $build, $this);
  }

  /**
   * {@inheritdoc}
   */
  public function build() {

  }

  /**
   * {@inheritdoc}
   */
  public function clearOption($parents) {
    $ref = &$this->options;

    if (is_string($parents)) {
      $parents = array($parents);
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
  }

  /**
   * {@inheritdoc}
   */
  public function setOption($parents, $value = NULL) {
    $ref = &$this->options;

    if (is_string($parents)) {
      $parents = array($parents);
    }

    foreach ($parents as $parent) {
      if (isset($ref) && !is_array($ref)) {
        $ref = array();
      }
      $ref = &$ref[$parent];
    }
    $ref = $value;
  }

  /**
   * {@inheritdoc}
   */
  public function getOption($parents, $default_value = NULL) {
    $options = $this->options;

    if (is_string($parents)) {
      $parents = array($parents);
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

    if (is_null($default_value)) {
      return FALSE;
    }

    return $default_value;
  }

  /**
   * {@inheritdoc}
   */
  public function attached() {
    if ($plugin = $this->getConfiguration()) {
      $path = $this->getClassDirectory();

      $jsdir = $path . '/js';
      $cssdir = $path . '/css';
      if (file_exists($jsdir)) {
        foreach (file_scan_directory($jsdir, '/.*\.js$/') as $file) {
          $this->attached['js'][$file->uri] = array(
            'data' => $file->uri,
            'type' => 'file',
            'group' => Config::get('openlayers.js_css.group'),
            'weight' => Config::get('openlayers.js_css.weight'),
          );
        }
      }
      if (file_exists($cssdir)) {
        foreach (file_scan_directory($cssdir, '/.*\.css$/') as $file) {
          $this->attached['css'][$file->uri] = array(
            'data' => $file->uri,
            'type' => 'file',
            'group' => Config::get('openlayers.js_css.group'),
            'weight' => Config::get('openlayers.js_css.weight'),
          );
        }
      }
    }

    return $this->attached;
  }

  /**
   * Returns an array with the maps this object is attached on.
   *
   * @return array
   *   An array of map objects this object is attached on. Keyed by the map
   *   machine name.
   */
  public function getParents() {
    $maps = ctools_export_crud_load_all('openlayers_maps');
    $parents = array();

    foreach ($maps as $map) {
      $map = openlayers_object_load('map', $map);
      foreach ($map->getCollection()->getFlatList() as $object) {
        if ($object->machine_name == $this->machine_name) {
          $parents[$map->machine_name] = $map;
        }
      }
    }

    return $parents;
  }

  /**
   * {@inheritdoc}
   */
  public function dependencies() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function getConfiguration() {
    return $this->pluginDefinition;
  }

  /**
   * Returns the path to the plugin directory.
   */
  public function getClassDirectory() {
    $class = explode('\\', $this->pluginDefinition['class']);
    return drupal_get_path('module', $class[1]) . '/src/' . implode('/', array_slice($class, 2, -1));
  }

  /**
   * Returns the path to the class file.
   */
  public function getClassPath() {
    $class = explode('\\', $this->pluginDefinition['class']);
    return drupal_get_path('module', $class[1]) . '/src/' . implode('/', array_slice($class, 2)) . '.php';
  }

  /**
   * {@inheritdoc}
   */
  public function isAsynchronous() {
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function getType() {
    $class = explode('\\', get_class($this));
    return $class[3];
  }

  /**
   * Allows to adjust the initially built collection.
   *
   * The collection can be accessed already by calling $this->getCollection().
   */
  protected function buildCollection() {
  }

  /**
   * {@inheritdoc}
   */
  public function getCollection() {
    if (!($this->collection instanceof Collection)) {
      $this->collection = \Drupal::service('openlayers.Types')->createInstance('Collection');
      $this->collection->append($this);
      $this->buildCollection();
    }
    return $this->collection;
  }

  /**
   * {@inheritdoc}
   */
  public function getJS() {
    return array(
      'mn' => $this->machine_name,
      'fs' => $this->factory_service,
      'opt' => $this->options,
    );
  }
}
