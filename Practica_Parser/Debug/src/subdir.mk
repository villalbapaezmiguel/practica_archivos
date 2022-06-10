################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Alumno.c \
../src/Practica_Parser.c \
../src/UTN.c 

C_DEPS += \
./src/Alumno.d \
./src/Practica_Parser.d \
./src/UTN.d 

OBJS += \
./src/Alumno.o \
./src/Practica_Parser.o \
./src/UTN.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Alumno.d ./src/Alumno.o ./src/Practica_Parser.d ./src/Practica_Parser.o ./src/UTN.d ./src/UTN.o

.PHONY: clean-src

