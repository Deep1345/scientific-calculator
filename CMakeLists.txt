cmake_minimum_required(VERSION 3.14)
project(ScientificCalculator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Main library
add_library(calculator_lib src/Calculator.cpp)
target_include_directories(calculator_lib PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Main executable
add_executable(scientific_calculator src/main.cpp)
target_link_libraries(scientific_calculator PRIVATE calculator_lib)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(calculator_tests tests/test_calculator.cpp)
target_link_libraries(calculator_tests PRIVATE calculator_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(calculator_tests)