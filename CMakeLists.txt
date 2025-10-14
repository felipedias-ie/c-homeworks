cmake_minimum_required(VERSION 3.21)
project(Homework C)

set(PROJECT_AUTHOR "Raul P. Pelaez")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)
enable_testing()
add_subdirectory(src)
add_subdirectory(tests)