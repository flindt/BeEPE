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

// Information used to simulate attached devices
#define numberOfBusses 1
enum AttatchedSlaves
{
  TEMP_A = 0x4F, TEMP_B = 0x4E
};
enum Registers
{
  TLOW = 0x02
};
int8_t Tlow[2] =
  { 0, 0 };

// Define the data needed for each bus
typedef struct
{
  int8_t isInitialised;
} HWBUS_struct;

HWBUS_struct bussesAttached[numberOfBusses];

// "initialize" the bus
int8_t
sim_I2C_bus_init(int8_t busNumber)
{
  bussesAttached[busNumber].isInitialised = 1;
  return 0;
}

HWBUS
sim_I2C_bus_open(int8_t busNumber)
{
  if (busNumber < numberOfBusses)
    {

      return (HWBUS) &bussesAttached[busNumber];

    }
  return 0;
}

int8_t
sim_I2C_send( HWBUS hwBus, int8_t slaveAddress, int8_t slaveRegister, int8_t noBytesToSend, int8_t *dataBytes)
{

  switch (slaveAddress)
    {
  case TEMP_A:
    switch (slaveRegister)
      {
    case TLOW:
      Tlow[0] = dataBytes[0];
      Tlow[1] = dataBytes[1];
      break;
      }
    return I2C_OK;
  case TEMP_B:
    return I2C_OK;
  default:
    // Slave address not recognized
    return I2C_ERROR;
    }
}

int8_t
sim_I2C_read( HWBUS hwBus, int8_t slaveAddress, int8_t slaveRegister, int8_t noBytesToRead,
    int8_t *dataBytes)
{
  switch (slaveAddress)
    {
  case TEMP_A:
    switch (slaveRegister)
      {
    case TLOW:
      dataBytes[0] = Tlow[0];
      dataBytes[1] = Tlow[1];
      break;
      }
    return I2C_OK;
  case TEMP_B:
    return I2C_OK;
  default:
    // Slave address not recognized
    return I2C_ERROR;
    }
}

