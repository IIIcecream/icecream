cmake_minimum_required(VERSION 3.1.0)

project (Test)

# Use C++11...
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE  "Debug")

# gtest
FILE(GLOB_RECURSE GTEST_SRC gtest/*.cpp gtest/*.cc gtest/*.h)
FILE(GLOB CASE case/*.cpp)

source_group(gtest FILES ${GTEST_SRC})
source_group(case FILES ${CASE})

set(TEST_SRC_ALL ${GTEST_SRC} ${CASE})

# 指定为可执行文件
add_executable(${PROJECT_NAME} ${TEST_SRC_ALL} Test.cpp)

# 头文件引用
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include ${CMAKE_CURRENT_SOURCE_DIR}/gtest ${CMAKE_CURRENT_SOURCE_DIR}/gtest/include)

# lib依赖
target_link_libraries(${PROJECT_NAME} ACM)