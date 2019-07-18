<?php

/**
 * @file
 * hours_of_operation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hours_of_operation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

