################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adc.c \
../src/config.c \
../src/debug.c \
../src/eeprom_manage.c \
../src/emonLib.c \
../src/fsm.c \
../src/main.c \
../src/pcf8563.c \
../src/sensors.c \
../src/time.c \
../src/twi.c \
../src/usart.c 

OBJS += \
./src/adc.o \
./src/config.o \
./src/debug.o \
./src/eeprom_manage.o \
./src/emonLib.o \
./src/fsm.o \
./src/main.o \
./src/pcf8563.o \
./src/sensors.o \
./src/time.o \
./src/twi.o \
./src/usart.o 

C_DEPS += \
./src/adc.d \
./src/config.d \
./src/debug.d \
./src/eeprom_manage.d \
./src/emonLib.d \
./src/fsm.d \
./src/main.d \
./src/pcf8563.d \
./src/sensors.d \
./src/time.d \
./src/twi.d \
./src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


