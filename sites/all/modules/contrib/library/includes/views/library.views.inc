<?php

/**
 * @file
 * Hooks into views module
 */

/**
 * Implementation of hook_views_handlers().
 */
function library_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'library') . '/includes/views/handlers',
    ),
    'handlers' => array(

      // field handlers
      'library_handler_field_library_status' => array(
        'parent' => 'views_handler_field',
      ),
      'library_handler_field_quantity' => array(
        'parent' => 'views_handler_field',
      ),

      // filter handlers
      'library_handler_filter_library_status' => array(
        'parent' => 'views_handler_filter_boolean_operator',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data()
 */
function library_views_data() {
  $data = array();

  // Basic table information.

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['library']['table']['group']  = t('Library');

  // For other base tables, explain how we join
  $data['library']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
     ),
  );

  // ----------------------------------------------------------------
  // Fields
  $data['library']['in_circulation'] = array(
    'title' => t('Reference Only'), // The item it appears as on the UI,
    'help' => t('Whether a library item is in circulation.'), // The help that appears on the UI,
    'filter' => array(
      'title' => t('Reference Only'),
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Reference Only'),
    ),
  );

  $data['library']['library_status'] = array(
    'title' => t('Item Status'), // The item it appears as on the UI,
    'help' => t('Whether a library item is available or unavailable. Note that this requires an additional query per row.'), // The help that appears on the UI,
     // Information for displaying a title as a field
    'field' => array(
      'handler' => 'library_handler_field_library_status',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'library_handler_filter_library_status',
      'label' => t('Item Status'),
    ),
  );

  $data['library']['quantity'] = array(
    'field' => array(
      'title' => t('Quantity'),
      'handler' => 'library_handler_field_quantity',
      'help' => t('Number of copies.'),
     ),
  );
  return $data;
}
