<?php
/**
 * @file
 * Component: JS Component.
 */

namespace Drupal\openlayers\Plugins\Component\InlineJS;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Types\Component;

/**
 * Class InlineJS.
 *
 * @Plugin(
 *  id = "InlineJS"
 * )
 *
 */
class InlineJS extends Component {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $attached = array();
    // $form = array();

    if (module_exists('ace_editor')) {
      $attached = array(
        'library' => array(
          array('ace_editor', 'ace-editor'),
        ),
        'js' => array(
          drupal_get_path('module', 'openlayers') . '/js/openlayers.editor.js',
        ),
      );
    }
    else {
      \Drupal::service('messenger')->addMessage(t('To get syntax highlighting, you should install the module <a href="@url1">ace_editor</a> and its <a href="@url2">library</a>.', array('@url1' => 'http://drupal.org/project/ace_editor', '@url2' => 'http://ace.c9.io/')), 'warning');
    }

    $form['options']['javascript'] = array(
      '#type' => 'textarea',
      '#title' => t('Javascript'),
      '#description' => t('Javascript to evaluate. The available variable is: <em>data</em>.'),
      '#rows' => 15,
      '#default_value' => $this->getOption('javascript'),
      '#attributes' => array(
        'data-editor' => 'javascript',
      ),
      '#attached' => $attached,
    );
  }

}
