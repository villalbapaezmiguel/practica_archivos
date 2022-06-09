################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Alumno.c \
../src/Practica_Parser.c \
../src/UTN.c 

OBJS += \
./src/Alumno.o \
./src/Practica_Parser.o \
./src/UTN.o 

C_DEPS += \
./src/Alumno.d \
./src/Practica_Parser.d \
./src/UTN.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


