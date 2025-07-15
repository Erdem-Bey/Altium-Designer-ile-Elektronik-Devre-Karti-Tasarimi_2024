/*
 * GPIO.cpp
 *
 *  Created on: Nov 17, 2024
 *      Author: Erdem
 */

#include "GPIO.h"

GPIO::GPIO(GPIO_TypeDef * port, const uint16_t pin)
	:	port(port)
	,	pin(pin)
{
	
}

void GPIO::Set() const
{
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

void GPIO::Reset() const
{
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

void GPIO::Set(GPIO_PinState pinState) const
{
	HAL_GPIO_WritePin(port, pin, pinState);
}





