cmake_minimum_required(VERSION 3.10)
project(CPP_Rules_Test)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加所有源文件
set(SOURCES
    main.cpp
    ZeroRuleClass.cpp
    ThreeRuleClass.cpp
    FiveRuleClass.cpp
        ../copy/main.cpp
)

# 添加可执行文件
add_executable(test_35Principles ${SOURCES})

# 为 ThreeRuleCounterExample.cpp 添加新的可执行目标
add_executable(ThreeRuleCounterExample ThreeRuleCounterExample.cpp)