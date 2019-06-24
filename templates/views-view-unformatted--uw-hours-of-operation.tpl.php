<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<?php if (!empty($title)): ?>
    <h2><?php print $title; ?></h2>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
    <div class="<?php print $classes_array[$id]; ?> clearfix">
        <?php print $row; ?>
    </div>
<?php endforeach; ?>

