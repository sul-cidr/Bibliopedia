<?php
/**
 * @file
 * SPARQL Views relationship handler.
 */

/**
 * Simple relationship handler that allows traversing a graph through
 * relationships between resources.
 */
class sparql_views_handler_relationship extends views_handler_relationship {
  /**
   * Override; Change the default required status to TRUE.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['required'] = array('default' => TRUE);

    return $options;
  }

  /**
   * Override; Change the wording of the required checkbox to match fields.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['required']['#title'] = t('Require this relationship (not OPTIONAL)');
  }

  /**
   * Override; Avoid the call to ensure_mytable. We aren't using tables, so we
   * don't need to ensure one.
   */
  function query() {
    $object = $this->options['id'];
    $relationship = $this->options['relationship'];

    if ($relationship == 'none') {
      $subject = $this->definition['subject'];
    }
    else {
      $subject = $relationship;
    }
    $predicate = $this->definition['rdf_mapping'][0];
    $optional = empty($this->options['required']);
    $this->field_alias = $this->query->add_relationship_triple($subject, $predicate, '?' . $object, array('#optional' => $optional));
  }
}
