/*
 * display.c
 *
 *  Created on: May 18, 2013
 *      Author: lrvillan
 */

#include "display.h"
#include "gpio.h"

#define NUM_DISP_SEGMENTS	4

static uint8_t bcd2sevensegdisp[] = { 0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x2,
		0x78, 0x0, 0x10, 0x8, 0x3, 0x46, 0x21, 0x6, 0xe };

static uint8_t current_segment;
static uint16_t display_buffer;

static uint16_t tempWrite_buffer;
static uint16_t tempWrite_counter;

void displayInit(void) {
	// Clock gate GPIO port B and port C
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOC;

	// initialize GPIOs dedicated to 7 segment display
	// as output
	GPIO_PORTB_DIR_R |= DISPLAY_PIN_ALL;
	GPIO_PORTB_DEN_R |= DISPLAY_PIN_ALL;

	// initialize GPIOs dedicated to multiplex each of the 4 for segments
	GPIO_PORTC_DIR_R |= GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
	GPIO_PORTC_DEN_R |= GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;

	// initialize global variables
	current_segment = 0x00;
	display_buffer = 0x0000;
	tempWrite_counter = 0;
}


tBoolean displayWrite(uint16_t bcdBuffer) {
	display_buffer = bcdBuffer;

	return true;
}

tBoolean displayTempWrite(uint16_t bcdBuffer) {
	tempWrite_buffer = bcdBuffer;
	tempWrite_counter = TEMP_WRITE_TICKS;

	return true;
}

static uint8_t _getDigit(uint16_t num, uint8_t nibble) {
	static uint16_t nibleMask[] = { 0xF000, 0x0F00, 0x00F0, 0x000F };

	return (num & nibleMask[nibble]) >> (4 * (4 - nibble - 1));
}

static void _enable_segment(uint8_t seg_num) {
	static uint8_t segment_pin[] = { GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6,
			GPIO_PIN_7 };

	GPIO_PORTC_DATA_R &= ~(GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
	GPIO_PORTC_DATA_R |= segment_pin[seg_num];

	return;
}

void displayTick(void) {
	uint8_t current_digit = 0;

	// get the digit for the segment of the display we are going to set
	current_digit = _getDigit(display_buffer, current_segment);

	// this is a special case when for example lapse information is to be
	// shown on the display.
	if (tempWrite_counter){
		current_digit = _getDigit(tempWrite_buffer, current_segment);
		tempWrite_counter -= 1;
	}

	// clear the display, enable the specific display segment, and then updates the digit on the 7 segment
	// display
	displayClear();
	_enable_segment(current_segment);
	GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R & 0x80) | (bcd2sevensegdisp[current_digit] & 0x7F);

	// increment the segment and restart if needed
	current_segment += 1;
	current_segment %= NUM_DISP_SEGMENTS;
}

void displayTest(void) {
	uint8_t loop = 0;

	// Turn all LEDS in board in sequence.
	GPIO_PORTB_DATA_R = 0;

	GPIO_PORTC_DATA_R &= ~(0xF0);
	GPIO_PORTC_DATA_R |= GPIO_PIN_4;

	GPIO_PORTC_DATA_R &= ~(0xF0);
	GPIO_PORTC_DATA_R |= GPIO_PIN_5;

	GPIO_PORTC_DATA_R &= ~(0xF0);
	GPIO_PORTC_DATA_R |= GPIO_PIN_6;

//	GPIO_PORTC_DATA_R &= ~(0xF0);
//	GPIO_PORTC_DATA_R |= GPIO_PIN_7;

	GPIO_PORTC_DATA_R &= ~(0xF0);
	GPIO_PORTC_DATA_R |= GPIO_PIN_4;

	GPIO_PORTC_DATA_R &= ~(0xF0);
	GPIO_PORTC_DATA_R |= 0xF0;

	for (loop = 0; loop < 0x8; loop++) {
		GPIO_PORTB_DATA_R = 0xFF;
		GPIO_PORTB_DATA_R &= ~(1 << loop);

	}

	GPIO_PORTB_DATA_R = 0x00;

	for (loop = 0; loop <= 0xF; loop++) {
//		GPIO_PORTB_DATA_R = 0xFF;
		GPIO_PORTB_DATA_R = bcd2sevensegdisp[loop];

	}

}

void displayClear(void) {
	GPIO_PORTB_DATA_R |= DISPLAY_PIN_ALL;
}
