/*
 * LCD.cpp
 *
 *  Created on: Nov 17, 2024
 *      Author: Erdem
 */

#include "LCD.h"

LCD::LCD(I2C & i2c,
		const uint8_t deviceAddress,
		GPIO & errLed,
		GPIO & sucLed)
	:	i2c(i2c)
	,	readAddress	((deviceAddress << 1) + 1)
	,	writeAddress((deviceAddress << 1) + 0)
	,	hardwareSettings_EMS(EMS_BASE	| (1 * EMS_INCREMENT)	| (0 * EMS_SHIFT))
	,	hardwareSettings_DCB(DCB_BASE	| (1 * DCB_DISPLAY)		| (0 * DCB_CURSOR)		| (0 * DCB_BLINK))
	,	hardwareSettings_FNS(FNS_BASE	| (1 * FNS_DATALENGTH)	| (1 * FNS_LINENUMBER)	| (0 * FNS_FONT))
	,	errorLed(errLed)
	,	successLed(sucLed)
{
	HAL_StatusTypeDef result;
	HAL_Delay(500);

	result = SendInstruction(hardwareSettings_FNS);
	DisplayResult(result);
	HAL_Delay(500);
	ClearResult();
	HAL_Delay(500);
	
	result = SendInstruction(hardwareSettings_DCB);
	DisplayResult(result);
	HAL_Delay(500);
	ClearResult();
	HAL_Delay(500);

	result = ClearDisplay();
	DisplayResult(result);
	HAL_Delay(500);
	ClearResult();
	HAL_Delay(500);

	result = SendInstruction(hardwareSettings_EMS);
	DisplayResult(result);
	HAL_Delay(500);
	ClearResult();
	HAL_Delay(500);
}




HAL_StatusTypeDef LCD::ClearDisplay() const
{
	return SendInstruction(0x01);
}

HAL_StatusTypeDef LCD::ReturnHome() const
{
	return SendInstruction(0x02);
}

HAL_StatusTypeDef LCD::SetCursor(const uint8_t row, const uint8_t col) const
{
	const uint8_t address = 0x40 * row + col;
	HAL_StatusTypeDef result = ChangeDDRAMAddress(address);
	return result;
}

HAL_StatusTypeDef LCD::ChangeDDRAMAddress(const uint8_t newAddress) const
{
	HAL_StatusTypeDef result = SendInstruction(DDRAM_ADR_BASE | newAddress);
	return result;
}

void LCD::Print(const std::string & text) const
{
	for (std::string::size_type i=0; i<text.length(); i++)
	{
		Print(text[i]);
	}
}

HAL_StatusTypeDef LCD::Print(const uint8_t character) const
{
	return SendData(character);
}

HAL_StatusTypeDef LCD::SendInstruction(const uint8_t instruction) const
{
	return i2c.MemWrite(writeAddress, addressCommand, instruction);
}

HAL_StatusTypeDef LCD::SendData(const uint8_t data) const
{
	return i2c.MemWrite(writeAddress, addressData, data);
}

void LCD::DisplayResult(const HAL_StatusTypeDef & result) const
{
	if (result == HAL_OK)
	{
		errorLed.Reset();
		successLed.Set();
	}
	else
	{
		errorLed.Set();
		successLed.Reset();
	}
}

void LCD::ClearResult() const
{
	errorLed.Reset();
	successLed.Reset();
}



