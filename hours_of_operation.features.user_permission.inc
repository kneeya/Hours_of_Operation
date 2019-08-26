<?php

/**
 * @file
 * hours_of_operation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hours_of_operation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer food services settings'.
  $permissions['administer food services settings'] = array(
    'name' => 'administer food services settings',
    'roles' => array(
      'WCMS support' => 'WCMS support',
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'uw_food_services',
  );

  return $permissions;
}
