#include "graphics.h"
#include "SpaceInvadersGame.h"
#include <string>
#include "Configuration.h"
using namespace std;

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
    // Prosvasi sto paixnidi
    SpaceInvadersGame* p = (SpaceInvadersGame*)graphics::getUserData();

    // kalei tin update gia olo to paixnidi
    p->update_objects();
}

// The window content drawing function.
void draw()
{
    // Prosvasi sto paixnidi
    SpaceInvadersGame* p = (SpaceInvadersGame*)graphics::getUserData();

    // kalei tin draw gia olo to paixnidi
    p->draw_objects();
}

int main()
{
    graphics::createWindow( window_width , window_height, window_title);

    // Draw kai update gia tin apeikonisi tou paixnidiou
    graphics::setUpdateFunction(update);
    graphics::setDrawFunction(draw);
    

    // Orismos rythmisewn kamva
    graphics::setCanvasSize( canvas_width, canvas_height);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    // Orismos maurou xrwmatos paraskiniou
    graphics::Brush br;
    
    br.fill_color[0] = 0.94;       // Red
    br.fill_color[1] = 0.63;       // Green
    br.fill_color[2] = 0.13;       // Blue
    graphics::setWindowBackground(br);

    // Orismos grammatoseiras Space Invaders apo to https://thefontsmagazine.com/font/space-invaders-font/
    graphics::setFont(string(assets_path)+"space_invaders.ttf");


    // Orismos tis klasis SpaceInvadersGame sto userdata
    SpaceInvadersGame sigame;
    graphics::setUserData( &sigame );

    // Wste na paixei mousiki
    graphics::playSound(string(assets_path) + "retro_sound.wav", 0.7f, true);

    // Ekkinisi tou paixnidiou
    graphics::startMessageLoop();

    return 0;
}
