cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories("${PROJECT_SOURCE_DIR}/..")
set(CMAKE_BUILD_TYPE Debug)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests test_kpl_struct.cpp ../kpl_struct.c)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
