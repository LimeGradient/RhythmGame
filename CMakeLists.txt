cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
project(RhythmGame)

file(GLOB_RECURSE SOURCES
    src/*.cpp
    include/*.hpp
)

include_directories(include/)

include(cmake/CPM.cmake)
CPMAddPackage("gh:fmtlib/fmt#10.2.1")
CPMAddPackage("gh:gabime/spdlog@1.14.1")
CPMAddPackage("gh:jeremy-rifkin/cpptrace#v0.7.3")
CPMAddPackage("gh:SFML/SFML#2.6.2")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC fmt spdlog cpptrace::cpptrace sfml-graphics)