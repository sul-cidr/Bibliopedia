<?php
/**
 * @file
 * Class Controls.
 */

namespace Drupal\openlayers_ui\UI;

/**
 * Class Controls.
 *
 * @package Drupal\openlayers_ui\UI
 */
class OpenlayersControls extends \OpenlayersObjects {

  /**
   * {@inheritdoc}
   */
  public function hook_menu(&$items) {
    parent::hook_menu($items);
    $items['admin/structure/openlayers/controls']['type'] = MENU_LOCAL_TASK;
    $items['admin/structure/openlayers/controls']['weight'] = 1;
  }

}
