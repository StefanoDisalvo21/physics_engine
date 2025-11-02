#include "physics_simulation.hpp"
using namespace std;

void Physics_Simualtion::run_simulation(){
    //simulation
    //starting
    Vector3 sphere_position{body_coordinate.x,body_coordinate.y,body_coordinate.z};
    DrawSphere(sphere_position,radius,LIGHTGRAY);

}

//updating position
void Physics_Simualtion::update_position(){
    
}