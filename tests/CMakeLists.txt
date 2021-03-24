cmake_minimum_required(VERSION 3.7)

project(PatternsTests)

set(_sources PatternsTests.cpp)
set(_headers SingletonTests.h
             StrategyTests.h)

add_executable(${PROJECT_NAME} ${_sources} ${_headers})

target_link_libraries(${PROJECT_NAME} PRIVATE
	GTest::GTest
	Behavioral
	Creational
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
