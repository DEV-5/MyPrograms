################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/port.c 

OBJS += \
./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/port.o 

C_DEPS += \
./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/port.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/%.o ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/%.su ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/%.cyclo: ../ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/%.c ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F723xx -c -I../Core/Inc -I"/home/vdev/MyPrograms/os/freeRTOS/stm32f723E-Disc0/FreeRTOS_HelloWorld/ThirdParty/FreeRTOS/include" -I"/home/vdev/MyPrograms/os/freeRTOS/stm32f723E-Disc0/FreeRTOS_HelloWorld/ThirdParty/FreeRTOS" -I"/home/vdev/MyPrograms/os/freeRTOS/stm32f723E-Disc0/FreeRTOS_HelloWorld/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM7

clean-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM7:
	-$(RM) ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/port.cyclo ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/port.d ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/port.o ./ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/port.su

.PHONY: clean-ThirdParty-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM7

