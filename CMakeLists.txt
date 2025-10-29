# set the minimum required version of cmake
cmake_minimum_required(VERSION 3.15)

# naming the project
project(physics_engine_gravity_simulation VERSION 1.0)

# set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# try to find raylib via CMake
find_package(raylib QUIET)

if (NOT raylib_FOUND)
    message(STATUS "Raylib not found via CMake, using Homebrew path manually")
    set(RAYLIB_INCLUDE_DIR /opt/homebrew/opt/raylib/include)
    set(RAYLIB_LIB_DIR /opt/homebrew/opt/raylib/lib)
    set(RAYLIB_LIBRARIES ${RAYLIB_LIB_DIR}/libraylib.a)
else()
    set(RAYLIB_INCLUDE_DIR ${raylib_INCLUDE_DIRS})
    set(RAYLIB_LIBRARIES ${raylib_LIBRARIES})
endif()

# Create library
add_library(physics_engine
    src/physics_simulation.cpp
    src/application.cpp
)

target_include_directories(physics_engine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${RAYLIB_INCLUDE_DIR}
)

target_link_libraries(physics_engine PRIVATE ${RAYLIB_LIBRARIES})

# Add executable
add_executable(simulation_physics src/main.cpp)

target_include_directories(simulation_physics PRIVATE
    ${RAYLIB_INCLUDE_DIR}
)

target_link_libraries(simulation_physics PRIVATE
    physics_engine
    ${RAYLIB_LIBRARIES}
    "-framework CoreVideo"
    "-framework OpenGL"
    "-framework IOKit"
    "-framework Cocoa"
    "-framework AudioToolbox"
)
