<?php
/**
 * @file
 * Interface ObjectInterface.
 */

namespace Drupal\openlayers\Types;

use Drupal\Component\Plugin\PluginInspectionInterface;

/**
 * Interface openlayers_object_interface.
 */
interface ObjectInterface extends PluginInspectionInterface {
  /**
   * Initializes the object.
   */
  public function init();

  /**
   * Initializes the Collection,
   * Import objects from options,
   * Import the current object.
   */
  public function initCollection();

  /**
   * The type of this object.
   *
   * @return string|FALSE
   *   The object type or FALSE on failure.
   */
  public function getType();

  /**
   * Remove an option.
   *
   * @param string|array $parents
   *   The option to remove.
   *   This can be a string or an array of parents keys if the option
   *   is in a multilevel array.
   */
  public function clearOption($parents);

  /**
   * Return the options array.
   *
   * @return array
   *   The array of options.
   */
  public function getOptions();

  /**
   * Set the options array.
   *
   * @param array $options
   *   The options array.
   *
   * @return ObjectInterface
   *   The current object.
   */
  public function setOptions(array $options = array());

  /**
   * Returns an option.
   *
   * @param string|array $parents
   *   TODO Define how this has to look like if it is an array.
   * @param mixed $default_value
   *   The default value to return if the option isn't set. Set to NULL if not
   *   defined.
   *
   * @return mixed
   *   The value of the option or the defined default value.
   */
  public function getOption($parents, $default_value = NULL);

  /**
   * Set an option.
   *
   * @param string|array $parents
   *   TODO: Define how this has to look like if it is an array.
   * @param mixed $value
   *   The value to set.
   *
   * @return ObjectInterface
   *   The current object.
   */
  public function setOption($parents, $value = NULL);

  /**
   * Reset the object's Collection.
   */
  public function resetCollection();

  /**
   * Provides the options form to configure this object.
   *
   * @param array $form
   *   The form array by reference.
   * @param array $form_state
   *   The form_state array by reference.
   */
  public function optionsForm(array &$form, array &$form_state);

  /**
   * Validation callback for the options form.
   *
   * @param array $form
   *   The form array.
   * @param array $form_state
   *   The form_state array by reference.
   */
  public function optionsFormValidate(array $form, array &$form_state);

  /**
   * Submit callback for the options form.
   *
   * @param array $form
   *   The form array.
   * @param array $form_state
   *   The form_state array by reference.
   */
  public function optionsFormSubmit(array $form, array &$form_state);

  /**
   * Returns a list of attachments for building the render array.
   *
   * @return array
   *   The attachments to add.
   */
  public function attached();

  /**
   * Defines dependencies.
   *
   * TODO Define how this has to look like.
   *
   * @return array
   *   The dependencies.
   */
  public function dependencies();

  /**
   * Whether or not this object has to be processed asynchronously.
   *
   * If true the map this object relates to won't be processes right away by
   * Drupals behaviour attach.
   *
   * @return int
   *   Return the number of asynchronous object contained in the parent object.
   */
  public function isAsynchronous();

  /**
   * Invoked before an objects render array is built.
   *
   * Mostly invoked by the map object.
   *
   * @param array $build
   *   The array with the build information.
   * @param \Drupal\openlayers\Types\ObjectInterface $context
   *   The context of the build. Mostly the map object.
   */
  public function preBuild(array &$build, ObjectInterface $context = NULL);

  /**
   * Invoked after an objects render array is built.
   *
   * Mostly invoked by the map object.
   *
   * @param array $build
   *   The array with the build information.
   * @param \Drupal\openlayers\Types\ObjectInterface $context
   *   The context of the build. Mostly the map object.
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL);

  /**
   * Return an object, CTools Exportable.
   *
   * @return \StdClass
   *   The object as CTools exportable.
   */
  public function getExport();

  /**
   * Return the object configuration.
   *
   * @return array
   */
  public function getConfiguration();

  /**
   * Return an array of OL objects indexed by their type.
   *
   * @param string $type
   * @return array
   */
  public function getObjects($type = NULL);

  /**
   * Returns an array with the maps this object is attached on.
   *
   * @return array
   *   An array of map objects this object is attached on. Keyed by the map
   *   machine name.
   */
  public function getParents();

  /**
   * Return the module that provides this plugin.
   *
   * @return string
   *   The module providing the plugin.
   */
  public function getProvider();

  /**
   * Returns the path to the plugin directory.
   *
   * @return string
   *   The path to the plugin directory of the class.
   */
  public function getClassDirectory();

  /**
   * Returns the path to the class file.
   *
   * @return string
   *   The path to the file containing the class definition.
   */
  public function getClassPath();

  /**
   * Return the Collection object linked to the object.
   *
   * @return Collection
   */
  public function getCollection();

  /**
   * Return the JS to insert in the page when building the object.
   *
   * @return array
   */
  public function getJS();

  /**
   * Set the weight of an object.
   *
   * @param int $weight
   *   The weight of the object.
   */
  public function setWeight($weight);

  /**
   * Get the weight of an object.
   *
   * @return int
   *   The weight of the object.
   */
  public function getWeight();

  /**
   * Return a flat array containing Openlayers Objects from the options array.
   *
   * @return ObjectInterface[]
   *   Return a list of objects.
   */
  public function optionsToObjects();

  /**
   * Return the human name of the object.
   *
   * @return string
   */
  public function getName();

  /**
   * Return the unique machine name of the object.
   *
   * @return string
   *   The unique machine name of this object.
   */
  public function getMachineName();

  /**
   * Return the description of the object.
   *
   * @return string
   */
  public function getDescription();

  /**
   * Return the description of the object's plugin.
   *
   * @return string
   */
  public function getPluginDescription();

  /**
   * Refresh string translations.
   */
  public function i18nStringsRefresh();

  /**
   * Set the Factory Service of the object.
   *
   * @param string $factory_service
   *   The object's factory service.
   *
   * @return ObjectInterface
   *   The parent object.
   */
  public function setFactoryService($factory_service);

  /**
   * Return the Factory Service of the object.
   *
   * @return string|FALSE
   *   The factory service otherwise FALSE.
   */
  public function getFactoryService();

  /**
   * Add an object into the collection of the parent object.
   *
   * @param \Drupal\openlayers\Types\ObjectInterface $object
   *   The object to add.
   *
   * @return ObjectInterface
   *   The parent object.
   */
  public function addObject(ObjectInterface $object);

  /**
   * Remove an object from the collection.
   *
   * @param string $object_machine_name
   *   The machine name of the object to remove.
   *
   * @return ObjectInterface
   *   The parent object.
   */
  public function removeObject($object_machine_name);

  /**
   * Return all the dependencies objects of the parent object.
   *
   * @return ObjectInterface[]
   *   The dependencies objects.
   */
  public function getDependencies();

  /**
   * Return the object unique ID.
   *
   * @return string
   *   The object ID.
   */
  public function getId();

  /**
   * Set the object ID.
   *
   * @param string $id
   *   The object ID.
   *
   * @return ObjectInterface
   *   The parent object.
   */
  public function setId($id);
}
