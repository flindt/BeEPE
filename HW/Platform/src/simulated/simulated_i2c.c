/*
 * simulated.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 *
 *
 *      This file holds the simulation for the I2C bus.
 *      It pretends to have two slave devices :
 *              slave A :       Type:   T100
 *                              Address: 111 ->
 *                              Temp:   27.3 degrees
 *              slave B :       Type:   T100
 *                              Address: 110 ->
 *                              Temp:   18.9 degrees
 *
 *
 */

#include "platform.h"

int8_t   sim_I2C_send(int8_t slaveAddress, int8_t slaveRegister, int8_t noBytesToSend, int8_t *dataBytes)
{
  return OK;
}


