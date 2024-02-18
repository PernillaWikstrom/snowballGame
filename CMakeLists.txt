cmake_minimum_required(VERSION  3.16)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
project(snowballGame VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF) # Dont use extensions between C and CXX unless you know that it's needed

set(MY_LIBRARY Library)
set(MY_EXECUTABLE Executable)


set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

find_package(SFML 2.5
    COMPONENTS
    system window graphics network audio REQUIRED)

add_subdirectory(configured)
add_subdirectory(src)
add_subdirectory(app)
