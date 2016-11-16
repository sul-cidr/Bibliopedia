<?php
/**
 * @file
 * Class Layer.
 */

namespace Drupal\openlayers\Types;

use Drupal\openlayers\Openlayers;

/**
 * Class Layer.
 */
abstract class Layer extends Object implements LayerInterface {
  /**
   * The array containing the options.
   *
   * @var array
   */
  protected $options = array();

  /**
   * {@inheritdoc}
   */
  public function getSource() {
    $source = $this->getObjects('source');
    if ($source = array_shift($source)) {
      return ($source instanceof SourceInterface) ? $source : FALSE;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function getStyle() {
    $style = $this->getObjects('style');
    if ($style = array_shift($style)) {
      return ($style instanceof StyleInterface) ? $style : FALSE;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function setSource(SourceInterface $source) {
    $this->setOption('source', $source->getMachineName());
    return $this->addObject($source);
  }

  /**
   * {@inheritdoc}
   */
  public function setStyle(StyleInterface $style) {
    /** @var Style $style */
    $this->setOption('style', $style->getMachineName());
    return $this->addObject($style);
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    foreach (array('style', 'source') as $option) {
      if ($option_value = $this->getOption($option, FALSE)) {
        if ($object = $this->getCollection()
          ->getObjectById($option, $option_value)
        ) {
          $import = array_merge($import, $object->getCollection()
            ->getFlatList());
        }
        else {
          $import = array_merge($import, Openlayers::load($option, $option_value)
            ->getCollection()
            ->getFlatList());
        }
      }
    }

    return $import;
  }

  /**
   * {@inheritdoc}
   */
  public function setOpacity($opacity) {
    return $this->setOption('opacity', floatval($opacity));
  }

  /**
   * {@inheritdoc}
   */
  public function getOpacity() {
    return $this->getOption('opacity');
  }

  /**
   * {@inheritdoc}
   */
  public function setZIndex($zindex) {
    return $this->setOption('zIndex', intval($zindex));
  }

  /**
   * {@inheritdoc}
   */
  public function getZIndex() {
    return $this->getOption('zIndex');
  }

  /**
   * {@inheritdoc}
   */
  public function setVisible($visibility) {
    return $this->setOption('visible', (bool) $visibility);
  }

  /**
   * {@inheritdoc}
   */
  public function getVisible() {
    return (bool) $this->getOption('visible');
  }
}
