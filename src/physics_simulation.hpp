#pragma once
#include "dimensions.hpp"
#include "raylib.h"
#include <iostream>
using namespace std;

class Physics_Simualtion {
    private:
        Position body_coordinate{0.0f,20.0f,0.0f};
        float radius = 1.0f;
        double gravity_constant = 9.81;
        int selected_planet_index = 1;
        Color selected_color = BLUE;
        vector<string> planets = {"Earth","Mars","Mercury","Venus","Jupiter","Saturn","Uranus","Neptune"};
        bool is_planet_selected=false;
    public:
        const string get_selected_planet() const{return planets[selected_planet_index-1];};
        const float get_x() const{ return body_coordinate.x;};
        const float get_y() const{ return body_coordinate.y;};
        const float get_z() const{ return body_coordinate.z;};
        const Position  get_position() const{ return body_coordinate;};
        const float get_radius() const { return radius;};
        void run_simulation();
        void insert_planet_gravity();
        void update_position();
};