/*
 * tmp100.c
 *
 *  Created on: Jan 17, 2013
 *      Author: flindt
 *
 *
 *      Device driver for the I2C temperature sensor TMP100 and TMP101
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "../inc/tmp100.h"


typedef struct
{
  I2C_HWBUS bus;
  int8_t address;

} deviceTMP100_struct;

deviceTMP100_struct deviceData[NO_SUPPORTED_TMP100_DEVICES + 1];
deviceTMP100_struct *deviceHandles[NO_SUPPORTED_TMP100_DEVICES] = { 0 };

void
initDeviceStructure(int8_t loopCounter,
    I2C_HWBUS hwBus, int8_t deviceAddress,
    deviceTMP100 device)
{
  deviceHandles[loopCounter] = &deviceData[loopCounter];
  device = (deviceTMP100) deviceHandles[0];
  deviceData[loopCounter].bus = hwBus;
  deviceData[loopCounter].address = deviceAddress;
}

deviceTMP100 tmp100_open(int8_t deviceNumber){
  if ( deviceNumber < NO_SUPPORTED_TMP100_DEVICES)
    {
      return (deviceTMP100) &deviceData[deviceNumber];
    }
  return 0;
}

TMP100_errors
tmp100_init(deviceTMP100 device, I2C_HWBUS hwBus, int8_t deviceAddress)
{
  // a zero pointer will initialize a new structure if there is more room
  // a handle may be initialized twice

  int8_t loopCounter = 0;
  for (loopCounter = 0; loopCounter < NO_SUPPORTED_TMP100_DEVICES;
      loopCounter++)
    {
      if (  (size_t)(deviceHandles[loopCounter]) ==  0)      // Free device handle
        {
          initDeviceStructure(loopCounter, hwBus, deviceAddress,
         device);
          return DEV_OK;
        }
       else if  (device == (deviceTMP100) deviceHandles[loopCounter] )
        {
          // TODO : run initialization again
           initDeviceStructure(loopCounter, hwBus, deviceAddress,
                    device);
          return DEV_OK; // This handle is in use
        }
    }

  // If the loop exits, there are no free handles
  return DEV_TOO_MANY_DEVICES;
}

int16_t tmp100_read_temp(deviceTMP100 device)
{
  deviceTMP100_struct *thisDevice;
  thisDevice = (deviceTMP100_struct*) device;
  int8_t dataBytes[2];
  int8_t error=0;

  error = I2C_read( thisDevice->bus, thisDevice->address, 0, 2, dataBytes);

  if (error==0)
    {
      // read ok - return data
      return dataBytes[0]<<8 | dataBytes[1];
    }

  return 0;
}
