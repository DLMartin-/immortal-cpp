cmake_minimum_required(VERSION 3.10)
project(immortal)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)
find_package(fmt REQUIRED)

add_executable(immortal src/main.cpp src/appmain.h src/appmain.cpp)
target_compile_options(immortal PRIVATE -Wall)
target_link_libraries(immortal PRIVATE SDL3::SDL3)
target_link_libraries(immortal PRIVATE fmt::fmt-header-only)

if(CMAKE_BUILD_TYPE MATCHES Debug)
  target_compile_options(immortal PRIVATE -O1)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
  target_compile_options(immortal PRIVATE -O3)
endif()

