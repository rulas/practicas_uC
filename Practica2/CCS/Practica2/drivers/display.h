/*
 * display.h
 *
 *  Created on: May 18, 2013
 *      Author: lrvillan
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_


#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "inc/hw_gpio.h"
#include "inc/lm4f120h5qr.h"
#include "inc/hw_timer.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/pin_map.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include <stdint.h>

#define TEMP_WRITE_TICKS	571
#define DISPLAY_PIN_ALL 			0x7F

void displayInit(void);
tBoolean displayWrite(uint16_t buffer);
tBoolean displayTempWrite(uint16_t buffer);
void displayClear(void);
void displayTick(void);


#endif /* DISPLAY_H_ */
