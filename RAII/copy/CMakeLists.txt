cmake_minimum_required(VERSION 3.10)
project(CopyDemoProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件目标
# 现在包含所有相关的源文件
add_executable(CopyDemo
        main.cpp
        shallow_string.cpp
        deep_string.cpp
        )

# (可选) 如果你的头文件在其他地方 (例如一个 'include' 目录)
# 你可能需要添加:
# target_include_directories(CopyDemo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# 或者如果头文件和源文件在同一目录，通常不需要显式添加 include_directories
# 因为编译器默认会查找当前目录。

message(STATUS "CMake configured for CopyDemoProject with multiple files.")