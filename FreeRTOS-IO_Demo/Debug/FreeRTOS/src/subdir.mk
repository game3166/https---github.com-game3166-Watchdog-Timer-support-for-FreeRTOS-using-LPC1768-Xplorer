################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/src/croutine.c \
../FreeRTOS/src/list.c \
../FreeRTOS/src/queue.c \
../FreeRTOS/src/tasks.c 

OBJS += \
./FreeRTOS/src/croutine.o \
./FreeRTOS/src/list.o \
./FreeRTOS/src/queue.o \
./FreeRTOS/src/tasks.o 

C_DEPS += \
./FreeRTOS/src/croutine.d \
./FreeRTOS/src/list.d \
./FreeRTOS/src/queue.d \
./FreeRTOS/src/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/src/%.o: ../FreeRTOS/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -D__CODE_RED -D__USE_CMSIS=CMSISv2p00_LPC17xx -I"C:\Users\desd56\Desktop\final\final_code v2\CMSISv2p00_LPC17xx" -I"C:\Users\desd56\Desktop\final\final_code v2\17xx.Firmware" -I"C:\Users\desd56\Desktop\final\final_code v2\lib_small_printf_m3\inc" -I"C:\Users\desd56\Desktop\final\final_code v2\17xx.Firmware\src" -I"C:\Users\desd56\Desktop\final\final_code v2\FreeRTOS-IO_Demo\FreeRTOS-IO\Device\LPC17xx\SupportedBoards" -I"C:\Users\desd56\Desktop\final\final_code v2\FreeRTOS-IO_Demo\FreeRTOS-IO\Include" -I"C:\Users\desd56\Desktop\final\final_code v2\17xx.Firmware\inc" -I"C:\Users\desd56\Desktop\final\final_code v2\FreeRTOS-IO_Demo\src" -I"C:\Users\desd56\Desktop\final\final_code v2\FreeRTOS-IO_Demo\FreeRTOS\inc" -I"C:\Users\desd56\Desktop\final\final_code v2\FreeRTOS-IO_Demo\FreeRTOS\port\lpcxpresso\m3" -I"C:\Users\desd56\Desktop\final\final_code v2\CMSISv2p00_LPC17xx\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


