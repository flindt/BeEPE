/*
 * i2c_test.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include "seatest.h"

#include "inc/tmp100.h"

void
test_tmp100_inittemp()
{

  deviceTMP100 myTempDevice = 0;

  int8_t errorCode = tmp100_init(&myTempDevice);

  // no errors should happen for first device
  assert_int_equal( 0, errorCode);

  // pointer should change
  assert_false( myTempDevice == 0);

  // device can be initialized again, with no error
  errorCode = tmp100_init(&myTempDevice);
  assert_int_equal( 0, errorCode);
}



void
test_tmp100(void)
{
  test_fixture_start()
  ;               // starts a fixture
  run_test(test_tmp100_inittemp);

  test_fixture_end()
  ;                 // ends a fixture

}
