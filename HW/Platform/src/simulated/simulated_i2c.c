/*
 * simulated.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 *
 *
 *      This file holds the simulation for the I2C bus.
 *      It pretends to have theese slave devices :
 *              slave A :       Type:   TMP100
 *                              Address: 111 -> 1001 111
 *                              Temp:   27.3 degrees
 *              slave B :       Type:   TMP100
 *                              Address: 110 -> 1001 110
 *                              Temp:   18.9 degrees
 *
 *
 *               Responds to :  Read temperature
 *
 *
 *
 *
 */

#include "platform.h"

enum AttatchedSlaves { TEMP_A = 0x4F, TEMP_B = 0x4E };



int8_t   sim_I2C_send(int8_t slaveAddress, int8_t slaveRegister, int8_t noBytesToSend, int8_t *dataBytes)
{

  switch (slaveAddress)
  {
  case TEMP_A:
    return I2C_OK;
  case TEMP_B:
    return I2C_OK;
  default:
    // Slave address not recognized
    return I2C_ERROR;
  }
}


