find_program(LCOV_EXECUTABLE lcov)
if(LCOV_EXECUTABLE)
  message(STATUS "Found lcov: ${LCOV_EXECUTABLE}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
  set(COVERAGE_FOUND True)
else()
  message(SEND_ERROR "lcov not found")
  set(COVERAGE_FOUND False)
endif()

find_program(GENHTML_EXECUTABLE genhtml)
if(GENHTML_EXECUTABLE)
  message(STATUS "Found genhtml: ${GENHTML_EXECUTABLE}")
else()
  message(SEND_ERROR "genhtml not found")
  set(COVERAGE_FOUND False)
endif()
