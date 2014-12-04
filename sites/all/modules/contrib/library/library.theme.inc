<?php

/**
 * @file
 * Theming for the library module
 */


/**
 * Menu callback: Library Actions
 * Theme Form to create a new action
 *
 * @see library_admin_action()
 * @see library_admin_action_validate()
 * @see library_admin_action_submit()
 */
function theme_library_admin_new_action($vars) {
  $header = array(t('Name'), t('Item Status'), t('Edit'));
  $output = '';
  $form=$vars['element'];

  foreach (library_actions() as $aid => $action) {
    switch ($action['status_change']) {
      case LIBRARY_ACTION_TYPE_UNAVAILABLE:
        $status_text = 'Unavailable';
        break;
      case LIBRARY_ACTION_TYPE_AVAILABLE:
        $status_text = 'Available';
        break;
      default:
        $status_text = 'No Change';
    }
    $rows[] = array($action['name'], $status_text, l(t('edit action'), 'admin/config/workflow/library/actions/edit/' . $aid));
  }
  if (isset($form['submit'])) {
    $rows[] = array(drupal_render($form['name']), drupal_render($form['status_change']), drupal_render_children($form));
  }
  $output .= theme('table', array('header' => $header, 'rows' => $rows));
  return $output;
}

function theme_library_items($items) {
  $barcodes = (variable_get('library_item_barcodes', LIBRARY_NO_BARCODES) == LIBRARY_BARCODES);
  $display_status = (variable_get('library_status_display', 0) == 1);

  $header = array(t('Copy'));
  if ($barcodes) {
    $header[] = t('Barcode');
  }
  if ($display_status) {
    $header[] = t('Status');
  }
  $header[] = t('Notes');
  $header[] = t('Actions');
  $rows = array();
  $itemlist = $items['items'];
  if ($itemlist) {
    foreach ($itemlist as $key => $item) {
      $temp_array = array($key + 1);
      if ($barcodes) {
        $temp_array[] = $item['barcode'];
      }
      if ($display_status) {
        $temp_array[] = library_get_status_text($item);
      }
      $temp_array[] = $item['notes'];
      $temp_array[] = implode(" | ", library_get_action_links($item)) . ' ';
      $rows[$key] = $temp_array;
    }
  }
  return theme('table', array('header' => $header, 'rows' => $rows));
}


/**
 * Theme the items section on library entries.
 *
 * @ingroup themeable
 */
function theme_library_items_field($form) {
  $barcodes = variable_get('library_item_barcodes', LIBRARY_NO_BARCODES) == LIBRARY_BARCODES;

  $rows = array();

  if ($barcodes) {
    $header[] = t('Barcode');
  }
  else {
    $header[] = t('Copy');
  }
  $header[] = t('Reference Only');
  $header[] = t('Notes');
  $header[] = t('Delete');

  foreach (element_children($form['form']['library_items']) as $key) {
    // No need to print the field title every time.
    unset($form['form']['library_items'][$key]['barcode']['#title'], $form['form']['library_items'][$key]['in_circulation']['#title'], $form['form']['library_items'][$key]['notes']['#title'], $form['form']['library_items'][$key]['delete']['#title']);

    // Build the table row.

    if ($barcodes) {
      $row['data'][] = array('data' => drupal_render($form['form']['library_items'][$key]['barcode']), 'class' => 'library-barcode');
    }
    else {
      $row['data'][] = array('data' => ($key + 1), 'class' => 'library-copy');
    }

    $row['data'][] = array('data' => drupal_render($form['form']['library_items'][$key]['in_circulation']), 'class' => 'library_circulation');
    $row['data'][] = array('data' => drupal_render($form['form']['library_items'][$key]['notes']), 'class' => 'library_notes');

    if ($key > 0) {
      $row['data'][] = array('data' => drupal_render($form['form']['library_items'][$key]['delete']), 'class' => 'library-delete');
    }
    else {
      $row['data'][] = array();
    }

    // Add additional attributes to the row, such as a class for this row.
    if (isset($form['form']['library_items'][$key]['#attributes'])) {
      $row = array_merge($row, $form['form']['library_items'][$key]['#attributes']);
    }
    $rows[] = $row;
    $row = array();
  }

  $output = theme('table', array('header' => $header, 'rows' => $rows));
  $output .= drupal_render_children($form['form']);

  return $output;
}
