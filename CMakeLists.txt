#=== Prepare environment ===#
cmake_minimum_required(VERSION 3.17)

# Include system environment
# include(toolchain.cmake)

# Set project name
project(EncoderPanel C ASM)

# Set project composition method
# Valid values: [COMP_PER_FILES ; COMP_PER_FOLDERS]
set(PROJECT_COMPOSITION COMP_PER_FOLDERS)

# Set C standard
set(CMAKE_C_STANDARD 99)
# Set microcontroller
set(CMAKE_SYSTEM_PROCESSOR cortex-m3)
# Binary file extension
set(CMAKE_EXECUTABLE_SUFFIX ".elf")
# Linker script file
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/system/STM32F103C8_FLASH.ld)
# Set startup file
set(STARTUP_FILE ${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/system/startup_stm32f10x_md.s)

# Adding compiler/linker options
include(compiler.cmake)

add_definitions(
        -DSTM32F10X_MD
        -DUSE_STDPERIPH_DRIVER)

#set(FREERTOS_DIR FreeRTOS/Source/)

file(GLOB_RECURSE HARDWARE_SOURCES 
        "${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/bsp/Init.c"
        "${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/bsp/Driver_mcp23017/*.c"
        "${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/mcu_hal/STM32F10x_StdPeriph_Driver/src/*.c"
        "${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/mcu_hal/system_stm32f10x.c"
        "${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/CMSIS/CM3/CoreSupport/*.c"
)

file(GLOB_RECURSE APPL_SOURCES 
        "${CMAKE_SOURCE_DIR}/codebase/main_fw//application/main.c"
)

#[[
file(
        GLOB_RECURSE
        FREERTOS_SOURCES
        "${FREERTOS_DIR}/croutine.c"
        "${FREERTOS_DIR}/event_groups.c"
        "${FREERTOS_DIR}/list.c"
        "${FREERTOS_DIR}/queue.c"
        "${FREERTOS_DIR}/stream_buffer.c"
        "${FREERTOS_DIR}/tasks.c"
        "${FREERTOS_DIR}/timers.c"
        "${FREERTOS_DIR}/portable/GCC/ARM_CM3/*.c"
        "${FREERTOS_DIR}/portable/MemMang/heap_1.c"
)

]]
include_directories(${CMAKE_SOURCE_DIR}/codebase/main_fw/application)
include_directories(${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/bsp)
include_directories(${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/bsp/Driver_mcp23017)
include_directories(${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/mcu_hal)
include_directories(${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/CMSIS/CM3/CoreSupport)
include_directories(${CMAKE_SOURCE_DIR}/codebase/main_fw/hardware/mcu_hal/STM32F10x_StdPeriph_Driver/inc)

#[[
include_directories(${FREERTOS_DIR})
include_directories(${FREERTOS_DIR}/include)
include_directories(${FREERTOS_DIR}/portable/GCC/ARM_CM3/)
#include_directories(${FREERTOS_DIR}/portable/IAR/ARM_CM3/)
include_directories(${FREERTOS_DIR}/portable/MemMang)
#include_directories(${FREERTOS_DIR}/portable/Common)
]]

add_executable(
        ${PROJECT_NAME} 
        ${STARTUP_FILE} 
        ${HARDWARE_SOURCES} 
        ${APPL_SOURCES})
        #${FREERTOS_SOURCES})




#=== Post-Build operations ===#

# Generate HEX-file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS -Oihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
        COMMENT "Generate ${PROJECT_NAME}.hex file"
        )

# Generate SREC-file
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS -Osrec ${PROJECT_NAME}.elf ${PROJECT_NAME}.s19
        COMMENT "Generate ${PROJECT_NAME}.s19 file"
        )

# Generate BIN-file
#[[
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
        ARGS -Obinary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
        COMMENT "Generate ${PROJECT_NAME}.bin file"
        )
]]

# Show memory usage
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${GCC_SIZE}
        ARGS --format=berkeley -t ${PROJECT_NAME}.elf
        COMMENT "Memory usage:"
        )