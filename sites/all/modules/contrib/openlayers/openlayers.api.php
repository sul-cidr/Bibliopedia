<?php

/**
 * @file
 * Hooks for openlayers module.
 */

/**
 * This hook will be triggered before a map is built and on each of its object.
 *
 * @param array $build
 *   The render array that will be rendered later.
 * @param \Drupal\openlayers\Types\ObjectInterface $context
 *   The context, this will be an openlayers object.
 */
function hook_openlayers_object_preprocess_alter(array &$build, \Drupal\openlayers\Types\ObjectInterface $context) {

}

/**
 * This hook will be triggered after a map is built and on each of its object.
 *
 * @param array $build
 *   The render array that will be rendered after this hook.
 * @param \Drupal\openlayers\Types\ObjectInterface $context
 *   The context, this will be an openlayers object.
 */
function hook_openlayers_object_postprocess_alter(array &$build, \Drupal\openlayers\Types\ObjectInterface $context) {

}
