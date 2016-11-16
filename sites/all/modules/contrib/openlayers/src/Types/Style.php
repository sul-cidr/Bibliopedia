<?php
/**
 * @file
 * Class Style.
 */

namespace Drupal\openlayers\Types;

/**
 * Class Style.
 */
abstract class Style extends Object implements StyleInterface {
  /**
   * The array containing the options.
   *
   * @var array
   */
  protected $options;

  /**
   * {@inheritdoc}
   */
  public function getJS() {
    $js = parent::getJS();

    unset($js['opt']['styles']);

    return $js;
  }

}
