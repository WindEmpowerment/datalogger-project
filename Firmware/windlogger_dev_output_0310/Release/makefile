################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
windlogger_dev_output_0310.lss \

FLASH_IMAGE += \
windlogger_dev_output_0310.hex \

EEPROM_IMAGE += \
windlogger_dev_output_0310.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: windlogger_dev_output_0310.elf secondary-outputs

# Tool invocations
windlogger_dev_output_0310.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,windlogger_dev_output_0310.map -mmcu=atmega128 -o "windlogger_dev_output_0310.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

windlogger_dev_output_0310.lss: windlogger_dev_output_0310.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S windlogger_dev_output_0310.elf  >"windlogger_dev_output_0310.lss"
	@echo 'Finished building: $@'
	@echo ' '

windlogger_dev_output_0310.hex: windlogger_dev_output_0310.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex windlogger_dev_output_0310.elf  "windlogger_dev_output_0310.hex"
	@echo 'Finished building: $@'
	@echo ' '

windlogger_dev_output_0310.eep: windlogger_dev_output_0310.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex windlogger_dev_output_0310.elf  "windlogger_dev_output_0310.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: windlogger_dev_output_0310.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 windlogger_dev_output_0310.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) windlogger_dev_output_0310.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
