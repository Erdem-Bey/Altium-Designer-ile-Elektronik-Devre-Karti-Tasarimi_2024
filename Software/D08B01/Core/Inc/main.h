/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Button_3_Pin GPIO_PIN_2
#define Button_3_GPIO_Port GPIOE
#define Led_R_Pin GPIO_PIN_3
#define Led_R_GPIO_Port GPIOE
#define Led_O_Pin GPIO_PIN_4
#define Led_O_GPIO_Port GPIOE
#define Led_Y_Pin GPIO_PIN_5
#define Led_Y_GPIO_Port GPIOE
#define Led_G_Pin GPIO_PIN_6
#define Led_G_GPIO_Port GPIOE
#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define DIR_1_Pin GPIO_PIN_2
#define DIR_1_GPIO_Port GPIOB
#define OE_1_Pin GPIO_PIN_7
#define OE_1_GPIO_Port GPIOE
#define GPIO_8_Pin GPIO_PIN_8
#define GPIO_8_GPIO_Port GPIOE
#define GPIO_9_Pin GPIO_PIN_9
#define GPIO_9_GPIO_Port GPIOE
#define GPIO_10_Pin GPIO_PIN_10
#define GPIO_10_GPIO_Port GPIOE
#define GPIO_11_Pin GPIO_PIN_11
#define GPIO_11_GPIO_Port GPIOE
#define GPIO_12_Pin GPIO_PIN_12
#define GPIO_12_GPIO_Port GPIOE
#define GPIO_13_Pin GPIO_PIN_13
#define GPIO_13_GPIO_Port GPIOE
#define GPIO_14_Pin GPIO_PIN_14
#define GPIO_14_GPIO_Port GPIOE
#define GPIO_15_Pin GPIO_PIN_15
#define GPIO_15_GPIO_Port GPIOE
#define OE_0_Pin GPIO_PIN_15
#define OE_0_GPIO_Port GPIOB
#define DIR_0_Pin GPIO_PIN_8
#define DIR_0_GPIO_Port GPIOD
#define GPIO_7_Pin GPIO_PIN_10
#define GPIO_7_GPIO_Port GPIOD
#define GPIO_6_Pin GPIO_PIN_12
#define GPIO_6_GPIO_Port GPIOD
#define GPIO_5_Pin GPIO_PIN_13
#define GPIO_5_GPIO_Port GPIOD
#define GPIO_4_Pin GPIO_PIN_14
#define GPIO_4_GPIO_Port GPIOD
#define GPIO_3_Pin GPIO_PIN_15
#define GPIO_3_GPIO_Port GPIOD
#define GPIO_2_Pin GPIO_PIN_6
#define GPIO_2_GPIO_Port GPIOC
#define GPIO_1_Pin GPIO_PIN_7
#define GPIO_1_GPIO_Port GPIOC
#define GPIO_0_Pin GPIO_PIN_8
#define GPIO_0_GPIO_Port GPIOC
#define Switch_1_Pin GPIO_PIN_7
#define Switch_1_GPIO_Port GPIOD
#define Switch_2_Pin GPIO_PIN_8
#define Switch_2_GPIO_Port GPIOB
#define Switch_3_Pin GPIO_PIN_9
#define Switch_3_GPIO_Port GPIOB
#define Button_1_Pin GPIO_PIN_0
#define Button_1_GPIO_Port GPIOE
#define Button_2_Pin GPIO_PIN_1
#define Button_2_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
