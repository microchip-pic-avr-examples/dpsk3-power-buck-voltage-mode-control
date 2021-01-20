/*
 * File:   lcd.c
 * Author: M91406
 *
 * Created on March 12, 2020, 12:10 PM
 */


#include "led/app_led.h"
#include "config/hal.h"

// PRIVATE VARIABLE DELARATIONS
volatile uint16_t tgl_cnt = 0;  // local counter of LED toggle loops
#define TGL_INTERVAL    4999    // LED toggle interval of (4999 + 1) x 100usec = 100ms

volatile DEBUGGING_LED_t debug_led;

/*********************************************************************************
 * @ingroup GROUP_NAME
 * @fn volatile uint16_t appLED_Initialize(void)
 * @brief  Initializes the LED driving GPIO
 * @param  void
 * @return unsigned int (0=failure, 1=success)
 * @details
 *  This routine configures the driving GPIO as output and sets the initial
 *  toggle interval
 **********************************************************************************/

volatile uint16_t appLED_Initialize(void) 
{
    volatile uint16_t retval = 1;
    
    if(debug_led.period == 0)
        debug_led.period = TGL_INTERVAL;
    
    DBGLED_Init();

    return(retval);
}

volatile uint16_t appLED_Execute(void) 
{
    volatile uint16_t retval = 1;

	// Toggle LED, refresh LCD and reset toggle counter
	if (tgl_cnt++ > debug_led.period) { // Count n loops until LED toggle interval is exceeded
		DBGLED_Toggle();
		tgl_cnt = 0;
	} 

    return(retval);
}

volatile uint16_t appLED_Dispose(void) 
{
    volatile uint16_t retval = 1;
    
    debug_led.period = 0;
    DBGLED_Dispose();

    return(retval);
}
