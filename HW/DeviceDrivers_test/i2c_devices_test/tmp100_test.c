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

  deviceTMP100 *myTempDevice = 0;

  int8_t errorCode = tmp100_init(myTempDevice);

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
