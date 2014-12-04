<?php

/**
 * @file
 * Field handler for library item quantity
 *
 */

/**
 * Display the library quantity
 */
class library_handler_field_quantity extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $nid = $values->{$this->aliases['nid']};
    $node = node_load($nid);
    if (isset($node->items) && !empty($node->items)) {
      return count($node->items);
    }
    return '';
  }
}
