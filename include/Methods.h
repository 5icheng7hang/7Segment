#ifndef GAME_METHODS
#define GAME_METHODS

#include <stdbool.h>

#include "Game.h"

// Game functions.

void EndGame(struct Game *game);


// Draw functions.

void SetPixel(struct Game *game, int x, int y, bool b);
bool GetPixel(struct Game *game, int x, int y);

void DrawRect(struct Game *game, int x0, int y0, int x1, int y1);
void DrawRectFill(struct Game *game, int x0, int y0, int x1, int y1);

void DrawCirc(struct Game *game, int x, int y, int r);
void DrawCircFill(struct Game *game, int x, int y, int r);

void DrawLine(struct Game *game, int x0, int y0, int x1, int y1);


// Control functions.

// TODO: Only consider alphabet yet.
// later may join the method for getting all SDLK type (or ASCII)
// and most inprotant is the mouse info: mouse position, and so on
bool IsKeyPressed(struct Game *game, char key);


#endif