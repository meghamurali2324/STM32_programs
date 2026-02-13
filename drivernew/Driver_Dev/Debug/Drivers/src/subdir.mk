################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/stm32_GPIO_Driver.c 

OBJS += \
./Drivers/src/stm32_GPIO_Driver.o 

C_DEPS += \
./Drivers/src/stm32_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o Drivers/src/%.su Drivers/src/%.cyclo: ../Drivers/src/%.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"C:/Users/megha/OneDrive/Desktop/STM32_programs/drivernew/Driver_Dev/Drivers/inc" -I"C:/Users/megha/OneDrive/Desktop/STM32_programs/drivernew/Driver_Dev/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-src

clean-Drivers-2f-src:
	-$(RM) ./Drivers/src/stm32_GPIO_Driver.cyclo ./Drivers/src/stm32_GPIO_Driver.d ./Drivers/src/stm32_GPIO_Driver.o ./Drivers/src/stm32_GPIO_Driver.su

.PHONY: clean-Drivers-2f-src

