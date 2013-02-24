//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    //--------------------------------------------------------------------------
    // Entity 1
    //--------------------------------------------------------------------------
    if(Claw.OnLoad("./claw.png", 150, 150, "./gfx/Claw/ClawData.txt") == false) {
        return false;
    }

    if(TestMap.OnLoad("1.map") == false){
        printf("Can't open mapfile!");
        return false;
    }


    CEntity::EntityList.push_back(&Claw);

    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    return true;
}

//==============================================================================
