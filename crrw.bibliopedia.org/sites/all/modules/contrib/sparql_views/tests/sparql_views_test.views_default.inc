<?php
/**
 * @file
 *   Test views
 */

define('TABLE_ID', 'sparql_views_' . crc32('localhost/arc2/sparql_views_test/sparql.php'));

/**
 * Implements hook_views_default_views().
 */
function sparql_views_test_views_default_views() {
  $views['sparql_views_test_formatters'] = sparql_views_test_formatters();

  return $views;
}

function sparql_views_test_formatters() {
  $view = new view;
  $view->name = 'sparql_views_test_formatters';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = TABLE_ID;
  $view->is_cacheable = FALSE;
  $view->api_version = 3;
  $view->version = 7;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';

  // Main resource.
  $handler->display->display_options['fields']['sparql_views_test_person']['id'] = 'sparql_views_test_person';
  $handler->display->display_options['fields']['sparql_views_test_person']['table'] = TABLE_ID;
  $handler->display->display_options['fields']['sparql_views_test_person']['field'] = 'sparql_views_test_person';

  // Text field.
  $handler->display->display_options['fields']['sparql_views_test_person_sparql_views_test_name']['id'] = 'sparql_views_test_person_sparql_views_test_name';
  $handler->display->display_options['fields']['sparql_views_test_person_sparql_views_test_name']['table'] = TABLE_ID;
  $handler->display->display_options['fields']['sparql_views_test_person_sparql_views_test_name']['field'] = 'sparql_views_test_person_sparql_views_test_name';

  // Number field.
  $handler->display->display_options['fields']['sparql_views_test_person_sparql_views_test_age']['id'] = 'sparql_views_test_person_sparql_views_test_age';
  $handler->display->display_options['fields']['sparql_views_test_person_sparql_views_test_age']['table'] = TABLE_ID;
  $handler->display->display_options['fields']['sparql_views_test_person_sparql_views_test_age']['field'] = 'sparql_views_test_person_sparql_views_test_age';

  // Image field.
  $handler->display->display_options['fields']['sparql_views_test_person_sparql_views_test_person_image']['id'] = 'sparql_views_test_person_sparql_views_test_person_image';
  $handler->display->display_options['fields']['sparql_views_test_person_sparql_views_test_person_image']['table'] = TABLE_ID;
  $handler->display->display_options['fields']['sparql_views_test_person_sparql_views_test_person_image']['field'] = 'sparql_views_test_person_sparql_views_test_person_image';
  
  $handler->display->display_options['filters']['sparql_views_test_person_sparql_views_test_name']['id'] = 'sparql_views_test_person_sparql_views_test_name';
  $handler->display->display_options['filters']['sparql_views_test_person_sparql_views_test_name']['table'] = TABLE_ID;
  $handler->display->display_options['filters']['sparql_views_test_person_sparql_views_test_name']['field'] = 'sparql_views_test_person_sparql_views_test_name';
  $handler->display->display_options['filters']['sparql_views_test_person_sparql_views_test_name']['value'] = 'Lin Clark';
  $handler->display->display_options['filters']['sparql_views_test_person_sparql_views_test_name']['group'] = 0;
  $handler->display->display_options['filters']['sparql_views_test_person_sparql_views_test_name']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['sparql_views_test_person_sparql_views_test_name']['sparql_options'] = array(
    'value_type' => 'string',
    'language' => '0',
  );

  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['fields'] = TRUE;

  $handler->display->display_options['path'] = 'sparql_views_test_formatters';

  return $view;
}

function sparql_views_test_table_id() {
  return 'sparql_views_' . crc32('localhost/arc2/sparql_views_test/sparql.php');
}