<?php
// $Id$

/**
 * @file
 * SPARQL Views type editing UI.
 */

/**
 * UI controller.
 */
class SparqlViewsResourceTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage SPARQL Views resource types, including fields.';
    return $items;
  }
}

/**
 * Generates the resource type editing form.
 */
function sparql_views_resource_type_form($form, &$form_state, $resource_type, $op = 'edit') {
  if ($op == 'clone') {
    $resource_type->label .= ' (cloned)';
    $resource_type->name .= '_clone';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $resource_type->label,
    '#description' => t('The human-readable label of this resource type.'),
    '#required' => TRUE,
  );
  // Machine-readable type name.
  $form['name'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($resource_type->name) ? $resource_type->name : '',
    '#disabled' => entity_has_status('sparql_views_resource_type', $resource_type, ENTITY_IN_CODE),
    '#machine_name' => array(
      'exists' => 'sparql_views_resource_type_load',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this resource type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  field_attach_form('sparql_views_resource_type', $resource_type, $form, $form_state);

  $selected_endpoints = db_query("SELECT endpoint_uri FROM {sparql_views_resource_type_endpoint} WHERE svid = :svid", array(':svid' => $resource_type->id))->fetchCol();
  $endpoints = sparql_registry_load_multiple();
  $options = array();
  foreach ($endpoints as $endpoint) {
    $options[$endpoint->uri] = $endpoint->title . ': <span class="description">' . $endpoint->uri . '</span>';
  }
  $form['endpoints'] = array(
    '#title' => t('Endpoints this resource can be found in'),
    '#type' => 'checkboxes',
    '#default_value' => !empty($selected_endpoints) ? $selected_endpoints : array(),
    '#description' => t('Different endpoints often have different ways of describing similar things. Select the endpoints that this resource can be used with and the resource and it\'s fields will show up as options in queries on the endpoints.'),
    '#options' => $options,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save resource type'),
    '#weight' => 40,
  );

  if (!entity_has_status('sparql_views_resource_type', $resource_type, ENTITY_IN_CODE) && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete resource type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('sparql_views_resource_type_form_submit_delete')
    );
  }
  return $form;
}

/**
 * Validation callback.
 */
function sparql_views_resource_type_form_validate($form, &$form_state) {
  entity_form_field_validate('sparql_views_resource_type', $form, $form_state);
}

/**
 * Form API submit callback for the type form.
 */
function sparql_views_resource_type_form_submit(&$form, &$form_state) {
  $resource_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $resource_type->save();
  $form_state['redirect'] = 'admin/structure/sparql-views';
}

/**
 * Form API submit callback for the delete button.
 */
function sparql_views_resource_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/sparql-views/manage/' . $form_state['sparql_views_resource_type']->name . '/delete';
}
