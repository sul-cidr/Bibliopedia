<?php
/**
 * @file
 * Source: GeoJson.
 */

namespace Drupal\openlayers\Plugin\Source\GeoJSON;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Config;
use Drupal\openlayers\Types\Source;

/**
 * Class GeoJSON.
 *
 * @OpenlayersPlugin(
 *  id = "GeoJSON"
 * )
 */
class GeoJSON extends Source {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['url'] = array(
      '#title' => t('URL'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('url'),
    );
    $form['options']['useBBOX'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use Bounding Box Strategy'),
      '#description' => t('Bounding Box strategy will add a query string onto the GeoJSON URL, which means that only data in the viewport of the map will be loaded.  This can be helpful if you have lots of data coming from the feed.'),
      '#default_value' => $this->getOption('useBBOX'),
    );
    $form['options']['paramForwarding'] = array(
      '#type' => 'checkbox',
      '#title' => t('Forward parameters on bbox load'),
      '#description' => t('If enabled all GET request parameters will be forwarded when loading the bbox content.'),
      '#default_value' => $this->getOption('paramForwarding', TRUE),
      '#states' => array(
        'invisible' => array(
          ':input[name="options[useBBOX]"]' => array('checked' => FALSE),
        ),
      ),
    );
    $form['options']['reloadOnZoomChange'] = array(
      '#type' => 'checkbox',
      '#title' => t('Reload features on zoom change.'),
      '#description' => t('Reload the features if the zoom level of the map changes. Handy if you use a zoom aware backend clustering.'),
      '#default_value' => $this->getOption('reloadOnZoomChange'),
    );
    $form['options']['reloadOnExtentChange'] = array(
      '#type' => 'checkbox',
      '#title' => t('Reload features on extent change'),
      '#description' => t('Reload the features if the visible part of the map changes (e.g. by dragging the map).'),
      '#default_value' => $this->getOption('reloadOnExtentChange'),
    );

    $form['options']['geojson_data'] = array(
      '#type' => 'textarea',
      '#title' => t('GeoJSON Data'),
      '#description' => t('Paste raw GeoJSON data here. It is better to use a URL.  This is provided for very simple use cases like one or two features.  If there is data here, it will override the URL above.'),
      '#default_value' => $this->getOption('geojson_data'),
      '#states' => array(
        'invisible' => array(
          ':input[name="options[useBBOX]"]' => array('checked' => TRUE),
        ),
      ),
    );

    $form['options']['devMode'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable developer mode.'),
      '#description' => t('If enabled you can edit the request to send using a dialog.'),
      '#default_value' => $this->getOption('devMode'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function getJS() {
    $js = parent::getJS();
    // Ensure we've a sane url.
    if (!empty($js['opt']['url'])) {
      $js['opt']['url'] = url($js['opt']['url']);
    }
    else {
      // Remove the option as it is even used if empty.
      unset($js['opt']['url']);
    }

    // @TODO Find a way how to do this just once per map / collection.
    if ($this->getOption('devMode')) {
      include 'forms.inc';
      $form_state = array();
      $form_state['build_info']['args'] = array($this);
      $form = drupal_build_form('openlayers_dev_dialog_form', $form_state);
      unset($form['options']['devMode']);
      $js['opt']['devDialog'] = filter_xss(
        drupal_render($form),
        array(
          'label',
          'form',
          'input',
          'select',
          'textarea',
          'div',
          'ul',
          'ol',
          'li',
          'dl',
          'dt',
          'dd',
        )
      );
    }

    return $js;
  }

  /**
   * {@inheritdoc}
   */
  public function attached() {
    $attached = parent::attached();
    $plugin = $this->getPluginDefinition();
    $plugin['path'] = $this->getClassDirectory();
    if ($this->getOption('devMode')) {
      // @TODO Find a way how to do this just once per map / collection.
      $attached['library']['system.ui.dialog'] = array('system', 'ui.dialog');
      $attached['library']['system.jquery.cookie'] = array('system', 'jquery.cookie');
      $attached['js'][$plugin['path'] . '/js/geojson_dev.js']['weight'] = Config::get('openlayers.js_css.weight') + 1;
    }
    else {
      unset($attached['js'][$plugin['path'] . '/js/geojson_dev.js']);
      unset($attached['css'][$plugin['path'] . '/css/geojson_dev.css']);
    }
    return $attached;
  }
}
