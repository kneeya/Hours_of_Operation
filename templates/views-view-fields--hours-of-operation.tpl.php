<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<!--<a name="nid--><?php //print $fields['nid']->raw; ?><!--"></a>-->
<span id="nid<?php print $fields['nid']->raw; ?>" class="new-font">
<?php //hours_of_operation_field_output($fields, 'title'); ?>
<div align="center" class="col-33 first">
    <?php hours_of_operation_field_output($fields, 'field_image'); ?>
</div>
<div class="col-66">
    <div class="outlet-title"><?php hours_of_operation_field_output($fields, 'title'); ?></div>
<div class="outlet-location"><?php hours_of_operation_field_output($fields, 'field_outlet_location'); ?></div>
    <div class="opening"><?php hours_of_operation_field_output($fields, 'field_opening_hours'); ?></div>
    <?php if(!empty($fields['field_date_closed']) || !empty($fields['field_hours_change'])) { ?>
    <ul class="exceptions_list">

        <?php
        // Exception - Closed (field_date_closed) display.
        $closed_fields = $row->field_field_date_closed;
        foreach ($closed_fields as $item) {

            // Get date from and date to values.
            $value = $item['raw']['value'];
            $value2 = $item['raw']['value2'];

            // Remove time part, only has yyyy-mm-dd.
            $close_date_from = substr($value, 0, -9);
            $close_date_to = substr($value2, 0, -9);

            // Create date from string 'yyyy-mm-dd'.
            $date = date_create($close_date_from);
            $date2 = date_create($close_date_to);

            // Exceptions - field_date_closed: no End Date.
            if (strcmp($close_date_from, $close_date_to) === 0) {
                $display_date = date_format($date, "M jS");
                echo '<li class="oh-display-closed-date"><span>' . $display_date . ':</span><span class="oh-display-closed">Closed</span></li>';
            }
            else {
                $close_year_from = substr($close_date_from, 0, 4);
                $close_year_to = substr($close_date_to, 0, 4);
                $close_month_from = substr($close_date_from, 5, 2);
                $close_month_to = substr($close_date_to, 5, 2);

                // Exception - field_date_closed: has End Date (same year).
                if (strcmp($close_year_from, $close_year_to) === 0) {
                    $display_month_from_format = uw_month_name_short($date->format('n'));
                    $display_month_to_format = uw_month_name_short($date2->format('n'));
                    $display_date_from_format = date_format($date, "jS");
                    $display_date_to_format = date_format($date2, "jS");

                    // Exception - Closed: has End Date (same year, same month and different date.)
                    if (strcmp($close_month_from, $close_month_to) === 0) {
                        echo '<li class="oh-display-closed-date"><span>' . $display_month_from_format . ' ' .
                            $display_date_from_format . ' - ' . $display_date_to_format . ':</span><span class="oh-display-closed">Closed</span></li>';
                    }
                    // Exception - field_date_closed: has End Date (same year, different month and different date)
                    else {
                        echo '<li class="oh-display-closed-date"><span>' . $display_month_from_format . ' ' .
                            $display_date_from_format . ' - ' . $display_month_to_format . ' ' . $display_date_to_format .
                            ':</span><span class="oh-display-closed">Closed</span></li>';
                    }
                }
                // Exception - field_date_closed: has End Date (different year).
                else {
                    echo '<li class="oh-display-closed-date"><span>' . $display_month_from_format . ' ' .
                        $display_date_from_format . ', ' . $close_year_from . ' - ' . $display_month_to_format . ' ' . $display_date_to_format .
                        ', ' . $close_year_to . ':</span><span class="oh-display-closed">Closed</span></li>';
                }
            }
        }

        // Exception - Hours Change (field_hours_change) display.
        $change_fields = $row->field_field_hours_change;

        foreach ($change_fields as $item) {
            // Get date from and date to values.
            $change_value = $item['raw']['value'];
            $change_value2 = $item['raw']['value2'];

            // Remove time part, only has yyyy-mm-dd.
            $change_date_from = substr($change_value, 0, -9);
            $change_date_to = substr($change_value2, 0, -9);

            // Remove yyyy-mm-dd part, only has time part.
            $change_time_from = substr($change_value, 11, 5);
            $change_time_to = substr($change_value2, 11, 5);

            // Change time from 24-hour time to 12-hour time.
            $time_from_12_hour = date("g:i a", strtotime($change_time_from));
            $time_to_12_hour = date("g:i a", strtotime($change_time_to));

            // Create date from string 'yyyy-mm-dd'.
            $change_date = date_create($change_date_from);
            $change_date2 = date_create($change_date_to);

            // Exceptions - field_hours_change: no End Date.
            if (strcmp($change_date_from, $change_date_to) === 0 && strcmp($change_time_from, $change_time_to) === 0) {
                $display_change_date = date_format($change_date, "M jS");
                echo '<li class="oh-display-change-hours"><span>' . $display_change_date .
                    ':</span><span>' . $time_from_12_hour . '</span></li>';
            }
            else {
                $change_year_from = substr($change_date_from, 0, 4);
                $change_year_to = substr($change_date_to, 0, 4);
                $change_month_from = substr($change_date_from, 5, 2);
                $change_month_to = substr($change_date_to, 5, 2);

                // Exceptions - field_hours_change: has End Date (same year).
                if (strcmp($change_year_from, $change_year_to) === 0) {
                    $display_change_month_from_format = uw_month_name_short($date->format('n'));
                    $display_change_month_to_format = uw_month_name_short($date2->format('n'));
                    $display_change_date_from_format = date_format($change_date, "jS");
                    $display_change_date_to_format = date_format($change_date2, "jS");

                    // Exception - field_hours_change: has End Date (same year, same month.)
                    if (strcmp($change_month_from, $change_month_to) === 0) {
                        // Exception - field_hours_change: has End Date (same year, same month, same day.)
                        if (strcmp($change_date_from, $change_date_to) === 0) {
                            echo '<li class="oh-display-change-hours"><span>' . $display_change_month_from_format . ' ' .
                                $display_change_date_from_format . ': </span><span>' . $time_from_12_hour . ' - ' . $time_to_12_hour . '</span></li>';
                        }
                        // Exception - field_hours_change: has End Date (same year, same month, different day.)
                        else {
                            echo '<li class="oh-display-change-hours"><span>' . $display_change_month_from_format . ' ' .
                                $display_change_date_from_format . ' - ' . $display_change_date_to_format . ': </span><span>' . $time_from_12_hour .
                                ' - ' . $time_to_12_hour . '</span></li>';
                        }
                    }
                    // Exception - field_hours_change: has End Date (same year, different month and different day)
                    else {
                        echo '<li class="oh-display-change-hours"><span>' . $display_change_month_from_format . ' ' .
                            $display_change_date_from_format . ' - ' . $display_change_month_to_format . ' ' . $display_change_date_to_format .
                            ': </span><span>' . $time_from_12_hour . ' - ' . $time_to_12_hour . '</span></li>';
                    }
                }
                // Exceptions - field_hours_change: has End Date (different year).
                else {
                    echo '<li class="oh-display-change-hours"><span>' . $display_month_from_format . ' ' .
                        $display_date_from_format . ', ' . $close_year_from . ' - ' . $display_month_to_format . ' ' . $display_date_to_format .
                        ', ' . $close_year_to . ': </span><span>' . $time_from_12_hour . ' - ' . $time_to_12_hour . '</span></li>';
                }
            }
        }
        } ?>
    </ul>
</div>
</span>
