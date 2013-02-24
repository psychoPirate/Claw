//==============================================================================
#include "CEntity.h"
#include <string.h>

//==============================================================================
std::vector<CEntity*> CEntity::EntityList;

//==============================================================================
CEntity::CEntity() {
    Surf_Entity = NULL;

    X = Y = 0;
    SpeedX = SpeedY = 1;

    Width = Height = 0;

    MoveLeft = false;
    MoveRight = false;

    AnimState = 0;
    State = 0;
    CurrentCol = RIGHT;

}

//==============================================================================
bool CEntity::OnLoad(char* File, int Width, int Height, char* EntityData) {
	if((Surf_Entity = CSurface::OnLoad(File)) == NULL) {
		return false;
	}


	//Number of animations
    int NumberAnimations = 0, Animation, NumberFrames;
    char line[100];
    char function[30];
    char* parameter1;
    char* parameter2;




    //Open file to Read Entity information about animation frames life and others things
    //TODO Encript file and then decript after load (extension .claw
    FILE* FileHandle = fopen(EntityData, "r");

    if(FileHandle == NULL){
        printf("Can't open %s\n\n", EntityData);
        return false;
    }

    while (fgets(line, sizeof line, FileHandle)) {

        // Ignore comments
        if (*line == '#') continue;

        if(*line != 'EOF'){
            //Read animation number and number of frames
            sscanf(line,"%s %*s %d %*s %d",function, &Animation, &NumberFrames);
            //printf("\n%s\n", function);
            if (strcmp(function, "animation") == 0){
                  //Print animation number and number of frames (for debug purpose)
                //printf("Animation %d : NFrames %d\n", Animation, NumberFrames);

                Anim_Control.SetAnimationFrames(Animation, NumberFrames);

                //Increment number of animations
                NumberAnimations++;
            }


        }

    }

    //printf("Number of Animations : %d\n", NumberAnimations);

    //Loop throw to all animations
    /*
    for(int i; i < NumberAnimations; i++){
        fscanf(FileHandle, "%d : %d", &Animation, &NumberFrames);
        printf("Animation %d : NFrames %d\n", Animation, NumberFrames);
        Anim_Control.SetAnimationFrames(Animation, NumberFrames);
    }*/
    fclose(FileHandle);


	this->Width = Width;
	this->Height = Height;
	Anim_Control.MaxFrames = Anim_Control.GetAnimationFrames(AnimState);


    return true;
}

//------------------------------------------------------------------------------
void CEntity::OnLoop() {
    int A = 0, B = 0;

    if(MoveLeft)
        A = -SpeedX;
    else if(MoveRight)
        A = SpeedX;

    if (MoveLeft || MoveRight)
        OnMove(A, B);
    else
        OnStop();

    OnAnimate();
}

//------------------------------------------------------------------------------
void CEntity::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;

    CSurface::OnDraw(Surf_Display, Surf_Entity, X, Y, AnimState * Width ,(Anim_Control.GetCurrentFrame() + (Anim_Control.MaxFrames * CurrentCol )) * Height, Width, Height);
}

//------------------------------------------------------------------------------
void CEntity::OnCleanup() {
    if(Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }

    Surf_Entity = NULL;
}

void CEntity::OnMove(int x, int y){
    State = WALK;
    X += x;
    Y += y;
}

void CEntity::OnStop(){
    State = IDLE;

}

void CEntity::OnAnimate(){
    if (MoveLeft)
        CurrentCol = LEFT;
    else if (MoveRight)
        CurrentCol = RIGHT;

    Anim_Control.OnAnimate(CurrentCol);

    if (AnimState != State){
        AnimState = State;
        Anim_Control.MaxFrames = Anim_Control.GetAnimationFrames(AnimState);
        Anim_Control.SetCurrentFrame(0);
    }
}



//==============================================================================
