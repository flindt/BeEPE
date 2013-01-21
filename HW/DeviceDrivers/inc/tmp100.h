/*
 * tmp100.h
 *
 *  Created on: Jan 17, 2013
 *      Author: flindt
 */



#ifndef TMP100_H_
#define TMP100_H_

#include <stdint.h>

struct deviceTMP100_struct;
typedef struct deviceTMP100_struct *deviceTMP100;

#define NO_SUPPORTED_TMP100_DEVICES 1
typedef enum { DEV_OK, DEV_TOO_MANY_DEVICES } TMP100_errors;

TMP100_errors tmp100_init(deviceTMP100* device);


#endif /* TMP100_H_ */
