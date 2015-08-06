/*
 * led.h
 *
 *  Created on: Mar 26, 2013
 *      Author: lrvillan
 */

#ifndef LED_H_
#define LED_H_

#include "inc/lm4f120h5qr.h"
#include "inc/hw_gpio.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"

#include <stdint.h>

/* These are valid options for uint8_t led */
#define LED_SYS_COUNTING		0x01
#define LED_SYS_WORKING			0x02
#define LED_SYS_ALL				(LED_SYS_COUNTING|LED_SYS_WORKING)

void ledInit(void);
void ledTurnOn(uint8_t led);
void ledTurnOff(uint8_t led);
void ledToggle(uint8_t led);

#endif /* LED_H_ */
