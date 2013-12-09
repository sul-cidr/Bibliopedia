<?php
/**
 * @file
 * content_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_types_node_info() {
  $items = array(
    'author_page' => array(
      'name' => t('Author Page'),
      'base' => 'node_content',
      'description' => t('A page containing information about an author of a book, article, etc.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'book' => array(
      'name' => t('Book page'),
      'base' => 'node_content',
      'description' => t('<em>Books</em> have a built-in hierarchical navigation. Use for handbooks or tutorials.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'journal' => array(
      'name' => t('Journal'),
      'base' => 'node_content',
      'description' => t('A journal that publishes articles.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'journal_article' => array(
      'name' => t('Journal Article'),
      'base' => 'node_content',
      'description' => t('An article from a journal. Not to be confused with Drupal\'s core "Article" type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'person_page' => array(
      'name' => t('Person page'),
      'base' => 'node_content',
      'description' => t('A page about a person. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'pointer' => array(
      'name' => t('Pointer'),
      'base' => 'node_content',
      'description' => t('A pointer to another node. We don\'t want direct references so that we can keep links stable while correcting them as needed.'),
      'has_title' => '1',
      'title_label' => t('ID'),
      'help' => t('Humans shouldn\'t usually be creating pointers. You can, if you want and know why you\'re doing it, but these are mostly for the automated processes.'),
    ),
  );
  return $items;
}

/**
 * Implements hook_rdf_default_mappings().
 */
function content_types_rdf_default_mappings() {
  $rdf_mappings = array();

  // Exported RDF mapping: journal_lookup_via_linked_periodicals
  $rdf_mappings['sparql_views_resource']['journal_lookup_via_linked_periodicals'] = array(
    'field_issn' => array(
      'type' => 'property',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'bibo:issn',
      ),
    ),
    'field_eissn' => array(
      'type' => 'property',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'bibo:eissn',
      ),
    ),
    'field_publisher' => array(
      'type' => 'rel',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'dc:publisher',
      ),
    ),
    'field_title' => array(
      'type' => 'property',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
  );

  // Exported RDF mapping: library_of_congress_subject_headings_
  $rdf_mappings['taxonomy_term']['library_of_congress_subject_headings_'] = array(
    'rdftype' => array(
      0 => 'skos:Concept',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'rdfs:label',
        1 => 'skos:prefLabel',
      ),
    ),
    'description' => array(
      'predicates' => array(
        0 => 'skos:definition',
      ),
    ),
    'vid' => array(
      'predicates' => array(
        0 => 'skos:inScheme',
      ),
      'type' => 'rel',
    ),
    'parent' => array(
      'predicates' => array(
        0 => 'skos:broader',
      ),
      'type' => 'rel',
    ),
  );

  // Exported RDF mapping: book
  $rdf_mappings['node']['book'] = array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  );

  // Exported RDF mapping: person_page
  $rdf_mappings['node']['person_page'] = array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
  );

  // Exported RDF mapping: author_page
  $rdf_mappings['node']['author_page'] = array(
    'rdftype' => array(
      0 => 'foaf:Person',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'foaf:familyName',
        1 => 'foaf:lastName',
      ),
      'type' => 'property',
      'datatype' => 'xsd:string',
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'field_birth' => array(
      'type' => 'property',
      'datatype' => 'xsd:date',
      'predicates' => array(
        0 => 'foaf:birthday',
      ),
    ),
    'field_biography' => array(
      'type' => 'property',
      'predicates' => array(
        0 => 'foaf',
      ),
    ),
    'field_homepage' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'foaf:homepage',
      ),
    ),
  );

  // Exported RDF mapping: journal
  $rdf_mappings['node']['journal'] = array(
    'rdftype' => array(
      0 => 'dc:BibliographicResource',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
      'type' => 'property',
      'datatype' => 'xsd:string',
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'field_issn' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'dc:identifier',
        1 => 'bibo:issn',
      ),
    ),
    'field_eissn' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'dc:identifier',
        1 => 'bibo:eissn',
      ),
    ),
    'field_publisher' => array(
      'type' => 'property',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'dc:publisher',
        1 => 'bibo:distributor',
      ),
    ),
    'field_doi' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'bibo:doi',
        1 => 'dc:identifier',
      ),
    ),
    'field_haspart' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'dc:hasPart',
      ),
    ),
    'field_article' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'dc:hasPart',
      ),
    ),
  );

  // Exported RDF mapping: journal_article
  $rdf_mappings['node']['journal_article'] = array(
    'rdftype' => array(
      0 => 'bibo:AcademicArticle',
      1 => 'dc:BibliographicResource',
      2 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
      'type' => 'property',
      'datatype' => 'xsd:string',
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'field_creator' => array(
      'type' => 'rel',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'foaf:lastName',
        1 => 'foaf:familyName',
      ),
    ),
    'field_subject' => array(
      'type' => 'rel',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'dc:subject',
      ),
    ),
    'field_publisher' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'dc:publisher',
      ),
    ),
    'field_issued' => array(
      'type' => 'property',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'dc:issued',
      ),
    ),
    'field_ispartof' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'dc:isPartOf',
      ),
    ),
    'field_bibliographiccitation' => array(
      'type' => 'property',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'dc:bibliographicCitation',
      ),
    ),
    'field_references' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'dc:references',
      ),
    ),
    'field_doi' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'dc:identifier',
      ),
    ),
    'field_startpage' => array(
      'type' => 'property',
      'datatype' => 'xsd:integer',
      'predicates' => array(
        0 => 'bibo:pageStart',
      ),
    ),
    'field_endpage' => array(
      'type' => 'property',
      'datatype' => 'xsd:integer',
      'predicates' => array(
        0 => 'bibo:pageEnd',
      ),
    ),
    'field_journal' => array(
      'type' => 'rel',
      'predicates' => array(
        0 => 'dc:isPartOf',
      ),
    ),
    'field_volume' => array(
      'type' => 'property',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'bibo:volume',
      ),
    ),
    'field_issue' => array(
      'type' => 'property',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'bibo:issue',
      ),
    ),
    'field_cites' => array(
      'type' => 'rel',
      'datatype' => 'xsd:string',
      'predicates' => array(
        0 => 'dc:references',
      ),
    ),
  );

  return $rdf_mappings;
}
