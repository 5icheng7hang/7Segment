#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "Game.h"

int main(int argc, char *argv[])
{
    
    struct Game NewGame;
    InitGame(&NewGame);

    RunGame(&NewGame);
    DestroyGame(&NewGame);
    return 0;
}