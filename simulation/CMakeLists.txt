PROJECT(WorldCupSimulatorProject)
cmake_minimum_required(VERSION 2.8)

#Add dependency paths.
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/)
#add_subdirectory(deps)

SET(CMAKE_CXX_FLAGS "-std=c++0x")

add_executable(simulator main.cpp
      #stdafx.cpp
      Simulation.cpp
      Team.cpp
      Rule.cpp
      Tournament.cpp
      Match.cpp

      )
