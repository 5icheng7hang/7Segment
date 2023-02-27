#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "Config.h"

struct Game
{
    SDL_Window* GameWindow;
    SDL_Renderer* GameRenderer;
    bool ShouldQuitGame;
    int millisecsPreviousFrame;
    bool KeyStateArray[26];
    bool ForegroundArray[RES_WIDTH][RES_HEITHT];
};


void InitGame(struct Game* game);
void RunGame(struct Game* game);
void UpdateGame(struct Game* game);
void DrawGame(struct Game* game);
void DestroyGame(struct Game* game);

void FixFrameRate(struct Game *game);
void DrawBackground(struct Game *game);
void DrawForeground(struct Game *game);

#endif