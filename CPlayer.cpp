#include "CPlayer.h"

CPlayer::CPlayer() {
}

bool CPlayer::OnLoad(char* File, int Width, int Height, char* PlayerData) {
    if(CEntity::OnLoad(File, Width, Height, PlayerData) == false) {
        return false;
    }

    return true;
}

void CPlayer::OnLoop() {
    CEntity::OnLoop();
}

void CPlayer::OnRender(SDL_Surface* Surf_Display) {
    CEntity::OnRender(Surf_Display);
}

void CPlayer::OnCleanup() {
    CEntity::OnCleanup();
}

void CPlayer::OnAnimate() {

        CEntity::OnAnimate();
}

void CPlayer::OnMove(int X, int Y){
    CEntity::OnMove(X, Y);
}

void CPlayer::OnStop(){
    CEntity::OnStop();
}



