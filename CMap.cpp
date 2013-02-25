#include "CMap.h"

CMap::CMap()
{
    Surf_Tileset = NULL;


}

//TODO Fix problem of only load 1 digit tiles

bool CMap::OnLoad(char* File)
{
    TileList.clear();

    if((Surf_Tileset = CSurface::OnLoad("./gfx/Levels/LEVEL1/spritesheets/action.png")) == NULL)
    {
        return false;
    }

    char line[1000000];
    char param1[30];
    char param2[30];
    char function[30];
    int nparam1, nparam2;

    FILE* FileHandle = fopen(File, "r");

    if(FileHandle == NULL)
    {
        printf("Can't open %s\n", File);
        return false;
    }

    while (fgets(line, sizeof line, FileHandle))
    {

        // Ignore comments
        if (*line == '#') continue;

        if(*line != 'EOF')
        {

            sscanf(line,"%s %s %d x %d",function, param1, &nparam1, &nparam2);
            sscanf(line, "%s %s", function, param1);

            if (strcmp(function, "map") == 0)
            {
                if(strcmp(param1, "size") == 0)
                {
                    Width  = nparam1;
                    Height = nparam2;
                    printf("\nWidth: %d Height: %d\n", Width, Height);

                    //Set function to none because can cause repetions case the next
                    //lines don't have functions to change the function variable
                }

                if(strcmp(param1, "setGrid") == 0)
                {

                    //Jump to grid
                    fgets(line, sizeof line, FileHandle);

                    int Y = 0;
                    int XWidth = 0;
                    int tempTileID = -1, tempTypeID = -1;

                    //Loop through the grid
                    do
                    {
                        XWidth = 0;
                        //Printf current line
                        for (int X = 0; line[X] !='\n'; X++)
                        {
                            //Create temporary Tile
                            if(line[X] == ' ' || line[X] == ':' )
                                continue;

                            if(line[X+1] == ':')
                            {
                                tempTileID=0;
                                if(X > 0 && line[X-1] != ' ')
                                {
                                    tempTileID = atoi(&line[X-1]);
                                }
                                else
                                    tempTileID = atoi(&line[X]);
                            }

                            if(line[X-1] == ':')
                            {
                                tempTypeID = atoi(&line[X]); //Assign tileType
                            }




                            if(tempTileID != -1 && tempTypeID != -1)
                            {
                                CTile tempTile;
                                tempTile.TileID = tempTileID;
                                tempTile.TypeID = tempTypeID;
                                TileList.push_back(tempTile);
                                tempTileID = -1;
                                tempTypeID = -1;
                                printf("Tile ID: %d Type ID %d\n", tempTile.TileID, tempTile.TypeID);
                                XWidth++;
                            }
                        }

                        fgets(line, sizeof line, FileHandle);
                        sscanf(line, "%*s %s",param1);
                        Y++;
                    }
                    while(strcmp(param1, "endSetGrid") != 0);

                    if(Width != XWidth || Height != Y)
                        Width = XWidth;
                    Height = Y;
                }
                function[0] = '\0';
            }

        }

    }

    fclose(FileHandle);
    printf("Numero de tiles %d", TileList.size());

    return true;
}

void CMap::OnRender(SDL_Surface* Surf_Display, int MapX, int MapY)
{
    int TILE_SIZE = 64;
    if(Surf_Tileset == NULL) return;

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



