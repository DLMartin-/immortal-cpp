cmake_minimum_required(VERSION 3.10)
project(immortal)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)

add_executable(immortal src/main.cpp)
target_link_libraries(immortal PRIVATE SDL3::SDL3)

