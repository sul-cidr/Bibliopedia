<?php
/**
 * @file
 * Component: GeofieldWidget.
 */

namespace Drupal\openlayers_geofield\Plugin\Component\GeofieldWidget;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Plugin\Source\Vector\Vector;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\LayerInterface;
use Drupal\openlayers\Types\ObjectInterface;
use geoPHP;

/**
 * Class GeofieldWidget.
 *
 * @OpenlayersPlugin(
 *  id = "GeofieldWidget"
 * )
 */
class GeofieldWidget extends Component {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['dataType'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Data type'),
      '#description' => t('If more than one type is choosen a control to select the type to use is displayed when drawing.'),
      '#multiple' => TRUE,
      '#options' => array(
        'GeoJSON' => 'GeoJSON',
        'KML' => 'KML',
        'GPX' => 'GPX',
        'WKT' => 'WKT',
      ),
      '#default_value' => $this->getOption('dataType'),
      '#required' => TRUE,
    );
    $form['options']['dataProjection'] = array(
      '#type' => 'radios',
      '#title' => t('Data projection'),
      '#options' => array(
        'EPSG:4326' => 'EPSG:4326',
        'EPSG:3857' => 'EPSG:3857',
      ),
      '#description' => t('Defines in which projection the data are read and written.'),
      '#default_value' => $this->getOption('dataProjection', 'EPSG:4326'),
      '#required' => TRUE,
    );
    $form['options']['featureLimit'] = array(
      '#type' => 'textfield',
      '#title' => t('Feature limit'),
      '#description' => t('Limits the number of features. Set to 0 for no limit.'),
      '#default_value' => $this->getOption('featureLimit'),
      '#required' => TRUE,
    );
    $form['options']['showInputField'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show input field'),
      '#description' => t('Shows the data in a textarea.'),
      '#default_value' => (int) $this->getOption('showInputField'),
    );
    $form['options']['inputFieldName'] = array(
      '#type' => 'textfield',
      '#title' => t('Name of the input field'),
      '#description' => t('Define the name of the input field. You can use brackets to build structure: [geofield][component][data]'),
      '#default_value' => $this->getOption('inputFieldName'),
    );
    $form['options']['initialData'] = array(
      '#type' => 'textarea',
      '#title' => t('Initial data'),
      '#description' => t('Initial data to set. You can use any of the data types available as "Data type". Ensure the data have the same projection as defined in "Data projection".'),
      '#default_value' => $this->getOption('initialData'),
    );
    $form['options']['editStyle'] = array(
      '#type' => 'select',
      '#title' => t('Edit style'),
      '#default_value' => $this->getOption('editStyle'),
      '#options' => Openlayers::loadAllAsOptions('style'),
    );
    $form['options']['editLayer'] = array(
      '#type' => 'select',
      '#title' => t('Select the widget layer'),
      '#default_value' => $this->getOption('editLayer'),
      '#options' => Openlayers::loadAllAsOptions('layer'),
    );
    $form['options']['editControl'] = array(
      '#type' => 'select',
      '#title' => t('Select the edit control'),
      '#default_value' => $this->getOption('editControl'),
      '#options' => Openlayers::loadAllAsOptions('control'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    if ($style = $this->getOption('editStyle')) {
      $style = Openlayers::load('style', $style);

      $this->setWeight($style->getWeight() + 1);
      $import = array_merge($style->getCollection()->getFlatList(), $import);
    }

    if ($layer = $this->getOption('editLayer')) {
      $layer = Openlayers::load('layer', $layer);
      $import = array_merge($layer->getCollection()->getFlatList(), $import);
    }

    if ($control = $this->getOption('editControl')) {
      $control = Openlayers::load('control', $control);
      $import = array_merge($control->getCollection()->getFlatList(), $import);
    }

    return $import;
  }

  /**
   * Convert an array of WKT into a Geometry and features.
   *
   * @return array
   *   An array containing the Geometry and the features.
   * @throws \exception
   */
  private function initialDataToGeomFeatures() {
    geophp_load();
    $initial_data = $this->getOption('initialData', '');
    $geom  = new \GeometryCollection(array());
    $features = array();

    // Process initial data. Ensure it's WKT.
    if (isset($initial_data)) {
      $geoms = array();

      // Process strings and arrays likewise.
      if (!is_array($initial_data)) {
        $initial_data = array($initial_data);
      }

      foreach ($initial_data as $delta => $item) {
        if (is_array($item) && array_key_exists('geom', $item)) {
          $geoms[] = geoPHP::load($item['geom']);
        }
      }

      $geom = geoPHP::geometryReduce($geoms);

      // If we could parse the geom process further.
      if ($geom && !$geom->isEmpty()) {
        if (in_array($geom->getGeomType(), array('MultiPoint', 'MultiLineString', 'MultiPolygon', 'GeometryCollection'))) {
          foreach ($geom->getComponents() as $component) {
            $features[] = array(
              'wkt' => $component->out('wkt'),
              'projection' => 'EPSG:4326',
            );
          }
        }
        else {
          $features[] = array(
            'wkt' => $geom->out('wkt'),
            'projection' => 'EPSG:4326',
          );
        }
      }
    }

    return array(
      'geom' => $geom,
      'features' => $features,
    );
  }

  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, ObjectInterface $context = NULL) {
    foreach ($context->getCollection()->getObjects('layer') as $layer) {
      if ($layer->getMachineName() == $this->getOption('editLayer', FALSE)) {
        if ($source = $layer->getSource()) {
          if ($source instanceof Vector) {
            $geom = $this->initialDataToGeomFeatures();
            $source->setOption('features', $geom['features']);
          }
        }
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    $component = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'openlayers-geofield-' . $context->getId(),
      ),
    );

    $data_type = $this->getOption('dataType', array('WKT' => 'WKT'));
    if (count($data_type) > 1) {
      $component['dataType'] = array(
        '#type' => 'select',
        '#title' => 'Data type',
        '#options' => array_intersect_key(
          array(
            'WKT' => 'WKT',
            'GeoJSON' => 'GeoJSON',
            'KML' => 'KML',
            'GPX' => 'GPX',
          ),
          $data_type
        ),
        '#attributes' => array(
          'class' => array('data-type'),
        ),
        '#default_value' => $data_type,
      );
    }
    else {
      $parents = $this->getOption('parents');
      $parents[] = 'dataType';

      $component['dataType'] = array(
        '#parents' => $parents,
        '#type' => 'hidden',
        '#default_value' => reset($data_type),
        '#value' => reset($data_type),
        '#attributes' => array(
          'class' => array('data-type'),
        ),
      );
    }

    $geom = $this->initialDataToGeomFeatures();
    $wkt = '';
    if (!empty($geom['geom'])) {
      $wkt = $geom['geom']->out('wkt');
    }
    $parents = $this->getOption('parents');
    $parents[] = 'geom';

    $component['data'] = array(
      '#parents' => $parents,
      '#type' => ($this->getOption('showInputField')) ? 'textarea' : 'hidden',
      '#title' => 'Data',
      '#attributes' => array(
        'class' => array('openlayers-geofield-data'),
      ),
      '#default_value' => $wkt,
    );

    // Now add the component into the build array. This is a bit complex due
    // the fact that we want to support form nesting.
    $parents = array('geofield', 'component');
    $data_input_field_name = $this->getOption('inputFieldName');
    if (!empty($data_input_field_name)) {
      $data_input_field_name = preg_replace('/(^\[|\]$)/', '', $data_input_field_name);
      $levels = explode('][', $data_input_field_name);
      $parents = array_slice(explode('][', $data_input_field_name), 0, count($levels) - 1);
      // Ensure the requested name for the input data field is set.
      $component[end($levels)] = $component['data'];
      unset($component['data']);
    }
    if (!empty($parents)) {
      drupal_array_set_nested_value($build, $parents, $component);
    }
    else {
      $build['parameters'][$this->getPluginId()] = $component;
    }
  }
}
