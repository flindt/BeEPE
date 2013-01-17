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

deviceTMP100*
tmp100_init()
{
  return 0;
}
