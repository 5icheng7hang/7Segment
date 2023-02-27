#include "GameplayCore.h"

#include "Game.h"
#include "Methods.h"

#include <stdio.h>

int x;
int y;

void Birth(struct Game* game)
{
    x = 0;
    y = 0;

    DrawCirc(game, 20, 20, 10);

    DrawCircFill(game, 40, 40 ,10);

    DrawRect(game, 10, 10, 50, 30);
}

void Pulse(struct Game *game)
{
    if (IsKeyPressed(game, 'w'))
    {
        y--;
    }
    if (IsKeyPressed(game, 'a'))
    {
        x--;
    }
    if (IsKeyPressed(game, 's'))
    {
        y++;
    }
    if (IsKeyPressed(game, 'd'))
    {
        x++;
    }

    SetPixel(game, x, y, true);

}