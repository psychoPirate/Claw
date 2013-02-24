#Makefile for Claw
#Made by Luís Mota aka Gold Monkey

# Compiler
CC=gcc

# Objects
OBJECTS=CAnimation.o CApp.o CApp_OnCleanup.o CApp_OnEvent.o CApp_OnInit.o CApp_OnLoop.o CApp_OnRender.o CEntity.o CEvent.o CSurface.o CEntity.o CPlayer.o 

# Compiler flags
CPPFLAGS=-Wall -g `sdl-config --cflags`

# Linker flags
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image

main: CApp.cpp
	$(CC) $(CPPFLAGS) -c CAnimation.cpp CApp.cpp CApp_OnCleanup.cpp CApp_OnEvent.cpp CApp_OnInit.cpp CApp_OnLoop.cpp CApp_OnRender.cpp CEntity.cpp CEvent.cpp CSurface.cpp  CEntity.cpp CPlayer.cpp
	$(CC) $(OBJECTS) $(CPPFLAGS) $(LDFLAGS) -o sdl_entities

# cleanup
clean:
	rm -rf $(OBJECTS)

# EOF
