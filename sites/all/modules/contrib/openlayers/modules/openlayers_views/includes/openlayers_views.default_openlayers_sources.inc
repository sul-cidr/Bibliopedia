<?php
/**
 * @file
 * Default sources from views.
 */

/**
 * Implements hook_default_sources_alter().
 */
function openlayers_views_default_openlayers_sources_alter(&$sources) {
  foreach (openalyers_views_get_views() as $data) {
    list($style_plugin, $view, $display) = $data;
    $machine_name = 'openlayers_views_source_' . $view->name . '_' . $display;
    $custom_version = \Drupal\openlayers\Openlayers::loadExportable('source', $machine_name);
    if (!isset($sources[$machine_name]) && empty($custom_version)) {
      $ol_source = new stdClass();
      $ol_source->api_version = 1;
      $ol_source->machine_name = $machine_name;
      $ol_source->name = 'Openlayers views source: ' . $view->name . ':' . $display;
      $ol_source->description = t('Source for !link views map', array('!link' => l(t('this'), 'admin/structure/views/view/' . $view->name . '/edit/' . $display)));
      $ol_source->factory_service = 'openlayers.Source:Views';
      $ol_source->options = array(
        'view' => $view->name . ':' . $display,
      );
      $sources[$ol_source->machine_name] = $ol_source;
    }
  }
}
