<?php
/**
 * @file
 * Interaction: DragRotateAndZoom.
 */

namespace Drupal\openlayers\Plugin\Interaction\DragRotateAndZoom;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Interaction;

/**
 * Class DragRotateAndZoom.
 *
 * @OpenlayersPlugin(
 *  id = "DragRotateAndZoom",
 *  description = "Allows the user to zoom and rotate the map by clicking and dragging on the map when the [ALT] and [SHIFT] keys are held down. This interaction is only supported for mouse devices."
 * )
 */
class DragRotateAndZoom extends Interaction {

}
