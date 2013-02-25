#include "CMap.h"

CMap::CMap()
{
    Surf_Tileset = NULL;
    Width = 5;
    Height = 5;

}

bool CMap::OnLoad(char* File)
{
    TileList.clear();

    if((Surf_Tileset = CSurface::OnLoad("./gfx/Levels/LEVEL1/spritesheets/action.png")) == NULL)
    {
        return false;
    }

    FILE* FileHandle = fopen(File, "r");

    if(FileHandle == NULL)
    {
        return false;
    }

    for(int Y = 0; Y < Height; Y++)
    {
        for(int X = 0; X < Width; X++)
        {
            CTile tempTile;

            fscanf(FileHandle, "%d:%d ", &tempTile.TileID, &tempTile.TypeID);

            TileList.push_back(tempTile);
        }
        fscanf(FileHandle, "\n");
    }

    fclose(FileHandle);

    return true;
}

void CMap::OnRender(SDL_Surface* Surf_Display, int MapX, int MapY)
{
    int TILE_SIZE = 64;
    if(Surf_Tileset == NULL) return;

    int TilesetWidth  = Surf_Tileset->w / TILE_SIZE;
    int TilesetHeight = Surf_Tileset->h / TILE_SIZE;

    int ID = 0;

    for(int Y = 0; Y < Height; Y++)
    {
        for(int X = 0; X < Width; X++)
        {
            /*if (TileList[ID].TypeID == 0){
                continue;
                ID++;
            }*/


            CSurface::OnDraw(Surf_Display, Surf_Tileset, TILE_SIZE*X, TILE_SIZE*Y, 0, TileList[ID].TileID * TILE_SIZE, TILE_SIZE, TILE_SIZE);

            ID++;
        }
    }
}



