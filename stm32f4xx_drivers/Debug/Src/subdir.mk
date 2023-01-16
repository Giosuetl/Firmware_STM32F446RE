################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/WWDG_1.c \
../Src/usart2.c 

OBJS += \
./Src/WWDG_1.o \
./Src/usart2.o 

C_DEPS += \
./Src/WWDG_1.d \
./Src/usart2.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I../Inc -I"C:/Users/Nestor/Documents/embedded/Firmware123/1/stm32f4xx_drivers/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/WWDG_1.d ./Src/WWDG_1.o ./Src/WWDG_1.su ./Src/usart2.d ./Src/usart2.o ./Src/usart2.su

.PHONY: clean-Src

