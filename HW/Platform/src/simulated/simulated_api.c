/*
 * simulated_api.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include <stdint.h>

#include "platform.h"
#include "simulated.h"

int8_t I2C_init()
{
  return ERROR;
}


int8_t I2C_send(int8_t slaveAddress, int8_t slaveRegister, int8_t noBytesToSend, int8_t *dataBytes)
{

  return sim_I2C_send(slaveAddress, slaveRegister, noBytesToSend, dataBytes);

}
