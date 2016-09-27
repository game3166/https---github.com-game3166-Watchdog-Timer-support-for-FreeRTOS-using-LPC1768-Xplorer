################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lpc17xx_clkpwr.c \
../src/lpc17xx_gpio.c \
../src/lpc17xx_libcfg_default.c \
../src/lpc17xx_pinsel.c \
../src/lpc17xx_wdt.c 

OBJS += \
./src/lpc17xx_clkpwr.o \
./src/lpc17xx_gpio.o \
./src/lpc17xx_libcfg_default.o \
./src/lpc17xx_pinsel.o \
./src/lpc17xx_wdt.o 

C_DEPS += \
./src/lpc17xx_clkpwr.d \
./src/lpc17xx_gpio.d \
./src/lpc17xx_libcfg_default.d \
./src/lpc17xx_pinsel.d \
./src/lpc17xx_wdt.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSISv2p00_LPC17xx -DCR_INTEGER_PRINTF -D__LPC17XX__ -I"C:\Users\desd56\Desktop\final\final_code v2\CMSISv2p00_LPC17xx" -I"C:\Users\desd56\Desktop\final\final_code v2\17xx.Firmware" -I"C:\Users\desd56\Desktop\final\final_code v2\17xx.Firmware\inc" -I"C:\Users\desd56\Desktop\final\final_code v2\FreeRTOS-IO_Demo\FreeRTOS\inc" -I"C:\Users\desd56\Desktop\final\final_code v2\CMSISv2p00_LPC17xx\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


