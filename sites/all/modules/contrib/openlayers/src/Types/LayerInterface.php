<?php
/**
 * @file
 * Interface LayerInterface.
 */

namespace Drupal\openlayers\Types;

/**
 * Interface LayerInterface.
 */
interface LayerInterface extends ObjectInterface {
  /**
   * Returns the source of this layer.
   *
   * @return SourceInterface|FALSE
   *   The source of this layer.
   */
  public function getSource();

  /**
   * Set the source of this layer.
   *
   * @param SourceInterface $source
   *   The source object.
   *
   * @return LayerInterface
   *   The parent layer.
   */
  public function setSource(SourceInterface $source);

  /**
   * Returns the style of this layer.
   *
   * @return StyleInterface|FALSE
   *   The style of this layer.
   */
  public function getStyle();

  /**
   * Set the style of this layer.
   *
   * @param StyleInterface $style
   *   The style object.
   *
   * @return LayerInterface
   *   The parent layer.
   */
  public function setStyle(StyleInterface $style);

  /**
   * Set the opacity of the layer.
   *
   * @param float $opacity
   *   The opacity value, allowed values range from 0 to 1.
   *
   * @return LayerInterface
   *   The parent layer.
   */
  public function setOpacity($opacity);

  /**
   * Return the opacity of the layer (between 0 and 1).
   *
   * @return float
   *   The opacity of the layer.
   */
  public function getOpacity();

  /**
   * Set Z-index of the layer, which is used to order layers before rendering.
   *
   * @param int $zindex
   *   The Z-Index. Default is 0.
   *
   * @return LayerInterface
   *   The parent layer.
   */
  public function setZIndex($zindex);

  /**
   * Return the Z-index of the layer.
   *
   * @return int
   *   The Z-Index.
   */
  public function getZIndex();

  /**
   * Set the visibility of the layer.
   *
   * @param bool $visibility
   *   The visibility of the layer, TRUE or FALSE.
   *
   * @return LayerInterface
   *   The parent layer.
   */
  public function setVisible($visibility);

  /**
   * Return the visibility of the layer.
   *
   * @return bool
   *   The visibility of the layer, TRUE or FALSE.
   */
  public function getVisible();

}
