cmake_minimum_required(VERSION 3.7)

if (WIN32 AND DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE
            STRING "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
    message(STATUS "Set CMake toolchain file ${CMAKE_TOOLCHAIN_FILE}")
endif()


set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "")
set(CMAKE_MODULES_DIR "${CMAKE_SOURCE_DIR}/cmake_modules")

include("${CMAKE_MODULES_DIR}/Functions.cmake")

# project
#
project(Patterns)

include("${CMAKE_MODULES_DIR}/CompilerOptions.cmake")

enable_testing()
find_package(GTest REQUIRED)

# directories
#
add_subdirectory(behavioral)
add_subdirectory(creational)
add_subdirectory(tests)
