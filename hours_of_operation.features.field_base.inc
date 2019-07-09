<?php

/**
 * @file
 * hours_of_operation.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hours_of_operation_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_outlet_location'.
  $field_bases['field_outlet_location'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_outlet_location',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
