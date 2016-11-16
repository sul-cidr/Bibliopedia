<?php
/**
 * @file
 * Contains class Error.
 */

namespace Drupal\openlayers\Types;

use Drupal\Core\Logger\LoggerChannelInterface;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\Object;
use Drupal\service_container\Messenger\MessengerInterface;

/**
 * Class Error.
 *
 * @OpenlayersPlugin(
 *   id = "Error",
 *   arguments = {
 *     "@logger.channel.default",
 *     "@messenger"
 *   }
 * )
 *
 * Dummy class to avoid breaking the whole processing if a plugin class is
 * missing.
 */
class Error extends Object implements ControlInterface, ComponentInterface, LayerInterface, SourceInterface, StyleInterface {

  /**
   * @var string
   */
  public $errorMessage;

  /**
   * The loggerChannel service.
   *
   * @var \Drupal\Core\Logger\LoggerChannelInterface
   */
  protected $loggerChannel;

  /**
   * The messenger service.
   *
   * @var \Drupal\service_container\Messenger\MessengerInterface
   */
  protected $messenger;

  /**
   * {@inheritdoc}
   */
  public function __construct($configuration, $plugin_id, $plugin_definition, LoggerChannelInterface $logger_channel, MessengerInterface $messenger) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->loggerChannel = $logger_channel;
    $this->messenger = $messenger;

    $this->errorMessage = 'Error while loading @type @machine_name having service @service.';

    if (!empty($configuration['errorMessage'])) {
      $this->errorMessage = $configuration['errorMessage'];
    }
  }

  /**
   * {@inheritdoc}
   */
  public function init() {
    $this->loggerChannel->error($this->getMessage(), array('channel' => 'openlayers'));
    $this->messenger->addMessage($this->getMessage(), 'error', FALSE);
    return parent::init();
  }

  /**
   * {@inheritdoc}
   */
  public function getMessage() {
    $machine_name = isset($this->machine_name) ? $this->machine_name : 'undefined';
    $service = isset($this->factory_service) ? $this->factory_service : 'undefined';
    $type = isset($this->configuration['type']) ? $this->configuration['type'] : 'undefined';

    return t($this->errorMessage, array(
      '@machine_name' => $machine_name,
      '@service' => $service,
      '@type' => $type,
    ));
  }

  /**
   * {@inheritdoc}
   */
  public function getType() {
    return 'Error';
  }

  /**
   * {@inheritdoc}
   */
  public function getStyle() {

  }

  /**
   * {@inheritdoc}
   */
  public function getSource() {

  }

  /**
   * {@inheritdoc}
   */
  public function setStyle(StyleInterface $style) {

  }

  /**
   * {@inheritdoc}
   */
  public function setSource(SourceInterface $source) {

  }

  /**
   * {@inheritdoc}
   */
  public function setVisible($visibility) {

  }

  /**
   * {@inheritdoc}
   */
  public function setOpacity($opacity) {

  }

  /**
   * {@inheritdoc}
   */
  public function setZIndex($zindex) {

  }

  /**
   * {@inheritdoc}
   */
  public function getVisible() {

  }

  /**
   * {@inheritdoc}
   */
  public function getOpacity() {

  }

  /**
   * {@inheritdoc}
   */
  public function getZIndex() {

  }


}
