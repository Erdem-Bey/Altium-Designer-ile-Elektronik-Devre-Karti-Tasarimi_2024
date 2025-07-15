/*
 * LCD.h
 *
 *  Created on: Nov 17, 2024
 *      Author: Erdem
 */

#ifndef SRC_DEVICES_LCD_H_
#define SRC_DEVICES_LCD_H_

#include <string>
#include "../Interfaces/GPIO.h"
#include "../Interfaces/I2C.h"

class LCD
{
	public:
		LCD() = delete;
		LCD(LCD &) = delete;
		LCD(I2C & i2c,
			const uint8_t deviceAddress,
			GPIO & errLed,
			GPIO & sucLed);

		HAL_StatusTypeDef ClearDisplay() const;
		HAL_StatusTypeDef ReturnHome() const;

		HAL_StatusTypeDef SetCursor(const uint8_t row, const uint8_t col) const;
		void Print(const std::string & text) const;
		HAL_StatusTypeDef Print(const uint8_t character) const;



	private:
		I2C & i2c;
		uint8_t readAddress;
		uint8_t writeAddress;

		static constexpr uint8_t addressCommand	= 0x00;
		static constexpr uint8_t addressData	= 0x40;
		static constexpr uint8_t DDRAM_ADR_BASE	= 0x80;

		uint8_t hardwareSettings_EMS;
		static constexpr uint8_t EMS_BASE		= 0b0000'0100;
		static constexpr uint8_t EMS_INCREMENT	= 0b0000'0010;
		static constexpr uint8_t EMS_SHIFT		= 0b0000'0001;

		uint8_t hardwareSettings_DCB;
		static constexpr uint8_t DCB_BASE		= 0b0000'1000;
		static constexpr uint8_t DCB_DISPLAY	= 0b0000'0100;
		static constexpr uint8_t DCB_CURSOR		= 0b0000'0010;
		static constexpr uint8_t DCB_BLINK		= 0b0000'0001;

		uint8_t hardwareSettings_FNS;
		static constexpr uint8_t FNS_BASE		= 0b0010'0000;
		static constexpr uint8_t FNS_DATALENGTH	= 0b0001'0000;
		static constexpr uint8_t FNS_LINENUMBER	= 0b0000'1000;
		static constexpr uint8_t FNS_FONT		= 0b0000'0100;

		const GPIO & errorLed;
		const GPIO & successLed;

		HAL_StatusTypeDef SendInstruction(const uint8_t instruction) const;
		HAL_StatusTypeDef SendData(const uint8_t data) const;
		HAL_StatusTypeDef ChangeDDRAMAddress(const uint8_t newAddress) const;

		void DisplayResult(const HAL_StatusTypeDef & result) const;
		void ClearResult() const;



};

#endif /* SRC_DEVICES_LCD_H_ */
