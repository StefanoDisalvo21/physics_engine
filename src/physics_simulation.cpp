#include "physics_simulation.hpp"
using namespace std;

void Physics_Simualtion::run_simulation(){
    //simulation
    //drawing the sphere
    Vector3 sphere_position{body_coordinate.x,body_coordinate.y,body_coordinate.z};
    DrawSphere(sphere_position,radius,selected_color);
    //check to start
    if(IsKeyPressed(KEY_ZERO)){
        //preventing from changing planets until reset
        speed=0;
        is_planet_selected=true;
        is_simulation_running=true;
    }
    else if(IsKeyPressed(KEY_R)){
        //reset the possibility to change planet
        is_planet_selected=false;
        is_simulation_running=false;
        //reset body coordinates
        body_coordinate.y=30.0f;
    }

    if(is_simulation_running==true){
        update_position();
    }
}

//updating position
void Physics_Simualtion::update_position(){
    //variables
    float delta_time=0;
    delta_time=GetFrameTime();
    speed += gravity_constant*delta_time;
    body_coordinate.y-= (speed*delta_time);
    //test phase - not implemented yet
    if(body_coordinate.y<=ground){
        body_coordinate.y=ground;
        speed=0;
        return;
    }
}

void Physics_Simualtion::insert_planet_gravity(){
    //checking if the wanted planet has been selected
    if(is_planet_selected==false){
        if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_THREE) || IsKeyPressed(KEY_FOUR) || 
            IsKeyPressed(KEY_FIVE) || IsKeyPressed(KEY_SIX) || IsKeyPressed(KEY_SEVEN) || IsKeyPressed(KEY_EIGHT)) {
            // Get the key that was pressed.
            int key = GetKeyPressed();
            switch (key) {
                case KEY_ONE: // Earth
                    gravity_constant = 9.81;
                    selected_planet_index = 1;
                    selected_color = BLUE;
                    break;
                case KEY_TWO: // Mars
                    gravity_constant = 3.71;
                    selected_planet_index = 2;
                    selected_color = RED;
                    break;
                case KEY_THREE: // Mercury
                    gravity_constant = 3.70;
                    selected_planet_index = 3;
                    selected_color = GRAY;
                    break;
                case KEY_FOUR: // Venus
                    gravity_constant = 8.87;
                    selected_planet_index = 4;
                    selected_color = BEIGE;
                    break;
                case KEY_FIVE: // Jupiter
                    gravity_constant = 24.79;
                    selected_planet_index = 5;
                    selected_color = ORANGE;
                    break;
                case KEY_SIX: // Saturn
                    gravity_constant = 10.44;
                    selected_planet_index = 6;
                    selected_color = YELLOW;
                    break;
                case KEY_SEVEN: // Uranus
                    gravity_constant = 8.87;
                    selected_planet_index = 7;
                    selected_color = LIME;
                    break;
                case KEY_EIGHT: // Neptune
                    gravity_constant = 11.15;
                    selected_planet_index = 8;
                    selected_color = DARKBLUE;
                    break;
                default:
                    // No planet key pressed
                    break;
            }//end switch  
        }//end if - key selection
    }//end if- planet selected checking
}//end procedure