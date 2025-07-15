/*
 * GPIO.h
 *
 *  Created on: Nov 17, 2024
 *      Author: Erdem
 */

#ifndef SRC_INTERFACES_GPIO_H_
#define SRC_INTERFACES_GPIO_H_

#include <type_traits>
#include "stm32f4xx_hal.h"

class GPIO
{
	public:
		GPIO() = delete;
		GPIO(GPIO &) = delete;
		GPIO(GPIO_TypeDef * port, const uint16_t pin);

		void Set() const;
		void Reset() const;
		void Set(GPIO_PinState pinState) const;

		template <class T>
		typename std::enable_if<!std::is_same<T, GPIO_PinState>::value>::type
		Set(T value) const
		{
			this->Set(static_cast<GPIO_PinState>(value));
		}


	private:
		GPIO_TypeDef * port;
		const uint16_t pin;

};

#endif /* SRC_INTERFACES_GPIO_H_ */
