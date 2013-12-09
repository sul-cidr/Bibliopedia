<?php
// $Id: semantic_similarity.admin.inc,v 1.6 2011/02/04 00:21:26 benoitborrel Exp $

/**
 * @file
 * Semantic Similarity module admin page callbacks.
 */

/**
 * Form builder for the semantic similarity admin form.
 *
 * @see system_settings_form()
 * @see system_settings_form_validate()
 * @see system_settings_form_submit()
 * @ingroup forms
 */
function semantic_similarity_admin_settings(&$form_state) {
  $form = array();

  // Preprocess settings
  $form['preprocess'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Preprocess'),
  );
  $form['preprocess']['semantic_similarity_stopwords'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Enable stopwords filtering'),
    '#default_value' => variable_get('semantic_similarity_stopwords', SEMANTIC_SIMILARITY_DEFAULT_STOPWORDS),
    '#description'   => t('If enabled, the scores will be computed excluding empty words (<em>only english is supported though</em>).'),
  );
  $form['preprocess']['semantic_similarity_stemming'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Enable stemming'),
    '#default_value' => variable_get('semantic_similarity_stemming', SEMANTIC_SIMILARITY_DEFAULT_STEMMING),
    '#description'   => t('If enabled, the scores will be computed from the stem of the words.'),
  );

  // Process settings
  $form['process'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Process'),
  );
  $form['process']['semantic_similarity_weighting'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Enable weighting'),
    '#default_value' => variable_get('semantic_similarity_weighting', SEMANTIC_SIMILARITY_DEFAULT_WEIGHTING),
    '#description'   => t('If enabled, the scores will be computed using weighting.'),
  );
  $form['process']['weighting'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Weighting'),
    '#collapsible' => TRUE,
    '#collapsed'   => !variable_get('semantic_similarity_weighting', SEMANTIC_SIMILARITY_DEFAULT_WEIGHTING),
  );
  $form['process']['weighting']['semantic_similarity_weitghting_scope'] = array(
    '#type'          => 'radios',
    '#title'         => t('Scope'),
    '#default_value' => variable_get('semantic_similarity_weitghting_scope', SEMANTIC_SIMILARITY_DEFAULT_WEIGHTING_SCOPE),
    '#options'       => array(
      'lw'   => t('local'),
      'lwgw' => t('local and global')
    ),
    '#description'   => t('Scope of the weighting to apply on the term node matrix.'),
  );
  $form['process']['weighting']['semantic_similarity_lw_scheme'] = array(
    '#type'          => 'radios',
    '#title'         => t('Local weighting scheme'),
    '#default_value' => variable_get('semantic_similarity_lw_scheme', SEMANTIC_SIMILARITY_DEFAULT_LW_SCHEME),
    '#options'       => array(
      'lw_logtf' => t('logarithmic'),
      'lw_bintf' => t('binary')
    ),
    '#description'   => t('Scheme of the local weighting to apply on the term node matrix.'),
  );
  $form['process']['weighting']['semantic_similarity_lw_scheme']['help'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Help'),
    '#collapsed'    => TRUE,
    '#collapsible'  => TRUE,
    '#weight'       => 1,
    '#description'  =>
      '<dl>'
        . '<dt>' . t('logarithmic') . '</dt>'
        . '<dd>' . t('returns the logarithmised n × m matrix; log(m<sub>i,j</sub> + 1) is applied on every cell') . '</dd>'
        . '<dt>' . t('binary') . '</dt>'
        . '<dd>' . t('returns binary values of the n × m matrix. Every cell is assigned 1, iff the term frequency is not equal to 0') . '</dd>'
      . '</dl>',
  );

  $form['process']['weighting']['semantic_similarity_gw_scheme'] = array(
    '#type'          => 'radios',
    '#title'         => t('Global weighting scheme'),
    '#default_value' => variable_get('semantic_similarity_gw_scheme', SEMANTIC_SIMILARITY_DEFAULT_GW_SCHEME),
    '#options'       => array(
      'gw_normalisation' => t('normalisation'),
      'gw_idf'           => t('Inverse Document Frequency (IDF)'),
      'gw_gfidf'         => t('product of global frequency and IDF (GfIdf)'),
      'entropy'          => t('entropy'),
      'gw_entropy'       => t('one plus entropy'),
    ),
    '#description'   => t('Scheme of the global weighting to apply on the term node matrix.'),
  );
  $form['process']['weighting']['semantic_similarity_gw_scheme']['help'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Help'),
    '#collapsed'    => TRUE,
    '#collapsible'  => TRUE,
    '#weight'       => 1,
    '#description'  =>
      '<dl>'
        . '<dt>' . t('normalisation') . '</dt>'
        . '<dd>' . t('returns a normalised n × m matrix; every cell equals 1 divided by the square root of the document vector length') . '</dd>'
        . '<dt>' . t('Inverse Document Frequency (IDF)') . '</dt>'
        . '<dd>' . t('returns the inverse document frequency in a n × m matrix; every cell is 1 plus the logarithmus of the number of documents divided by the number of documents where the term appears') . '</dd>'
        . '<dt>' . t('product of global frequency and IDF (GfIdf)') . '</dt>'
        . '<dd>' . t('calculates the number of singular values according to the Kaiser-Criterium, i.e. from the descending order of values all values with sequence_of_singular_values[n] > 1 will be taken') . '</dd>'
        . '<dt>' . t('entropy') . '</dt>'
        . '<dd>' . t('returns the entropy (as defined by Shannon)') . '</dd>'
        . '<dt>' . t('one plus entropy') . '</dt>'
        . '<dd>' . t('eturns one plus entropy') . '</dd>'
      . '</dl>',
  );
  $form['process']['semantic_similarity_lsa'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Enable Latent Semantic Analysis'),
    '#default_value' => variable_get('semantic_similarity_lsa', SEMANTIC_SIMILARITY_DEFAULT_LSA),
    '#description'   => t('If enabled, the scores will be computed semantically using Latent Semantic Analysis.')
                        . t('The rank of the term node matrix will be reduced by Singular Value Decomposition (SVD).'),
  );
  $form['process']['lsa'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Latent Semantic Analysis'),
    '#collapsible' => TRUE,
    '#collapsed'   => !variable_get('semantic_similarity_lsa', SEMANTIC_SIMILARITY_DEFAULT_LSA),
  );
  $form['process']['lsa']['semantic_similarity_lsa_dimcalc'] = array(
    '#type'          => 'radios',
    '#title'         => t('Singular Value Decomposition method'),
    '#default_value' => variable_get('semantic_similarity_lsa_dimcalc', SEMANTIC_SIMILARITY_DEFAULT_LSA_DIMCALC),
    '#options'       => array(
      'share'    => t('share') . ' <em>' . t('(fixed at 0.5)') . '</em>',
      'ndocs'    => t('number of nodes'),
      'kaiser'   => t('Kaiser-Criterium'),
      'raw'      => t('raw'),
      //'fraction' => t('fraction'),
    ),
    '#description'   => t('Method for choosing a ‘good’ number of singular values for the dimensionality reduction of the term node matrix.'),
  );
  $form['process']['lsa']['semantic_similarity_lsa_dimcalc']['help'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Help'),
    '#collapsed'    => TRUE,
    '#collapsible'  => TRUE,
    '#weight'       => 1,
    '#description'  =>
      '<dl>'
        . '<dt>' . t('share') . '</dt>'
        . '<dd>' . t('finds the first position in the descending sequence of singular values where their sum (divided by the sum of all values) meets or exceeds the specified share') . '</dd>'
        . '<dt>' . t('number of nodes') . '</dt>'
        . '<dd>' . t('calculates the first position in the descending sequence of singular values where their sum meets or exceeds the number of nodes') . '</dd>'
        . '<dt>' . t('Kaiser-Criterium') . '</dt>'
        . '<dd>' . t('calculates the number of singular values according to the Kaiser-Criterium, i.e. from the descending order of values all values with sequence_of_singular_values[n] > 1 will be taken') . '</dd>'
        . '<dt>' . t('raw') . '</dt>'
        . '<dd>' . t('return the maximum number of singular values (= the length of sequence_of_simgular_values)') . '</dd>'
        . '<dt>' . t('fraction') . '</dt>'
        . '<dd>' . t('returns the specified share of the number of singular value') . '</dd>'
      . '</dl>',
  );

  // Postprocess settings
  $form['postprocess'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Postprocess'),
  );
  $form['postprocess']['semantic_similarity_correlation'] = array(
    '#type'          => 'radios',
    '#title'         => t('Correlation method'),
    '#default_value' => variable_get('semantic_similarity_correlation', SEMANTIC_SIMILARITY_DEFAULT_CORRELATION),
    '#options'       => drupal_map_assoc(array('cosine', 'Pearson', 'Spearman'), 't'),
    '#description'   => t('Mathematical method to compute distance between nodes vectors.'),
  );

  // Display settings
  $form['display'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Display'),
  );
  $form['display']['semantic_similarity_limit'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Limit of nodes to list'),
    '#default_value' => variable_get('semantic_similarity_limit', SEMANTIC_SIMILARITY_DEFAULT_LIMIT),
    '#description'   => t('Number of nodes to list in the module blocks.'),
    '#size'          => 2,
  );

  return system_settings_form($form);
}
