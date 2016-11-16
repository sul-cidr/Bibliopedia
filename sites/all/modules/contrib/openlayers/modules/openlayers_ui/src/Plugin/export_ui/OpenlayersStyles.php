<?php
/**
 * @file
 * Class openlayers_components_ui.
 */

namespace Drupal\openlayers_ui\UI;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\MapInterface;

/**
 * Class openlayers_components_ui.
 */
class OpenlayersStyles extends \OpenlayersObjects {

  /**
   * {@inheritdoc}
   */
  public function hook_menu(&$items) {
    parent::hook_menu($items);
    $items['admin/structure/openlayers/styles']['type'] = MENU_LOCAL_TASK;
    $items['admin/structure/openlayers/styles']['weight'] = -6;
  }

  /**
   * Provide the table header.
   *
   * If you've added columns via list_build_row() but are still using a
   * table, override this method to set up the table header.
   */
  public function list_table_header() {
    $header = array();
    $header[] = array('data' => t('Preview'), 'class' => array('ctools-export-ui-preview'));
    if (!empty($this->plugin['export']['admin_title'])) {
      $header[] = array('data' => t('Name'), 'class' => array('ctools-export-ui-title'));
    }

    $header[] = array('data' => t('Machine name'), 'class' => array('ctools-export-ui-name'));
    $header[] = array('data' => t('Service'), 'class' => array('ctools-export-ui-service'));
    $header[] = array('data' => t('Storage'), 'class' => array('ctools-export-ui-storage'));
    $header[] = array('data' => t('Operations'), 'class' => array('ctools-export-ui-operations'));

    return $header;
  }

  /**
   * Build a row based on the item.
   *
   * By default all of the rows are placed into a table by the render
   * method, so this is building up a row suitable for theme('table').
   * This doesn't have to be true if you override both.
   */
  public function list_build_row($item, &$form_state, $operations) {
    // Set up sorting.
    $name = $item->{$this->plugin['export']['key']};
    $schema = ctools_export_get_schema($this->plugin['schema']);

    list($plugin_manager, $plugin_id) = explode(':', $item->factory_service);
    list($module, $plugin_type) = explode('.', $plugin_manager);
    $object = \Drupal\openlayers\Openlayers::load($plugin_type, $item->machine_name);

    // Note: $item->{$schema['export']['export type string']} should have
    // already been set up by export.inc so we can use it safely.
    switch ($form_state['values']['order']) {
      case 'disabled':
        $this->sorts[$name] = empty($item->disabled) . $name;
        break;

      case 'title':
        $this->sorts[$name] = $item->{$this->plugin['export']['admin_title']};
        break;

      case 'name':
        $this->sorts[$name] = $name;
        break;

      case 'class':
        $this->sorts[$name] = $name;
        break;

      case 'storage':
        $this->sorts[$name] = $item->{$schema['export']['export type string']} . $name;
        break;
    }

    switch ($item->type) {
      case t('Default'):
      default:
        $type = t('In code');
        break;

      case t('Normal'):
        $type = t('In database');
        break;

      case t('Overridden'):
        $type = t('Database overriding code');
    }

    // Generate a map and use the style on it to make a preview.
    /** @var MapInterface $map */
    $map = Openlayers::load('map', 'openlayers_ui_map_style_demo');
    $layer = $map->getCollection()->getObjectById('layer', 'openlayers_ui_layer_style_demo');
    $map_render = $map->addLayer($layer->setStyle($object))->render();

    $this->rows[$name]['data'] = array();
    $this->rows[$name]['class'] = !empty($item->disabled) ? array('ctools-export-ui-disabled') : array('ctools-export-ui-enabled');
    $this->rows[$name]['data'][] = array('data' => $map_render, 'class' => array('ctools-export-ui-title'));

    // If we have an admin title, make it the first row.
    if (!empty($this->plugin['export']['admin_title'])) {
      $this->rows[$name]['data'][] = array('data' => check_plain($item->{$this->plugin['export']['admin_title']}), 'class' => array('ctools-export-ui-title'));
    }
    $this->rows[$name]['data'][] = array('data' => check_plain($name), 'class' => array('ctools-export-ui-name'));
    $this->rows[$name]['data'][] = array('data' => check_plain($item->factory_service), 'class' => array('ctools-export-ui-service'));
    $this->rows[$name]['data'][] = array('data' => $type, 'class' => array('ctools-export-ui-storage'));

    $ops = theme('links__ctools_dropbutton', array(
      'links' => $operations,
      'attributes' => array('class' => array('links', 'inline')),
    ));

    $this->rows[$name]['data'][] = array('data' => $ops, 'class' => array('ctools-export-ui-operations'));

    // Add an automatic mouseover of the description if one exists.
    if (!empty($this->plugin['export']['admin_description'])) {
      $this->rows[$name]['title'] = $item->{$this->plugin['export']['admin_description']};
    }
  }

}
