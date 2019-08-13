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

/**
 * Implements hook_views_api().
 */
function hours_of_operation_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function hours_of_operation_image_default_styles() {
  $styles = array();

  // Exported image style: uw_food_outlet_image_style.
  $styles['uw_food_outlet_image_style'] = array(
    'label' => 'Food Outlets (150x150)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => 150,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
