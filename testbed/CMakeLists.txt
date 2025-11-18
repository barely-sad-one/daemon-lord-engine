cmake_minimum_required(VERSION 3.15)
project(DaemonLord LANGUAGES CXX)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, defaulting to Debug")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type: Debug or Release" FORCE)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g3 -DNDEBUG")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})

set(ENGINE_DIR "${CMAKE_SOURCE_DIR}/../engine/build/${CMAKE_BUILD_TYPE}")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Enabling AddressSanitizer")
    set(ASAN_FLAGS "-fsanitize=address -fno-omit-frame-pointer")

    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${ASAN_FLAGS}")
    set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} ${ASAN_FLAGS}")
endif()

add_executable(testbed src/main.cpp)

add_library(engine_lib SHARED IMPORTED)
set_target_properties(engine_lib PROPERTIES IMPORTED_LOCATION "${ENGINE_DIR}/libengine.so")

target_link_libraries(testbed PRIVATE engine_lib)
target_include_directories(testbed PRIVATE "${CMAKE_SOURCE_DIR}/../engine/src")

set_target_properties(testbed PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "${ENGINE_DIR}"
)

