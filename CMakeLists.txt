#set the minimum required version of cmake
cmake_minimum_required(VERSION 3.15)

#naming the project
project(physics_engine_gravity_simulation VERSION 1.0)

#finding raylib
find_package(raylib CONFIG REQUIRED)

#set standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#including subdir
add_subdirectory(src)