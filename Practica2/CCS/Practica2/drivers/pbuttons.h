/*
 * pushbutton.h
 *
 *  Created on: Mar 27, 2013
 *      Author: lrvillan
 */

#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

#include <stdint.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "inc/hw_gpio.h"
#include "inc/lm4f120h5qr.h"

/* push button state */
#define PBTN_RELEASED			0x00
#define PBTN_PRESSED			0x01

#define PBUTTON_LEFT			0x01
#define PBUTTON_RIGHT			0x02


/* These are valid options for uint8_t pbtn */
#define PRESSED_START			0x01
#define PRESSED_LAP				0x02
#define PRESSED_STOP			0x03
#define PRESSED_RESET			0x04

#define NUM_BUTTONS             4

/* assignment */
#define PBUTTON_START			PBUTTON_LEFT
#define PBUTTON_LAP				PBUTTON_LEFT
#define PBUTTON_STOP			PBUTTON_RIGHT
#define PBUTTON_RESET			PBUTTON_RIGHT


/* Debounce counting*/
#define SHORT_PRESS				2
#define LONG_PRESS				30

void pbuttonsInit(void);
tBoolean btnPressed(uint8_t pbtn);

#endif /* PUSHBUTTON_H_ */
