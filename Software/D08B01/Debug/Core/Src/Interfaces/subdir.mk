################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Interfaces/GPIO.cpp \
../Core/Src/Interfaces/I2C.cpp 

OBJS += \
./Core/Src/Interfaces/GPIO.o \
./Core/Src/Interfaces/I2C.o 

CPP_DEPS += \
./Core/Src/Interfaces/GPIO.d \
./Core/Src/Interfaces/I2C.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Interfaces/%.o Core/Src/Interfaces/%.su Core/Src/Interfaces/%.cyclo: ../Core/Src/Interfaces/%.cpp Core/Src/Interfaces/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++20 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F417xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Interfaces

clean-Core-2f-Src-2f-Interfaces:
	-$(RM) ./Core/Src/Interfaces/GPIO.cyclo ./Core/Src/Interfaces/GPIO.d ./Core/Src/Interfaces/GPIO.o ./Core/Src/Interfaces/GPIO.su ./Core/Src/Interfaces/I2C.cyclo ./Core/Src/Interfaces/I2C.d ./Core/Src/Interfaces/I2C.o ./Core/Src/Interfaces/I2C.su

.PHONY: clean-Core-2f-Src-2f-Interfaces

