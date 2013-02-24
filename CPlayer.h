#ifndef _CPLAYER_H_
    #define _CPLAYER_H_

#include "CEntity.h"
#include "CEvent.h"

class CPlayer : public CEntity{
    public:
        CPlayer();


        bool OnLoad(char* File, int Width, int Height, char* PlayerData);

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();

        void OnMove(int X, int Y);

        void OnStop();

        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

};


#endif
