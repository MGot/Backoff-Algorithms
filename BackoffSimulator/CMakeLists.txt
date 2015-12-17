cmake_minimum_required(VERSION 3.3)
project(BackoffSimulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES SimulatorMainClass.cpp "Backoff options/BinaryExponentialBackoff.cpp" "Backoff options/BinaryExponentialBackoff.h" SimulationClass.cpp SimulationClass.h "Backoff options/NodeClass.cpp" "Backoff options/NodeClass.h" "Backoff options/ConstantBackoff.cpp" "Backoff options/ConstantBackoff.h" "Backoff options/AdditiveBackoff.cpp" "Backoff options/AdditiveBackoff.h" "Backoff options/LogarithmicBackoff.cpp" "Backoff options/LogarithmicBackoff.h")
add_executable(BackoffSimulator ${SOURCE_FILES})