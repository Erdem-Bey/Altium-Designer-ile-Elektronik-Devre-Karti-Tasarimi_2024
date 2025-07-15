/*
 * I2C.h
 *
 *  Created on: Nov 17, 2024
 *      Author: Erdem
 */

#ifndef SRC_INTERFACES_I2C_H_
#define SRC_INTERFACES_I2C_H_

#include <vector>
#include "stm32f4xx_hal.h"

class I2C
{
	public:
		uint32_t defaultTimeout_ms;

		I2C() = delete;
		I2C(I2C &) = delete;
		I2C(I2C_HandleTypeDef & handle,
			const uint32_t defaultTimeout_ms = HAL_MAX_DELAY);

		HAL_StatusTypeDef Transmit	(const	uint8_t deviceAddress,
											std::vector<uint8_t> data);

		HAL_StatusTypeDef MemWrite(	const	uint8_t deviceAddress,
									const	uint8_t memoryAddress,
											uint8_t data);

	private:
		I2C_HandleTypeDef & handle;
};

#endif /* SRC_INTERFACES_I2C_H_ */
