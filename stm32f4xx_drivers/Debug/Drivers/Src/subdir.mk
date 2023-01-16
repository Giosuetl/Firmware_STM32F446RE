################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/stm32f446_rcc.c \
../Drivers/Src/stm32f446xx_gpio.c \
../Drivers/Src/stm32f446xx_i2c.c \
../Drivers/Src/stm32f446xx_iwdg.c \
../Drivers/Src/stm32f446xx_nvic.c \
../Drivers/Src/stm32f446xx_systick.c \
../Drivers/Src/stm32f446xx_tim.c \
../Drivers/Src/stm32f446xx_wwdg.c 

OBJS += \
./Drivers/Src/stm32f446_rcc.o \
./Drivers/Src/stm32f446xx_gpio.o \
./Drivers/Src/stm32f446xx_i2c.o \
./Drivers/Src/stm32f446xx_iwdg.o \
./Drivers/Src/stm32f446xx_nvic.o \
./Drivers/Src/stm32f446xx_systick.o \
./Drivers/Src/stm32f446xx_tim.o \
./Drivers/Src/stm32f446xx_wwdg.o 

C_DEPS += \
./Drivers/Src/stm32f446_rcc.d \
./Drivers/Src/stm32f446xx_gpio.d \
./Drivers/Src/stm32f446xx_i2c.d \
./Drivers/Src/stm32f446xx_iwdg.d \
./Drivers/Src/stm32f446xx_nvic.d \
./Drivers/Src/stm32f446xx_systick.d \
./Drivers/Src/stm32f446xx_tim.d \
./Drivers/Src/stm32f446xx_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I../Inc -I"C:/Users/Nestor/Documents/embedded/Firmware123/1/stm32f4xx_drivers/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/stm32f446_rcc.d ./Drivers/Src/stm32f446_rcc.o ./Drivers/Src/stm32f446_rcc.su ./Drivers/Src/stm32f446xx_gpio.d ./Drivers/Src/stm32f446xx_gpio.o ./Drivers/Src/stm32f446xx_gpio.su ./Drivers/Src/stm32f446xx_i2c.d ./Drivers/Src/stm32f446xx_i2c.o ./Drivers/Src/stm32f446xx_i2c.su ./Drivers/Src/stm32f446xx_iwdg.d ./Drivers/Src/stm32f446xx_iwdg.o ./Drivers/Src/stm32f446xx_iwdg.su ./Drivers/Src/stm32f446xx_nvic.d ./Drivers/Src/stm32f446xx_nvic.o ./Drivers/Src/stm32f446xx_nvic.su ./Drivers/Src/stm32f446xx_systick.d ./Drivers/Src/stm32f446xx_systick.o ./Drivers/Src/stm32f446xx_systick.su ./Drivers/Src/stm32f446xx_tim.d ./Drivers/Src/stm32f446xx_tim.o ./Drivers/Src/stm32f446xx_tim.su ./Drivers/Src/stm32f446xx_wwdg.d ./Drivers/Src/stm32f446xx_wwdg.o ./Drivers/Src/stm32f446xx_wwdg.su

.PHONY: clean-Drivers-2f-Src

