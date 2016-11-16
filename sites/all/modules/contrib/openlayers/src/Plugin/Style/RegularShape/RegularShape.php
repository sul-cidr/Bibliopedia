<?php
/**
 * @file
 * Style: RegularShape.
 */

namespace Drupal\openlayers\Plugin\Style\RegularShape;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Style;

/**
 * Class RegularShape.
 *
 * @OpenlayersPlugin(
 *  id = "RegularShape",
 *  description = "Set regular shape style for vector features. The resulting shape will be a regular polygon when radius is provided, or a star when radius1 and radius2 are provided."
 * )
 */
class RegularShape extends Style {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['default'] = array(
      '#type' => 'fieldset',
      '#title' => t('Default'),
      '#collapsible' => TRUE,
    );
    $form['options']['default']['image'] = array(
      '#type' => 'fieldset',
      '#title' => t('Image options'),
      '#collapsible' => FALSE,
    );
    $form['options']['default']['image']['points'] = array(
      '#type' => 'textfield',
      '#title' => 'Points',
      '#default_value' => $this->getOption(array('default', 'image', 'points'), '4'),
      '#required' => TRUE,
      '#description' => 'Number of points for stars and regular polygons. In case of a polygon, the number of points is the number of sides.',
    );
    $form['options']['default']['image']['radius'] = array(
      '#type' => 'textfield',
      '#title' => 'Radius',
      '#default_value' => $this->getOption(array('default', 'image', 'radius'), '5'),
      '#description' => 'Radius of a regular polygon.',
    );
    $form['options']['default']['image']['radius1'] = array(
      '#type' => 'textfield',
      '#title' => 'Radius1',
      '#default_value' => $this->getOption(array('default', 'image', 'radius1'), NULL),
      '#description' => 'Inner radius of a star.',
    );
    $form['options']['default']['image']['radius2'] = array(
      '#type' => 'textfield',
      '#title' => 'Radius2',
      '#default_value' => $this->getOption(array('default', 'image', 'radius2'), NULL),
      '#description' => 'Outer radius of a star.',
    );
    $form['options']['default']['image']['angle'] = array(
      '#type' => 'textfield',
      '#title' => 'Angle',
      '#default_value' => $this->getOption(array('default', 'image', 'angle'), 0),
      '#description' => 'Shape\'s angle in degrees. A value of 0 will have one of the shape\'s point facing up. Default value is 0.',
    );
    $form['options']['default']['image']['rotation'] = array(
      '#type' => 'textfield',
      '#title' => 'Rotation',
      '#default_value' => $this->getOption(array('default', 'image', 'rotation'), NULL),
      '#required' => TRUE,
      '#description' => 'Rotation in degrees (positive rotation clockwise). Default is 0.',
    );
    $form['options']['default']['image']['fill'] = array(
      '#type' => 'fieldset',
      '#title' => t('Fill options'),
      '#collapsible' => FALSE,
    );
    $form['options']['default']['image']['fill']['color'] = array(
      '#type' => 'textfield',
      '#title' => 'Fill color',
      '#field_prefix' => 'rgba(',
      '#field_suffix' => ')',
      '#default_value' => $this->getOption(array('default', 'image', 'fill', 'color'), '255,255,255,0.4'),
      '#required' => TRUE,
    );
    $form['options']['default']['image']['stroke'] = array(
      '#type' => 'fieldset',
      '#title' => t('Stroke options'),
      '#collapsible' => FALSE,
    );
    $form['options']['default']['image']['stroke']['color'] = array(
      '#type' => 'textfield',
      '#title' => 'Stroke color',
      '#field_prefix' => 'rgba(',
      '#field_suffix' => ')',
      '#default_value' => $this->getOption(array('default', 'image', 'stroke', 'color'), '51,153,204,1'),
      '#required' => TRUE,
    );
    $form['options']['default']['image']['stroke']['width'] = array(
      '#type' => 'textfield',
      '#title' => 'Stroke width',
      '#default_value' => $this->getOption(array('default', 'image', 'stroke', 'width'), '1.25'),
      '#required' => TRUE,
    );
    $form['options']['default']['image']['stroke']['lineDash'] = array(
      '#type' => 'textfield',
      '#title' => 'Line dash',
      '#description' => 'Two integers separated by a comma. The comma is mandatory. Default to disable is <em>0,0</em>.',
      '#default_value' => $this->getOption(array('default', 'image', 'stroke', 'lineDash'), '0,0'),
      '#required' => TRUE,
    );
    $form['options']['default']['stroke'] = array(
      '#type' => 'fieldset',
      '#title' => 'Stroke',
    );
    $form['options']['default']['stroke']['color'] = array(
      '#type' => 'textfield',
      '#title' => 'Color',
      '#field_prefix' => 'rgba(',
      '#field_suffix' => ')',
      '#default_value' => $this->getOption(array('default', 'stroke', 'color'), '51,153,204,1'),
      '#required' => TRUE,
    );
    $form['options']['default']['stroke']['width'] = array(
      '#type' => 'textfield',
      '#title' => 'Width',
      '#default_value' => $this->getOption(array('default', 'stroke', 'width'), 1.25),
      '#required' => TRUE,
    );
    $form['options']['default']['stroke']['lineDash'] = array(
      '#type' => 'textfield',
      '#title' => 'Line dash',
      '#description' => 'Two integers separated by a comma. The comma is mandatory. Default to disable is <em>0,0</em>.',
      '#default_value' => $this->getOption(array('default', 'stroke', 'lineDash'), '0,0'),
      '#required' => TRUE,
    );
    $form['options']['default']['fill'] = array(
      '#type' => 'fieldset',
      '#title' => 'Fill',
    );
    $form['options']['default']['fill']['color'] = array(
      '#type' => 'textfield',
      '#title' => 'Color',
      '#field_prefix' => 'rgba(',
      '#field_suffix' => ')',
      '#default_value' => $this->getOption(array('default', 'fill', 'color'), '51,153,204,1'),
      '#required' => TRUE,
    );

    foreach (Openlayers::getGeometryTypes() as $geometry_type => $geometry) {
      $enabled = (bool) $this->getOption(array($geometry_type, 'enabled'), FALSE);
      $form['options'][$geometry_type] = array(
        '#type' => 'fieldset',
        '#title' => t('Geometry @geometry', array('@geometry' => $geometry)),
        '#collapsible' => TRUE,
        '#collapsed' => !$enabled,
      );
      $form['options'][$geometry_type]['enabled'] = array(
        '#type' => 'checkbox',
        '#title' => t('Enable this geometry type ?'),
        '#default_value' => $enabled,
      );
      $form['options'][$geometry_type]['image'] = array(
        '#type' => 'fieldset',
        '#title' => t('Image options'),
        '#collapsible' => FALSE,
      );
      $form['options'][$geometry_type]['image']['points'] = array(
        '#type' => 'textfield',
        '#title' => 'Radius2',
        '#default_value' => $this->getOption(array($geometry_type, 'image', 'points'), '4'),
        '#description' => 'Number of points for stars and regular polygons. In case of a polygon, the number of points is the number of sides.',
      );
      $form['options'][$geometry_type]['image']['radius'] = array(
        '#type' => 'textfield',
        '#title' => 'Radius',
        '#default_value' => $this->getOption(array($geometry_type, 'image', 'radius'), '5'),
        '#description' => 'Radius of a regular polygon.',
      );
      $form['options'][$geometry_type]['image']['radius1'] = array(
        '#type' => 'textfield',
        '#title' => 'Radius',
        '#default_value' => $this->getOption(array($geometry_type, 'image', 'radius1'), NULL),
        '#description' => 'Inner radius of a star.',
      );
      $form['options'][$geometry_type]['image']['radius2'] = array(
        '#type' => 'textfield',
        '#title' => 'Radius1',
        '#default_value' => $this->getOption(array($geometry_type, 'image', 'radius2'), NULL),
        '#description' => 'Outer radius of a star.',
      );
      $form['options'][$geometry_type]['image']['angle'] = array(
        '#type' => 'textfield',
        '#title' => 'Angle',
        '#default_value' => $this->getOption(array($geometry_type, 'image', 'angle'), 0),
        '#description' => 'Shape\'s angle in degrees. A value of 0 will have one of the shape\'s point facing up. Default value is 0.',
      );
      $form['options'][$geometry_type]['image']['rotation'] = array(
        '#type' => 'textfield',
        '#title' => 'Rotation',
        '#default_value' => $this->getOption(array($geometry_type, 'image', 'rotation'), NULL),
        '#description' => 'Rotation in degrees (positive rotation clockwise). Default is 0.',
      );
      $form['options'][$geometry_type]['image']['fill'] = array(
        '#type' => 'fieldset',
        '#title' => t('Fill options'),
        '#collapsible' => FALSE,
      );
      $form['options'][$geometry_type]['image']['fill']['color'] = array(
        '#type' => 'textfield',
        '#title' => 'Fill color',
        '#field_prefix' => 'rgba(',
        '#field_suffix' => ')',
        '#default_value' => $this->getOption(array($geometry_type, 'image', 'fill', 'color'), '255,255,255,0.4'),
        '#required' => TRUE,
      );
      $form['options'][$geometry_type]['image']['stroke'] = array(
        '#type' => 'fieldset',
        '#title' => t('Stroke options'),
        '#collapsible' => FALSE,
      );
      $form['options'][$geometry_type]['image']['stroke']['color'] = array(
        '#type' => 'textfield',
        '#title' => 'Stroke color',
        '#field_prefix' => 'rgba(',
        '#field_suffix' => ')',
        '#default_value' => $this->getOption(array($geometry_type, 'image', 'stroke', 'color'), '51,153,204,1'),
      );
      $form['options'][$geometry_type]['image']['stroke']['width'] = array(
        '#type' => 'textfield',
        '#title' => 'Stroke width',
        '#default_value' => $this->getOption(array($geometry_type, 'image', 'stroke', 'width'), '1.25'),
      );
      $form['options'][$geometry_type]['image']['stroke']['lineDash'] = array(
        '#type' => 'textfield',
        '#title' => 'Line dash',
        '#description' => 'Two integers separated by a comma. The comma is mandatory. Default to disable is <em>0,0</em>.',
        '#default_value' => $this->getOption(array($geometry_type, 'image', 'stroke', 'lineDash'), '0,0'),
      );
      $form['options'][$geometry_type]['stroke'] = array(
        '#type' => 'fieldset',
        '#title' => 'Stroke',
      );
      $form['options'][$geometry_type]['stroke']['color'] = array(
        '#type' => 'textfield',
        '#title' => 'Color',
        '#field_prefix' => 'rgba(',
        '#field_suffix' => ')',
        '#default_value' => $this->getOption(array($geometry_type, 'stroke', 'color'), '51,153,204,1'),
      );
      $form['options'][$geometry_type]['stroke']['width'] = array(
        '#type' => 'textfield',
        '#title' => 'Width',
        '#default_value' => $this->getOption(array($geometry_type, 'stroke', 'width'), 1.25),
      );
      $form['options'][$geometry_type]['stroke']['lineDash'] = array(
        '#type' => 'textfield',
        '#title' => 'Line dash',
        '#description' => 'Two integers separated by a comma. The comma is mandatory. Default to disable is <em>0,0</em>.',
        '#default_value' => $this->getOption(array($geometry_type, 'stroke', 'lineDash'), '0,0'),
      );
      $form['options'][$geometry_type]['fill'] = array(
        '#type' => 'fieldset',
        '#title' => 'Fill',
      );
      $form['options'][$geometry_type]['fill']['color'] = array(
        '#type' => 'textfield',
        '#title' => 'Color',
        '#field_prefix' => 'rgba(',
        '#field_suffix' => ')',
        '#default_value' => $this->getOption(array($geometry_type, 'fill', 'color'), '51,153,204,1'),
      );
    }
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit(array $form, array &$form_state) {
    parent::optionsFormSubmit($form, $form_state);

    $options = $this->getOptions();
    foreach (Openlayers::getGeometryTypes() as $geometry_type => $geometry) {
      if ((bool) $options[$geometry_type]['enabled'] === FALSE) {
        unset($options[$geometry_type]);
      }
    }

    $this->setOptions($options);
    $form_state['values']['options'] = $options;
    parent::optionsFormSubmit($form, $form_state);
  }


}
