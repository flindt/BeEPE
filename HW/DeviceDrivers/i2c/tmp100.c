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
  int8_t isInitialised;
} deviceTMP100_struct;

deviceTMP100_struct deviceData[NO_SUPPORTED_TMP100_DEVICES + 1];
deviceTMP100_struct *deviceHandles[NO_SUPPORTED_TMP100_DEVICES] = { 0 };

TMP100_errors
tmp100_init(deviceTMP100* device)
{
  // a zero pointer will initialize a new structure if there is more room
  // a handle may be initialized twice

  int8_t loopCounter = 0;
  for (loopCounter = 0; loopCounter < NO_SUPPORTED_TMP100_DEVICES;
      loopCounter++)
    {
      if (  (size_t)(deviceHandles[loopCounter]) ==  0)      // Free device handle
        {
          deviceHandles[0] = &deviceData[0];
          *device = (deviceTMP100) deviceHandles[0];

          return DEV_OK;
        }
       else if  (*device == (deviceTMP100) deviceHandles[loopCounter] )
        {
          // TODO : run initialization again
          return DEV_OK; // This handle is in use
        }
    }

  // If the loop exits, there are no free handles
  return DEV_TOO_MANY_DEVICES;
}
