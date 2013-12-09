<?php
// $Id: semantic_similarity.theme.inc,v 1.6 2011/02/04 00:21:26 benoitborrel Exp $

/**
 * @file
 * Semantic Similarity module theme callbacks.
 */

/******************
 * BLOCKS THEMING *
 ******************/

/**
 * Returns HTML for site-wide block content.
 *
 * @param array $variables
 *   Associative array of:
 *   - string order
 *     The order of the nodes list to display. Either 'DESC' or 'ASC'.
 *   - int limit
 *     The number of nodes to display in the list.
 *
 * @return string $output
 *   The xHTML snippet.
 *
 * @ingroup themeable
 */
function theme_semantic_similarity_block($variables) {
  $output = '';
  $data = $items = array();

  // Get data
  if ($data = _semantic_similarity_get_scored_nids($variables['order'], $variables['limit'])) {
    // Fetch nids into items
    foreach ($data as $row) {
      $items[] = sprintf('%d%%', $row['score'] * 100)
               . ' '
               . l($row['title1'], 'node/' . $row['snid'])
               . ' <-> '
               . l($row['title2'], 'node/' . $row['tnid']);
    }
    // Theme output as an item list
    $output = theme('item_list', array('items' => $items));
  }
  else {
    $output = t('No pair of similar nodes were found.');
  }

  return $output;
}

/**
 * Returns HTML for node page block content.
 *
 * @param array $variables
 *   Associative array of:
 *   - int nid
 *     The node id of the displayed node.
 *   - string order
 *     The order of the nodes list to display. Either 'DESC' or 'ASC'.
 *   - int limit
 *     The number of nodes to display in the list.
 *
 * @return string $output
 *   The xHTML snippet.
 *
 * @ingroup themeable
 */
function theme_semantic_similarity_node_block($variables) {
  $output = '';
  $data = $items = array();

  // Get data
  if ($data = _semantic_similarity_get_node_scored_nids($variables['nid'], $variables['order'], $variables['limit'])) {
    // add Raphael JS
    raphael_add();
    // add own JS
    drupal_add_js(drupal_get_path('module', 'semantic_similarity') . '/js/raphael_radial-map.js');

    // Graphical representation with an SVG canvas
    $output .= '<div id="radialMap-' . drupal_strtolower($variables['order']) . '"></div>';
    $output .= '<script type="text/javascript">!--' . "\n";
    $output .= "drawRadialMap('" . drupal_json_encode($data) . "', '" . drupal_strtolower($variables['order']) . "');";
    $output .= "\n" . '//--></script>';

    // Textual representation
    // - fetch data into items
    foreach ($data as $row) {
      $items[] = sprintf('%d%%', $row['score'] * 100)
               . ' '
               . l($row['title'], 'node/' . $row['nid']);
    }
    // - theme output as an item list
    $output .= theme('item_list', array('items' => $items));

  }
  else {
    $output = t('No similar nodes were found.');
  }

  return $output;
}
