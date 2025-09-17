cmake_minimum_required(VERSION 3.31)
project(breadth_first_graph_traversal)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(breadth_first_graph_traversal
        task_1.cpp
        task_2.cpp
        task_3.cpp
        task_4.cpp
        task_5.cpp)

add_executable(Test1 task_1.cpp)
add_executable(Test2 task_2.cpp)
add_executable(Test3 task_3.cpp)
add_executable(Test4 task_4.cpp)
add_executable(Test5 task_5.cpp)

target_compile_options(breadth_first_graph_traversal PRIVATE -Wextra -Werror)
