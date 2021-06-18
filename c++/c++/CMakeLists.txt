# version
cmake_minimum_required(VERSION 3.1.0)

# project name 杂七杂八
project (ZQZB)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#指定源文件的目录
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} DIR_SRCS)

# 指定为可执行文件
add_executable(${PROJECT_NAME} ${DIR_SRCS})
