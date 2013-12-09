<?php
// $Id: semantic_similarity.crud.inc,v 1.2 2011/02/04 00:21:26 benoitborrel Exp $

/**
 * @file
 * Semantic Similarity module Create, Retrieve, Update and Delete functions.
 */

/**
 * Returns sorted list of published node ids for which content has not been
 * exported to the filesystem yet. If $nid specified, it will be excluded from
 * the list.
 *
 * @param int $nid
 *   The node id to exclude from the list. Default to NULL.
 *
 * @return array $nids
 *   The num-keyed array of node ids not in the corpus.
 */
function _semantic_similarity_get_nids_not_exported($nid = NULL) {
  $nids = array();

  // Get all published nids from database but the one passed in parameter
  if ($nid) {
    $sql = "SELECT nid from {node} WHERE status = :node_published AND nid <> :nid ORDER BY nid";
    $result = db_query($sql, array(':node_published' => NODE_PUBLISHED, ':nid' => $nid));
  }
  else {
    $sql = "SELECT nid from {node} WHERE status = :node_published ORDER BY nid";
    $result = db_query($sql, array(':node_published' => NODE_PUBLISHED));
  }
  foreach ($result as $record) {
    $nids[] = $record->nid;
  }

  // Parse nids from corpus/filesystem and remove their match from $nids
  $corpus = file_scan_directory(SEMANTIC_SIMILARITY_CORPUS_PATH, '/([0-9]+)/', array('recurse' => FALSE, 'key' => 'name'));
  ksort($corpus);

  // Filter out corpus nids from $nids
  foreach ($corpus as $corpus_k => $corpus_v) {
    if ($nids_k = array_search($corpus_k, $nids)) {
      unset($nids[$nids_k]);
    }
  }

  return $nids;
}

/**
 * Returns ids of published nodes which are missing some semantic similarity
 * scores with other nodes.
 *
 * @return array
 *   A num-keyed array of node ids missing some semantic scores.
 */
function _semantic_similarity_get_nids_missing_scores() {
  $nids = array();

  // Get number of possible scores per nid
  $result = db_query("SELECT COUNT(n.nid) AS nb_nodes FROM {node} AS n WHERE status = :node_published", array(':node_published' => NODE_PUBLISHED));
  $record = $result->fetchObject();

  // Get nids for which number of scores is below number of possible scores per nid
  $sql = "
    SELECT n.nid AS nid, COUNT(n.nid) AS count
    FROM {node} AS n
    LEFT OUTER JOIN {node_semantic_similarity} AS nss ON (n.nid = nss.snid OR n.nid = nss.tnid)
    WHERE n.status = :node_published
    GROUP BY n.nid
    HAVING count < :max_nb_scores_per_node
  ";
  $result = db_query($sql, array(':node_published' => NODE_PUBLISHED, ':max_nb_scores_per_node' => $record->nb_nodes));
  foreach ($result as $record) {
    $nids[] = $record->nid;
  }

  return $nids;
}

/**
 * Return ids of published nodes which were changed (created or updated) since last cron.
 *
 * @return array
 *   A num-keyed array of node ids changed since last cron.
 */
function _semantic_similarity_get_nids_changed_since_last_cron() {
  $nids = array();

  // Get all nids created/updated since last cron
  $sql = "SELECT n.nid AS nid FROM {node} AS n WHERE n.status = :node_published AND n.changed > :changed";
  $result = db_query($sql, array(':node_published' => NODE_PUBLISHED, ':changed' => variable_get('cron_last', 0)));
  foreach ($result as $record) {
    $nids[] = $record->nid;
  }

  return $nids;
}

/**
 * Saves nodes' semantic similarity scores into database.
 *
 * @param array &$scores
 *   The node ids nids-keyed array of scores.
 */
function _semantic_similarity_save_scores(&$scores) {
  // Delete previous scores from database
  _semantic_similarity_delete_scores();

  // Insert new scores into database
  foreach ($scores as $snid => $tnids) {
    foreach ($tnids as $tnid => $score) {
      $values[] = array(
        'snid'  => $snid,
        'tnid'  => $tnid,
        'score' => $score,
      );
    }
  }
  $query = db_insert('node_semantic_similarity')->fields(array('snid', 'tnid', 'score'));
  foreach ($values as $record) {
    $query->values($record);
  }
  $query->execute();
}

/**
 * Deletes node's / all semantic similarity scores from database.
 *
 * @param int $nid
 *   The node id for which we delete scores. If NULL we delete all scores.
 */
function _semantic_similarity_delete_scores($nid = NULL) {
  if ($nid) {
    // Delete previous scores from database
    $num_deleted = db_delete('node_semantic_similarity')
      ->condition(db_or()->condition('snid', $nid)->condition('tnid', $nid))
      ->execute();
  }
  else {
    $result = db_query("TRUNCATE {node_semantic_similarity}");
  }
}

/**
 * Returns pair of most similar node ids (source and target node) and their
 * score.
 *
 * @param string $order
 *   The order of the result set. Either DESC for most or ASC for least
 *   similars.
 * @param int $limit
 *   The number of records to return.
 *
 * @return array $data
 *   A num-keyed 2D array of nids with their title and score. Format is
 *   array(array('snid', 'tnid', 'score', 'title1', 'title2')).
 */
function _semantic_similarity_get_scored_nids($order = 'DESC', $limit) {
  $data = array();

  // dynamic query to the sole reason that we need node access restrictions
  $query = db_select('node_semantic_similarity', 'nss');
  $n1_alias = $query->leftJoin('node', 'n1', 'n1.nid = nss.snid');
  $n2_alias = $query->leftJoin('node', 'n2', 'n2.nid = nss.tnid');
  $query->fields('nss', array('snid', 'tnid', 'score'));
  $title1_field = $query->addField('n1', 'title', 'title1');
  $title2_field = $query->addField('n2', 'title', 'title2');
  $query
    ->condition('n1.status', NODE_PUBLISHED)
    ->condition('n2.status', NODE_PUBLISHED)
    ->orderBy('nss.score', $order)
    ->range(0, $limit)
    ->addTag('node_access');
  $result = $query->execute();

  foreach ($result as $record) {
    $data[] = array(
      'snid'   => $record->snid,
      'tnid'   => $record->tnid,
      'score'  => $record->score,
      'title1' => $record->title1,
      'title2' => $record->title2,
    );
  }

  return $data;
}

/**
 * Returns node id most/least similar node ids and their score.
 *
 * @param int $nid
 *   The node id for which we want the semantically similar node ids.
 * @param string $order
 *   The order of the result set. Either DESC for most or ASC for least
 *   similars.
 * @param int $limit
 *   The number of records to return.
 *
 * @return array $data
 *   A num-keyed 2D array of nids with their title and score. Format is
 *   array(array('nid', 'score', 'title')).
 */
function _semantic_similarity_get_node_scored_nids($nid, $order = 'DESC', $limit) {
  $data = array();

  // dynamic query to the sole reason that we need node access restrictions
  $query = db_select('node_semantic_similarity', 'nss');
  $n_alias = $query->join('node', 'n', '(n.nid = nss.snid OR n.nid = nss.tnid)');
  $query
    ->fields('nss', array('score'))
    ->condition('n.status', NODE_PUBLISHED)
    ->condition('n.nid', $nid, '<>')
    ->condition(db_or()->condition('nss.tnid', $nid)->condition('nss.snid', $nid))
    ->orderBy('nss.score', $order)
    ->range(0, $limit)
    ->addTag('node_access');
  $nid_field = $query->addField('n', 'nid', 'nid');
  $title_field = $query->addField('n', 'title', 'title');
  $result = $query->execute();

  foreach ($result as $record) {
    $data[] = array(
      'nid'   => $record->nid,
      'score' => $record->score,
      'title' => $record->title,
    );
  }

  return $data;
}
