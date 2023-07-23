cmake_minimum_required(VERSION 3.25)
project(libjni)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MAJOR_VERSION 0)
set(CMAKE_MINOR_VERSION 0)
set(CMAKE_MINOR_VERSION 2)
set(LIBRARY_OUTPUT_PATH "${CMAKE_HOME_DIRECTORY}/build/shared")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/build/static")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_HOME_DIRECTORY}/build/bin")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_DEBUG_POSTFIX ".debug")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(DEBUG true)
else ()
    set(DEBUG false)
endif ()

set(PROJECT_SOURCE_DIR "${CMAKE_HOME_DIRECTORY}/src")
set(MAIN_SOURCE_DIR "${PROJECT_SOURCE_DIR}")
set(WRAPPER_SOURCE_DIR "${PROJECT_SOURCE_DIR}/wrapper")

aux_source_directory("${MAIN_SOURCE_DIR}" MAIN_SOURCES)
aux_source_directory("${WRAPPER_SOURCE_DIR}" WRAPPER_SOURCES)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

add_library(
    "libreg"
    SHARED
    ${MAIN_SOURCES}
    ${WRAPPER_SOURCES}
)

if (DEBUG)
    add_subdirectory("${PROJECT_SOURCE_DIR}/test")
endif ()
