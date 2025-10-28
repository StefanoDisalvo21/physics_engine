#set the minimum required version of cmake
cmake_minimum_required(VERSION 3.15)

#naming the project
project(physics_engine_gravity_simulation VERSION 1.0)

#finding raylib
find_package(raylib CONFIG REQUIRED)

#set standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#creating library composed of various file
add_library(physics_engine
    src/physics_simulation.cpp
    src/application.cpp
)

#including headers
target_include_directories(physics_engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#adding executable
add_executable(simulation_physics src/main.cpp)

#linking libraries
target_link_libraries(simulation_physics PRIVATE physics_engine)
target_link_libraries(simulation_physics PRIVATE ${RAYLIB_LIBRARIES})