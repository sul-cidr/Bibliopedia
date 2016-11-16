<?php

/**
 * @file
 * This file holds all the theme related functions.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function template_preprocess_openlayers(&$variables) {
  /** @var \Drupal\openlayers\Types\MapInterface $map */
  $map = $variables['openlayers']['#map'];

  /*
   * Add a theme suggestion so the template can be customized for a particular
   * map if needed.
   *
   *  Default template: openlayers.tpl.php
   *  Custom map template: openlayers--[map-machine-name].tpl.php
   */
  $variables['theme_hook_suggestions'][] = 'openlayers__' . str_replace('-', '_', $map->getMachineName());

  // The map ID.
  $variables['openlayers']['id'] = $map->getId();

  // The map container CSS styles.
  $variables['openlayers']['styles'] = implode(array_map(function ($key) use ($map) {
    return $key . ':' . $map->getOption($key) . ';';
  }, array('width', 'height')));

  // The map element classes.
  $variables['openlayers']['classes'] = trim(implode(
    ' ',
    array(
      'openlayers-map',
      $map->getMachineName(),
      ((bool) $map->isAsynchronous()) ? 'asynchronous' : NULL,
    )
  ));
}
