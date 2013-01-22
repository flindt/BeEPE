/*
 * simulated_api.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include <stdint.h>

#include "platform.h"
//#include "simulated.h"

I2C_HWBUS
I2C_bus_open(int8_t busNumber)
{
  return sim_I2C_bus_open(busNumber);
}

//int8_t I2C_init()
//{
//  return I2C_ERROR;
//}

int8_t
I2C_send(I2C_HWBUS hwBus, int8_t slaveAddress, int8_t slaveRegister,
    int8_t noBytesToSend, int8_t *dataBytes)
{

  return sim_I2C_send(hwBus, slaveAddress, slaveRegister, noBytesToSend,
      dataBytes);

}

int8_t
I2C_read(I2C_HWBUS hwBus, int8_t slaveAddress, int8_t slaveRegister,
    int8_t noBytesToRead, int8_t *dataBytes)
{
  return sim_I2C_read(hwBus, slaveAddress, slaveRegister, noBytesToRead,
      dataBytes);

}
