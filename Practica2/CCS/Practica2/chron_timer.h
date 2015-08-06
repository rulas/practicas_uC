/*
 * chron_timer.h
 *
 *  Created on: May 19, 2013
 *      Author: lrvillan
 */

#ifndef CHRON_TIMER_H_
#define CHRON_TIMER_H_

#include <stdint.h>
#include "inc/hw_types.h"

#define NUM_LAPS	100

void chronTimerInit(void);
void chronTimerTick(void);
uint16_t chronTimerGetTimeInBcd(void);
void chronTimerSetTimeInBcd(uint16_t bcdTime);
void chronTimerPause(void);
void chronTimerStart(void);
void chronTimerStop(void);
void chronTimerReset(void);
void chronTimerSetLap(void);
uint8_t chronTimerGetNumLaps(void);
uint16_t chronTimerGetTimeLap(uint8_t lap_num);
uint16_t chronTimerGetLastLap(void);
uint16_t chronTimerGetNextLap(void);
tBoolean chronTimerIsRunning(void);


#endif /* CHRON_TIMER_H_ */
