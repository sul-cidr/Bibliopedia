<?php
/**
 * @file
 * Class Collection.
 */

namespace Drupal\openlayers\Types;

use Drupal\Component\Plugin\PluginBase;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Object;


/**
 * Class Collection.
 *
 * @OpenlayersPlugin(
 *   id = "Collection"
 * )
 */
class Collection extends PluginBase {

  /**
   * The variable containing the objects.
   *
   * @var ObjectInterface[] $objects
   *   List of objects in this collection. The items have to be instances of
   *   \Drupal\openlayers\Types\Object.
   */
  protected $objects = array();

  /**
   * Import a flat list of Openlayers Objects.
   *
   * @param ObjectInterface[] $import
   *   The array of objects to import.
   */
  public function import(array $import = array()) {
    array_walk($import, function (ObjectInterface $object_to_add) {
      $dependencies = $object_to_add->getCollection()->getFlatList();
      array_walk($dependencies, function (ObjectInterface $object_dependency) {
        $this->append($object_dependency);
      });
      $this->append($object_to_add);
    });
  }

  /**
   * Return an array with all the collection objects.
   *
   * @param array $types
   *   Array of type to filter for. If set, only a list with objects of this
   *   type is returned.
   *
   * @return \Drupal\openlayers\Types\ObjectInterface[]
   *   List of objects of this collection or list of a specific type of objects.
   */
  public function getFlatList(array $types = array()) {
    $list = $this->objects;


    if (!empty($types)) {
      $types = array_values($types);

      array_walk($types, function (&$value) {
        $value = drupal_strtolower($value);
      });

      $list = array_filter($this->objects, function ($obj) use ($types) {
        /** @var Object $obj */
        return in_array($obj->getType(), $types);
      });
    }

    uasort($list, function ($a, $b) {
      return strnatcmp($a->getWeight(), $b->getWeight());
    });

    return $list;
  }

  /**
   * Add object to this collection.
   *
   * @param ObjectInterface $object
   *   Object instance to add to this collection.
   */
  public function append(ObjectInterface $object) {
    $this->objects[$object->getType() . '_' . $object->getMachineName()] = $object;
  }

  /**
   * Remove object from this collection.
   *
   * @param ObjectInterface $object
   *   Object instance to remove from this collection.
   */
  public function delete(ObjectInterface $object) {
    unset($this->objects[$object->getType() . '_' . $object->getMachineName()]);
  }

  /**
   * Remove object type.
   *
   * @param array $types
   *   The types of objects to remove.
   */
  public function clear(array $types = array()) {
    foreach ($types as $type) {
      unset($this->objects[$type]);
    }
  }

  /**
   * Returns an array with all the attachments of the collection objects.
   *
   * @return array
   *   Array with all the attachments of the collection objects.
   */
  public function getAttached() {
    $attached = array();
    foreach ($this->getFlatList() as $object) {
      $object_attached = $object->attached() + array(
          'js' => array(),
          'css' => array(),
          'library' => array(),
          'libraries_load' => array(),
        );
      foreach (array('js', 'css', 'library', 'libraries_load') as $type) {
        foreach ($object_attached[$type] as $data) {
          if (isset($attached[$type])) {
            array_unshift($attached[$type], $data);
          }
          else {
            $attached[$type] = array($data);
          }
        }
      }
    }
    return $attached;
  }

  /**
   * Array with all the JS settings of the collection objects.
   *
   * @return array
   *   All the JS settings of the collection objects.
   */
  public function getJS() {
    $settings = array();

    foreach ($this->getFlatList() as $object) {
      $settings[$object->getType()][] = $object->getJS();
    }

    return array_change_key_case($settings, CASE_LOWER);
  }

  /**
   * Array with all the collection objects.
   *
   * @param string $type
   *   Type to filter for. If set only a list with objects of this type is
   *   returned.
   *
   * @return array|ObjectInterface[]
   *   List of objects of this collection or list of a specific type of objects.
   */
  public function getObjects($type = NULL) {
    if ($type == NULL) {
      $list = array();
      foreach ($this->getFlatList() as $object) {
        $list[$object->getType()][] = $object;
      }
      return array_change_key_case($list, CASE_LOWER);
    }

    return $this->getFlatList(array($type));
  }

  /**
   * Merges another collection into this one.
   *
   * @param \Drupal\openlayers\Types\Collection $collection
   *   The collection to merge into this one.
   */
  public function merge(Collection $collection) {
    foreach ($collection->getFlatList() as $object) {
      $this->prepend($object);
    }
  }

  /**
   * Add object to this collection.
   *
   * @param ObjectInterface $object
   *   Object instance to add to this collection.
   */
  public function prepend(ObjectInterface $object) {
    $this->objects = array_merge(array($object->getType() . '_' . $object->getMachineName() => $object), $this->objects);
  }

  /**
   * Get the collection as an export array with id's instead of objects.
   *
   * @return array
   *   The export array.
   */
  public function getExport() {
    $export = array();
    foreach ($this->getFlatList() as $object) {
      $export[$object->getType()][] = $object->getMachineName();
    }
    return array_change_key_case($export, CASE_LOWER);
  }

  /**
   * Return an object given an ID.
   *
   * @param string|array $type
   *   The type of object to get.
   * @param string $id
   *   The id of the object to get.
   *
   * @return false|\Drupal\openlayers\Types\ObjectInterface
   *   If found, returns the object. False otherwise.
   */
  public function getObjectById($type = array(), $id) {
    foreach ($this->getFlatList((array) $type) as $object) {
      if ($id === $object->getMachineName()) {
        return $object;
      }
    }
    return FALSE;
  }

  /**
   * Remove an object from the collection.
   *
   * @param string $id
   *   The machine name (same as ID) of the object.
   */
  public function remove($id) {
    foreach ($this->objects as $collection_id => $object) {
      if ($id === $object->getMachineName()) {
        unset($this->objects[$collection_id]);
      }
    }
  }

}
