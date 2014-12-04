<?php

/**
 * @file
 * Filter handler for library item status
 *
 */

class library_handler_filter_library_status extends views_handler_filter_boolean_operator {
  function construct() {
    parent::construct();
    $this->value_value = t('Is Available');
  }

  function query() {
    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";
    $field2 = "$this->table_alias.in_circulation";
    $node = $this->query->ensure_table('library');
    $this->query->add_where($this->options['group'], "$field " . (empty($this->value) ? '!=' : '=') . " " . LIBRARY_ITEM_AVAILABLE . " AND $field2 = " . LIBRARY_CIRCULATION);
  }
}
