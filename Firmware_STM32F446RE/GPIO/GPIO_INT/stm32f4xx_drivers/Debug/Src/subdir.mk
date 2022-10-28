################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/GPIO_02_INT.c 

OBJS += \
./Src/GPIO_02_INT.o 

C_DEPS += \
./Src/GPIO_02_INT.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/Nestor/Documents/embedded/driver_firmware/stm32f4xx_drivers/Drivers/Src" -I"C:/Users/Nestor/Documents/embedded/driver_firmware/stm32f4xx_drivers/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/GPIO_02_INT.d ./Src/GPIO_02_INT.o ./Src/GPIO_02_INT.su

.PHONY: clean-Src

