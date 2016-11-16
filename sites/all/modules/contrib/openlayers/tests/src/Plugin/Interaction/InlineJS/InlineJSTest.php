<?php

/**
 * @file
 * Contains \Drupal\Tests\openlayers\Openlayers\Interaction\InlineJS\InlineJSTest;
 */

namespace Drupal\Tests\openlayers\Plugin\Interaction\InlineJS;

use Drupal\openlayers\Plugin\Interaction\InlineJS\InlineJS;

/**
 * @coversDefaultClass \Drupal\openlayers\Plugin\Interaction\InlineJS\InlineJS
 * @group openlayers
 */
class InlineJSTest extends \PHPUnit_Framework_TestCase {

  public function setUp() {
    $this->moduleHandler = \Mockery::mock('\Drupal\Core\Extension\ModuleHandlerInterface');
    $this->messenger = \Mockery::mock('\Drupal\service_container\Messenger\MessengerInterface');
    $this->drupal7 = \Mockery::mock('\Drupal\service_container\Legacy\Drupal7');
    $configuration = array(
       'plugin module' => 'openlayers',
       'plugin type' => 'Interaction',
       'name' => 'openlayers.interaction', // @todo check the name.
    );

    $this->inlineJS = new InlineJS($configuration, 'InkineJS', array(), $this->moduleHandler, $this->messenger, $this->drupal7);
  }

  /**
   * @covers ::__construct
   */
  public function test_construct() {
    $this->assertInstanceOf('\Drupal\openlayers\Plugin\Interaction\InlineJS\InlineJS', $this->inlineJS);
  }
}
