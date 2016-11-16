<?php
/**
 * @file
 * CTools Export UI plugin definition for maps.
 */

/**
 * CTools Export UI plugin definition.
 */
function openlayers_ui_OpenlayersMaps_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_maps',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'maps',
      'menu title' => 'Maps',
      'menu description' => 'Administer Openlayers maps presets.',
    ),

    'handler' => array(
      'class' => '\\Drupal\\openlayers_ui\\UI\\OpenlayersMaps',
      'file' => 'OpenlayersMaps.php',
    ),

    'use wizard' => TRUE,
    'form info' => array(
      'order' => array(
        'start' => t('Administrative settings'),
        'settings' => t('Map settings'),
        'layers' => t('Layers'),
        'controls' => t('Controls'),
        'interactions' => t('Interactions'),
        'components' => t('Components'),
        'preview' => t('Preview'),
      ),
      'forms' => array(
        'start' => array(
          'form id' => 'openlayers_map_form_start',
        ),
        'settings' => array(
          'form id' => 'openlayers_map_form_settings',
        ),
        'layers' => array(
          'form id' => 'openlayers_map_form_layers',
        ),
        'controls' => array(
          'form id' => 'openlayers_map_form_controls',
        ),
        'interactions' => array(
          'form id' => 'openlayers_map_form_interactions',
        ),
        'components' => array(
          'form id' => 'openlayers_map_form_components',
        ),
        'preview' => array(
          'form id' => 'openlayers_map_form_preview',
        ),
      ),
      'wrapper' => 'openlayers_objects_ui_form_wrapper',
    ),

    'export' => array(
      'admin_title' => 'name',
      'admin_description' => 'description',
    ),

    'title singular' => t('map'),
    'title plural' => t('maps'),
    'title singular proper' => t('Openlayers map preset'),
    'title plural proper' => t('Openlayers maps presets'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Map saved.'),
        ),
        'delete' => array(
          'success' => t('Map was deleted.'),
        ),
      ),
    ),
  );
}

/**
 * Map base config form handler.
 */
function openlayers_map_form_start($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersMaps();
  $class->init($form_state['plugin']);
  $class->edit_form($form, $form_state);
  return $form;
}

/**
 * Map base config form validation handler.
 */
function openlayers_map_form_start_validate($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersMaps();
  $class->init($form_state['plugin']);
  $class->edit_form_validate($form, $form_state);
}

/**
 * Map base config form submit handler.
 */
function openlayers_map_form_start_submit($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersMaps();
  $class->init($form_state['plugin']);
  $class->edit_form_submit($form, $form_state);
}

/**
 * Map settings config form handler.
 */
function openlayers_map_form_settings($form, &$form_state) {
  if (!isset($form_state['item']->factory_service)) {
    $form_state['item']->factory_service = 'openlayers.Map:OLMap';
  }
  if (($map = \Drupal\openlayers\Openlayers::load('Map', $form_state['item'])) == TRUE) {
    $map->optionsForm($form, $form_state);
    $form['options']['#tree'] = TRUE;
  }

  return $form;
}

/**
 * Map settings config form validation handler.
 */
function openlayers_map_form_settings_validate($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);
  $map->optionsFormValidate($form, $form_state);
}

/**
 * Map settings config form submit handler.
 */
function openlayers_map_form_settings_submit($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);

  if (!$map->getFactoryService()) {
    $map->setFactoryService('openlayers.Map:OLMap');
  }

  $map->optionsFormSubmit($form, $form_state);
}

/**
 * Map layers config form handler.
 */
function openlayers_map_form_layers($form, &$form_state) {
  if (($map = \Drupal\openlayers\Openlayers::load('Map', $form_state['item'])) == FALSE) {
    return;
  }

  $all_layers = \Drupal\openlayers\Openlayers::loadAll('Layer');

  array_walk($all_layers, function(\Drupal\openlayers\Types\LayerInterface $layer) {
    $layer->setWeight(0);
    $layer->enabled = 0;
  });

  foreach ($map->getOption('layers', array()) as $weight => $layer) {
    /** @var Drupal\openlayers\Types\LayerInterface $layer */
    $layer = \Drupal\openlayers\Openlayers::load('layer', $layer);
    $all_layers[$layer->getMachineName()]->setWeight($weight);
    $all_layers[$layer->getMachineName()]->enabled = 1;
  }

  uasort($all_layers, function(\Drupal\openlayers\Types\LayerInterface $a, \Drupal\openlayers\Types\LayerInterface $b) {
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
  foreach ($all_layers as $machine_name => $layer) {
    $data[$machine_name] = array(
      'name' => $layer->getName(),
      'machine_name' => $layer->getMachineName(),
      'factory_service' => $layer->getFactoryService(),
      'weight' => $i++,
      'enabled' => isset($layer->enabled) ? $layer->enabled : 0,
      'default' => 1,
      'style' => $layer->getOption('style', NULL),
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
            '#parents' => array('layers', $id, 'weight'),
            '#attributes' => array(
              'class' => array('entry-order-weight'),
            ),
          ),
        ),
        array(
          'data' => array(
            '#type' => 'hidden',
            '#default_value' => $entry['machine_name'],
            '#parents' => array('layers', $id, 'machine_name'),
          ),
        ),
        array(
          'data' => array(
            '#type' => 'checkbox',
            '#title' => t('Enable'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['enabled'],
            '#parents' => array('layers', $id, 'enabled'),
          ),
        ),
        array(
          'data' => array(
            '#type' => 'select',
            '#title' => t('Style'),
            '#title_display' => 'invisible',
            '#options' => array('' => t('- Select a Style -')) + \Drupal\openlayers\Openlayers::loadAllAsOptions('style'),
            '#default_value' => $entry['style'],
            '#parents' => array('layers', $id, 'style'),
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
      'style' => &$rows[$id]['data'][3]['data'],
      'machine_name' => &$rows[$id]['data'][4]['data'],
    );
  }

  // Add the table to the form.
  $form['layers']['table_layers'] = array(
    '#theme' => 'table',
    // The row form elements need to be processed and build,
    // therefore pass them as element children.
    'elements' => $row_elements,
    '#header' => array(
      // We need two empty columns for the weigth field and the cross.
      array('data' => NULL, 'colspan' => 2),
      array('data' => t('Enabled'), 'colspan' => 2),
      array('data' => t('Style'), 'colspan' => 1),
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

  return $form;
}

/**
 * Map layers config form submit handler.
 */
function openlayers_map_form_layers_submit($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);

  $layers_enabled = array_filter($form_state['values']['layers'], function($item) {
    return (bool) $item['enabled'];
  });

  uasort($layers_enabled, function($a, $b) {
    return $a['weight'] - $b['weight'];
  });

  foreach ($layers_enabled as $data) {
    // Update the layer style.
    if (($layer = \Drupal\openlayers\Openlayers::load('layer', $data['machine_name'])) == TRUE) {
      if (!empty($data['style'])) {
        $layer->setOption('style', $data['style']);
      }
      else {
        $layer->clearOption('style');
      }
      \Drupal\openlayers\Openlayers::save($layer);
    }
  }

  $map->setOption('layers', array_keys($layers_enabled));
  $form_state['item'] = $map->getExport();
}

/**
 * Map controls config form handler.
 */
function openlayers_map_form_controls($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);
  $all_controls = \Drupal\openlayers\Openlayers::loadAll('Control');

  if (!isset($form_state['item']->options['controls'])) {
    $form_state['item']->options['controls'] = array();
  }

  array_walk($all_controls, function(\Drupal\openlayers\Types\ControlInterface $control) {
    $control->setWeight(0);
    $control->enabled = 0;
  });

  foreach ($map->getObjects('control') as $control) {
    /** @var Drupal\openlayers\Types\Control $control */
    $all_controls[$control->getMachineName()]->setWeight($control->getWeight());
    $all_controls[$control->getMachineName()]->enabled = 1;
  }

  uasort($all_controls, function(\Drupal\openlayers\Types\ControlInterface $a, \Drupal\openlayers\Types\ControlInterface $b) {
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
  foreach ($all_controls as $machine_name => $control) {
    $data[$machine_name] = array(
      'name' => $control->getName(),
      'machine_name' => $control->getMachineName(),
      'description' => $control->getDescription(),
      'weight' => $i++,
      'enabled' => (int) $control->enabled,
    );
  }

  $rows = array();
  $row_elements = array();
  foreach ($data as $id => $entry) {
    $rows[$id] = array(
      'data' => array(
        array(
          'class',
          array(
            'entry-cross',
          ),
        ),
        array(
          'data' => array(
            '#type' => 'weight',
            '#title' => t('Weight'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['weight'],
            '#parents' => array('controls', $id, 'weight'),
            '#attributes' => array(
              'class' => array('entry-order-weight'),
            ),
          ),
        ),
        array(
          'data' => array(
            '#type' => 'checkbox',
            '#title' => t('Enable'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['enabled'],
            '#parents' => array('controls', $id, 'enabled'),
          ),
        ),
        check_plain($entry['name']),
        check_plain($entry['machine_name']),
        check_plain($entry['description']),
        l(t('Edit'), 'admin/structure/openlayers/controls/list/' . $entry['machine_name'] . '/edit',
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
    );
  }

  $form['options']['#tree'] = TRUE;

  // Add the table to the form.
  $form['controls']['table_controls'] = array(
    '#theme' => 'table',
    // The row form elements need to be processed and build,
    // therefore pass them as element children.
    'elements' => $row_elements,
    '#header' => array(
      // We need two empty columns for the weigth field and the cross.
      array('data' => NULL, 'colspan' => 2),
      t('Enabled'),
      t('Name'),
      t('Machine name'),
      t('Description'),
      t('Operations'),
    ),
    '#rows' => $rows,
    '#empty' => t('There are no entries available.'),
    '#attributes' => array('id' => 'entry-order-controls'),
  );
  drupal_add_tabledrag('entry-order-controls', 'order', 'sibling', 'entry-order-weight');

  return $form;
}

/**
 * Map controls config form submit handler.
 */
function openlayers_map_form_controls_submit($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);

  $controls_enabled = array_filter($form_state['values']['controls'], function($item) {
    return (bool) $item['enabled'];
  });

  uasort($controls_enabled, function($a, $b) {
    return $a['weight'] - $b['weight'];
  });

  $map->setOption('controls', array_keys($controls_enabled));

  $form_state['item'] = $map->getExport();
}

/**
 * Map interactions config form handler.
 */
function openlayers_map_form_interactions($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);
  $all_interactions = \Drupal\openlayers\Openlayers::loadAll('Interaction');

  $header = array(
    'name' => t('Name'),
    'machine_name' => t('Machine name'),
    'description' => t('Description'),
    'operations' => t('Operations'),
  );

  array_walk($all_interactions, function(\Drupal\openlayers\Types\InteractionInterface $interaction) {
    $interaction->setWeight(0);
    $interaction->enabled = 0;
  });

  foreach ($map->getObjects('interaction') as $interaction) {
    /** @var Drupal\openlayers\Types\InteractionInterface $interaction */
    $all_interactions[$interaction->getMachineName()]->setWeight($interaction->getWeight());
    $all_interactions[$interaction->getMachineName()]->enabled = 1;
  }

  uasort($all_interactions, function(\Drupal\openlayers\Types\InteractionInterface $a, \Drupal\openlayers\Types\InteractionInterface $b) {
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

  $rows = array();
  foreach ($all_interactions as $interaction) {
    $rows[$interaction->getMachineName()] = array(
      'name' => $interaction->getName(),
      'machine_name' => $interaction->getMachineName(),
      'description' => $interaction->getDescription(),
      'operations' => l(
        t('Edit'),
        'admin/structure/openlayers/interactions/list/' . $interaction->getMachineName() . '/edit/options',
        array(
          'query' => array(
            'destination' => current_path(),
          ),
        )
      ),
    );
  }

  $form['options']['#tree'] = TRUE;

  if (!isset($form_state['item']->options['interactions'])) {
    $form_state['item']->options['interactions'] = array();
  }

  $form['options']['interactions'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $rows,
    '#default_value' => drupal_map_assoc($form_state['item']->options['interactions']),
  );

  return $form;
}

/**
 * Map interactions config form submit handler.
 */
function openlayers_map_form_interactions_submit($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);

  $interactions_enabled = array_filter($form_state['values']['options']['interactions']);

  $map->setOption('interactions', array_keys($interactions_enabled));

  $form_state['item'] = $map->getExport();
}

/**
 * Map components config form handler.
 */
function openlayers_map_form_components($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);
  $all_components = \Drupal\openlayers\Openlayers::loadAll('Component');

  array_walk($all_components, function(\Drupal\openlayers\Types\ComponentInterface $component) {
    $component->setWeight(0);
    $component->enabled = 0;
  });

  foreach ($map->getObjects('component') as $component) {
    /** @var Drupal\openlayers\Types\Component $component */
    $all_components[$component->getMachineName()]->setWeight($component->getWeight());
    $all_components[$component->getMachineName()]->enabled = 1;
  }

  uasort($all_components, function(\Drupal\openlayers\Types\ComponentInterface $a, \Drupal\openlayers\Types\ComponentInterface $b) {
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
  foreach ($all_components as $component) {
    $data[$component->getMachineName()] = array(
      'name' => $component->getName(),
      'machine_name' => $component->getMachineName(),
      'description' => $component->getDescription(),
      'weight' => $i++,
      'enabled' => $component->enabled,
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
            '#parents' => array('components', $id, 'weight'),
            '#attributes' => array(
              'class' => array('entry-order-weight'),
            ),
          )),
        array(
          'data' => array(
            '#type' => 'checkbox',
            '#title' => t('Enable'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['enabled'],
            '#parents' => array('components', $id, 'enabled'),
          )),
        check_plain($entry['name']),
        check_plain($entry['machine_name']),
        check_plain($entry['description']),
        l(t('Edit'), 'admin/structure/openlayers/components/list/' . $entry['machine_name'] . '/edit',
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
    );
  }

  $form['options']['#tree'] = TRUE;

  // Add the table to the form.
  $form['components']['table_components'] = array(
    '#theme' => 'table',
    // The row form elements need to be processed and build,
    // therefore pass them as element children.
    'elements' => $row_elements,
    '#header' => array(
      // We need two empty columns for the weight field and the cross.
      array('data' => NULL, 'colspan' => 2),
      t('Enabled'),
      t('Name'),
      t('Machine name'),
      t('Description'),
      t('Operations'),
    ),
    '#rows' => $rows,
    '#empty' => t('There are no entries available.'),
    '#attributes' => array('id' => 'entry-order-components'),
  );
  drupal_add_tabledrag('entry-order-components', 'order', 'sibling', 'entry-order-weight');

  return $form;
}

/**
 * Map components config form submit handler.
 */
function openlayers_map_form_components_submit($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);

  $components_enabled = array_filter($form_state['values']['components'], function($item) {
    return (bool) $item['enabled'];
  });

  uasort($components_enabled, function($a, $b) {
    return $a['weight'] - $b['weight'];
  });

  $map->setOption('components', array_keys($components_enabled));

  $form_state['item'] = $map->getExport();
}

/**
 * Map preview form handler.
 */
function openlayers_map_form_preview($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);

  $form['preview'] = array(
    '#type' => 'openlayers',
    '#map' => $map,
  );

  $alternative_template = 'openlayers--' . str_replace('_', '-', $map->getMachineName()) . '.tpl.php';

  $form['information']['theme'] = array(
    '#weight' => 20,
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => 'Theming information',
    'template_content' => array(
      '#title' => 'Openlayers map template',
      '#type' => 'textarea',
      '#default_value' => file_get_contents(drupal_get_path('module', 'openlayers') . '/theme/openlayers.tpl.php'),
      '#description' => t('The default Openlayers template is <strong>openlayers.tpl.php</strong> for all the maps. You may override it by creating a file with the same name in your theme template\'s directory. You can also name it <em>openlayers--[map_machine_name].tpl.php</em> if you want to alter the display of this particular map only. For example: <strong>@template</strong>.', array('@template' => $alternative_template)),
    ),
  );

  return $form;
}

/**
 * Map preview config form submit handler.
 */
function openlayers_map_form_preview_submit($form, &$form_state) {

}
