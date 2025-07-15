/*
 * I2C.cpp
 *
 *  Created on: Nov 17, 2024
 *      Author: Erdem
 */

#include "I2C.h"

I2C::I2C(I2C_HandleTypeDef & handle, const uint32_t defaultTimeout_ms /*= HAL_MAX_DELAY*/)
	:	defaultTimeout_ms(defaultTimeout_ms)
	,	handle(handle)
{

}

HAL_StatusTypeDef I2C::Transmit(const uint8_t deviceAddress,
								std::vector<uint8_t> data)
{
	HAL_StatusTypeDef result = HAL_I2C_Master_Transmit(&handle, deviceAddress, data.data(), data.size(), defaultTimeout_ms);
	return result;
}

HAL_StatusTypeDef I2C::MemWrite(const	uint8_t deviceAddress,
								const	uint8_t memoryAddress,
										uint8_t data)
{
	HAL_StatusTypeDef result = HAL_I2C_Mem_Write(	&handle,
													deviceAddress,
													memoryAddress,
													I2C_MEMADD_SIZE_8BIT,	// = sizeof(uint8_t)
													&data,
													(uint16_t) sizeof(data),
													defaultTimeout_ms);
	return result;
}

