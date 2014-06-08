PROJECT(WorldCupSimulatorProject)
cmake_minimum_required(VERSION 2.8)

#Add dependency paths.
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/json_spirit )
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/json_spirit)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/json-spirit/build {CMAKE_CURRENT_BINARY_DIR}/json-spirit)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/json-spirit/include)

SET(CMAKE_CXX_FLAGS "-std=c++0x")



add_executable(simulator main.cpp
      #stdafx.cpp
      Simulation.cpp
      Team.cpp
      Rule.cpp
      Tournament.cpp
      Match.cpp
      )

target_link_libraries(simulator json_spirit)

