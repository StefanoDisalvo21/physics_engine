#creating library composed of various file
add_library(physics_engine
    physics_simulation.cpp
    application.cpp
)

#including headers
target_include_directories(physics_engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#adding executable
add_executable(simulation_physics main.cpp)

#linking libraries
target_link_libraries(simulation_physics PRIVATE physic_engine)
