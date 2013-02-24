//==============================================================================
#include "CApp.h"

//==============================================================================
CApp::CApp() {
    Surf_Display = NULL;

    Running = true;
}

//TODO Create FPS class
//TODO Create class to handle collisions
//TODO Create classes for TILE, MAP and levels
//TODO Create a debug classe (debug.log, debug.DrawRect)

//------------------------------------------------------------------------------
int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

//==============================================================================
int main(int argc, char* argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}

//==============================================================================
