cmake_minimum_required(VERSION 3.15)
project(DaemonLord LANGUAGES CXX)

set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, defaulting to Debug")
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type: Debug or Release" FORCE)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g3 -DNDEBUG")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_VISIBILITY_PRESET hidden)
    set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Enabling AddressSanitizer")
    set(ASAN_FLAGS "-fsanitize=address -fno-omit-frame-pointer")

    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${ASAN_FLAGS}")
    set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} ${ASAN_FLAGS}")
endif()

add_library(engine SHARED
  src/platform/window_linux.cpp
  src/platform/platform_linux.cpp
  src/core/window.cpp
  src/core/application.cpp
  src/subsystems/events.cpp
  src/subsystems/input.cpp
)

target_include_directories(engine
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(XCB REQUIRED xcb)
pkg_check_modules(XCB_KEYSYMS REQUIRED xcb-keysyms)

target_include_directories(engine
  PRIVATE
    ${XCB_INCLUDE_DIRS}
    ${XCB_KEYSYMS_INCLUDE_DIRS}
)

target_link_libraries(engine
  PRIVATE
    ${XCB_LIBRARIES}
    ${XCB_KEYSYMS_LIBRARIES}
)
