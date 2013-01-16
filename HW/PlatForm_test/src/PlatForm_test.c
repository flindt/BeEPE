/*
 ============================================================================
 Name        : PlatForm_test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "seatest.h"


void test_i2c(void );

void all_tests( void )
{
        test_i2c();
        // add new test fixtures here.
}

void my_suite_setup( void )
{
        //printf("I'm done before every single test in the suite\r\n");
}

void my_suite_teardown( void )
{
        //printf("I'm done after every single test in the suite\r\n");
}



int main(void) {


	suite_setup(my_suite_setup);
        suite_teardown(my_suite_teardown);
        run_tests(all_tests);

	return EXIT_SUCCESS;
}
