<?php

/**
 * @file
 * hours_of_operation.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hours_of_operation_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'hours_of_operation';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'hours_of_operation' => 'hours_of_operation',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hours_of_operation-hours_of_operation_header' => array(
          'module' => 'hours_of_operation',
          'delta' => 'hours_of_operation_header',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['hours_of_operation'] = $context;

  return $export;
}
