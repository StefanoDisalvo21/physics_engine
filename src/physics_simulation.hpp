#pragma once
#include "dimensions.hpp"
#include "raylib.h"
#include <iostream>
using namespace std;

class Physics_Simualtion {
    private:
        Position body_coordinate{0.0f,200.0f,0.0f};
        float radius = 1.0f;
    public:
        const float get_x() const{ return body_coordinate.x;};
        const float get_y() const{ return body_coordinate.y;};
        const float get_z() const{ return body_coordinate.z;};
        const Position  get_position() const{ return body_coordinate;}
        const float get_radius() const { return radius;}
        void run_simulation();
        void update_position();
};