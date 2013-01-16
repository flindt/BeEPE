/*
 * i2c_test.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include "seatest.h"

#include "platform.h"

void
test_i2c_init()
{

}

void
test_i2c_send_command()
{
  int8_t address_ok_a = 0x4F;        // Address of temp sensor at "111"
  int8_t address_ok_b = 0x4E;        // Address of temp sensor at "110"
  int8_t address_not_ok = 0x33;    // Address of no slave
  int8_t slaveRegister = 0x02;  // Tlow register - this is read / write
  int8_t noBytesToSend = 1;
  int8_t dataBytes[1] =
    { 11 };

  // Send to non-attached slave address
  // TODO: return values shold be taken from "platform.h"
  assert_int_equal( 1,
      I2C_send( address_not_ok, slaveRegister, noBytesToSend, dataBytes));
  assert_int_equal( 0,
      I2C_send( address_ok_a, slaveRegister, noBytesToSend, dataBytes));
  assert_int_equal( 0,
      I2C_send( address_ok_b, slaveRegister, noBytesToSend, dataBytes));
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
