<?php
/**
 * @file
 * Class Object.
 */

namespace Drupal\openlayers\Types;

use Drupal\Component\Plugin\PluginBase;
use Drupal\openlayers\Config;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Collection;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Object.
 */
abstract class Object extends PluginBase implements ObjectInterface {
  /**
   * A unique ID for the object.
   *
   * @var string
   */
  protected $id;

  /**
   * The array containing the options.
   *
   * @var array
   */
  protected $options = array();

  /**
   * Holds the Collection object.
   *
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
  public function init() {
    $this->options = $this->getOptions();
    $this->setWeight(0);
    return $this->initCollection();
  }

  /**
   * {@inheritdoc}
   */
  public function getOptions() {
    if (!empty($this->options)) {
      return $this->options;
    }
    else {
      $configuration = $this->getConfiguration();
      if (!empty($configuration['options'])) {
        return $configuration['options'];
      }
    }

    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function setOptions(array $options = array()) {
    $this->options = $options;

    // Invalidate the Collection so it gets rebuilt with new options.
    $this->collection = NULL;

    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getConfiguration() {
    return $this->configuration;
  }

  /**
   * {@inheritdoc}
   */
  public function getMachineName() {
    $configuration = $this->getConfiguration();
    if (isset($configuration['machine_name'])) {
      return check_plain($configuration['machine_name']);
    }
    else {
      return 'undefined';
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getName() {
    $configuration = $this->getConfiguration();
    if (isset($configuration['name'])) {
      return check_plain($configuration['name']);
    }
    else {
      return 'undefined';
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getDescription() {
    $configuration = $this->getConfiguration();
    if (isset($configuration['description'])) {
      return check_plain($configuration['description']);
    }
    else {
      return 'undefined';
    }
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
  public function setFactoryService($factory_service) {
    $this->configuration['factory_service'] = $factory_service;

    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getFactoryService() {
    $configuration = $this->getConfiguration();
    if (isset($configuration['factory_service'])) {
      return check_plain($configuration['factory_service']);
    }

    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function initCollection() {
    if (is_null($this->collection) || !($this->collection instanceof Collection)) {
      $this->collection = \Drupal::service('openlayers.Types')
        ->createInstance('Collection');
    }

    $this->getCollection()->import($this->optionsToObjects());
    $this->getCollection()->append($this);

    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getCollection() {
    return $this->collection;
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function addObject(ObjectInterface $object) {
    $this->setOption($object->getType() . 's', $this->getOption($object->getType() . 's', array()) + array($object->getMachineName()));
    $object->setWeight(count($this->getOption($object->getType() . 's', array())) + 2);
    $this->getCollection()->import(array($object));
    return $this;
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

    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getOption($parents, $default_value = NULL) {
    if (is_string($parents)) {
      $parents = array($parents);
    }

    if (is_array($parents)) {
      $notfound = FALSE;

      if (!isset($this->options)) {
        $notfound = TRUE;
        $parents = array();
        $options = array();
      }
      else {
        $options = $this->options;
      }

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
  public function removeObject($object_machine_name) {
    $this->getCollection()->remove($object_machine_name);
    return $this;
  }

  /**
   * {@inheritdoc}
   *
   * @TODO What is this return? If it is the form, why is form by reference?
   */
  public function optionsForm(array &$form, array &$form_state) {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormValidate(array $form, array &$form_state) {
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit(array $form, array &$form_state) {
    if (isset($form_state['values']['options'])) {
      $options = array_merge((array) $this->getOptions(), (array) $form_state['values']['options']);
      $this->setOptions($options);
    }

    $form_state['item'] = $this->getExport();

    // Refresh translatable strings.
    $this->i18nStringsRefresh();
  }

  /**
   * {@inheritdoc}
   */
  public function getExport() {
    $configuration = $this->getConfiguration();
    $options = $this->getOptions();

    $options = Openlayers::array_map_recursive('\Drupal\openlayers\Openlayers::floatval_if_numeric', (array) $options);
    $options = Openlayers::removeEmptyElements((array) $options);
    $configuration['options'] = $options;

    return (object) $configuration;
  }

  /**
   * {@inheritdoc}
   */
  public function i18nStringsRefresh() {
  }

  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, ObjectInterface $context = NULL) {
    foreach ($this->getCollection()->getFlatList() as $object) {
      if ($object !== $this) {
        $object->preBuild($build, $context);
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
  public function resetCollection() {
    $this->collection = NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function attached() {
    if ($plugin = $this->getPluginDefinition()) {
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
            'media' => Config::get('openlayers.js_css.media'),
          );
        }
      }
    }

    return $this->attached;
  }

  /**
   * {@inheritdoc}
   */
  public function getClassDirectory() {
    $class = explode('\\', $this->pluginDefinition['class']);
    return drupal_get_path('module', $this->getProvider()) . '/src/' . implode('/', array_slice($class, 2, -1));
  }

  /**
   * {@inheritdoc}
   */
  public function getProvider() {
    $class = explode('\\', $this->pluginDefinition['class']);
    return $class[1];
  }

  /**
   * {@inheritdoc}
   */
  public function getObjects($type = NULL) {
    return array_values($this->getCollection()->getObjects($type));
  }

  /**
   * {@inheritdoc}
   */
  public function getParents() {
    return array_filter(Openlayers::loadAll('Map'), function ($map) {
      return array_filter($map->getObjects($this->getType()), function ($object) {
        return $object->getMachineName() == $this->getMachineName();
      });
    });
  }

  /**
   * {@inheritdoc}
   */
  public function getType() {
    $class = explode('\\', get_class($this));
    return drupal_strtolower($class[3]);
  }

  /**
   * {@inheritdoc}
   */
  public function getClassPath() {
    $class = explode('\\', $this->pluginDefinition['class']);
    return drupal_get_path('module', $this->getProvider()) . '/src/' . implode('/', array_slice($class, 2)) . '.php';
  }

  /**
   * {@inheritdoc}
   */
  public function getDependencies() {
    $objects = $this->getCollection()->getFlatList();
    unset($objects[$this->getType() . '_' . $this->getMachineName()]);

    return $objects;
  }

  /**
   * {@inheritdoc}
   */
  public function isAsynchronous() {
    return FALSE;
  }

  /**
   * {@inheritdoc}
   *
   * !Attention! This function will remove any option that is named after a
   * plugin type e.g.: layers, controls, styles, interactions, components .
   */
  public function getJS() {
    $export = $this->getExport();

    array_map(function ($type) use ($export) {
      unset($export->options[$type . 's']);
    }, Openlayers::getPluginTypes());

    $js = array(
      'mn' => $export->machine_name,
      'fs' => $export->factory_service,
    );

    if (!empty($export->options)) {
      $js['opt'] = $export->options;
    }

    return $js;
  }

  /**
   * {@inheritdoc}
   */
  public function getWeight() {
    return floatval($this->configuration['weight']);
  }

  /**
   * {@inheritdoc}
   */
  public function setWeight($weight) {
    $this->configuration['weight'] = floatval($weight);
  }

  /**
   * {@inheritdoc}
   */
  public function getPluginDescription() {
    $plugin_definition = $this->getPluginDefinition();
    return isset($plugin_definition['description']) ? $plugin_definition['description'] : '';
  }

  /**
   * {@inheritdoc}
   */
  public function getId() {
    if (!isset($this->id)) {
      $css_name = drupal_clean_css_identifier($this->getType() . '-' . $this->getMachineName());
      // Use uniqid to ensure we've really an unique id - otherwise there will
      // occur issues with caching.
      $this->id = drupal_html_id('openlayers-' . $css_name . '-' . uniqid('', TRUE));
    }

    return $this->id;
  }

  /**
   * {@inheritdoc}
   */
  public function setId($id) {
    $this->id = drupal_html_id(drupal_clean_css_identifier($id));

    return $this;
  }

}
