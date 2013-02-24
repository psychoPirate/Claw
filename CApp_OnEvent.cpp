//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

//==============================================================================
void CApp::OnExit() {
	Running = false;
}

//==============================================================================
void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_UP: Claw.OnMove(0,-1); break;
        case SDLK_DOWN: Claw.OnMove(0,1); break;
        case SDLK_LEFT:   Claw.MoveLeft = true; break;
        case SDLK_RIGHT:  Claw.MoveRight = true; break;
        case SDLK_ESCAPE: OnExit(); break;

        default: {
        }
    }
}

void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
      switch(sym) {
        case SDLK_UP: break;
        case SDLK_DOWN:  break;
        case SDLK_LEFT:   Claw.MoveLeft = false; break;
        case SDLK_RIGHT:  Claw.MoveRight = false; break;

        default: {
        }
    }
}
