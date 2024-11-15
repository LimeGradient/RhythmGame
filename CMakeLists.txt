cmake_minimum_required(VERSION 3.25)
project(RhythmGame)

file(GLOB_RECURSE SOURCES
    src/*.cpp
    include/*.hpp
)

include_directories(include/)

include(cmake/CPM.cmake)
CPMAddPackage("gh:fmtlib/fmt#10.2.1")
CPMAddPackage("gh:gabime/spdlog@1.14.1")

# https://www.studyplan.dev/sdl2-minesweeper/sdl-setup-mac

add_executable(${PROJECT_NAME} ${SOURCES})

if (APPLE)
    set(SDL2 /Library/Frameworks/SDL2.framework)
    set(SDL2_image /Library/Frameworks/SDL2_image.framework)
else()
    include(cmake/FindSDL2.cmake)
    list(APPEND CMAKE_PREFIX_PATH "C:\\vslib\\SDL2-2.30.9")
    list(APPEND CMAKE_PREFIX_PATH "C:\\vslib\\SDL2_image-2.8.2")
    find_package(SDL2 REQUIRED)
    find_package(SDL2_IMAGE REQUIRED)
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC fmt spdlog)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} PUBLIC  ${SDL2}/Versions/A/SDL2 ${SDL2_image}/Versions/A/SDL2_image)
    target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2}/Versions/A/Headers ${SDL2_image}/Versions/A/Headers ${SDL2_ttf}/Versions/A/Headers)
else()
    target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
    target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
endif()