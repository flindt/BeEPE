/*
 * tmp100.h
 *
 *  Created on: Jan 17, 2013
 *      Author: flindt
 */



#ifndef TMP100_H_
#define TMP100_H_

#include <stdint.h>
#include "inc/platform.h"

struct deviceTMP100_struct;
typedef struct deviceTMP100_struct *deviceTMP100;

// How many similar devices to support at once
#define NO_SUPPORTED_TMP100_DEVICES 1

enum tmp100_error_enum { DEV_OK, DEV_TOO_MANY_DEVICES };
typedef enum tmp100_error_enum TMP100_errors;

deviceTMP100 tmp100_open(int8_t deviceAddress);
TMP100_errors tmp100_init(deviceTMP100 device, HWBUS hwBus, int8_t deviceAddress);

int16_t tmp100_read_temp(deviceTMP100 device);

#endif /* TMP100_H_ */
