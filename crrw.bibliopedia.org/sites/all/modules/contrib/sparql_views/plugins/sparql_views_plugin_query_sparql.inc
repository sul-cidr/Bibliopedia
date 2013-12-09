<?php
/**
 * Object used to create a SELECT query.
 */
class sparql_views_plugin_query_sparql extends views_plugin_query {
  /**
   * Endpoint that this query should be run against.
   */
  public $endpoint;

  /**
   * Namespaces that are used in this query.
   */
  var $required_namespaces = array();

  /**
   * An array of fields which have been specified for selection. Fields may be
   * included in the triple patterns (i.e. in filters or for path traversal)
   * without being selected for retrieval.
   */
  var $select_fields = array();

  /**
   * An array of sections of the triple pattern. Each section is in itself
   * an array of pieces.
   */
  var $triples = array();

  /**
   * An array of URIs and resources that are used as replacements for variables.
   */
  var $replacements = array();

  /**
   * An array of filter functions and parameters.
   */
  var $filters = array();

  /**
   * An array of fields to order by and the ordering direction.
   */
  var $orderby = array();

  /**
   * A pager plugin that should be provided by the display.
   */
  var $pager = NULL;

  /**
   * An array of relationship fields.
   */
  var $relationships_fields = array();

  /**
   * Constructor; Create the basic query object and fill with default values.
   */
  function init($base_table, $base_field, $options) {
    parent::init($base_table, $base_field, $options);
    $this->base_table = $base_table;
    $this->base_field = $base_field;
    $this->unpack_options($this->options, $options);

    // Check to see whether the necessary requirements are met in order to
    // create a valid query.
    $data = views_fetch_data();

    // Set the endpoint.
    $endpoint_uri = $data[$this->base_table]['table']['endpoint']->uri;
    $this->endpoint = sparql_registry_load_by_uri($endpoint_uri);

    unset($data[$base_table]['table']);
    if (count($data[$base_table]) === 0) {
      $config = l(t('resource configuration'), 'admin/structure/sparql-views');
      drupal_set_message(t('No resources are available for this endpoint. Please edit the !config to indicate which resources can be used with this endpoint.', array('!config' => $config)), 'warning', FALSE);
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['consolidate'] = array(
      'default' => FALSE,
      'bool' => TRUE,
    );
    $options['distinct'] = array(
      'default' => TRUE,
      'bool' => TRUE,
    );

    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    // Some form elements belong in a fieldset for presentation, but can't
    // be moved into one because of the form_state['values'] hierarchy. Those
    // elements can add a #fieldset => 'fieldset_name' property, and they'll
    // be moved to their fieldset during pre_render.
    // @todo Remove this when issue #1208824 is resolved.
    $form['#pre_render'][] = 'views_ui_pre_render_add_fieldset_markup';

    $form['consolidate'] = array(
      '#type' => 'checkbox',
      '#title' => t('Consolidate Results'),
      '#description' => t('This will combine all the properties for a given subject into one result. This will override any field-level consolidation.'),
      '#default_value' => !empty($this->options['consolidate']),
    );

    $form['advanced_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Advanced settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['distinct'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use DISTINCT query'),
      '#description' => t("This eliminates duplicate rows by using !distinct. This can negatively effect the performance of the query, so you may want to turn off this option if you know that your dataset does not return duplicates for this query.", array('!distinct' => l('DISTINCT', 'http://www.w3.org/TR/rdf-sparql-query/#modDistinct'))),
      '#default_value' => !empty($this->options['distinct']),
      '#fieldset' => 'advanced_settings',
    );
  }

 /**
  * Generate a query and a countquery from all of the information supplied
  * to the object.
  *
  * @param $get_count
  *   Provide a countquery if this is true, otherwise provide a normal query.
  */
  function query($view, $get_count = FALSE) {
    $graph_pattern = '';
    $filters = '';
    $orderby = '';
    $ns = rdf_get_namespaces();
    $bindings = array();
    $prefixes = '';

    // Create the SELECT clause.
    $select = 'SELECT';

    // Add DISTINCT if selected in Query Settings. This is only added if this
    // is not a COUNT query because the DISTINCT keyword is added within the
    // COUNT function.
    if ($this->options['distinct'] == TRUE && !$get_count) {
      $select .= ' DISTINCT';
    }

    // Add fields that the user has added to the Fields section in Views UI.
    foreach ($this->select_fields as $key => $field) {
      // If this is not a COUNT query, add all of the fields.
      if (!$get_count) {
        // Do not add variable to SELECT if it will be replaced with a value.
        if (!isset($this->replacements[$field])) {
          // Add a question mark before each variable.
          $select .= " ?$field";
        }
      }
      // Otherwise, just add the COUNT function.
      else {
        // ARC2 doesn't currently parse COUNT queries if there is a DISTINCT
        // keyword inside.
        // $distinct = $this->options['distinct'] ? 'DISTINCT ' : '';
        $select .= " (COUNT(?$field) AS ?pager_count)";
        break;
      }
    }

    // Form the triple pattern.
    $subject_triples = array();
    foreach($this->triples as $s => $pattern) {
      $statements = array();
      $optionals = array();
      $triples_block = isset($this->replacements[$s]) ? $this->replacements[$s]['replacement_formatted'] : "?$s";

      foreach($pattern['pred_obj'] as $pred_obj) {
        $p = isset($this->replacements[$pred_obj['p']]) ? $this->replacements[$pred_obj['p']]['replacement_formatted'] : $this->validate_curie($pred_obj['p']);

        // If there is a preset value for the object, use the formatted version
        // of it. Otherwise, use the field_alias as a variable.
        $o = isset($this->replacements[$pred_obj['o']]) ? $this->replacements[$pred_obj['o']]['replacement_formatted'] : $pred_obj['o'];

        // If this field is optional, wrap it in an OPTIONAL clause.
        if ($pred_obj['#optional'] == TRUE) {
          $optionals[] = array('object' => preg_replace('/^\?/', '', $o), 'statement' => "?$s $p $o");
        }
        else {
          $statements[] = " $p $o";
        }
      }

      // Form the graph pattern about the current subject.
      if(empty($statements)) {
        $triples_block = '';
      } else {
        $triples_block = $triples_block . implode(';', $statements) . '.';
      }
      $subject_graph_pattern = array('triples' => $triples_block, 'optionals' => $optionals);

      // If this field forms a relationship, add the graph pattern its relationship parent.
      if (!empty($this->relationship_fields[$s])) {
        $relationship = $this->relationship_fields[$s];
        $subject_triples[$relationship['parent']]['relationships'][$s] = $subject_graph_pattern;
      } else {
        $subject_triples[$s] = $subject_graph_pattern;
      }
    }

    // Build the complete graph pattern.
    foreach ($subject_triples as $s => $pattern_elements) {
      $graph_pattern .= $this->build_graph_pattern($pattern_elements);
    }

    // Get namespaces.
    $required_namespaces = array_unique($this->required_namespaces);
    foreach($required_namespaces as $prefix) {
      if (isset($ns[$prefix])) {
        $namespace = $ns[$prefix];
        $prefixes .= "PREFIX $prefix: <$namespace>\n";
      }
    }
    // If no triples were added, run a generic ?s ?p ?o query.
    if (empty($triple_pattern)) {
      $triple_pattern = "?$field ?p ?o";
    }

    foreach ($this->filters as $filter) {
      $filters .= "FILTER $filter\n";
    }

    if (!empty($this->orderby)) {
      $orderby = "ORDER BY";
      foreach ($this->orderby as $field => $order) {
        $orderby .= " $order(?$field)\n";
      }
    }
    $limit = isset($this->limit) ? "LIMIT $this->limit" : '';
    $offset = isset($this->offset) ? " OFFSET $this->offset" : '';
    
    $query = $prefixes;
    $query .= $select . "\n";
    $query .= "WHERE {\n$graph_pattern$filters} \n";
    $query .= $orderby;
    if (!$get_count) {
      $query .= $limit;
      $query .= $offset;
    }
    return $query;
  }

  function build_graph_pattern($pattern_elements) {
    $subject_pattern = '';
    $relationship_pattern = '';
    $optionals = '';

    $subject_pattern .= $pattern_elements['triples'] . "\n";

    // Build optionals and add any nested relationship triples.
    foreach ($pattern_elements['optionals'] as $optional_block) {
      $optionals .= 'OPTIONAL {';

      if (!empty($pattern_elements['relationships'][$optional_block['object']])) {
        $optionals .= "\n" . $optional_block['statement'] . '.';
        $optionals .= "\n" . $this->build_graph_pattern($pattern_elements['relationships'][$optional_block['object']]);
        unset($pattern_elements['relationships'][$optional_block['object']]);
      } else {
        $optionals .= $optional_block['statement'];
      }

      $optionals .= "}\n";
    }

    // Build remaining non-optional relationships.
    if (!empty($pattern_elements['relationships'])) {
      foreach ($pattern_elements['relationships'] as $relationship) {
        $relationship_pattern .= $this->build_graph_pattern($relationship);
      }
    }

    return $subject_pattern . $relationship_pattern . $optionals;
  }

  /**
   * Let modules modify the query just prior to finalizing it.
   */
  function alter(&$view) {  }

  /**
   * Builds the necessary info to execute the query.
   */
  function build(&$view) {
    $view->init_pager();

    // Let the pager modify the query to add limits.
    $this->pager->query($view);

    $view->build_info['query'] = $this->query($view);
    $view->build_info['count_query'] = $this->query($view, TRUE);
  }

  /**
   * Executes the query and fills the associated view object with according
   * values.
   *
   * Values to set: $view->result, $view->total_rows, $view->execute_time,
   * $view->pager['current_page'].
   */
  function execute(&$view) {
    $views_result = array();
    $query = $view->build_info['query'];
    $views_data = sparql_views_views_data();
    $start = microtime(TRUE);

    // If this is a paged query, get the count.
    $count_query = $view->build_info['count_query'];
    try {
      if ($this->pager->use_count_query() || !empty($view->get_total_rows)) {
        $this->pager->execute_count_query($count_query);
      }

      // Let the pager modify the query to add limits.
      $this->pager->pre_execute($query);

      // Get the results for display.
      $sparql_result = sparql_request($query, $this->endpoint);
      if (empty($sparql_result) || empty($sparql_result['result']['rows'])) {
        $view->result = array();
        vsm(t('No result returned. Please check your query and the endpoint status.'));
        return;
      }
      $rows = $sparql_result['result']['rows'];
      $fields = $sparql_result['result']['variables'];
  
      // Add the fields that were replaced by values so that we can render the
      // preset values as part of the result.
      $fields = array_merge($fields, array_keys($this->replacements));
      foreach ($rows as $row) {
        $views_row = array();
        foreach($fields as $field) {
          if (isset($row[$field])) {
            $views_row[$field] = $row[$field];
          }
          else if (isset($this->replacements[$field])) {
            $views_row[$field] = $this->replacements[$field]['replacement_raw'];
          }
        }
        $views_result[] = (object) $views_row;
      }
      if ($this->options['consolidate']) {
        $view->result = $this->consolidate_results($views_result);
      }
      else {
        $view->result = $views_result;
      }

      if ($this->pager->use_pager()) {
        $view->total_rows = $this->pager->get_total_items();
      } else {
        $view->total_rows = count($view->result);
      }
    }
    catch (Exception $e) {
      $view->result = array();
      if (!empty($view->live_preview)) {
        drupal_set_message(time());
        drupal_set_message($e->getMessage(), 'error');
      }
      else {
        vpr('Exception in @human_name[@view_name]: @message', array('@human_name' => $view->human_name, '@view_name' => $view->name, '@message' => $e->getMessage()));
      }
    }

    $view->execute_time = microtime(TRUE) - $start;
  }

  function add_triple($subject, $predicate, $object, $options = array()) {
    $i = 1;
    $alias = $object;

    $defaults = array(
      '#select' => FALSE,
      '#optional' => FALSE,
    );

    $options = array_merge($defaults, $options);
    while (in_array(preg_replace('/^\?/', '', $alias), $this->select_fields)) {
      $alias = $object . '_' . $i;
      $i++;
    }

    $o = $alias;
    if ($options['#select'] == TRUE) {
      $alias = preg_replace('/^\?/', '', $alias);
      $this->select_fields[] = $alias;
    }
    $this->triples[$subject]['pred_obj'][] = array_merge(array('p' => $predicate, 'o' => $o), $options);

    return $alias;
  }

  function add_relationship_triple($subject, $predicate, $object, $options = array()) {
    $alias = $this->add_triple($subject, $predicate, $object, $options);
    $field_alias = preg_replace('/^\?/', '', $alias);
    $this->relationship_fields[$field_alias] = array('field' => $field_alias, 'parent' => $subject);
    return $alias;
  }

  function add_filter($function, $params) {
    $operators = array('=', '<', '>');
    if (in_array($function, $operators)) {
      $this->filters[] = "({$params[0]} $function {$params[1]})";
    }
    else {
      $params = implode(', ',$params);
      $this->filters[] = "$function($params)";
    }
  }

  function add_orderby($field_name, $order) {
    $this->orderby[$field_name] = $order;
  }

  /**
   * Set a LIMIT on the query, specifying a maximum number of results.
   */
  function set_limit($limit) {
    $this->limit = $limit;
  }

  function consolidate_results($views_result) {
    $results = array();
    $columns = array_keys((array) $views_result[0]);
    $triples = $this->triples;
    $subjects = array_keys($triples);
    $properties = array_diff($columns, $subjects);

    // Get all the rows that share the same subject
    foreach ($views_result as $key => $value) {
      foreach ($subjects as $sub_key => $subject) {
        // If the URI is included as a field, use it to consolidate. Otherwise
        // consolidate on the subject that comes directly before.
        if (isset($value->{$subject})) {
          $row_key = $subject;
          $row_subjects[$key][$subject] = $value->{$subject};
        }
        else {
          $row_key = $subjects[$sub_key - 1];
        }
        foreach ($triples[$subject]['pred_obj'] as $pred_obj) {
          $field = substr($pred_obj['o'], 1);
          if (in_array($field, $properties)) {
            $subject_uris[$row_key][$value->{$row_key}][$field][$value->{$field}] = $value->{$field};
          }
        }
      }
    }
    $rows = _sparql_views_super_unique($row_subjects);
    // The row key will be the first occurance of the subject.
    foreach ($rows as $key => $row) {
      foreach ($row as $subject_field_name => $subject) {
        $results[$key][$subject_field_name][] = $subject;
        if (is_array($subject_uris[$subject_field_name][$subject])) {
          $results[$key] += $subject_uris[$subject_field_name][$subject];
        }
      }
    }
    return $results;
  }

  function validate_curie($curie) {
    // If this starts with http, it isn't a CURIE.
    if (preg_match('/^http/', $curie)) {
      return $curie;
    }

    $split = explode(':', $curie);
    if(count($split) == 2) {
      $this->required_namespaces[] = $split[0];
    }
    return $curie; 
  }

  function format_replacement($replacement, $value_type, $language = NULL) {
    switch($value_type){
      case 'uri':
        $replacement_formatted = preg_match('/^http/', $replacement) ? "<$replacement>" : $this->validate_curie($replacement);
        break;
      case 'string':
        $replacement_formatted = '"' . $replacement . '"';
        if (!empty($language)) {
          $replacement_formatted .= "@$language";
        }
        break;
    }
    return $replacement_formatted;
  }
}

function _sparql_views_super_unique($array)
{
  $result = array_map("unserialize", array_unique(array_map("serialize", $array)));

  foreach ($result as $key => $value) {
    if (is_array($value)) {
      $result[$key] = _sparql_views_super_unique($value);
    }
  }

  return $result;
}
