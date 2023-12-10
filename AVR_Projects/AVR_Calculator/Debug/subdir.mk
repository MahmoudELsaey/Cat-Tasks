################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Calc_prog.c \
../DIO_prog.c \
../KPD_prog.c \
../LCD_prog.c \
../main.c 

OBJS += \
./Calc_prog.o \
./DIO_prog.o \
./KPD_prog.o \
./LCD_prog.o \
./main.o 

C_DEPS += \
./Calc_prog.d \
./DIO_prog.d \
./KPD_prog.d \
./LCD_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


