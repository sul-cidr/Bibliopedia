<?php
/**
 * @file
 * Layer: Heatmap.
 */

namespace Drupal\openlayers\Plugin\Layer\Group;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Layer;
use Drupal\openlayers\Types\LayerInterface;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Group.
 *
 * @OpenlayersPlugin(
 *  id = "Group"
 * )
 */
class Group extends Layer {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['grouptitle'] = array(
      '#type' => 'textfield',
      '#title' => 'Layer group title',
      '#default_value' => $this->getOption('grouptitle', 'Base layers'),
    );

    /** @var LayerInterface[] $all_layers */
    $all_layers = Openlayers::loadAll('Layer');

    array_walk($all_layers, function($object) {
      $object->setWeight(0);
      $object->enabled = 0;
    });

    foreach ($this->getOption('grouplayers', array()) as $weight => $layer) {
      $layer = Openlayers::load('layer', $layer);
      $all_layers[$layer->getMachineName()]->setWeight($weight);
      $all_layers[$layer->getMachineName()]->enabled = 1;
    }

    uasort($all_layers, function($a, $b) {
      if ($a->enabled > $b->enabled) {
        return -1;
      }
      elseif ($a->enabled < $b->enabled) {
        return 1;
      }
      if ($a->getWeight() < $b->getWeight()) {
        return -1;
      }
      elseif ($a->getWeight() > $b->getWeight()) {
        return 1;
      }
      if ($a->getMachineName() < $b->getMachineName()) {
        return -1;
      }
      elseif ($a->getMachineName() > $b->getMachineName()) {
        return 1;
      }
      return 0;
    });

    $data = array();
    $i = 0;
    /** @var \Drupal\openlayers\Types\Layer $layer */
    foreach ($all_layers as $layer) {
      $data[$layer->getMachineName()] = array(
        'name' => $layer->getName(),
        'machine_name' => $layer->getMachineName(),
        'factory_service' => $layer->getFactoryService(),
        'weight' => $i++,
        'enabled' => isset($layer->enabled) ? $layer->enabled : 0,
      );
    }

    $rows = array();
    $row_elements = array();
    foreach ($data as $id => $entry) {
      $rows[$id] = array(
        'data' => array(
          array('class', array('entry-cross')),
          array(
            'data' => array(
              '#type' => 'weight',
              '#title' => t('Weight'),
              '#title_display' => 'invisible',
              '#default_value' => $entry['weight'],
              '#parents' => array('grouplayers', $id, 'weight'),
              '#attributes' => array(
                'class' => array('entry-order-weight'),
              ),
            ),
          ),
          array(
            'data' => array(
              '#type' => 'hidden',
              '#default_value' => $entry['machine_name'],
              '#parents' => array('grouplayers', $id, 'machine_name'),
            ),
          ),
          array(
            'data' => array(
              '#type' => 'checkbox',
              '#title' => t('Enable'),
              '#title_display' => 'invisible',
              '#default_value' => $entry['enabled'],
              '#parents' => array('grouplayers', $id, 'enabled'),
            ),
          ),
          check_plain($entry['name']),
          check_plain($entry['machine_name']),
          check_plain($entry['factory_service']),
          l(t('Edit'), 'admin/structure/openlayers/layers/list/' . $entry['machine_name'] . '/edit/options',
            array(
              'query' => array(
                'destination' => current_path(),
              ),
            )
          ),
        ),
        'class' => array('draggable'),
      );
      // Build rows of the form elements in the table.
      $row_elements[$id] = array(
        'weight' => &$rows[$id]['data'][1]['data'],
        'enabled' => &$rows[$id]['data'][2]['data'],
        'machine_name' => &$rows[$id]['data'][3]['data'],
      );
    }

    $form['grouplayers'] = array(
      '#type' => 'fieldset',
      '#title' => 'Layers',
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );

    // Add the table to the form.
    $form['grouplayers']['table_layers'] = array(
      '#theme' => 'table',
      // The row form elements need to be processed and build,
      // therefore pass them as element children.
      'elements' => $row_elements,
      '#header' => array(
        // We need two empty columns for the weigth field and the cross.
        array('data' => NULL, 'colspan' => 2),
        array('data' => t('Enabled'), 'colspan' => 2),
        t('Name'),
        t('Machine name'),
        t('Factory service'),
        t('Operations'),
      ),
      '#rows' => $rows,
      '#empty' => t('There are no entries available.'),
      '#attributes' => array('id' => 'entry-order-layers'),
    );
    drupal_add_tabledrag('entry-order-layers', 'order', 'sibling', 'entry-order-weight');
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit(array $form, array &$form_state) {
    $layers_enabled = array_filter($form_state['values']['grouplayers'], function($item) {
      return (bool) $item['enabled'];
    });

    uasort($layers_enabled, function($a, $b) {
      return $a['weight'] - $b['weight'];
    });

    $this->setOption('grouplayers', array_keys($layers_enabled));

    $form_state['item'] = $this->getExport();
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    $import = array();

    foreach ($this->getOption('grouplayers', array()) as $weight => $object) {
      if ($merge_object = Openlayers::load('layer', $object)) {
        $merge_object->setWeight($weight);
        $import[] = $merge_object;
      }
    }

    return $import;
  }

  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, ObjectInterface $context = NULL) {
    /** @var LayerInterface $layer */
    foreach ($context->getObjects('layer') as $layer) {
      $layer->setOption('title', $layer->getName());
    }
  }
}
