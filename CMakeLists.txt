cmake_minimum_required(VERSION 3.16)

# Set your project name here
set(PROJECT_NAME picosystem_template)

# Set your project sources here
set(PROJECT_SOURCES
  src/main.cpp
)

# Include pico-sdk base cmake file
include(external/pico-sdk/external/pico_sdk_import.cmake)

# set up proejct
project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the pico-sdk
pico_sdk_init()

# Find the PicoSystem library
include(external/picosystem/template/picosystem_sdk_import.cmake)

# Create the output target
picosystem_executable(
  ${PROJECT_NAME}
  ${PROJECT_SOURCES}
)

# Set your build options here
pixel_double(${PROJECT_NAME})          # 120x120 resolution game, pixel-doubled to 240x240
disable_startup_logo(${PROJECT_NAME})  # Skip the PicoSystem splash
#no_font(${PROJECT_NAME})              # Omit the default font
#no_spritesheet(${PROJECT_NAME})       # Omit the default spritesheet
#no_overclock(${PROJECT_NAME})         # Don't overclock

set_source_files_properties(
  ${PROJECT_NAME}
  PROPERTIES
  COMPILE_FLAGS -Wall
  COMPILE_FLAGS -Werror
  COMPILE_FLAGS -Wextra
  COMPILE_FLAGS -Wshadow
  COMPILE_FLAGS -Wpedantic
)


# Add modules
# add_subdirectory(${CMAKE_SOURCE_DIR}/src/SEGGER_RTT_V752a EXCLUDE_FROM_ALL)
# add_subdirectory(${CMAKE_SOURCE_DIR}/src/logger EXCLUDE_FROM_ALL)

# Print build info
message(STATUS "****************************************************")
message(STATUS "***   CMAKE_PROJECT_NAME:   ${CMAKE_PROJECT_NAME}")
message(STATUS "***   CMAKE_BUILD_TYPE:     ${CMAKE_BUILD_TYPE}")
message(STATUS "***   CMAKE_GENERATOR:      ${CMAKE_GENERATOR}")
message(STATUS "***   PICO_PLATFORM:        ${PICO_PLATFORM}")
message(STATUS "****************************************************")



# pico_enable_stdio_usb(${APP_NAME} 0)
# pico_enable_stdio_uart(${APP_NAME} 0)

# pico_add_extra_outputs(${APP_NAME})

# target_include_directories(${APP_NAME}
#   PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}
# )

# target_link_libraries(${APP_NAME}
#   PRIVATE
#     pico_stdlib
#     logger
# )
