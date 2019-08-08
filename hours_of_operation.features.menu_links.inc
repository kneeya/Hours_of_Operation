<?php

/**
 * @file
 * hours_of_operation.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hours_of_operation_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-site-management_food-services-settings:admin/config/system/food-services.
  $menu_links['menu-site-management_food-services-settings:admin/config/system/food-services'] = array(
    'menu_name' => 'menu-site-management',
    'link_path' => 'admin/config/system/food-services',
    'router_path' => 'admin/config/system/food-services',
    'link_title' => 'Food Services Settings',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-site-management_food-services-settings:admin/config/system/food-services',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Food Services Settings');

  return $menu_links;
}
