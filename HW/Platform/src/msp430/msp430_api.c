/*
 * simulated_api.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include <stdint.h>

#include "platform.h"

int8_t I2C_init()
{
  return I2C_ERROR;
}


int8_t I2C_send(int8_t slaveAddress, int8_t slaveRegister, int8_t noBytesToSend, int8_t *dataBytes)
{

  return sim_I2C_send(slaveAddress, slaveRegister, noBytesToSend, dataBytes);

}


int8_t I2C_read( int8_t slaveAddress, int8_t slaveRegister, int8_t noBytesToRead, int8_t *dataBytes)
{
  return sim_I2C_read();
}
