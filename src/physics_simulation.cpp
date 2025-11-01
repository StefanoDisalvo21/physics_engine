#include "physics_simulation.hpp"
using namespace std;

void Physics_Simualtion::run_simulation(){
    //simulation
    Vector3 myTempVect{body_coordinate.x,body_coordinate.y,body_coordinate.z};
    DrawSphere(myTempVect,radius,LIGHTGRAY);
}