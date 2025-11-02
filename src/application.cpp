#include "application.hpp"
using namespace std;

void Application_Exectution::run_application(){
    //initialize window
    InitWindow(dimension_screen_x,dimension_screen_y,"3D Gravity Simulation");
    SetTargetFPS(60);
    //initialize 3D camera for the environment
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 15.0f, 250.0f, 20.0f };
    camera.target = (Vector3){ 0.0f, 10.0f, 0.0f };     
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };         
    camera.fovy = 45.0f;                               
    camera.projection = CAMERA_PERSPECTIVE;
    //Intialize the object for the physics computations
    Physics_Simualtion p_body;
    //game loop until window cloased closed
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(VIOLET);
        BeginMode3D(camera);
        p_body.run_simulation();
        EndMode3D();
        EndDrawing();
    }//end game loop
    //closing window
    CloseWindow();
}//end run app