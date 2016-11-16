<?php
/**
 * @file
 * Default theme implementation to display an Openlayers map.
 *
 * Debug the result of the function get_defined_vars() to have an overview
 * of all the variables you have access to.
 */
?>

<div id="openlayers-container-<?php print $openlayers['id']; ?>" class="openlayers-container contextual-links-region">
  <div id="openlayers-map-container-<?php print $openlayers['id']; ?>" class="openlayers-map-container" style="<?php print $openlayers['styles']; ?>">
    <?php print render($openlayers['map_prefix']); ?>
    <div id="<?php print $openlayers['id']; ?>" class="<?php print $openlayers['classes']; ?>"></div>
    <?php print render($openlayers['map_suffix']); ?>
  </div>
</div>

<?php if (isset($openlayers['parameters'])): ?>
  <?php print render($openlayers['parameters']); ?>
<?php endif; ?>

<?php if (isset($openlayers['capabilities'])): ?>
  <?php print render($openlayers['capabilities']); ?>
<?php endif; ?>
