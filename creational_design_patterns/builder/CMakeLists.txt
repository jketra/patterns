cmake_minimum_required(VERSION 3.7)

project(Builder)

file(GLOB _sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB _headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(${PROJECT_NAME} ${_sources} ${_headers})
