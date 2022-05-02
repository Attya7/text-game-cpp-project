# CMakeList.txt : CMake project for Ex1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# set the project name

project(project)

# Add source to this project's executable.
add_executable (project "player.cpp" "player.h" "monster.cpp" "monster.h" "main.cpp" "main.h")

# TODO: Add tests and install targets if needed.
