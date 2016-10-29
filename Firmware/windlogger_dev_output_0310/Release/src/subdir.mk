################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FAT32.c \
../src/config.c \
../src/debug.c \
../src/eeprom_manage.c \
../src/fct_SDCard.c \
../src/fct_rs232.c \
../src/fct_spi.c \
../src/fsm.c \
../src/main.c \
../src/sensors.c \
../src/time.c \
../src/usart.c 

OBJS += \
./src/FAT32.o \
./src/config.o \
./src/debug.o \
./src/eeprom_manage.o \
./src/fct_SDCard.o \
./src/fct_rs232.o \
./src/fct_spi.o \
./src/fsm.o \
./src/main.o \
./src/sensors.o \
./src/time.o \
./src/usart.o 

C_DEPS += \
./src/FAT32.d \
./src/config.d \
./src/debug.d \
./src/eeprom_manage.d \
./src/fct_SDCard.d \
./src/fct_rs232.d \
./src/fct_spi.d \
./src/fsm.d \
./src/main.d \
./src/sensors.d \
./src/time.d \
./src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


