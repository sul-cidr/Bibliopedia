<?php
/**
 * Base sort handler that performs a simple sort.
 */
class sparql_views_handler_sort extends views_handler_sort {
  /**
   * Called to add the sort to a query.
   */
  function query() {
    $this->query->add_orderby($this->real_field, $this->options['order']);
  }
}
