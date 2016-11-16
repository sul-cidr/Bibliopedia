<?php
/**
 * @file
 * Provide default interactions.
 */

/**
 * Implements hook_default_openlayers_interactions().
 */
function openlayers_examples_default_openlayers_interactions() {
  $export = array();

  $ol_interaction = new stdClass();
  $ol_interaction->disabled = FALSE; /* Edit this to true to make a default ol_interaction disabled initially */
  $ol_interaction->api_version = 1;
  $ol_interaction->machine_name = 'openlayers_examples_interaction_select';
  $ol_interaction->name = 'Openlayers examples: Select';
  $ol_interaction->description = '';
  $ol_interaction->factory_service = 'openlayers.Interaction:Select';
  $ol_interaction->options = array(
    'style' => 'openlayers_style_select',
    'multi' => 1,
  );
  $export['openlayers_examples_interaction_select'] = $ol_interaction;

  return $export;
}
