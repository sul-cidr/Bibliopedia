<?php
/**
 * SPARQL Views arguments.
 *
 * The argument enables re-writing the argument. For instance, if someone goes
 * to http://example.org/Pittsburgh, this argument could be rewritten to
 * http://dbpedia.org/resource/Pittsburgh.
 */
class sparql_views_handler_argument_subject extends sparql_views_handler_argument {
  //@todo This should never be a number. Remove that as an option.  

  /**
   * Set up the query for this argument.
   *
   * The argument sent may be found at $this->argument.
   */
  function query() {
    ob_start();
    $return = eval($this->options['sparql_options']['code']);
    ob_end_clean();

    $replacement = !empty($return) ? $return : $this->argument;
    $relationship = $this->options['relationship'];

    if ($relationship == 'none') {
      $subject = $this->definition['subject'];
    }
    else {
      $subject = $relationship;
    }

    if (!empty($replacement)) {
      $value_type = $this->options['sparql_options']['value_type'];
      $language = $this->options['sparql_options']['language'];
      $object = $this->query->format_replacement($replacement, $value_type, $language);

      $this->query->add_filter('=', array('?' . $subject, $object));
    }
  }
}