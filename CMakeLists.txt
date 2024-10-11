cmake_minimum_required(VERSION 3.16)
project(SFINAE CXX)

set(CMAKE_CXX_STANDARD  17)

include_directories(SFINAE_1 PRIVATE "${PROJECT_SOURCE_DIR}/inc")

function(add_sfinae_executable target_name source_file)
    add_executable(${target_name} ${source_file})
endfunction()

add_sfinae_executable(SFINAE_0 src/SFINAE_0.cpp)
add_sfinae_executable(SFINAE_1 src/SFINAE_1.cpp)
add_sfinae_executable(SFINAE_2 src/SFINAE_2.cpp)
add_sfinae_executable(SFINAE_3 src/SFINAE_3.cpp)
add_sfinae_executable(SFINAE_4 src/SFINAE_4.cpp)
add_sfinae_executable(SFINAE_5 src/SFINAE_5.cpp)
