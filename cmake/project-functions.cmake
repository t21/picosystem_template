# Function to add a standard project module library
# Typically call as 'proj_add_library(${MODULE_NAME} ${SRC_LIST})
# If more libraries need to be included in this library, add a target_link_libraries statement after the function, i.e.
#   target_link_libraries(${MODULE_NAME}
#     PRIVATE | PUBLIC | INTERFACE
#     ${LIBRARIES_THAT_SHOULD_BE_INCLUDED}
#   )
function(proj_add_library TARGET_LIB)

  add_library(${TARGET_LIB} EXCLUDE_FROM_ALL ${ARGN})

  target_include_directories(${TARGET_LIB}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

  set_source_files_properties(${ARGN}
    PROPERTIES
    COMPILE_FLAGS -Wall
    COMPILE_FLAGS -Werror
    COMPILE_FLAGS -Wextra
    COMPILE_FLAGS -Wshadow
    COMPILE_FLAGS -Wpedantic
  )

#  target_compile_features(${TARGET_LIB}
#    PRIVATE
#    cxx_std_14
#    c_std_11
#  )

  if (BUILD_TESTING)
    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/test)
      add_subdirectory(test)
    endif()
  endif()
endfunction()

# Function to add a unit test target for a standard project module library
# Typically call as proj_add_test_target(${NAME_OF_LIB_TO_BE_TESTED} ${SRC_LIST})
#  Ex: proj_add_test_target(utils ${SRC_LIST})
# If more libraries need to be included in this library, add a target_link_libraries statement after the function, i.e.
#   target_link_libraries(${MODULE_NAME}
#     gmock
#     gmock_main
#     ${LIB_MOCK}
#   )
function(proj_add_test_target TARGET_LIB)

  set(TEST_EXEC ${TARGET_LIB}-test)

  # Build the test executable.
  add_executable(${TEST_EXEC} ${ARGN})

  target_link_libraries(${TEST_EXEC}
    ${TARGET_LIB}
    gtest
    gtest-main
  )

  set_source_files_properties(${ARGN}
    PROPERTIES
    COMPILE_FLAGS -Wall
    COMPILE_FLAGS -Werror
  )

  target_compile_features(${TEST_EXEC}
    PRIVATE
    cxx_std_14
    c_std_11
  )

  gtest_discover_tests(${TEST_EXEC}
    DISCOVERY_TIMEOUT ${BCM3_DISCOVERY_TIMEOUT}
  )

  add_custom_target(run-${TEST_EXEC}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${TEST_EXEC}
    COMMENT "Running tests for ${TARGET_LIB} (${TEST_EXEC})."
  )
endfunction()
