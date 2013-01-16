/*
 * i2c_test.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include "seatest.h"

#include <platform.h>

void
test_i2c_init()
{

}

void
test_i2c_send_command()
{
  int8_t address = 0;
  int8_t slaveRegister = 0;
  int8_t noBytesToSend = 0;
  int8_t dataBytes[1] = {0};

  assert_int_equal( 0, I2C_send( address, slaveRegister, noBytesToSend, dataBytes) );
}

void
test_i2c(void)
{
  test_fixture_start()
  ;               // starts a fixture
  run_test(test_i2c_init);
  run_test(test_i2c_send_command);
  test_fixture_end()
  ;                 // ends a fixture

}
