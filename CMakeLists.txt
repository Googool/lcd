cmake_minimum_required(VERSION 3.12)

# Pull the SDK (must be before project)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set name of the project (as PROJECT_NAME)
project(lcd)

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Create the library target
add_library(${PROJECT_NAME} INTERFACE)

# Specify the source files for the library
target_sources(${PROJECT_NAME} INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/lcd.c
)

# Specify the include directory for the library
target_include_directories(${PROJECT_NAME} INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/include
)

# Link the standard SDK libraries (for stdio, etc.)
target_link_libraries(${PROJECT_NAME} INTERFACE
    pico_stdlib
    hardware_spi
    hardware_pwm
    hardware_dma
)
