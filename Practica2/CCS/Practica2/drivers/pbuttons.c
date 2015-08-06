/*
 * pushbutton.c
 *
 *  Created on: Mar 27, 2013
 *      Author: lrvillan
 *	TODO: perhaps better to user base address, ie: GPIO_PORTF_BASE
 */

#include "gpio.h"
#include "pbuttons.h"

static uint16_t buttonPressedCounter[NUM_BUTTONS] = { 0 };
static tBoolean waitUntilButtonReleased[NUM_BUTTONS] = { 0 };

#define GPIO_CK_PBTN_L		SYSCTL_RCGC2_GPIOF
#define GPIO_CK_PBTN_R		SYSCTL_RCGC2_GPIOF

#define GPIO_PORT_DIR_L		GPIO_PORTF_DIR_R
#define GPIO_PORT_DIR_R		GPIO_PORTF_DIR_R

#define GPIO_PORT_DEN_L		GPIO_PORTF_DEN_R
#define GPIO_PORT_DEN_R		GPIO_PORTF_DEN_R

#define GPIO_PORT_DATA_L	GPIO_PORTF_DATA_R
#define GPIO_PORT_DATA_R	GPIO_PORTF_DATA_R

#define GPIO_PIN_PBTN_LEFT		GPIO_PIN_4
#define GPIO_PIN_PBTN_RIGHT		GPIO_PIN_0

//*****************************************************************************
//
// Holds the current, debounced state of each button.  A 0 in a bit indicates
// that that button is currently pressed, otherwise it is released.
// We assume that we start with all the buttons released (though if one is
// pressed when the application starts, this will be detected).
//
//*****************************************************************************

void pbuttonsInit(void) {

	//
	// Enable the GPIO port that is used for the on-board push buttons.
	//
	SYSCTL_RCGC2_R |= GPIO_CK_PBTN_L | GPIO_CK_PBTN_R;

	// Unlock PF0 so we can change it to a GPIO input
	// Once we have enabled (unlocked) the commit register then re-lock it
	// to prevent further changes.  PF0 is muxed with NMI thus a special case.
	// Note: this apply only if PF0 gpio is being used.

	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY_DD;
	GPIO_PORTF_CR_R |= GPIO_PIN_PBTN_RIGHT;
	GPIO_PORTF_LOCK_R = 0;

	// set the push buttons gpio ports as input
	// (by default they should be configured as inputs)
	GPIO_PORT_DIR_L &= ~GPIO_PIN_PBTN_LEFT;
	GPIO_PORT_DIR_R &= ~GPIO_PIN_PBTN_RIGHT;

	// Set port to 2mA
	GPIO_PORTF_DR2R_R |= GPIO_PIN_PBTN_LEFT;
	GPIO_PORTF_DR2R_R |= GPIO_PIN_PBTN_RIGHT;

	// set port to weak pull up
	GPIO_PORTF_PUR_R |= GPIO_PIN_PBTN_LEFT;
	GPIO_PORTF_PUR_R |= GPIO_PIN_PBTN_RIGHT;

	// enable digital for push button pins
	GPIO_PORT_DEN_L |= GPIO_PIN_PBTN_LEFT;
	GPIO_PORT_DEN_R |= GPIO_PIN_PBTN_RIGHT;
}

tBoolean _pbuttonPressed(uint8_t pbtn) {
	tBoolean btn_pressed = false;

	if (pbtn == PRESSED_START || pbtn == PRESSED_LAP){
		btn_pressed = !(GPIO_PORT_DATA_L & GPIO_PIN_PBTN_LEFT);
	} else if (pbtn == PRESSED_STOP || pbtn == PRESSED_RESET){
		btn_pressed = !(GPIO_PORT_DATA_R & GPIO_PIN_PBTN_RIGHT);
	}

	return btn_pressed;
}

tBoolean btnPressed(uint8_t btn) {

	tBoolean buttonPressed = false;

	// this function implements a counter in order to handle
	// push button debouncing.

	if (_pbuttonPressed(btn)) {

		buttonPressedCounter[btn] += 1;

	} else {

		buttonPressedCounter[btn] = 0;
		waitUntilButtonReleased[btn] = false;

	}

	if (!waitUntilButtonReleased[btn]){
		if (btn == PRESSED_START || btn == PRESSED_LAP || btn == PRESSED_STOP) {
			if (buttonPressedCounter[btn] > SHORT_PRESS) {

				buttonPressed = true;
				waitUntilButtonReleased[btn] = true;
			}
		}

		if (btn == PRESSED_RESET) {
			if (buttonPressedCounter[btn] > LONG_PRESS) {

				buttonPressed = true;
				waitUntilButtonReleased[btn] = true;
			}
		}
	}

	return buttonPressed;
}
