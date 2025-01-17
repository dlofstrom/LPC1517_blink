/*
===============================================================================
 Name        : lpc1517_Blink.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here

    //Initialize GPIO
    Chip_GPIO_Init(LPC_GPIO);

	//Set GPIO as output
	Chip_GPIO_SetPinDIROutput(LPC_GPIO, 2, 13);

	//Set GPIO value low
	Chip_GPIO_WritePortBit(LPC_GPIO, 2, 13, false);

	//Delay variables
	uint32_t current_delay = 0;
	uint32_t delay_value = 3500000;


    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;

        //Set GPIO value high
		Chip_GPIO_WritePortBit(LPC_GPIO, 2, 13, true);

		//Delay 500ms
		for (current_delay = 0; current_delay < delay_value; current_delay++) {}

        //Set GPIO value low
		Chip_GPIO_WritePortBit(LPC_GPIO, 2, 13, false);

		//Delay 500ms
		for (current_delay = 0; current_delay < delay_value; current_delay++) {}

    }
    return 0 ;
}
