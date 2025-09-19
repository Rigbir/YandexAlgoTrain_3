cmake_minimum_required(VERSION 3.31)
project(additional)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(additional
        task_1.cpp
        task_2.cpp
        task_3.cpp
        task_4.cpp
        task_5.cpp
        task_6.cpp
        task_7.cpp
        task_8.cpp
        task_9.cpp
        task_10.cpp)

add_executable(Test1 task_1.cpp)
add_executable(Test2 task_2.cpp)
add_executable(Test3 task_3.cpp)
add_executable(Test4 task_4.cpp)
add_executable(Test5 task_5.cpp)
add_executable(Test6 task_6.cpp)
add_executable(Test7 task_7.cpp)
add_executable(Test8 task_8.cpp)
add_executable(Test9 task_9.cpp)
add_executable(Test10 task_10.cpp)

target_compile_options(additional PRIVATE -Wextra -Werror)
