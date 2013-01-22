/*
 * i2c_test.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include "seatest.h"

#include "tmp100.h"
#include <platform.h>

deviceTMP100 myTempDevice = 0;

void
test_tmp100_inittemp()
{
  deviceTMP100 myTempDevice2 = 0;
  deviceTMP100 myTempDevice3 = 0;

  I2C_HWBUS myBus = 0;

  myBus = I2C_bus_open(0);   // Open the first attached bus
  assert_false( myBus == 0);

  myTempDevice = tmp100_open(0);
  assert_false( myTempDevice==0);

  int8_t errorCode = tmp100_init(myTempDevice, myBus, 0x4F);

  // no errors should happen for first device
  assert_int_equal( 0, errorCode);

  // pointer should change
  assert_false( myTempDevice == 0);

  // device can be initialized again, with no error
  errorCode = tmp100_init(myTempDevice, myBus, 0x4F);
  assert_int_equal( 0, errorCode);

  // next device gives an error since only 1 is supported

  // Try to use device number two
  errorCode = tmp100_init(myTempDevice2, myBus, 0x4F);
  assert_int_equal( DEV_TOO_MANY_DEVICES, errorCode);
  assert_true( myTempDevice2 == 0);

  // Try to use device number two
  errorCode = tmp100_init(myTempDevice3, myBus, 0x4F);
  assert_int_equal( DEV_TOO_MANY_DEVICES, errorCode);
  assert_true( myTempDevice2 == 0);
}

void
test_tmp100_read_temp()
{
  uint16_t temperature = 0;

  I2C_HWBUS myBus = 0;

  myBus = I2C_bus_open(0);   // Open the first attached bus
  assert_false( myBus == 0);

  myTempDevice = tmp100_open(0);
  assert_false( myTempDevice==0);

  int8_t errorCode = tmp100_init(myTempDevice, myBus, 0x4F);

  // no errors should happen for first device
  assert_int_equal( 0, errorCode);

  temperature = tmp100_read_temp(myTempDevice);

  assert_int_equal( 0xff00, temperature);
}

void
test_tmp100(void)
{
  test_fixture_start()
  ;               // starts a fixture

  run_test(test_tmp100_inittemp);
  run_test(test_tmp100_read_temp);

  test_fixture_end()
  ;                 // ends a fixture

}
