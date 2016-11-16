<?php
/**
 * @file
 * This file holds main views functions for the openlayers_views module.
 *
 * @ingroup openlayers
 */

/**
 * Implements hook_views_plugins().
 */
function openlayers_views_views_plugins() {
  return array(
    'display' => array(
      'openlayers' => array(
        'title' => t('Openlayers data'),
        'help' => t('Data for Openlayers module.'),
        'handler' => 'openlayers_views_plugin_display_openlayers',
        'path' => drupal_get_path('module', 'openlayers_views') . '/views',
        'uses hook menu' => FALSE,
        'use ajax' => FALSE,
        'use pager' => TRUE,
        'accept attachments' => FALSE,
        'admin' => t('Openlayers data'),
      ),
    ),
    'style' => array(
      'openlayers_source_vector' => array(
        'title' => t('Openlayers source'),
        'help' => t('Provides an openlayers source to power an openlayers layer.'),
        'handler' => 'openlayers_views_plugin_style_source_vector',
        'path' => drupal_get_path('module', 'openlayers_views') . '/views',
        'uses fields' => TRUE,
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'uses grouping' => TRUE,
        'type' => 'openlayers',
        'even empty' => TRUE,
      ),
      'openlayers_map_views' => array(
        'title' => t('Openlayers map'),
        'help' => t('Provides a map based on a views configuration.'),
        'handler' => 'openlayers_views_plugin_map_views',
        'uses fields' => TRUE,
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        // 'uses grouping' => TRUE,
        'even empty' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
