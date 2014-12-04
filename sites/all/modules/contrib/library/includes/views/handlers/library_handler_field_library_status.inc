<?php

/**
 * @file
 * Field handler for library item status
 *
 */


/**
 * Display a node's status in the library as a whole
 */
class library_handler_field_library_status extends views_handler_field {
  function construct() {
    parent::construct();
  }

  function query() {
    $this->ensure_my_table();
  }

  function render($values) {
    $nid = $values->nid;
    $node = node_load($nid);
    $item = library_get_status_item($node);
    if ($item) {
      return library_get_status_text($item);
    }
    return '';
  }
}
