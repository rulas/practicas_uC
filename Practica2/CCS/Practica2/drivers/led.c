#include "led.h"

#define GPIO_CK_SC 			SYSCTL_RCGC2_GPIOB
#define GPIO_CK_SW 			SYSCTL_RCGC2_GPIOF

#define GPIO_PORT_DIR_SC	GPIO_PORTB_DIR_R
#define GPIO_PORT_DIR_SW	GPIO_PORTF_DIR_R

#define GPIO_PORT_DEN_SC	GPIO_PORTB_DEN_R
#define GPIO_PORT_DEN_SW	GPIO_PORTF_DEN_R

#define GPIO_PORT_DATA_SC	GPIO_PORTB_DATA_R
#define GPIO_PORT_DATA_SW	GPIO_PORTF_DATA_R

#define GPIO_PIN_SC 		(1 << 7)
#define GPIO_PIN_SW			(1 << 2)

void ledInit()
{
	//
	// Enable the GPIO port that is used for the on-board LED.
	//
	SYSCTL_RCGC2_R |= GPIO_CK_SW;
	SYSCTL_RCGC2_R |= GPIO_CK_SC;

	// set LED PORT F pins as outputs
	GPIO_PORT_DIR_SC |= GPIO_PIN_SC;
	GPIO_PORT_DIR_SW |= GPIO_PIN_SW;

	// enable digital for LED PORT F pins
	GPIO_PORT_DEN_SC |= GPIO_PIN_SC;
	GPIO_PORT_DEN_SW |= GPIO_PIN_SW;

	// clear all PORT F pins
	ledTurnOff(LED_SYS_ALL);
}



void ledTurnOn(uint8_t led)
{
	if (led & LED_SYS_COUNTING)
	{
		GPIO_PORT_DATA_SC &= ~GPIO_PIN_SC;
	}

	if (led & LED_SYS_WORKING)
	{
		GPIO_PORT_DATA_SW |= GPIO_PIN_SW;
	}
}

void ledTurnOff(uint8_t led)
{
	if (led & LED_SYS_COUNTING)
	{
		GPIO_PORT_DATA_SC |= GPIO_PIN_SC;
	}

	if (led & LED_SYS_WORKING)
	{
		GPIO_PORT_DATA_SW &= ~GPIO_PIN_SW;
	}
}

void ledToggle(uint8_t led)
{
	if (led & LED_SYS_COUNTING)
	{
		GPIO_PORT_DATA_SC ^= GPIO_PIN_SC;
	}

	if (led & LED_SYS_WORKING)
	{
		GPIO_PORT_DATA_SW ^= GPIO_PIN_SW;
	}
}
