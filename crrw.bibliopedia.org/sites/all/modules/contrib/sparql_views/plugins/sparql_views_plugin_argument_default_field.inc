<?php
/**
 * @file
 * Argument default to retrieve a field value from the node.
 */

/**
 * The fixed argument default handler; also used as the base.
 */
class sparql_views_plugin_argument_default_field extends views_plugin_argument_default {
  // We will use the value type and language form elements for getting
  // necessary info about replacements that this argument makes.
  var $selected_sparql_options = array('value_type', 'language');
  /**
   * Return the default argument.
   *
   * This needs to be overridden by every default argument handler to properly do what is needed.
   */
  function get_argument() {
    foreach (range(1, 3) as $i) {
      $node = menu_get_object('node', $i);
      if (!empty($node)) {
        $nid = $node->nid;
        $source_field = $this->options['sparql_options']['source_field'];
        $field = field_get_items('node', $node, $source_field);
        $replacement = $field[0]['value'];

        return $replacement;
      }
    }
  }

  /**
   * Retrieve the options when this is a new access
   * control plugin
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['source_field'] = array('default' => '');
    // Attach the SPARQL specific options.

    return $options;
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $fields = array();
    $instance_info = field_info_instances('node');
    foreach ($instance_info as $bundle) {
      foreach ($bundle as $field_name => $field_info) {
        $fields[$field_name] = check_plain(t($field_info['label']));
      }
    }
    $form['sparql_options']['source_field'] = array(
      '#type' => 'select',
      '#title' => t('Source Field'),
      '#options' => $fields,
      '#default_value' => $this->options['sparql_options']['source_field'],
      '#description' => t('The variable in the query will be replaced with the value of this field on the node.'),
      '#weight' => -1,
    );
  }
}

