cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(${CMAKE_SOURCE_DIR}/external/pico-sdk/pico_sdk_init.cmake)

set(APP_NAME "Template")
project(${APP_NAME})

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

add_executable(${APP_NAME}
  main.cpp
)

set_source_files_properties(
  main.cpp
  PROPERTIES
    COMPILE_FLAGS -Wall
    COMPILE_FLAGS -Werror
    COMPILE_FLAGS -Wextra
    COMPILE_FLAGS -Wshadow
)

pico_enable_stdio_usb(${APP_NAME} 0)
pico_enable_stdio_uart(${APP_NAME} 0)

pico_add_extra_outputs(${APP_NAME})

target_include_directories(${APP_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# target_include_directories(${APP_NAME}
#   PUBLIC
#     .
#     ${CMAKE_CURRENT_SOURCE_DIR}
# )

target_link_libraries(${APP_NAME}
  PRIVATE
    pico_stdlib
    logger
)
