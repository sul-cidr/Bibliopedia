<?php
/**
 * Handler for a subject.
 */
class sparql_views_handler_field_subject extends sparql_views_handler_field {
  /**
  * Called to add the field to a query.
  */
  function query() {
    $subject = $this->get_subject();
    $this->query->select_fields[] = $subject;
  }

  function render_field_formatter($values, $formatter) {
    $subject = $this->get_subject();
    $items[] = array('value' => $values->$subject);
    $display['type'] = 'text_plain';
    return render(text_field_formatter_view(NULL, NULL, NULL, NULL, NULL, $items, $display));
  }

  protected function get_subject() {
    $relationship = $this->options['relationship'];
    if ($relationship == 'none') {
      $subject = $this->real_field;
    }
    else {
      $subject = $relationship;
    }
    $this->field_alias = $subject;
    return $subject;
  }
}
