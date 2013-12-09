<?php
/**
 * @file
 * Views filter handler to display UI for WHERE clauses and prepare them for
 * the query.
 */

class sparql_views_handler_filter_rdftype extends sparql_views_handler_filter{  
  /**
   * This kind of construct makes it relatively easy for a child class
   * to add or remove functionality by overriding this function and
   * adding/removing items from this array.
   */
  function operators() {
    $operators = array(
      '=' => array(
        'title' => t('Is equal to'),
        'short' => t('='),
        'method' => 'op_equal',
        'values' => 1,
      ),
    );
    return $operators;
  }

  function admin_summary() {
    $output = $this->operator . ' ';
    $output .= check_plain($this->options['value']);
    return $output;
  }
  
  function value_form(&$form, &$form_state) {
    // We have to make some choices when creating this as an exposed
    // filter form. For example, if the operator is locked and thus
    // not rendered, we can't render dependencies; instead we only
    // render the form items we need.
    $which = 'all';
    if (!empty($form['operator'])) {
      $source = ($form['operator']['#type'] == 'radios') ? 'radio:options[operator]' : 'edit-options-operator';
    }
    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];

      if (empty($this->options['expose']['use_operator']) || empty($this->options['expose']['operator'])) {
        // exposed and locked.
        $which = in_array($this->operator, $this->operator_values(1)) ? 'value' : 'none';
      }
      else {
        $source = 'edit-' . drupal_html_id($this->options['expose']['operator']);
      }
    }

    if ($which == 'all' || $which == 'value') {
      $value = $this->value;
      if (empty($this->value) && count($this->definition['rdf_type']) > 0) {
        $value = reset($this->definition['rdf_type']);
      }
      $form['value'] = array(
        '#type' => 'textfield',
        '#title' => t('Value'),
        '#size' => 60,
        '#default_value' => $value,
      );
      if (!empty($form_state['exposed']) && !isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $this->value;
      }

      if ($which == 'all') {
        $form['value'] += array(
          '#process' => array('ctools_dependent_process'),
          '#dependency' => array($source => $this->operator_values(1)),
        );
      }
    }

    if (!isset($form['value'])) {
      // Ensure there is something in the 'value'.
      $form['value'] = array(
        '#type' => 'value',
        '#value' => NULL
      );
    }
  }

  function query() {
    $field_name = $this->real_field;
    $info = $this->operators();
    if (!empty($info[$this->operator]['method'])) {
      $this->{$info[$this->operator]['method']}($field_name);
    }
  }
  
  function op_equal($field_name) {
    $object = $this->query->format_replacement($this->options['value'], 'uri');
    $relationship = $this->options['relationship'];

    if ($relationship == 'none') {
      $subject = $this->definition['subject'];
    }
    else {
      $subject = $relationship;
    }

    // All RDF types have predicate rdf:type.
    $predicate = 'rdf:type';
    $this->query->add_triple($subject, $predicate, $object);
  }
}
