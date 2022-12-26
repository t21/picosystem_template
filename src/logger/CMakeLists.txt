set(MODULE_NAME "logger")

proj_add_library(${MODULE_NAME}
  Log.cpp
)

# target_include_directories(${MODULE_NAME}
#   ${CMAKE_SOURCE_DIR}/external
# )

target_link_libraries(${MODULE_NAME}
  PRIVATE
    segger-rtt
)
