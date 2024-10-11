cmake_minimum_required(VERSION 3.16)
project(SFINAE CXX)

set(CMAKE_CXX_STANDARD  17)

add_executable(BASE
        src/base.cpp)

add_executable(SFINAE_1
        src/SFINAE_1.cpp)

target_include_directories(SFINAE_1 PRIVATE "${PROJECT_SOURCE_DIR}/inc")

add_executable(SFINAE_2
        src/SFINAE_2.cpp)

target_include_directories(SFINAE_2 PRIVATE "${PROJECT_SOURCE_DIR}/inc")
