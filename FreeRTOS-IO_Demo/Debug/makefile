################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include FreeRTOS/src/subdir.mk
-include FreeRTOS/port/memmang/subdir.mk
-include FreeRTOS/port/lpcxpresso/m3/subdir.mk
-include FreeRTOS-IO/Device/LPC17xx/subdir.mk
-include FreeRTOS-IO/Common/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: FreeRTOS-IO_Demo.axf

dependents:
	-cd C:/Users/desd56/Desktop/final/final_code\ v2/17xx.Firmware/Debug && $(MAKE) all
	-cd C:/Users/desd56/Desktop/final/final_code\ v2/CMSISv2p00_LPC17xx/Debug && $(MAKE) all
	-cd C:/Users/desd56/Desktop/final/final_code\ v2/lib_small_printf_m3/Debug && $(MAKE) all

# Tool invocations
FreeRTOS-IO_Demo.axf: $(OBJS) $(USER_OBJS) C:/Users/desd56/Desktop/final/final_code\ v2/17xx.Firmware/Debug/lib17xx.Firmware.a C:/Users/desd56/Desktop/final/final_code\ v2/CMSISv2p00_LPC17xx/Debug/libCMSISv2p00_LPC17xx.a C:/Users/desd56/Desktop/final/final_code\ v2/lib_small_printf_m3/Debug/liblib_small_printf_m3.a
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\desd56\Desktop\final\final_code v2\CMSISv2p00_LPC17xx\Debug" -L"C:\Users\desd56\Desktop\final\final_code v2\17xx.Firmware\Debug" -L"C:\Users\desd56\Desktop\final\final_code v2\lib_small_printf_m3\Debug" -Xlinker -Map="FreeRTOS-IO_Demo.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "FreeRTOS-IO_Demo_Debug.ld" -o "FreeRTOS-IO_Demo.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) FreeRTOS-IO_Demo.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "FreeRTOS-IO_Demo.axf"; # arm-none-eabi-objcopy -O binary "FreeRTOS-IO_Demo.axf" "FreeRTOS-IO_Demo.bin" ; checksum -p LPC1768 -d "FreeRTOS-IO_Demo.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
C:/Users/desd56/Desktop/final/final_code\ v2/17xx.Firmware/Debug/lib17xx.Firmware.a:
C:/Users/desd56/Desktop/final/final_code\ v2/CMSISv2p00_LPC17xx/Debug/libCMSISv2p00_LPC17xx.a:
C:/Users/desd56/Desktop/final/final_code\ v2/lib_small_printf_m3/Debug/liblib_small_printf_m3.a:

-include ../makefile.targets
