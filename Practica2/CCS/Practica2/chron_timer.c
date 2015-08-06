/*
 * chron_timer.c
 *
 *  Created on: May 19, 2013
 *      Author: lrvillan
 */

#include "chron_timer.h"

static uint8_t minutes;
static uint8_t seconds;
static uint8_t decimas; //FIXME: what's the name of decimas in english
static uint16_t laps[NUM_LAPS];
static uint8_t current_lap;
static uint8_t next_lap;

static tBoolean timer_running;

void _reset_laps(void);

void chronTimerReset() {
	minutes = 0;
	seconds = 0;
	decimas = 0;
	timer_running = false;
	_reset_laps();
}

void _reset_laps(void){
	int lap;

	for(lap = 0; lap < NUM_LAPS; lap++)
	{
		laps[lap] = 0;
	}
	current_lap = 0;
	next_lap = 0;
}

void chronTimerTick() {

	if (timer_running) {
		decimas += 1;

		if (decimas == 10) {
			decimas = 0;
			seconds += 1;
		}

		if (seconds == 60) {
			seconds = 0;
			minutes += 1;
		}

		if (minutes == 10) {
			// shall we stop
			minutes = 9;
			seconds = 59;
			decimas = 9;
			chronTimerStop();
		}
	}
}

uint16_t chronTimerGetTimeInBcd() {
	uint16_t bcdMinutes;
	uint16_t bcdSeconds;
	uint16_t bcdDecims;
	uint16_t bcdTime;

	bcdMinutes = minutes;
	bcdSeconds = ((seconds / 10) << 4) | (seconds % 10);
	bcdDecims = decimas;

	bcdTime = (bcdMinutes << 12) | (bcdSeconds << 4) | bcdDecims;
	return bcdTime;
}

void chronTimerSetTimeInBcd(uint16_t bcdTime){

}

void chronTimerPause() {

}

void chronTimerStart(void) {
	timer_running = true;
}

void chronTimerStop() {
	timer_running = false;
}

void chronTimerSetLap() {
	if (current_lap < NUM_LAPS){
		laps[current_lap] = chronTimerGetTimeInBcd();
		current_lap += 1;
	}
}

uint8_t chronTimerGetNumLaps() {
	return current_lap;
}

uint16_t chronTimerGetTimeLap(uint8_t lap_num) {
	return laps[lap_num - 1];
}

uint16_t chronTimerGetLastLap(){
	return laps[current_lap - 1];
}

uint16_t chronTimerGetNextLap(){
	uint16_t laptime;

	laptime = laps[next_lap];
	next_lap += 1;

	if (next_lap > (current_lap-1)){
		next_lap = 0;
	}

	return laptime;
}

tBoolean chronTimerIsRunning(void){
	return timer_running;
}
