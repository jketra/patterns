cmake_minimum_required(VERSION 3.7)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "")
set(CMAKE_MODULES_DIR "${CMAKE_SOURCE_DIR}/cmake_modules")

include("${CMAKE_MODULES_DIR}/Functions.cmake")

# project
#
project(Patterns)

include("${CMAKE_MODULES_DIR}/CompilerOptions.cmake")

# directories
#
add_subdirectory(creational_design_patterns)
