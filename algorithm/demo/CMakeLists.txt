cmake_minimum_required(VERSION 3.1.0)

project (Demo)

# Use C++11...
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE  "Debug")


# 指定为可执行文件
add_executable(${PROJECT_NAME} ./main.cpp)

# 头文件引用
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

# lib依赖
target_link_libraries(${PROJECT_NAME} ACM)