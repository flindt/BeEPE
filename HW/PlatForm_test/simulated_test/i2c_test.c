/*
 * i2c_test.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include "seatest.h"

#include "platform.h"

int8_t address_ok_a = 0x4F;        // Address of temp sensor at "111"
int8_t address_ok_b = 0x4E;        // Address of temp sensor at "110"
int8_t address_not_ok = 0x33;    // Address of no slave
int8_t slaveRegister = 0x02;  // Tlow register - this is read / write
int8_t noBytesToSend = 1;
int8_t dataBytes[1] =
  { 11 };

void
test_i2c_open_bus()
{
  // Req: Support more than 1 bus
  //            The simulated platform only has 1 i2c bus

  HWBUS myBus = 0;

  myBus = I2C_bus_open(0);   // Open the first attached bus
  assert_false( myBus == 0);

  myBus = I2C_bus_open(1);   // Open another bus
  assert_true( myBus == 0);
  // Error - there is not other bus
}

void
test_i2c_send_command()
{
  HWBUS myBus = 0;
  myBus = I2C_bus_open(0);   // Open the first attached bus
  assert_false( myBus == 0);

  // Send to non-attached slave address
  // TODO: return values shold be taken from "platform.h"
  assert_int_equal( 1,
      I2C_send( myBus, address_not_ok, slaveRegister, noBytesToSend, dataBytes));

  // send to two attached slaves (at least in simulator)
  assert_int_equal( 0,
      I2C_send( myBus, address_ok_a, slaveRegister, noBytesToSend, dataBytes));
  assert_int_equal( 0,
      I2C_send( myBus, address_ok_b, slaveRegister, noBytesToSend, dataBytes));
}

void
test_i2c_write_read()
{
  HWBUS myBus = 0;
  myBus = I2C_bus_open(0);   // Open the first attached bus
  assert_false( myBus == 0);

  int8_t tlowBytes[2] =
    { 22, 33 };
  int8_t response[4] =
    { 1, 1, 1, 1 };
  int8_t noBytesTlow = 2;
  // write to slave register - then read to confirm
  assert_int_equal( 0,
      I2C_send( myBus, address_ok_a, slaveRegister, noBytesTlow, tlowBytes));
  assert_int_equal( 0,
      I2C_read( myBus, address_ok_a, slaveRegister, noBytesTlow, &response[1]));

  // check buffer
  assert_int_equal( 1, response[0]);
  assert_int_equal( tlowBytes[0], response[1]);
  assert_int_equal( tlowBytes[1], response[2]);
  assert_int_equal( 1, response[3]);

  tlowBytes[0] = 66;
  tlowBytes[0] = 77;

  // write to slave register - then read to confirm
  assert_int_equal( 0,
      I2C_send( myBus, address_ok_a, slaveRegister, noBytesTlow, tlowBytes));
  assert_int_equal( 0,
      I2C_read( myBus, address_ok_a, slaveRegister, noBytesTlow, &response[1]));

  // check buffer
  assert_int_equal( 1, response[0]);
  assert_int_equal( tlowBytes[0], response[1]);
  assert_int_equal( tlowBytes[1], response[2]);
  assert_int_equal( 1, response[3]);

}


void
test_i2c(void)
{
  test_fixture_start()
  ;               // starts a fixture

  run_test(test_i2c_open_bus);
  run_test(test_i2c_send_command);
  run_test(test_i2c_write_read);

  test_fixture_end()
  ;                 // ends a fixture

}
