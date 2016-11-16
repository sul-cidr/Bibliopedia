<?php
/**
 * @file
 * Provides forms for the GeoJSON Source.
 */

/**
 * Form callback handler to prepare the developer dialog form.
 *
 * Prepares an object options form to be used in a frontend development dialog.
 *
 * @param array $form
 *   The form array - likely emtpy.
 * @param array $form_state
 *   The form state.
 * @param object $object
 *   The object that provides the options form. Has to have the public method
 *   optionsForms().
 *
 * @return array
 *   The populated form.
 *
 * @see \Drupal\openlayers\Plugin\Source\GeoJSON\GeoJSON::getJS()
 */
function openlayers_dev_dialog_form(array $form, array $form_state, $object) {
  $object->optionsForm($form, $form_state);
  openlayers_dev_dialog_form_clean($form);
  return $form;
}

/**
 * Prepares a form structure to be added to a development dialog.
 *
 * Removes all JS related stuff.
 *
 * @param array $form
 *   The form array to prepare.
 */
function openlayers_dev_dialog_form_clean(array &$form) {
  foreach (element_children($form) as $key) {
    unset(
      $form[$key]['#states'],
      $form[$key]['#attached']
    );
    openlayers_dev_dialog_form_clean($form[$key]);
  }
}
