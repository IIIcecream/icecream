# version
cmake_minimum_required(VERSION 3.1.0)

# project name 杂七杂八
project (DesignPattern)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 开启使用文件夹选项
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB_RECURSE SOURCE_FILES_BehaviorType ./BehaviorType/*.h ./BehaviorType/*.cpp)
file(GLOB_RECURSE SOURCE_FILES_CreationType ./CreationType/*.h ./CreationType/*.cpp)
file(GLOB_RECURSE SOURCE_FILES_StructureType ./StructureType/*.h ./StructureType/*.cpp)
file(GLOB_RECURSE SOURCE_FILES_MAIN ./DesignPatterns/*.cpp)

# 目录结构
source_group(BehaviorType FILES ${SOURCE_FILES_BehaviorType})
source_group(CreationType FILES ${SOURCE_FILES_CreationType})
source_group(StructureType FILES ${SOURCE_FILES_StructureType})

set(AP_ALL ${SOURCE_FILES_BehaviorType}
           ${SOURCE_FILES_CreationType}
		   ${SOURCE_FILES_StructureType}
	）

add_executable(${PROJECT_NAME} ${SOURCE_FILES_MAIN})
