<?php

/**
 * @file
 * uw_hours_of_operation.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function uw_hours_of_operation_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_views:admin/structure/views.
  $menu_links['management_views:admin/structure/views'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/views',
    'router_path' => 'admin/structure/views',
    'link_title' => 'Views',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage customized lists of content.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_views:admin/structure/views',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: navigation_food-outlet:node/add/uw-food-outlet.
  $menu_links['navigation_food-outlet:node/add/uw-food-outlet'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/uw-food-outlet',
    'router_path' => 'node/add/uw-food-outlet',
    'link_title' => 'Food Outlet',
    'options' => array(
      'attributes' => array(
        'title' => 'A content type for food outlet information. Location, hours, menu, etc.',
      ),
      'identifier' => 'navigation_food-outlet:node/add/uw-food-outlet',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Food Outlet');
  t('Views');

  return $menu_links;
}
