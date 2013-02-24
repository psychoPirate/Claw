//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() {
    SDL_FillRect(Surf_Display,NULL, 0x000000);
    //--------------------------------------------------------------------------
    // Render Map
    //--------------------------------------------------------------------------
    TestMap.OnRender(Surf_Display,0,0);
    //--------------------------------------------------------------------------
    // Render Entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnRender(Surf_Display);
    }

	SDL_Flip(Surf_Display);
}

//==============================================================================
