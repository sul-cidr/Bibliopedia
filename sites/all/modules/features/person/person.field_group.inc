<?php
/**
 * @file
 * person.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function person_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_birth_info|node|person|form';
  $field_group->group_name = 'group_birth_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Birth Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_birth_date_exact',
      1 => 'field_birth_date_approx',
      2 => 'field_birth_place',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-birth-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_birth_info|node|person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_death_info|node|person|form';
  $field_group->group_name = 'group_death_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Death Information',
    'weight' => '7',
    'children' => array(
      0 => 'field_death_date_exact',
      1 => 'field_death_date_approx',
      2 => 'field_death_place',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-death-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_death_info|node|person|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Birth Information');
  t('Death Information');

  return $field_groups;
}
