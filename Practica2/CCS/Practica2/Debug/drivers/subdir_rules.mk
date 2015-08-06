################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
drivers/display.obj: ../drivers/display.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="c:/StellarisWare" --include_path="c:/StellarisWare/boards/ek-lm4f120xl" --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="drivers/display.pp" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/gpio.obj: ../drivers/gpio.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="c:/StellarisWare" --include_path="c:/StellarisWare/boards/ek-lm4f120xl" --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="drivers/gpio.pp" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/led.obj: ../drivers/led.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="c:/StellarisWare" --include_path="c:/StellarisWare/boards/ek-lm4f120xl" --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="drivers/led.pp" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/pbuttons.obj: ../drivers/pbuttons.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --include_path="c:/StellarisWare" --include_path="c:/StellarisWare/boards/ek-lm4f120xl" --include_path="C:/ti/ccsv5/tools/compiler/tms470_4.9.5/include" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="drivers/pbuttons.pp" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


