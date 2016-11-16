<?php
/**
 * @file
 * Helper functions
 */

function _openlayers_services_retrieve($name) {
  /** @var \Drupal\openlayers\Types\MapInterface $map */
  if (($map = \Drupal\openlayers\Openlayers::load('Map', $name)) == TRUE) {

    array_map(
      'drupal_static_reset',
      array(
        'drupal_add_css',
        'drupal_add_js',
        'libraries_load',
        'drupal_add_library',
      )
    );

    drupal_process_attached(array('#attached' => $map->getCollection()->getAttached()));
    drupal_add_css(drupal_get_path('module', 'openlayers_services') . '/css/reset.css');

    return theme('openlayers_map_iframe', array(
      'page' => $map->render(),
      'scripts' => drupal_get_js(),
      'styles' => drupal_get_css(),
    ));
  }
}

function _openlayers_services_access($operation, $map) {
  $map = \Drupal\openlayers\Openlayers::load('Map', $map[0]);
  return $map == TRUE && (bool) $map->getOption('provideIframe', FALSE);
}
