# version
cmake_minimum_required(VERSION 3.1.0)

# project name
project (ACM)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 开启使用文件夹选项
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB _INCLUDE ./include/*.h)

file(GLOB BS_INCLUDE include/binarySearch/*.h)
file(GLOB BS_SOURCE src/binarySearch/*.cpp)

file(GLOB DP_INCLUDE include/dynamicProgramming/*.h)
file(GLOB DP_SOURCE src/dynamicProgramming/*.cpp)

file(GLOB GRAPH_INCLUDE include/graph/*.h)
file(GLOB GRAPH_SOURCE src/graph/*.cpp)

file(GLOB HEAP_INCLUDE include/heap/*.h)
file(GLOB HEAP_SOURCE src/heap/*.cpp)

file(GLOB LL_INCLUDE include/linkedList/*.h)
file(GLOB LL_SOURCE src/linkedList/*.cpp)

file(GLOB MATH_INCLUDE include/math/*.h)
file(GLOB MATH_SOURCE src/math/*.cpp)

file(GLOB RECURSION_INCLUDE include/recursion/*.h)
file(GLOB RECURSION_SOURCE src/recursion/*.cpp)

file(GLOB SCHEDUL_INCLUDE include/scheduling/*.h)
file(GLOB SCHEDUL_SOURCE src/scheduling/*.cpp)

file(GLOB SW_INCLUDE include/slidingWindow/*.h)
file(GLOB SW_SOURCE src/slidingWindow/*.cpp)

file(GLOB SORT_INCLUDE include/sort/*.h)
file(GLOB SORT_SOURCE src/sort/*.cpp)

file(GLOB STACK_INCLUDE include/stack/*.h)
file(GLOB STACK_SOURCE src/stack/*.cpp)

file(GLOB STRING_INCLUDE include/string/*.h)
file(GLOB STRING_SOURCE src/string/*.cpp)

file(GLOB TREE_INCLUDE include/tree/*.h)
file(GLOB TREE_SOURCE src/tree/*.cpp)

file(GLOB OTHER_INCLUDE include/others/*.h)
file(GLOB OTHER_SOURCE src/others/*.cpp)

source_group(Include FILES ${_INCLUDE})

source_group(Include/BinarySearch FILES ${BINARYSEARCH_INCLUDE})
source_group(Include/DynamicProgramming FILES ${DP_INCLUDE})
source_group(Include/Graph FILES ${GRAPH_INCLUDE})
source_group(Include/Heap FILES ${HEAP_INCLUDE})
source_group(Include/LinkedList FILES ${LL_INCLUDE})
source_group(Include/Math FILES ${MATH_INCLUDE})
source_group(Include/Recursion FILES ${RECURSION_INCLUDE})
source_group(Include/Scheduling FILES ${SCHEDUL_INCLUDE})
source_group(Include/SlidingWindow FILES ${SW_INCLUDE})
source_group(Include/Sort FILES ${SORT_INCLUDE})
source_group(Include/Stack FILES ${STACK_INCLUDE})
source_group(Include/String FILES ${STRING_INCLUDE})
source_group(Include/Tree FILES ${TREE_INCLUDE})
source_group(Include/Others FILES ${OTHER_INCLUDE})

source_group(Source/BinarySearch FILES ${BINARYSEARCH_SOURCE})
source_group(Source/DynamicProgramming FILES ${DP_SOURCE})
source_group(Source/Graph FILES ${GRAPH_SOURCE})
source_group(Source/Heap FILES ${HEAP_SOURCE})
source_group(Source/LinkedList FILES ${LL_SOURCE})
source_group(Source/Math FILES ${MATH_SOURCE})
source_group(Source/Recursion FILES ${RECURSION_SOURCE})
source_group(Source/Scheduling FILES ${SCHEDUL_SOURCE})
source_group(Source/SlidingWindow FILES ${SW_SOURCE})
source_group(Source/Sort FILES ${SORT_SOURCE})
source_group(Source/Stack FILES ${STACK_SOURCE})
source_group(Source/String FILES ${STRING_SOURCE})
source_group(Source/Tree FILES ${TREE_SOURCE})
source_group(Source/Others FILES ${OTHER_SOURCE})

set(AP_ALL  ${_INCLUDE}
            ${BINARYSEARCH_INCLUDE} ${DP_INCLUDE} ${GRAPH_INCLUDE} ${HEAP_INCLUDE} ${LL_INCLUDE} ${MATH_INCLUDE} ${RECURSION_INCLUDE} ${SCHEDUL_INCLUDE}
            ${SW_INCLUDE} ${SORT_INCLUDE} ${STACK_INCLUDE} ${STRING_INCLUDE} ${TREE_INCLUDE} ${OTHER_INCLUDE}
	        ${BINARYSEARCH_SOURCE} ${DP_SOURCE} ${GRAPH_SOURCE} ${HEAP_SOURCE} ${LL_SOURCE} ${MATH_SOURCE} ${RECURSION_SOURCE} ${SCHEDUL_SOURCE}
		    ${SW_SOURCE} ${SORT_SOURCE} ${STACK_SOURCE} ${STRING_SOURCE} ${TREE_SOURCE} ${OTHER_SOURCE})


# 生成静态库
add_library(${PROJECT_NAME} STATIC ${AP_ALL})
# 动态库为：add_library(${PROJECT_NAME} SHARED ${AP_ALL})
# 可执行文件为：add_executable(${PROJECT_NAME} ${AP_ALL})

# 设置包含的目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 开启demo及单测
add_subdirectory("./Demo")
add_subdirectory("./Test")

# debug开关
if(ENABLE_DEBUG)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
endif()