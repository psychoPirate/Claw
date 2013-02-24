//==============================================================================
#ifndef _CENTITY_H_
    #define _CENTITY_H_

#include <vector>

#include "CAnimation.h"
#include "CSurface.h"

//==============================================================================
class CEntity {
    public:
        static std::vector<CEntity*>    EntityList;

    protected:
        CAnimation      Anim_Control;

        SDL_Surface*    Surf_Entity;

        enum{
            RIGHT = 0,
            LEFT,
        };

        enum {
            IDLE = 0,
            WALK,
            JUMP,
            FALL,
            DEAD,
            ATACK1,
            ATACK2,
        };

    public:
        int X;
        int Y;

        int Width;
        int Height;

        bool MoveLeft, MoveRight;

        int SpeedX;
        int SpeedY;

        int CurrentRow;
        int CurrentCol;

        int AnimState;
        int State;

	public:
		CEntity();

	public:
        virtual bool OnLoad(char* File, int Width, int Height, char* EntityData);

        virtual void OnLoop();

		virtual void OnRender(SDL_Surface* Surf_Display);

		virtual void OnCleanup();


		virtual void OnMove(int x, int y);

		virtual void OnStop();

		virtual void OnAnimate();
};

//==============================================================================

#endif
