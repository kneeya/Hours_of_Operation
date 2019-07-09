<?php

/**
 * @file
 * hours_of_operation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hours_of_operation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hours_of_operation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Hours of Operation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Hours of Operation';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Choose an image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Hours of Operation */
  $handler->display->display_options['fields']['field_opening_hours']['id'] = 'field_opening_hours';
  $handler->display->display_options['fields']['field_opening_hours']['table'] = 'field_data_field_opening_hours';
  $handler->display->display_options['fields']['field_opening_hours']['field'] = 'field_opening_hours';
  $handler->display->display_options['fields']['field_opening_hours']['label'] = '';
  $handler->display->display_options['fields']['field_opening_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opening_hours']['click_sort_column'] = 'day';
  $handler->display->display_options['fields']['field_opening_hours']['settings'] = array(
    'showclosed' => 'all',
    'date_first_day' => '1',
    'daysformat' => 'long',
    'hoursformat' => '1',
    'compress' => 0,
    'grouped' => 1,
    'closedformat' => 'Closed',
    'separator_days' => '<br />',
    'separator_grouped_days' => ' - ',
    'separator_day_hours' => ': ',
    'separator_hours_hours' => '-',
    'separator_more_hours' => ', ',
    'current_status' => array(
      'position' => 'hide',
      'open_text' => 'Currently open!',
      'closed_text' => 'Currently closed',
    ),
  );
  $handler->display->display_options['fields']['field_opening_hours']['delta_offset'] = '0';
  /* Field: Content: Closed */
  $handler->display->display_options['fields']['field_date_closed']['id'] = 'field_date_closed';
  $handler->display->display_options['fields']['field_date_closed']['table'] = 'field_data_field_date_closed';
  $handler->display->display_options['fields']['field_date_closed']['field'] = 'field_date_closed';
  $handler->display->display_options['fields']['field_date_closed']['label'] = '';
  $handler->display->display_options['fields']['field_date_closed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_closed']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date_closed']['delta_offset'] = '0';
  /* Field: Content: Hours Change */
  $handler->display->display_options['fields']['field_hours_change']['id'] = 'field_hours_change';
  $handler->display->display_options['fields']['field_hours_change']['table'] = 'field_data_field_hours_change';
  $handler->display->display_options['fields']['field_hours_change']['field'] = 'field_hours_change';
  $handler->display->display_options['fields']['field_hours_change']['label'] = '';
  $handler->display->display_options['fields']['field_hours_change']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hours_change']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_hours_change']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uw_food_outlet' => 'uw_food_outlet',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'hours_of_operation');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'hours-of-operation';
  $translatables['hours_of_operation'] = array(
    t('Master'),
    t('Hours of Operation'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
    t('Page'),
  );
  $export['hours_of_operation'] = $view;

  return $export;
}
