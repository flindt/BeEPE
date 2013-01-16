/*
 * i2c_test.c
 *
 *  Created on: Jan 15, 2013
 *      Author: flindt
 */

#include "seatest.h"

#include <platform.h>

void test_i2c_init()
{

}

void test_i2c_send_command()
{
    assert_int_equal( 0, I2C_send() ) ;
}

void test_i2c( void )
{
        test_fixture_start();               // starts a fixture
        run_test(test_i2c_init);
        run_test(test_i2c_send_command);
        test_fixture_end();                 // ends a fixture
}
