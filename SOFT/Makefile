# ******************************************************************************
# * INCLUDES
# ******************************************************************************

-include $(wildcard $(BUILD_DIR)/*.d)

# ******************************************************************************
# * FUNCTIONS
# ******************************************************************************

# TODO add functions here

# ******************************************************************************
# * VARIABLES
# ******************************************************************************

BUILD_DIR = artifacts/build
TARGET = encoder_panel

DEBUG = 1			# debug build?
OPT = -Og			# optimization
CPU = -mcpu=cortex-m3

C_DEFS =  \
-DSTM32F10X_MD \
-DUSE_STDPERIPH_DRIVER

AS_DEFS = 

C_SOURCES =  \
	codebase/main_fw//application/main.c \
	codebase/main_fw//application/app.c \
	codebase/main_fw/hardware/bsp/bsp.c \
	codebase/main_fw/hardware/bsp/Driver_encoder/encoder_drv.c \
	codebase/main_fw/hardware/bsp/Driver_buttons/buttons_drv.c \
	codebase/main_fw/hardware/bsp/Driver_control/control_drv.c \
	codebase/main_fw/hardware/bsp/Driver_control/control_data.c \
	codebase/main_fw/hardware/mcu_hal/STM32F10x_StdPeriph_Driver/src/misc.c \
	codebase/main_fw/hardware/mcu_hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_dma.c \
	codebase/main_fw/hardware/mcu_hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c \
	codebase/main_fw/hardware/mcu_hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_i2c.c \
	codebase/main_fw/hardware/mcu_hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c \
	codebase/main_fw/hardware/mcu_hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_tim.c \
	codebase/main_fw/hardware/mcu_hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c \
	codebase/main_fw/hardware/mcu_hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_flash.c \
	codebase/main_fw/hardware/mcu_hal/system_stm32f10x.c \
	codebase/main_fw/middleware/Circular_Buffer/Latest/circ_buffer.c \
	codebase/main_fw/middleware/Common/scr/crc.c \
	codebase/main_fw/middleware/upload_config_service/upl_cfg_service.c \
	codebase/main_fw/middleware/async_xmodem-master/xmodem_server.c

C_INCLUDES =  \
	-Icodebase/main_fw/application \
	-Icodebase/main_fw/hardware/bsp \
	-Icodebase/main_fw/hardware/bsp/Driver_encoder \
	-Icodebase/main_fw/hardware/bsp/Driver_buttons \
	-Icodebase/main_fw/hardware/bsp/Driver_control \
	-Icodebase/main_fw/hardware/mcu_hal \
	-Icodebase/main_fw/hardware/system \
	-Icodebase/main_fw/hardware/CMSIS/CM3/CoreSupport \
	-Icodebase/main_fw/hardware/mcu_hal/STM32F10x_StdPeriph_Driver/inc \
	-Icodebase/main_fw/middleware/Circular_Buffer/Latest \
	-Icodebase/main_fw/middleware/Common/inc \
	-Icodebase/main_fw/middleware/upload_config_service \
	-Icodebase/main_fw/middleware/async_xmodem-master


# ASM sources
ASM_SOURCES =  \
	codebase/main_fw/hardware/system/startup_stm32f10x_md.s

PREFIX = arm-none-eabi-

# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
# GCC_PATH=D:\soft\gcc-arm-none-eabi-10-2020-q4-major\bin

ifdef GCC_PATH
	CC = $(GCC_PATH)/$(PREFIX)gcc
	AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
	CP = $(GCC_PATH)/$(PREFIX)objcopy
	SZ = $(GCC_PATH)/$(PREFIX)size
else
	CC = $(PREFIX)gcc
	AS = $(PREFIX)gcc -x assembler-with-cpp
	CP = $(PREFIX)objcopy
	SZ = $(PREFIX)size
endif

HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS += $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

# ifeq ($(DEBUG), 1)
CFLAGS += -g3 -gdwarf
# endif

# Generate dependency information
# CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"

# link script
LDSCRIPT = codebase/main_fw/hardware/system/STM32F103C8_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))

OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

# ******************************************************************************
# * TARGETS - MANDATORY
# ******************************************************************************

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf | $(BUILD_DIR)
	$(BIN) $< $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

# Init repository / project
init:
	echo "Not implemented"
	exit 1


# Apply codestyle to all codebase
style_apply:
	echo "Not implemented"
	exit 1


# Check codestyle and return error if ther ere some violence, generate a report into ./artifacts 
style_analyze:
	echo "Not implemented"
	exit 1


# Run unit tests, generate a test report and a gcov report into ./artifacts 
test_unit:
	ceedling test:all
	echo "Reports not implemented"
	exit 1

# Run static analyzers, generate an analyze report into ./artifacts 
static_analyze:
	echo "Not implemented"
	exit 1


# Run security analyzers, generate an analyze report into ./artifacts 
security_analyze:
	echo "Not implemented"
	exit 1


# Build project in debug configuration
# build_debug:
# 	$(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


# Build project in release configuraiton
build_release:
	echo "Not implemented"
	exit 1


# Test on the emulator, generate a test report into ./artifacts 
test_on-emulator:
	echo "Not implemented"
	exit 1


# # Test on the test stand, generate a test report into ./artifacts 
test_on-stand:
	echo "Not implemented"
	exit 1


# Build docs and generate a docs bundle into ./artifacts
docs_build:
	doxygen doxygen_config


# Run debug workflow
all_debug:
	init build_debug


# Run release workflow
all_release:
	init style_analyze test_unit static_analyze build_release test_on-emulator test_on-stand docs_build security_analyze

# ******************************************************************************
# * TARGETS - PROJECT-SPECIFIC
# ******************************************************************************


# $(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
# 	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

# $(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
# 	$(AS) -c $(CFLAGS) $< -o $@

# $(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
# 	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
# 	$(SZ) $@

# $(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
# 	$(HEX) $< $@
	
# $(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
# 	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@

clean:
	-rm -r $(BUILD_DIR)

# ******************************************************************************
# * END OF MAKEFILE
# ******************************************************************************
