set(MODULE_NAME "segger-rtt")

add_library(${MODULE_NAME}
  EXCLUDE_FROM_ALL
  RTT/SEGGER_RTT.c
  RTT/SEGGER_RTT_printf.c
)

target_include_directories(${MODULE_NAME}
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/RTT
)

set_source_files_properties(${ARGN}
  PROPERTIES
  COMPILE_FLAGS -Wall
  COMPILE_FLAGS -Werror
)

#  target_compile_features(${TARGET_LIB}
#    PRIVATE
#    cxx_std_14
#    c_std_11
#  )
