# version
cmake_minimum_required(VERSION 3.1.0)

# project name 杂七杂八
project (DesignPattern)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 开启使用文件夹选项
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB_RECURSE BehaviorType_Iterator ./BehaviorType/Iterator/*.h ./BehaviorType/Iterator/*.cpp)
file(GLOB_RECURSE BehaviorType_Observer ./BehaviorType/Observer/*.h ./BehaviorType/Observer/*.cpp)

file(GLOB_RECURSE CreationType_Factory ./CreationType/Factory/*.h ./CreationType/Factory/*.cpp)
file(GLOB_RECURSE CreationType_Singleton ./CreationType/Singleton/*.h ./CreationType/Singleton/*.cpp)

file(GLOB_RECURSE StructureType_Composite ./StructureType/Composite/*.h ./StructureType/Composite/*.cpp)

file(GLOB_RECURSE MAIN ./DesignPatterns/*.cpp)

# 目录结构
source_group(BehaviorType/Iterator FILES ${BehaviorType_Iterator})
source_group(BehaviorType/Observer FILES ${BehaviorType_Observer})

source_group(CreationType/Factory FILES ${CreationType_Factory})
source_group(CreationType/Singleton FILES ${CreationType_Singleton})

source_group(StructureType/Composite FILES ${StructureType_Composite})

set(AP_ALL ${BehaviorType_Iterator} ${BehaviorType_Observer}
		   ${CreationType_Factory} ${CreationType_Singleton}
		   ${StructureType_Composite}
		   ${MAIN})

add_executable(${PROJECT_NAME} ${AP_ALL})
