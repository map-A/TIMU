cmake_minimum_required(VERSION 3.17)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(Contest)
add_subdirectory(NC)
add_subdirectory(leetcode)
add_executable(main main.cpp)
