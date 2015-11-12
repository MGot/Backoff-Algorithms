cmake_minimum_required(VERSION 3.3)
project(BackoffSimulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES SimulatorMainClass.cpp "Backoff options/StaticSimulationClass.cpp" "Backoff options/StaticSimulationClass.h" SimulationClass.cpp SimulationClass.h "Backoff options/NodeClass.cpp" "Backoff options/NodeClass.h")
add_executable(BackoffSimulator ${SOURCE_FILES})