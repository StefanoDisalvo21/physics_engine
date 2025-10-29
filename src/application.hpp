#pragma once
#include "raylib.h"
#include "physics_simulation.hpp"
#include <iostream>
using namespace std;

class Application_Exectution{
    private:
        //dimensions of the application screen
        const int dimension_screen_y = 700;
        const int dimension_screen_x = 1000;
    public:
        void run_application();
};