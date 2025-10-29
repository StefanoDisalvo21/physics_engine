#include "application.hpp"
using namespace std;

void Application_Exectution::run_application(){
    //initialize window
    InitWindow(dimension_screen_x,dimension_screen_y,"3D Gravity Simulation");
    //game loop until window cloased closed
    while (!WindowShouldClose())
    {
        //start 
        BeginDrawing();
        //Setting background to black
        ClearBackground(BLACK);
        
        EndDrawing();
    }//end game loop
    //closing window
    CloseWindow();
}//end run app;