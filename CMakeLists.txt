cmake_minimum_required(VERSION 3.24)

project(
    ThreadPerformanceDemontration 
    VERSION 1.0
    DESCRIPTION "Demonstration on multi-threading vs single-threading and the performance implications" 
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(tdp ${SOURCES} )

