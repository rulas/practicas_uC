//*****************************************************************************
//
// hello.c - Simple hello world example.
//
// Copyright (c) 2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
// This is part of revision 9453 of the EK-LM4F120XL Firmware Package.
//
//*****************************************************************************

//#include "inc/lm4f120h5qr.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "drivers/led.h"
#include "drivers/pbuttons.h"
#include "drivers/display.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"
#include "chron_timer.h"


//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, unsigned long ulLine)
{
}
#endif

/* Default timer counters definition */
#define DELAY					666
#define COUNTER_BASE_TIME 		200
#define COUNTER_DISPLAY			7
#define COUNTER_LED_WORKING		332
#define COUNTER_LED_COUNTING	500
#define COUNTER_PBUTTON			100

void main(void) {
	int delay;
	int counter_base_time;
	int counter_display;
	int counter_led_working;
	int counter_led_counting;
	int counter_pbutton;
	tBoolean timer_is_running;


	// Initialize LED, push button and driplay drivers
	ledInit();
	pbuttonsInit();
	displayInit();

	// reset chronometer timer
	chronTimerReset();

	// initialize the big main loop counters
	counter_base_time = COUNTER_BASE_TIME;
	counter_display = COUNTER_DISPLAY;
	counter_led_working = COUNTER_LED_WORKING;
	counter_led_counting = COUNTER_LED_COUNTING;
	counter_pbutton = COUNTER_PBUTTON;


	timer_is_running = false;

	// loop forever
	while (1) {
		// Self explaining
		counter_base_time--;
		counter_display--;
		counter_led_working--;
		counter_led_counting--;
		counter_pbutton--;

		timer_is_running = chronTimerIsRunning();

		// DISPLAY TASK
		if (!counter_display) {
			counter_display = COUNTER_DISPLAY;

			// if timer is running, then updates the time in the display and then refresh the display
			if (timer_is_running){
				displayWrite(chronTimerGetTimeInBcd());
			}
			displayTick();
		}

		// BUTTON TASKS
		// Stellaris launchpad has only 2 buttons.
		// However, with these 2 buttons, we can generate events based on what state we are.
		if (!counter_pbutton) {
			counter_pbutton = COUNTER_PBUTTON;

			// start the chronometer if timer is already not running
			if (!timer_is_running && btnPressed(PRESSED_START)) {
				chronTimerStart();
			}

			// if timer is running, then if we press the start button
			// we will create a new lap in memory.
			if (timer_is_running && btnPressed(PRESSED_LAP)) {
				chronTimerSetLap();
				if (chronTimerGetNumLaps() >= 1) {
					displayTempWrite(chronTimerGetLastLap());
				}
			}

			// Stop if timer is running
			if (btnPressed(PRESSED_STOP)) {
				if (timer_is_running){
					chronTimerStop();
					chronTimerSetLap();
				} else{
					// timer is stop, so we should be able to read all laps in memory
					// by pressing stop button at will
					displayWrite(chronTimerGetNextLap());
				}
			}

			// if button is pressed for 3 seconds, then reset the timer so that
			// chronometer can start again
			if (btnPressed(PRESSED_RESET)) {
				chronTimerReset();

			}
		}

		// BLINKING LED WORKING TASK
		if (!counter_led_working) {
			counter_led_working = COUNTER_LED_WORKING;
			ledToggle(LED_SYS_WORKING);
		}

		// BLINKING LED COUNTING TASK
		if (!counter_led_counting) {
			counter_led_counting = COUNTER_LED_COUNTING;
			if(timer_is_running){
				ledToggle(LED_SYS_COUNTING);
			} else {
				ledTurnOff(LED_SYS_COUNTING);
			}
		}

		// CHRONOMETER TASK
		if (!counter_base_time) {
			counter_base_time = COUNTER_BASE_TIME;
			chronTimerTick();
		}



		// This is our time base
		// generates a delay equivalent to TODO: investigate delay in mseconds
		for (delay = 0; delay < DELAY; delay++) {
		}

	}

}
