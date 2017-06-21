<?php
/**
 * @file
 * Interface LayerInterface.
 */

namespace Drupal\openlayers\Types;

/**
 * Interface LayerInterface.
 */
interface LayerInterface {

  /**
   * Returns the source of this layer.
   *
   * @return openlayers_source_interface|FALSE
   *   The source assigned to this layer.
   */
  public function getSource();
}
