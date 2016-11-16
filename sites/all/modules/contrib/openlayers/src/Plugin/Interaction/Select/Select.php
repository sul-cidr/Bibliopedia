<?php
/**
 * @file
 * Interaction: Select.
 */

namespace Drupal\openlayers\Plugin\Interaction\Select;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Interaction;

/**
 * Class Select.
 *
 * @OpenlayersPlugin(
 *  id = "Select",
 *  description = "Handles selection of vector data."
 * )
 */
class Select extends Interaction {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(array &$form, array &$form_state) {
    $form['options']['multi'] = array(
      '#type' => 'checkbox',
      '#title' => t('Multi select ?'),
      '#default_value' => $this->getOption('multi', TRUE),
      '#description' => t('A boolean that determines if the default behaviour should select only single features or all (overlapping) features at the clicked map position. Default is false i.e single select.'),
    );
    $form['options']['condition'] = array(
      '#type' => 'select',
      '#title' => t('Condition'),
      '#empty_option' => t('- Select a condition -'),
      '#default_value' => $this->getOption('condition', ''),
      '#description' => t('Select the condition.'),
      '#options' => array(
        'singleClick' => t('Single click'),
        'shiftKeyOnly' => t('Shift key only'),
        'pointerMove' => t('Pointer move'),
      ),
    );
    $form['options']['addCondition'] = array(
      '#type' => 'select',
      '#title' => t('Add condition'),
      '#empty_option' => t('- Select an add condition -'),
      '#default_value' => $this->getOption('addCondition', 'never'),
      '#description' => t('Select the add condition.'),
      '#options' => array(
        'never' => t('Never'),
        'singleClick' => t('Single click'),
        'shiftKeyOnly' => t('Shift key only'),
        'pointerMove' => t('Pointer move'),
      ),
    );
    $form['options']['toggleCondition'] = array(
      '#type' => 'select',
      '#title' => t('Toggle condition'),
      '#empty_option' => t('- Select a toggle condition -'),
      '#default_value' => $this->getOption('toggleCondition', 'shiftKeyOnly'),
      '#description' => t('Select the toggle condition.'),
      '#options' => array(
        'never' => t('Never'),
        'singleClick' => t('Single click'),
        'shiftKeyOnly' => t('Shift key only'),
        'pointerMove' => t('Pointer move'),
      ),
    );
    $form['options']['style'] = array(
      '#type' => 'select',
      '#title' => t('Style'),
      '#empty_option' => t('- Select a Style -'),
      '#default_value' => $this->getOption('style', ''),
      '#description' => t('Select the source.'),
      '#options' => Openlayers::loadAllAsOptions('Style'),
      '#required' => TRUE,
    );
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    if ($style = $this->getOption('style')) {
      $style = Openlayers::load('style', $style);

      // This style is a dependency of the current one,
      // we need a lighter weight.
      $this->setWeight($style->getWeight() + 1);
      $import = array_merge($style->getCollection()->getFlatList(), $import);
    }

    return $import;
  }

}
