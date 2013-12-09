<?php

/**
 * @file
 * Provides a controller building upon the core controller but providing more
 * features like full CRUD functionality.
 */

/**
 * A controller implementing EntityAPIControllerInterface for the database 
 * which can deal with exportable SPARQL Views resources.
 */
class SparqlViewsController extends EntityAPIControllerExportable implements EntityAPIControllerInterface {

  /**
   * Implements EntityAPIControllerInterface.
   *
   * @param $transaction
   *   Optionally a DatabaseTransaction object to use. Allows overrides to pass
   *   in their transaction object.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $transaction = isset($transaction) ? $transaction : db_transaction();
    $entity_record = parent::save($entity, $transaction);

    // Add the endpoints that this resource works with.
    if (isset($entity->endpoints)) {
      $entity_id = db_query("SELECT id FROM {sparql_views_resource_type} WHERE name = :name", array(':name' => $entity->name))->fetch();
      $svid = $entity_id->id;
      $delete = db_delete('sparql_views_resource_type_endpoint')->condition('svid', $svid)->execute();
      $insert = db_insert('sparql_views_resource_type_endpoint')->fields(array('svid', 'endpoint_uri'));
      foreach ($entity->endpoints as $endpoint_uri => $selected) {
        if ($selected) {
          $insert->values(array('svid' => $svid, 'endpoint_uri' => $endpoint_uri));
        }
      }
      $insert->execute();
    }

    field_info_cache_clear();
    return $entity_record;
  }

}
