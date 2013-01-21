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

#include <stdint.h>
#include "../inc/tmp100.h"

typedef struct
{
  int8_t isInitialised;
} deviceTMP100_struct;

deviceTMP100_struct deviceData[NO_SUPPORTED_TMP100_DEVICES+1];
deviceTMP100_struct* deviceHandles[NO_SUPPORTED_TMP100_DEVICES] =
  { 0 };

TMP100_errors
tmp100_init(deviceTMP100* device)
{
  // a zero pointer will initialize a new structure if there is more room
  if (*device != 0)
    {
      if ( deviceHandles[0] != 0) {
          // Device already initialized
         // return DEV_TOO_MANY_DEVICES;
      }
    }
  else
    {
      deviceHandles[0] = &deviceData[0];
      deviceHandles[0]->isInitialised = 1; // just to have some data while testing

      *device = (deviceTMP100)deviceHandles[0];
    }

  return DEV_OK;
}
