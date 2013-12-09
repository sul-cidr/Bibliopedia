<?php
/**
 * @file
 * crrw_content_types_and_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crrw_content_types_and_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'crrw_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Chinese Railroad Workers Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Chinese Railroad Workers Item Records';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'edit_node' => 'edit_node',
    'field_crrw_file_format' => 'field_crrw_file_format',
    'field_crrw_filename' => 'field_crrw_filename',
    'field_crrw_institution' => 'field_crrw_institution',
    'field_crrw_originating_archive' => 'field_crrw_originating_archive',
    'created' => 'created',
    'field_crrw_subjects' => 'field_crrw_subjects',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_crrw_file_format' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_crrw_filename' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_crrw_institution' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_crrw_originating_archive' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_crrw_subjects' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit this record';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: File Format */
  $handler->display->display_options['fields']['field_crrw_file_format']['id'] = 'field_crrw_file_format';
  $handler->display->display_options['fields']['field_crrw_file_format']['table'] = 'field_data_field_crrw_file_format';
  $handler->display->display_options['fields']['field_crrw_file_format']['field'] = 'field_crrw_file_format';
  $handler->display->display_options['fields']['field_crrw_file_format']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Filename */
  $handler->display->display_options['fields']['field_crrw_filename']['id'] = 'field_crrw_filename';
  $handler->display->display_options['fields']['field_crrw_filename']['table'] = 'field_data_field_crrw_filename';
  $handler->display->display_options['fields']['field_crrw_filename']['field'] = 'field_crrw_filename';
  /* Field: Content: Institution */
  $handler->display->display_options['fields']['field_crrw_institution']['id'] = 'field_crrw_institution';
  $handler->display->display_options['fields']['field_crrw_institution']['table'] = 'field_data_field_crrw_institution';
  $handler->display->display_options['fields']['field_crrw_institution']['field'] = 'field_crrw_institution';
  $handler->display->display_options['fields']['field_crrw_institution']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Originating Source */
  $handler->display->display_options['fields']['field_crrw_originating_archive']['id'] = 'field_crrw_originating_archive';
  $handler->display->display_options['fields']['field_crrw_originating_archive']['table'] = 'field_data_field_crrw_originating_archive';
  $handler->display->display_options['fields']['field_crrw_originating_archive']['field'] = 'field_crrw_originating_archive';
  $handler->display->display_options['fields']['field_crrw_originating_archive']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Subjects */
  $handler->display->display_options['fields']['field_crrw_subjects']['id'] = 'field_crrw_subjects';
  $handler->display->display_options['fields']['field_crrw_subjects']['table'] = 'field_data_field_crrw_subjects';
  $handler->display->display_options['fields']['field_crrw_subjects']['field'] = 'field_crrw_subjects';
  $handler->display->display_options['fields']['field_crrw_subjects']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_crrw_subjects']['delta_offset'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Record created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'crrw_annotation' => 'crrw_annotation',
    'crrw_artwork' => 'crrw_artwork',
    'crrw_book' => 'crrw_book',
    'crrw_business_documentation' => 'crrw_business_documentation',
    'crrw_census_record' => 'crrw_census_record',
    'crrw_congressional_record_report' => 'crrw_congressional_record_report',
    'crrw_diary' => 'crrw_diary',
    'crrw_illustration' => 'crrw_illustration',
    'crrw_institution' => 'crrw_institution',
    'crrw_interview' => 'crrw_interview',
    'crrw_letter' => 'crrw_letter',
    'crrw_magazine' => 'crrw_magazine',
    'crrw_map' => 'crrw_map',
    'crrw_music' => 'crrw_music',
    'crrw_newspaper_article' => 'crrw_newspaper_article',
    'crrw_pamphlet' => 'crrw_pamphlet',
    'crrw_person' => 'crrw_person',
    'crrw_photograph_archeological' => 'crrw_photograph_archeological',
    'crrw_photograph_architecture' => 'crrw_photograph_architecture',
    'crrw_photograph_artwork' => 'crrw_photograph_artwork',
    'crrw_photograph_contemporary' => 'crrw_photograph_contemporary',
    'crrw_photograph_historical' => 'crrw_photograph_historical',
    'crrw_photograph_monument' => 'crrw_photograph_monument',
    'crrw_poster' => 'crrw_poster',
    'crrw_report' => 'crrw_report',
    'crrw_scrapbook' => 'crrw_scrapbook',
    'crrw_source' => 'crrw_source',
    'crrw_interview_transcript' => 'crrw_interview_transcript',
    'crrw_travel_narrative_log' => 'crrw_travel_narrative_log',
    'crrw_interview_video' => 'crrw_interview_video',
    'crrw_video_recording' => 'crrw_video_recording',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'crrw_annotation' => 'crrw_annotation',
    'crrw_artwork' => 'crrw_artwork',
    'crrw_book' => 'crrw_book',
    'crrw_business_documentation' => 'crrw_business_documentation',
    'crrw_census_record' => 'crrw_census_record',
    'crrw_congressional_record_report' => 'crrw_congressional_record_report',
    'crrw_diary' => 'crrw_diary',
    'crrw_illustration' => 'crrw_illustration',
    'crrw_institution' => 'crrw_institution',
    'crrw_interview' => 'crrw_interview',
    'crrw_letter' => 'crrw_letter',
    'crrw_magazine' => 'crrw_magazine',
    'crrw_map' => 'crrw_map',
    'crrw_music' => 'crrw_music',
    'crrw_newspaper_article' => 'crrw_newspaper_article',
    'crrw_pamphlet' => 'crrw_pamphlet',
    'crrw_person' => 'crrw_person',
    'crrw_photograph_archeological' => 'crrw_photograph_archeological',
    'crrw_photograph_architecture' => 'crrw_photograph_architecture',
    'crrw_photograph_artwork' => 'crrw_photograph_artwork',
    'crrw_photograph_contemporary' => 'crrw_photograph_contemporary',
    'crrw_photograph_historical' => 'crrw_photograph_historical',
    'crrw_photograph_monument' => 'crrw_photograph_monument',
    'crrw_poster' => 'crrw_poster',
    'crrw_report' => 'crrw_report',
    'crrw_scrapbook' => 'crrw_scrapbook',
    'crrw_source' => 'crrw_source',
    'crrw_interview_transcript' => 'crrw_interview_transcript',
    'crrw_travel_narrative_log' => 'crrw_travel_narrative_log',
    'crrw_interview_video' => 'crrw_interview_video',
    'crrw_video_recording' => 'crrw_video_recording',
  );
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'crrw');
  $handler->display->display_options['path'] = 'crrw';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: File Format */
  $handler->display->display_options['fields']['field_crrw_file_format']['id'] = 'field_crrw_file_format';
  $handler->display->display_options['fields']['field_crrw_file_format']['table'] = 'field_data_field_crrw_file_format';
  $handler->display->display_options['fields']['field_crrw_file_format']['field'] = 'field_crrw_file_format';
  $handler->display->display_options['fields']['field_crrw_file_format']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Filename */
  $handler->display->display_options['fields']['field_crrw_filename']['id'] = 'field_crrw_filename';
  $handler->display->display_options['fields']['field_crrw_filename']['table'] = 'field_data_field_crrw_filename';
  $handler->display->display_options['fields']['field_crrw_filename']['field'] = 'field_crrw_filename';
  /* Field: Content: Institution */
  $handler->display->display_options['fields']['field_crrw_institution']['id'] = 'field_crrw_institution';
  $handler->display->display_options['fields']['field_crrw_institution']['table'] = 'field_data_field_crrw_institution';
  $handler->display->display_options['fields']['field_crrw_institution']['field'] = 'field_crrw_institution';
  $handler->display->display_options['fields']['field_crrw_institution']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Originating Source */
  $handler->display->display_options['fields']['field_crrw_originating_archive']['id'] = 'field_crrw_originating_archive';
  $handler->display->display_options['fields']['field_crrw_originating_archive']['table'] = 'field_data_field_crrw_originating_archive';
  $handler->display->display_options['fields']['field_crrw_originating_archive']['field'] = 'field_crrw_originating_archive';
  $handler->display->display_options['fields']['field_crrw_originating_archive']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Subjects */
  $handler->display->display_options['fields']['field_crrw_subjects']['id'] = 'field_crrw_subjects';
  $handler->display->display_options['fields']['field_crrw_subjects']['table'] = 'field_data_field_crrw_subjects';
  $handler->display->display_options['fields']['field_crrw_subjects']['field'] = 'field_crrw_subjects';
  $handler->display->display_options['fields']['field_crrw_subjects']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_crrw_subjects']['delta_offset'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Record created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: # of Pages */
  $handler->display->display_options['fields']['field_crrw_pages']['id'] = 'field_crrw_pages';
  $handler->display->display_options['fields']['field_crrw_pages']['table'] = 'field_data_field_crrw_pages';
  $handler->display->display_options['fields']['field_crrw_pages']['field'] = 'field_crrw_pages';
  $handler->display->display_options['fields']['field_crrw_pages']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: # of volumes */
  $handler->display->display_options['fields']['field_crrw_book_num_volumes']['id'] = 'field_crrw_book_num_volumes';
  $handler->display->display_options['fields']['field_crrw_book_num_volumes']['table'] = 'field_data_field_crrw_book_num_volumes';
  $handler->display->display_options['fields']['field_crrw_book_num_volumes']['field'] = 'field_crrw_book_num_volumes';
  $handler->display->display_options['fields']['field_crrw_book_num_volumes']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: # of volumes */
  $handler->display->display_options['fields']['field_crrw_volumes_number']['id'] = 'field_crrw_volumes_number';
  $handler->display->display_options['fields']['field_crrw_volumes_number']['table'] = 'field_data_field_crrw_volumes_number';
  $handler->display->display_options['fields']['field_crrw_volumes_number']['field'] = 'field_crrw_volumes_number';
  $handler->display->display_options['fields']['field_crrw_volumes_number']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'crrw_file_formats' => 0,
    'crrw_subjects' => 0,
    'distribution' => 0,
    'hardware_platform' => 0,
    'hardware_version' => 0,
    'library_of_congress_subject_headings_' => 0,
    'pessoa_groups' => 0,
    'pessoa_institutions' => 0,
    'pessoa_movements' => 0,
    'pessoa_phenomena' => 0,
    'software_platform' => 0,
    'tags' => 0,
  );
  /* Field: Content: Alternate Title */
  $handler->display->display_options['fields']['field_crrw_alias']['id'] = 'field_crrw_alias';
  $handler->display->display_options['fields']['field_crrw_alias']['table'] = 'field_data_field_crrw_alias';
  $handler->display->display_options['fields']['field_crrw_alias']['field'] = 'field_crrw_alias';
  $handler->display->display_options['fields']['field_crrw_alias']['delta_offset'] = '0';
  /* Field: Content: Annotation for */
  $handler->display->display_options['fields']['field_crrw_annotates']['id'] = 'field_crrw_annotates';
  $handler->display->display_options['fields']['field_crrw_annotates']['table'] = 'field_data_field_crrw_annotates';
  $handler->display->display_options['fields']['field_crrw_annotates']['field'] = 'field_crrw_annotates';
  $handler->display->display_options['fields']['field_crrw_annotates']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Archive Title */
  $handler->display->display_options['fields']['field_crrw_archive_title']['id'] = 'field_crrw_archive_title';
  $handler->display->display_options['fields']['field_crrw_archive_title']['table'] = 'field_data_field_crrw_archive_title';
  $handler->display->display_options['fields']['field_crrw_archive_title']['field'] = 'field_crrw_archive_title';
  /* Field: Content: Artist */
  $handler->display->display_options['fields']['field_crrw_artist']['id'] = 'field_crrw_artist';
  $handler->display->display_options['fields']['field_crrw_artist']['table'] = 'field_data_field_crrw_artist';
  $handler->display->display_options['fields']['field_crrw_artist']['field'] = 'field_crrw_artist';
  $handler->display->display_options['fields']['field_crrw_artist']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Audio/Video File Name Associated With This Transcription */
  $handler->display->display_options['fields']['field_crrw_transcript_avfilename']['id'] = 'field_crrw_transcript_avfilename';
  $handler->display->display_options['fields']['field_crrw_transcript_avfilename']['table'] = 'field_data_field_crrw_transcript_avfilename';
  $handler->display->display_options['fields']['field_crrw_transcript_avfilename']['field'] = 'field_crrw_transcript_avfilename';
  /* Field: Content: Author/Editor */
  $handler->display->display_options['fields']['field_crrw_person']['id'] = 'field_crrw_person';
  $handler->display->display_options['fields']['field_crrw_person']['table'] = 'field_data_field_crrw_person';
  $handler->display->display_options['fields']['field_crrw_person']['field'] = 'field_crrw_person';
  $handler->display->display_options['fields']['field_crrw_person']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Birthplace */
  $handler->display->display_options['fields']['field_crrw_birthplace']['id'] = 'field_crrw_birthplace';
  $handler->display->display_options['fields']['field_crrw_birthplace']['table'] = 'field_data_field_crrw_birthplace';
  $handler->display->display_options['fields']['field_crrw_birthplace']['field'] = 'field_crrw_birthplace';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: Composer */
  $handler->display->display_options['fields']['field_crrw_composer']['id'] = 'field_crrw_composer';
  $handler->display->display_options['fields']['field_crrw_composer']['table'] = 'field_data_field_crrw_composer';
  $handler->display->display_options['fields']['field_crrw_composer']['field'] = 'field_crrw_composer';
  $handler->display->display_options['fields']['field_crrw_composer']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_crrw_date']['id'] = 'field_crrw_date';
  $handler->display->display_options['fields']['field_crrw_date']['table'] = 'field_data_field_crrw_date';
  $handler->display->display_options['fields']['field_crrw_date']['field'] = 'field_crrw_date';
  $handler->display->display_options['fields']['field_crrw_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date Item Digitized */
  $handler->display->display_options['fields']['field_crrw_digitized_date']['id'] = 'field_crrw_digitized_date';
  $handler->display->display_options['fields']['field_crrw_digitized_date']['table'] = 'field_data_field_crrw_digitized_date';
  $handler->display->display_options['fields']['field_crrw_digitized_date']['field'] = 'field_crrw_digitized_date';
  $handler->display->display_options['fields']['field_crrw_digitized_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date of Birth */
  $handler->display->display_options['fields']['field_crrw_date_birth']['id'] = 'field_crrw_date_birth';
  $handler->display->display_options['fields']['field_crrw_date_birth']['table'] = 'field_data_field_crrw_date_birth';
  $handler->display->display_options['fields']['field_crrw_date_birth']['field'] = 'field_crrw_date_birth';
  $handler->display->display_options['fields']['field_crrw_date_birth']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date of Death */
  $handler->display->display_options['fields']['field_crrw_date_death']['id'] = 'field_crrw_date_death';
  $handler->display->display_options['fields']['field_crrw_date_death']['table'] = 'field_data_field_crrw_date_death';
  $handler->display->display_options['fields']['field_crrw_date_death']['field'] = 'field_crrw_date_death';
  $handler->display->display_options['fields']['field_crrw_date_death']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date of Interview */
  $handler->display->display_options['fields']['field_crrw_interview_date']['id'] = 'field_crrw_interview_date';
  $handler->display->display_options['fields']['field_crrw_interview_date']['table'] = 'field_data_field_crrw_interview_date';
  $handler->display->display_options['fields']['field_crrw_interview_date']['field'] = 'field_crrw_interview_date';
  $handler->display->display_options['fields']['field_crrw_interview_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Dates covered in diary */
  $handler->display->display_options['fields']['field_crrw_diary_dates']['id'] = 'field_crrw_diary_dates';
  $handler->display->display_options['fields']['field_crrw_diary_dates']['table'] = 'field_data_field_crrw_diary_dates';
  $handler->display->display_options['fields']['field_crrw_diary_dates']['field'] = 'field_crrw_diary_dates';
  $handler->display->display_options['fields']['field_crrw_diary_dates']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_crrw_diary_dates']['delta_offset'] = '0';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_crrw_description']['id'] = 'field_crrw_description';
  $handler->display->display_options['fields']['field_crrw_description']['table'] = 'field_data_field_crrw_description';
  $handler->display->display_options['fields']['field_crrw_description']['field'] = 'field_crrw_description';
  /* Field: Content: Description of actions taken with file */
  $handler->display->display_options['fields']['field_crrw_desc_file_actions']['id'] = 'field_crrw_desc_file_actions';
  $handler->display->display_options['fields']['field_crrw_desc_file_actions']['table'] = 'field_data_field_crrw_desc_file_actions';
  $handler->display->display_options['fields']['field_crrw_desc_file_actions']['field'] = 'field_crrw_desc_file_actions';
  /* Field: Content: Digitization Specifications */
  $handler->display->display_options['fields']['field_crrw_digitized_specs']['id'] = 'field_crrw_digitized_specs';
  $handler->display->display_options['fields']['field_crrw_digitized_specs']['table'] = 'field_data_field_crrw_digitized_specs';
  $handler->display->display_options['fields']['field_crrw_digitized_specs']['field'] = 'field_crrw_digitized_specs';
  /* Field: Content: Documentation Type */
  $handler->display->display_options['fields']['field_crrw_doc_type']['id'] = 'field_crrw_doc_type';
  $handler->display->display_options['fields']['field_crrw_doc_type']['table'] = 'field_data_field_crrw_doc_type';
  $handler->display->display_options['fields']['field_crrw_doc_type']['field'] = 'field_crrw_doc_type';
  /* Field: Content: Edition */
  $handler->display->display_options['fields']['field_crrw_book_edition']['id'] = 'field_crrw_book_edition';
  $handler->display->display_options['fields']['field_crrw_book_edition']['table'] = 'field_data_field_crrw_book_edition';
  $handler->display->display_options['fields']['field_crrw_book_edition']['field'] = 'field_crrw_book_edition';
  /* Field: Content: Edition */
  $handler->display->display_options['fields']['field_crrw_edition']['id'] = 'field_crrw_edition';
  $handler->display->display_options['fields']['field_crrw_edition']['table'] = 'field_data_field_crrw_edition';
  $handler->display->display_options['fields']['field_crrw_edition']['field'] = 'field_crrw_edition';
  /* Field: Content: File Format */
  $handler->display->display_options['fields']['field_crrw_file_format_1']['id'] = 'field_crrw_file_format_1';
  $handler->display->display_options['fields']['field_crrw_file_format_1']['table'] = 'field_data_field_crrw_file_format';
  $handler->display->display_options['fields']['field_crrw_file_format_1']['field'] = 'field_crrw_file_format';
  /* Field: Content: Filename */
  $handler->display->display_options['fields']['field_crrw_filename_1']['id'] = 'field_crrw_filename_1';
  $handler->display->display_options['fields']['field_crrw_filename_1']['table'] = 'field_data_field_crrw_filename';
  $handler->display->display_options['fields']['field_crrw_filename_1']['field'] = 'field_crrw_filename';
  /* Field: Content: Format of Original Interview */
  $handler->display->display_options['fields']['field_crrw_transcript_format']['id'] = 'field_crrw_transcript_format';
  $handler->display->display_options['fields']['field_crrw_transcript_format']['table'] = 'field_data_field_crrw_transcript_format';
  $handler->display->display_options['fields']['field_crrw_transcript_format']['field'] = 'field_crrw_transcript_format';
  /* Field: Content: Institution */
  $handler->display->display_options['fields']['field_crrw_institution_1']['id'] = 'field_crrw_institution_1';
  $handler->display->display_options['fields']['field_crrw_institution_1']['table'] = 'field_data_field_crrw_institution';
  $handler->display->display_options['fields']['field_crrw_institution_1']['field'] = 'field_crrw_institution';
  $handler->display->display_options['fields']['field_crrw_institution_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Interview length */
  $handler->display->display_options['fields']['field_crrw_interview_length']['id'] = 'field_crrw_interview_length';
  $handler->display->display_options['fields']['field_crrw_interview_length']['table'] = 'field_data_field_crrw_interview_length';
  $handler->display->display_options['fields']['field_crrw_interview_length']['field'] = 'field_crrw_interview_length';
  /* Field: Content: Interview with */
  $handler->display->display_options['fields']['field_crrw_interviewee']['id'] = 'field_crrw_interviewee';
  $handler->display->display_options['fields']['field_crrw_interviewee']['table'] = 'field_data_field_crrw_interviewee';
  $handler->display->display_options['fields']['field_crrw_interviewee']['field'] = 'field_crrw_interviewee';
  $handler->display->display_options['fields']['field_crrw_interviewee']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_crrw_interviewee']['delta_offset'] = '0';
  /* Field: Content: Interviewed by */
  $handler->display->display_options['fields']['field_crrw_interviewer']['id'] = 'field_crrw_interviewer';
  $handler->display->display_options['fields']['field_crrw_interviewer']['table'] = 'field_data_field_crrw_interviewer';
  $handler->display->display_options['fields']['field_crrw_interviewer']['field'] = 'field_crrw_interviewer';
  $handler->display->display_options['fields']['field_crrw_interviewer']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_crrw_interviewer']['delta_offset'] = '0';
  /* Field: Content: Issue */
  $handler->display->display_options['fields']['field_crrw_issue']['id'] = 'field_crrw_issue';
  $handler->display->display_options['fields']['field_crrw_issue']['table'] = 'field_data_field_crrw_issue';
  $handler->display->display_options['fields']['field_crrw_issue']['field'] = 'field_crrw_issue';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['field_crrw_language']['id'] = 'field_crrw_language';
  $handler->display->display_options['fields']['field_crrw_language']['table'] = 'field_data_field_crrw_language';
  $handler->display->display_options['fields']['field_crrw_language']['field'] = 'field_crrw_language';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_crrw_location']['id'] = 'field_crrw_location';
  $handler->display->display_options['fields']['field_crrw_location']['table'] = 'field_data_field_crrw_location';
  $handler->display->display_options['fields']['field_crrw_location']['field'] = 'field_crrw_location';
  /* Field: Content: Location at death */
  $handler->display->display_options['fields']['field_crrw_deathplace']['id'] = 'field_crrw_deathplace';
  $handler->display->display_options['fields']['field_crrw_deathplace']['table'] = 'field_data_field_crrw_deathplace';
  $handler->display->display_options['fields']['field_crrw_deathplace']['field'] = 'field_crrw_deathplace';
  /* Field: Content: Location Sent From */
  $handler->display->display_options['fields']['field_crrw_location_from']['id'] = 'field_crrw_location_from';
  $handler->display->display_options['fields']['field_crrw_location_from']['table'] = 'field_data_field_crrw_location_from';
  $handler->display->display_options['fields']['field_crrw_location_from']['field'] = 'field_crrw_location_from';
  /* Field: Content: Location Sent To */
  $handler->display->display_options['fields']['field_crrw_location_to']['id'] = 'field_crrw_location_to';
  $handler->display->display_options['fields']['field_crrw_location_to']['table'] = 'field_data_field_crrw_location_to';
  $handler->display->display_options['fields']['field_crrw_location_to']['field'] = 'field_crrw_location_to';
  /* Field: Content: Medium */
  $handler->display->display_options['fields']['field_crrw_artwork_medium']['id'] = 'field_crrw_artwork_medium';
  $handler->display->display_options['fields']['field_crrw_artwork_medium']['table'] = 'field_data_field_crrw_artwork_medium';
  $handler->display->display_options['fields']['field_crrw_artwork_medium']['field'] = 'field_crrw_artwork_medium';
  /* Field: Content: Medium */
  $handler->display->display_options['fields']['field_crrw_medium']['id'] = 'field_crrw_medium';
  $handler->display->display_options['fields']['field_crrw_medium']['table'] = 'field_data_field_crrw_medium';
  $handler->display->display_options['fields']['field_crrw_medium']['field'] = 'field_crrw_medium';
  /* Field: Content: Name of Digitization Party */
  $handler->display->display_options['fields']['field_crrw_digitized_name']['id'] = 'field_crrw_digitized_name';
  $handler->display->display_options['fields']['field_crrw_digitized_name']['table'] = 'field_data_field_crrw_digitized_name';
  $handler->display->display_options['fields']['field_crrw_digitized_name']['field'] = 'field_crrw_digitized_name';
  /* Field: Content: Original/Institutional Description */
  $handler->display->display_options['fields']['field_crrw_original_desc']['id'] = 'field_crrw_original_desc';
  $handler->display->display_options['fields']['field_crrw_original_desc']['table'] = 'field_data_field_crrw_original_desc';
  $handler->display->display_options['fields']['field_crrw_original_desc']['field'] = 'field_crrw_original_desc';
  /* Field: Content: Originating Source */
  $handler->display->display_options['fields']['field_crrw_originating_archive_1']['id'] = 'field_crrw_originating_archive_1';
  $handler->display->display_options['fields']['field_crrw_originating_archive_1']['table'] = 'field_data_field_crrw_originating_archive';
  $handler->display->display_options['fields']['field_crrw_originating_archive_1']['field'] = 'field_crrw_originating_archive';
  $handler->display->display_options['fields']['field_crrw_originating_archive_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Part Of */
  $handler->display->display_options['fields']['field_crrw_member_of']['id'] = 'field_crrw_member_of';
  $handler->display->display_options['fields']['field_crrw_member_of']['table'] = 'field_data_field_crrw_member_of';
  $handler->display->display_options['fields']['field_crrw_member_of']['field'] = 'field_crrw_member_of';
  $handler->display->display_options['fields']['field_crrw_member_of']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Person who discovered artefact */
  $handler->display->display_options['fields']['field_crrw_discoverer']['id'] = 'field_crrw_discoverer';
  $handler->display->display_options['fields']['field_crrw_discoverer']['table'] = 'field_data_field_crrw_discoverer';
  $handler->display->display_options['fields']['field_crrw_discoverer']['field'] = 'field_crrw_discoverer';
  $handler->display->display_options['fields']['field_crrw_discoverer']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Publication */
  $handler->display->display_options['fields']['field_crrw_publication']['id'] = 'field_crrw_publication';
  $handler->display->display_options['fields']['field_crrw_publication']['table'] = 'field_data_field_crrw_publication';
  $handler->display->display_options['fields']['field_crrw_publication']['field'] = 'field_crrw_publication';
  /* Field: Content: Publication Author */
  $handler->display->display_options['fields']['field_crrw_publication_author']['id'] = 'field_crrw_publication_author';
  $handler->display->display_options['fields']['field_crrw_publication_author']['table'] = 'field_data_field_crrw_publication_author';
  $handler->display->display_options['fields']['field_crrw_publication_author']['field'] = 'field_crrw_publication_author';
  $handler->display->display_options['fields']['field_crrw_publication_author']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Publisher */
  $handler->display->display_options['fields']['field_crrw_publisher']['id'] = 'field_crrw_publisher';
  $handler->display->display_options['fields']['field_crrw_publisher']['table'] = 'field_data_field_crrw_publisher';
  $handler->display->display_options['fields']['field_crrw_publisher']['field'] = 'field_crrw_publisher';
  /* Field: Content: Publisher Location */
  $handler->display->display_options['fields']['field_crrw_publisher_location']['id'] = 'field_crrw_publisher_location';
  $handler->display->display_options['fields']['field_crrw_publisher_location']['table'] = 'field_data_field_crrw_publisher_location';
  $handler->display->display_options['fields']['field_crrw_publisher_location']['field'] = 'field_crrw_publisher_location';
  /* Field: Content: Report Number */
  $handler->display->display_options['fields']['field_crrw_report_number']['id'] = 'field_crrw_report_number';
  $handler->display->display_options['fields']['field_crrw_report_number']['table'] = 'field_data_field_crrw_report_number';
  $handler->display->display_options['fields']['field_crrw_report_number']['field'] = 'field_crrw_report_number';
  /* Field: Content: Report Type */
  $handler->display->display_options['fields']['field_crrw_report_type']['id'] = 'field_crrw_report_type';
  $handler->display->display_options['fields']['field_crrw_report_type']['table'] = 'field_data_field_crrw_report_type';
  $handler->display->display_options['fields']['field_crrw_report_type']['field'] = 'field_crrw_report_type';
  /* Field: Content: Rights */
  $handler->display->display_options['fields']['field_crrw_rights']['id'] = 'field_crrw_rights';
  $handler->display->display_options['fields']['field_crrw_rights']['table'] = 'field_data_field_crrw_rights';
  $handler->display->display_options['fields']['field_crrw_rights']['field'] = 'field_crrw_rights';
  /* Field: Content: Running Time */
  $handler->display->display_options['fields']['field_crrw_music_running_time']['id'] = 'field_crrw_music_running_time';
  $handler->display->display_options['fields']['field_crrw_music_running_time']['table'] = 'field_data_field_crrw_music_running_time';
  $handler->display->display_options['fields']['field_crrw_music_running_time']['field'] = 'field_crrw_music_running_time';
  /* Field: Content: Running Time */
  $handler->display->display_options['fields']['field_crrw_length']['id'] = 'field_crrw_length';
  $handler->display->display_options['fields']['field_crrw_length']['table'] = 'field_data_field_crrw_length';
  $handler->display->display_options['fields']['field_crrw_length']['field'] = 'field_crrw_length';
  /* Field: Content: Scale */
  $handler->display->display_options['fields']['field_crrw_map_scale']['id'] = 'field_crrw_map_scale';
  $handler->display->display_options['fields']['field_crrw_map_scale']['table'] = 'field_data_field_crrw_map_scale';
  $handler->display->display_options['fields']['field_crrw_map_scale']['field'] = 'field_crrw_map_scale';
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_crrw_section']['id'] = 'field_crrw_section';
  $handler->display->display_options['fields']['field_crrw_section']['table'] = 'field_data_field_crrw_section';
  $handler->display->display_options['fields']['field_crrw_section']['field'] = 'field_crrw_section';
  /* Field: Content: Series */
  $handler->display->display_options['fields']['field_crrw_book_series']['id'] = 'field_crrw_book_series';
  $handler->display->display_options['fields']['field_crrw_book_series']['table'] = 'field_data_field_crrw_book_series';
  $handler->display->display_options['fields']['field_crrw_book_series']['field'] = 'field_crrw_book_series';
  /* Field: Content: Series Number */
  $handler->display->display_options['fields']['field_crrw_series_number']['id'] = 'field_crrw_series_number';
  $handler->display->display_options['fields']['field_crrw_series_number']['table'] = 'field_data_field_crrw_series_number';
  $handler->display->display_options['fields']['field_crrw_series_number']['field'] = 'field_crrw_series_number';
  /* Field: Content: Series Number */
  $handler->display->display_options['fields']['field_crrw_book_series_number']['id'] = 'field_crrw_book_series_number';
  $handler->display->display_options['fields']['field_crrw_book_series_number']['table'] = 'field_data_field_crrw_book_series_number';
  $handler->display->display_options['fields']['field_crrw_book_series_number']['field'] = 'field_crrw_book_series_number';
  /* Field: Content: Series Title */
  $handler->display->display_options['fields']['field_crrw_series_title']['id'] = 'field_crrw_series_title';
  $handler->display->display_options['fields']['field_crrw_series_title']['table'] = 'field_data_field_crrw_series_title';
  $handler->display->display_options['fields']['field_crrw_series_title']['field'] = 'field_crrw_series_title';
  /* Field: Content: Song Title */
  $handler->display->display_options['fields']['field_crrw_song_title']['id'] = 'field_crrw_song_title';
  $handler->display->display_options['fields']['field_crrw_song_title']['table'] = 'field_data_field_crrw_song_title';
  $handler->display->display_options['fields']['field_crrw_song_title']['field'] = 'field_crrw_song_title';
  /* Field: Content: Subjects */
  $handler->display->display_options['fields']['field_crrw_subjects_1']['id'] = 'field_crrw_subjects_1';
  $handler->display->display_options['fields']['field_crrw_subjects_1']['table'] = 'field_data_field_crrw_subjects';
  $handler->display->display_options['fields']['field_crrw_subjects_1']['field'] = 'field_crrw_subjects';
  $handler->display->display_options['fields']['field_crrw_subjects_1']['delta_offset'] = '0';
  /* Field: Content: Transcription By */
  $handler->display->display_options['fields']['field_crrw_transcription_by']['id'] = 'field_crrw_transcription_by';
  $handler->display->display_options['fields']['field_crrw_transcription_by']['table'] = 'field_data_field_crrw_transcription_by';
  $handler->display->display_options['fields']['field_crrw_transcription_by']['field'] = 'field_crrw_transcription_by';
  $handler->display->display_options['fields']['field_crrw_transcription_by']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_crrw_letter_type']['id'] = 'field_crrw_letter_type';
  $handler->display->display_options['fields']['field_crrw_letter_type']['table'] = 'field_data_field_crrw_letter_type';
  $handler->display->display_options['fields']['field_crrw_letter_type']['field'] = 'field_crrw_letter_type';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_crrw_map_type']['id'] = 'field_crrw_map_type';
  $handler->display->display_options['fields']['field_crrw_map_type']['table'] = 'field_data_field_crrw_map_type';
  $handler->display->display_options['fields']['field_crrw_map_type']['field'] = 'field_crrw_map_type';
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_crrw_url']['id'] = 'field_crrw_url';
  $handler->display->display_options['fields']['field_crrw_url']['table'] = 'field_data_field_crrw_url';
  $handler->display->display_options['fields']['field_crrw_url']['field'] = 'field_crrw_url';
  $handler->display->display_options['fields']['field_crrw_url']['click_sort_column'] = 'url';
  /* Field: Content: Volume */
  $handler->display->display_options['fields']['field_crrw_book_volume']['id'] = 'field_crrw_book_volume';
  $handler->display->display_options['fields']['field_crrw_book_volume']['table'] = 'field_data_field_crrw_book_volume';
  $handler->display->display_options['fields']['field_crrw_book_volume']['field'] = 'field_crrw_book_volume';
  /* Field: Content: Volume */
  $handler->display->display_options['fields']['field_crrw_volume']['id'] = 'field_crrw_volume';
  $handler->display->display_options['fields']['field_crrw_volume']['table'] = 'field_data_field_crrw_volume';
  $handler->display->display_options['fields']['field_crrw_volume']['field'] = 'field_crrw_volume';
  /* Field: Content: Year Created */
  $handler->display->display_options['fields']['field_crrw_artwork_year_created']['id'] = 'field_crrw_artwork_year_created';
  $handler->display->display_options['fields']['field_crrw_artwork_year_created']['table'] = 'field_data_field_crrw_artwork_year_created';
  $handler->display->display_options['fields']['field_crrw_artwork_year_created']['field'] = 'field_crrw_artwork_year_created';
  $handler->display->display_options['fields']['field_crrw_artwork_year_created']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Year of Publication */
  $handler->display->display_options['fields']['field_crrw_year']['id'] = 'field_crrw_year';
  $handler->display->display_options['fields']['field_crrw_year']['table'] = 'field_data_field_crrw_year';
  $handler->display->display_options['fields']['field_crrw_year']['field'] = 'field_crrw_year';
  $handler->display->display_options['fields']['field_crrw_year']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['path'] = 'crrw_content.csv';
  $export['crrw_content'] = $view;

  return $export;
}
