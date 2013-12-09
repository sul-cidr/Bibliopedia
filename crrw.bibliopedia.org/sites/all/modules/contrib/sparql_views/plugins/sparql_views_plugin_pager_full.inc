<?php
/**
 * @file
 * The plugin to handle full pager.
 *
 * @ingroup views_pager_plugins
 */

class sparql_views_plugin_pager_full extends views_plugin_pager_full {
  /**
   * Execute the count query, which will be done just prior to the query
   * itself being executed.
   */
  function execute_count_query(&$count_query) {
    $sparql_result = sparql_request($count_query, $this->view->query->endpoint);
    if (empty($sparql_result) || empty($sparql_result['result']['rows'])) {
      vsm(t('No result returned. Please check your query and the endpoint status.'));
      return;
    }
    $row = reset($sparql_result['result']['rows']);
    $this->total_items = $row['pager_count'];
    if (!empty($this->options['offset'])) {
      $this->total_items -= $this->options['offset'];
    }

    $this->update_page_info();
    return $this->total_items;
  }
}
