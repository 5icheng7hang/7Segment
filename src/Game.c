#include <stdio.h>

#include "Game.h"
#include "Config.h"
#include "GameplayCore.h"

void InitGame(struct Game *game)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    memset(game, 0, sizeof(struct Game));

    game->GameWindow = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        RES_WIDTH * RENDER_SCALE + RES_WIDTH * TILE_GAP + TILE_GAP,
        RES_HEITHT * RENDER_SCALE + RES_HEITHT * TILE_GAP + TILE_GAP,
        SDL_WINDOW_SHOWN);

    game->GameRenderer = SDL_CreateRenderer(
        game->GameWindow,
        -1,
        SDL_TEXTUREACCESS_TARGET);

    game->ShouldQuitGame = false;

    Birth(game);
}

void RunGame(struct Game *game)
{
    while (!game->ShouldQuitGame)
    {
        UpdateGame(game);
        DrawGame(game);
    }
}

void FixFrameRate(struct Game *game)
{
    int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - game->millisecsPreviousFrame);

    if (timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME)
    {
        SDL_Delay(timeToWait);
    }

    double deltaTime = (SDL_GetTicks() - game->millisecsPreviousFrame) / 1000.0;

    game->millisecsPreviousFrame = SDL_GetTicks();
}

void UpdateGame(struct Game *game)
{
    FixFrameRate(game);

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
        {
            game->ShouldQuitGame = true;
            printf("Trying to escape");
        }
        break;

        case SDL_KEYDOWN:
        {
            char key = event.key.keysym.sym;
            if (key >= 'a' && key <= 'z')
            {
                game->KeyStateArray[key - 'a'] = true;
            }
        }
        break;

        case SDL_KEYUP:
        {
            char key = event.key.keysym.sym;

            game->KeyStateArray[key - 'a'] = false;
            if (key >= 'a' && key <= 'z')
            {
                game->KeyStateArray[key - 'a'] = false;
            }
        }
        break;

        default:
            break;
        }
    }
    Pulse(game);
}

void DrawBackground(struct Game *game)
{

    SDL_SetRenderDrawColor(game->GameRenderer, COLOR2);
    SDL_RenderClear(game->GameRenderer);
    SDL_SetRenderDrawColor(game->GameRenderer, COLOR1);

    for (int x = 0; x < RES_WIDTH; x++)
    {
        for (int y = 0; y < RES_HEITHT; y++)
        {
            SDL_Rect rect;
            rect.x = x * RENDER_SCALE + (x + 1) * TILE_GAP;
            rect.y = y * RENDER_SCALE + (y + 1) * TILE_GAP;
            rect.w = RENDER_SCALE;
            rect.h = RENDER_SCALE;
            SDL_RenderFillRect(game->GameRenderer, &rect);
        }
    }
    SDL_RenderPresent(game->GameRenderer);
}

void DrawForeground(struct Game *game)
{

    SDL_SetRenderDrawColor(game->GameRenderer, COLOR3);

    for (int x = 0; x < RES_WIDTH; x++)
    {
        for (int y = 0; y < RES_HEITHT; y++)
        {
            if (game->ForegroundArray[x][y])
            {
                SDL_Rect r;
                r.x = x * RENDER_SCALE + (x + 1) * TILE_GAP;
                r.y = y * RENDER_SCALE + (y + 1) * TILE_GAP;
                r.w = RENDER_SCALE;
                r.h = RENDER_SCALE;
                SDL_RenderFillRect(game->GameRenderer, &r);
            }
        }
    }
    SDL_RenderPresent(game->GameRenderer);
}

void DrawGame(struct Game *game)
{
    DrawBackground(game);
    DrawForeground(game);
}

void DestroyGame(struct Game *game)
{
    SDL_DestroyRenderer(game->GameRenderer);
    SDL_DestroyWindow(game->GameWindow);
    SDL_Quit();
}