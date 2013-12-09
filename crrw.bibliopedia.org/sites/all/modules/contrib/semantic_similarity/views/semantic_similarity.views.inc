<?php
// $Id: semantic_similarity.views.inc,v 1.2 2011/01/30 01:34:21 benoitborrel Exp $

/**
 * @file
 * Semantic Similarity module views integration file.
 * @see http://drupal.org/project/views
 */

/**
 * Implements hook_views_data().
 * Describes node_semantic_similarity table structure to Views.
 */
function semantic_similarity_views_data() {
  $data = array();

  // expose node_semantic_similarity table to Views
  $data['node_semantic_similarity']['table'] = array(
    'group' => t('Node Semantic Similarity'),
    'join' => array(
      'node' => array(
        'handler' => 'semantic_similarity_handler_join_complex',
        'base_table' => 'node_semantic_similarity',
        'left_field' => 'nid',
        'field' => 'snid',
      ),
    ),
  );

  // expose node_semantic_similarity table fields to Views
  // - source node id
  $data['node_semantic_similarity']['snid'] = array(
    'title' => t('Source node id'),
    'help' => t('The node id of the source node.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'snid', // the field to display in the summary.
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // - target node id
  $data['node_semantic_similarity']['tnid'] = array(
    'title' => t('Target node id'),
    'help' => t('The node id of the target node.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    // used in page display only
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'nid',
      'label' => t('node'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'tnid', // the field to display in the summary.
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // - score
  $data['node_semantic_similarity']['score'] = array(
    'title' => t('Score'),
    'help' => t('The semantic similarity score between the target and the source nodes.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'score', // the field to display in the summary.
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_query_alter().
 * Alter JOIN and WHERE clauses for module's view displays.
 */
function semantic_similarity_views_query_alter(&$view, &$query) {
  switch ($view->name) {
    case 'semantic_similarity':
      switch ($view->current_display) {

        // block display
        case 'block_1':
          // add conditions to WHERE clause
          $query->where[0]['clauses'][] = sprintf(
            "%s.%s = %d OR %s.tnid = %d",
            $query->table_queue['node_semantic_similarity']['alias'],
            $query->table_queue['node_semantic_similarity']['join']->definition['field'],
            $view->args[0],
            $query->table_queue['node_semantic_similarity']['alias'],
            $view->args[0]
          );
        break;

        // page display:
        case 'page_1':
          // add field for JOIN clause from view relationship
          $query->fields['node_title2'] = array(
            'field' => 'title',
            'table' => 'node_node_semantic_similarity',
            'alias' => 'node_title2',
          );
          // add condition to WHERE clause
          $query->where[0]['clauses'][] = sprintf(
            "%s.status <> 0",
            $query->table_queue['node_node_semantic_similarity']['alias']
          );
        break; // switch view->current_display
      }
    break; // switch view->name
  }
}

/**
 * Extension of views_join.
 * Alter JOIN condition for module's view block display.
 */
class semantic_similarity_handler_join_complex extends views_join {
  // PHP 4 doesn't call constructors of the base class automatically from a
  // constructor of a derived class. It is your responsibility to propagate
  // the call to constructors upstream where appropriate.
  function construct($table = NULL, $left_table = NULL, $left_field = NULL, $field = NULL, $extra = array(), $type = 'LEFT') {
    parent::construct($table, $left_table, $left_field, $field, $extra, $type);
  }

  function join($table, &$query) {
    $output = '';

    // block display
    if (count($query->table_queue) == 2) {
      // inject a '(' before 'ON'
      $output  = str_replace(' ON ', ' ON (', parent::join($table, $query));
      // inject JOIN condition
      $output .= sprintf(" OR %s.%s = %s.tnid", $table['join']->left_table, $table['join']->left_field, $table['alias'], $table['join']->extra);
      // append a ')' after the JOIN condition
      $output .= ')';
    }

    // page display and default
    else {
      $output = parent::join($table, $query);
    }

    return $output;
  }
}
