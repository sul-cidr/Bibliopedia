<?php
/**
 * @file
 * Interface MapInterface.
 */

namespace Drupal\openlayers\Types;

/**
 * Interface MapInterface.
 */
interface MapInterface extends ObjectInterface {
  /**
   * Returns the id of this map.
   *
   * @return string
   *   The id of this map.
   */
  public function getId();

  /**
   * Add a layer to the map.
   *
   * @param LayerInterface $layer
   *   The layer object to add.
   *
   * @return MapInterface
   *   The parent map.
   */
  public function addLayer(LayerInterface $layer);

  /**
   * Add a component to the map.
   *
   * @param ComponentInterface $component
   *   The component object to add.
   *
   * @return MapInterface
   *   The parent map.
   */
  public function addComponent(ComponentInterface $component);

  /**
   * Add a control to the map.
   *
   * @param ControlInterface $control
   *   The control object to add.
   *
   * @return MapInterface
   *   The parent map.
   */
  public function addControl(ControlInterface $control);

  /**
   * Add an interaction to the map.
   *
   * @param InteractionInterface $interaction
   *   The interaction object to add.
   *
   * @return MapInterface
   *   The parent map.
   */
  public function addInteraction(InteractionInterface $interaction);

  /**
   * Remove a layer from the map.
   *
   * @param string $layer_id
   *   The machine name (or id) of the layer to remove.
   *
   * @return MapInterface
   *   The map.
   */
  public function removeLayer($layer_id);

  /**
   * Remove a component from the map.
   *
   * @param string $component_id
   *   The machine name (or id) of the component to remove.
   *
   * @return MapInterface
   *   The map.
   */
  public function removeComponent($component_id);

  /**
   * Remove a control from the map.
   *
   * @param string $control_id
   *   The machine name (or id) of the control to remove.
   *
   * @return MapInterface
   *   The map.
   */
  public function removeControl($control_id);

  /**
   * Remove a interaction from the map.
   *
   * @param string $interaction_id
   *   The machine name (or id) of the interaction to remove.
   *
   * @return MapInterface
   *   The map.
   */
  public function removeInteraction($interaction_id);

  /**
   * Build render array of a map.
   *
   * @param array $build
   *   The build array before being completed.
   *
   * @return array
   *   The render array.
   */
  public function build(array $build = array());

  /**
   * Render a build array into HTML.
   *
   * @return array
   *   The map HTML.
   */
  public function render();

  /**
   * Return the size of the map.
   *
   * @return array $size
   *   Return an array with width and height.
   */
  public function getSize();

  /**
   * Set the size of the map.
   *
   * @return MapInterface
   *   The map.
   */
  public function setSize(array $size = array());

  /**
   * Set the target element to render this map into.
   *
   * @param string $target
   *   The html ID of the element to render the map into.
   *
   * @return MapInterface
   *   The map.
   */
  public function setTarget($target);

  /**
   * Get the target ID in which this map is rendered.
   *
   * @return string
   *   The ID of the Element that the map is rendered in.
   */
  public function getTarget();

}
