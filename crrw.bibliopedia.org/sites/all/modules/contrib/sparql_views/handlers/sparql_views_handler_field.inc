<?php
/**
 * Helper function: Return an array of formatter options for a field type.
 *
 * Borrowed from field_ui.
 */
function _sparql_views_field_formatter_options($field_type = NULL) {
  $options = &drupal_static(__FUNCTION__);

  if (!isset($options)) {
    $field_types = field_info_field_types();
    $options = array();
    foreach (field_info_formatter_types() as $name => $formatter) {
      foreach ($formatter['field types'] as $formatter_field_type) {
        // Check that the field type exists.
        if (isset($field_types[$formatter_field_type])) {
          $options[$formatter_field_type][$name] = $formatter['label'];
        }
      }
    }
  }

  if ($field_type) {
    return !empty($options[$field_type]) ? $options[$field_type] : array();
  }
  return $options;
}

/**
 * Base field handler that has no options and renders an unformatted field.
 *
 * Definition terms:
 * - additional fields: An array of fields that should be added to the query
 *                      for some purpose. The array is in the form of:
 *                      array('identifier' => array('table' => tablename,
 *                      'field' => fieldname); as many fields as are necessary
 *                      may be in this array.
 * - click sortable: If TRUE, this field may be click sorted.
 */
class sparql_views_handler_field extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();

    if (!empty($this->definition['field_info'])) {
      // Set the field formatter based on the field definition. This would have
      // been set either by a user through the Field UI or in a module's code
      // definition of a bundle.
      $field = $this->definition['field_info'];
      $field_type = field_info_field_types($field['type']);
      $options['type'] = array(
        'default' => $field_type['default_formatter'],
      );
    }
    else {
      // Some fields, such as subject URI fields, are not full fledged Field
      // API fields. Give them a default text handler.
      // @todo Should non-field API fields just not have this handler as a parent?
      $options['type'] = array(
        'default' => 'text_default',
      );
    }
    $options['required'] = array(
      'default' => TRUE,
    );
    $options['settings'] = array(
      'default' => array(),
    );

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // If this is not a Field API field, there are no formatting options.
    // @todo Should non-field API fields just not have this handler as a parent?
    if (empty($this->definition['field_info'])) {
      return;
    }

    $field = $this->definition['field_info'];
    $formatters = _sparql_views_field_formatter_options($field['type']);

    $form['required'] = array(
      '#type' => 'checkbox',
      '#title' => t('Require a value for this field (not OPTIONAL).'),
      '#default_value' => $this->options['required'],
      '#ajax' => array(
        'path' => views_ui_build_form_url($form_state),
      ),
    );

    $form['type'] = array(
      '#type' => 'select',
      '#title' => t('Formatter'),
      '#options' => $formatters,
      '#default_value' => $this->options['type'],
      '#ajax' => array(
        'path' => views_ui_build_form_url($form_state),
      ),
    );

    // Get the currently selected formatter.
    if (isset($form_state['values']['options']['type'])) {
      $format = $form_state['values']['options']['type'];
    }
    else {
      $format = $this->options['type'];
    }
    $formatter = field_info_formatter_types($format);
    $settings = $this->options['settings'] + field_info_formatter_settings($format);

    // Provide an instance array for hook_field_formatter_settings_form().
    ctools_include('fields');
    $instance = ctools_fields_fake_field_instance($this->definition['field_info']['field_name'], '_dummy', $formatter, $settings);

    // Store the settings in a '_dummy' view mode.
    $instance['display']['_dummy'] = array(
      'type' => $format,
      'settings' => $settings,
    );

    // Get the settings form.
    $settings_form = array('#value' => array());
    $function = $formatter['module'] . '_field_formatter_settings_form';
    if (function_exists($function)) {
      $settings_form = $function($field, $instance, '_dummy', $form, $form_state);
    }

    $form['settings'] = $settings_form;
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
    $object = $this->real_field;
    $relationship = $this->options['relationship'];
    $optional = empty($this->options['required']);
    if ($relationship == 'none') {
      $subject = $this->definition['subject'];
    }
    else {
      $subject = $relationship;
    }
    $predicate = $this->definition['rdf_mapping'][0];
    $this->field_alias = $this->query->add_triple($subject, $predicate, '?' . $object, array('#select' => TRUE, '#optional' => $optional));
  }

  function click_sort($order) {
    $this->query->add_orderby($this->field_alias, $order);
  }

  /**
   * This kind of construct makes it relatively easy for a child class
   * to add or remove functionality by overriding this function and
   * adding/removing items from this array.
   */
  function formatters() {
    $formatters = &drupal_static(__FUNCTION__);

    if (!isset($options)) {
      $formatters = array(
        'list_default' => array(
          'method' => 'render_field_formatter',
        ),
        'list_key' => array(
          'method' => 'render_field_formatter',
        ),
        'number_integer' => array(
          'method' => 'render_field_formatter',
        ),
        'number_decimal' => array(
          'method' => 'render_field_formatter',
        ),
        'number_unformatted' => array(
          'method' => 'render_field_formatter',
        ),
        'text_default' => array(
          'method' => 'render_field_formatter',
        ),
        'text_trimmed' => array(
          'method' => 'render_field_formatter',
        ),
        'text_summary_or_trimmed' => array(
          'method' => 'render_field_formatter',
        ),
        'text_plain' => array(
          'method' => 'render_field_formatter',
        ),
        // Special handling required.
        'image' => array(
          'method' => 'image',
        ),
      );
    }
    return $formatters;
  }

  /**
   * Load the entities for all fields that are about to be displayed.
   */
  function pre_render(&$values) {
    // @todo Combine subjects.
  }

  function render($values) {
    $output = '';
    if (is_array($values)) {
      $items = array();
      foreach ($values[$this->real_field] as $value) {
        $val = (object) array($this->field_alias => $value);
        $items[] = $this->render_value($val);
      }
      if (count($items) > 1) {
        //$output = theme('item_list', array('items' => $items, 'type' => 'ul'));
        foreach ($items as $item) {
          $output .= "<div>$item</div>";
        }
      }
      else {
        $output = $items[0];
      }
    }
    else {
      $output .= $this->render_value($values);
    }
    return $output;
  }

  function render_value($val) {
    $formatter = $this->options['type'];
    $formatters = $this->formatters();
    if (!empty($formatters[$formatter]['method'])) {
      return $this->{$formatters[$formatter]['method']}($val, $formatter);
    }
    else {
      vsm("Missing formatter: $formatter");
      return parent::render($val);
    }
  }

  function render_field_formatter($values, $formatter) {
    $field_name = $this->definition['field_name'];
    $field = field_info_field($field_name);
    $value = isset($values->{$this->field_alias}) ? $values->{$this->field_alias} : $this->options['empty'];

    $items[] = array('value' => $value);
    $instances = field_info_instances('sparql_views_resource', $this->definition['bundle']);
    $display['type'] = $formatter;
    $display['settings'] = $this->options['settings'];
    $formatter_function = $field['module'] . '_field_formatter_view';
    return render($formatter_function(NULL, NULL, NULL, $instances[$field_name], NULL, $items, $display));
  }

  function image($values) {
    $item['path'] = $values->{$this->real_field};
    $image_style = $this->options['settings']['image_style'];
    $image_styles = image_styles();
    if (isset($image_styles[$image_style]['effects'])) {
      foreach ($image_styles[$image_style]['effects'] as $effect) {
        if ($effect['name'] == 'image_scale') {
          $item['width'] = $effect['data']['width'];
        }
      }
    }
    $output = theme('image', $item);
    return filter_xss($output, array('img', 'a'));
  }
}
