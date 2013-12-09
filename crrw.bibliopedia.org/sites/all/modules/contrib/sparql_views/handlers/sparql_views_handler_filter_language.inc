<?php
/**
 * @file
 * Views filter handler to display UI for WHERE clauses and prepare them for
 * the query.
 */

class sparql_views_handler_filter_language extends sparql_views_handler_filter{

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }
  
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
    $languages = array('<none>') + _sparql_views_get_language_list();

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
      $form['value'] = array(
        '#type' => 'select',
        '#title' => t('Language'),
        '#options' => $languages,
        '#default_value' => $this->value,
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
    $field_name = $this->definition['base field'];
    $info = $this->operators();
    if (!empty($info[$this->operator]['method'])) {
      $this->{$info[$this->operator]['method']}($field_name);
    }
  }
  
  function op_equal($field_name) {
    $this->query->add_filter('langMatches', array("lang(?$field_name)", '"' . strtoupper($this->value) . '"'));
  }
}
