################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Driver/Driver_ADC0.c \
../Sources/Driver/Driver_GPIO.c \
../Sources/Driver/Driver_PIT.c \
../Sources/Driver/Driver_PORT.c \
../Sources/Driver/Driver_SIM.c 

OBJS += \
./Sources/Driver/Driver_ADC0.o \
./Sources/Driver/Driver_GPIO.o \
./Sources/Driver/Driver_PIT.o \
./Sources/Driver/Driver_PORT.o \
./Sources/Driver/Driver_SIM.o 

C_DEPS += \
./Sources/Driver/Driver_ADC0.d \
./Sources/Driver/Driver_GPIO.d \
./Sources/Driver/Driver_PIT.d \
./Sources/Driver/Driver_PORT.d \
./Sources/Driver/Driver_SIM.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Driver/%.o: ../Sources/Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


