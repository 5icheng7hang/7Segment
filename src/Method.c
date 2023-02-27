#include "Methods.h"

#include "Game.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void SetPixel(struct Game *game, int x, int y)
{
    game->ForegroundArray[x][y] = true;
}

bool GetPixel(struct Game *game, int x, int y)
{
    return game->ForegroundArray[x][y];
}

void DrawRect(struct Game *game, int x0, int y0, int x1, int y1)
{
    DrawLine(game, x0, y0, x1, y0);
    DrawLine(game, x0, y0, x0, y1);
    DrawLine(game, x1, y0, x1, y1);
    DrawLine(game, x0, y1, x1, y1);
}

void DrawRectFill(struct Game *game, int x0, int y0, int x1, int y1)
{
    if (x0 > x1)
    {
        int temp;
        
        temp = x0;
        x0 = x1;
        x1 = temp;
    }
    
    if (y0 > y1)
    {
        int temp;

        temp = y0;
        y0 = y1;
        y1 = temp;
    }

    for (int x = 0; x < RES_WIDTH; x++)
    {
        for (int y = 0; y < RES_HEITHT; y++)
        {
            if (x >= x0 && x <= x1 && y >= y0 && y <= y1)
            {
                SetPixel(game, x, y);
            }
        }
    }
}

void DrawCirc(struct Game *game, int x_centre, int y_centre, int r)
{
    int x = r, y = 0;

    SetPixel(game, x + x_centre, y + y_centre);
    printf("(%d, %d) ", x + x_centre, y + y_centre);
    
    if (r > 0)
    {
        SetPixel(game, -x + x_centre, y + y_centre);
        SetPixel(game, y + x_centre, x + y_centre);
        SetPixel(game, y + x_centre, -x + y_centre);
        printf("(%d, %d) ", x + x_centre, -y + y_centre);
        printf("(%d, %d) ", y + x_centre, x + y_centre);
        printf("(%d, %d)\n", -y + x_centre, x + y_centre);
    }
     
    int P = 1 - r;
    while (x > y)
    {
        y++;

        if (P <= 0)
            P = P + 2*y + 1;
             
        else
        {
            x--;
            P = P + 2*y - 2*x + 1;
        }
         
        if (x < y)
            break;
        
        SetPixel(game, x + x_centre, y + y_centre);
        SetPixel(game, -x + x_centre, y + y_centre);
        SetPixel(game, x + x_centre, -y + y_centre);
        SetPixel(game, -x + x_centre, -y + y_centre);
         
        if (x != y)
        {
            SetPixel(game, y + x_centre, x + y_centre);
            SetPixel(game, -y + x_centre, x + y_centre);
            SetPixel(game, y + x_centre, -x + y_centre);
            SetPixel(game, -y + x_centre, -x + y_centre);
        }
    }
}


void DrawCircFill(struct Game *game, int x_centre, int y_centre, int r)
{
    int x = r, y = 0;

    SetPixel(game, x + x_centre, y + y_centre);
    printf("(%d, %d) ", x + x_centre, y + y_centre);
    
    if (r > 0)
    {
        SetPixel(game, -x + x_centre, y + y_centre);
        SetPixel(game, y + x_centre, x + y_centre);
        SetPixel(game, y + x_centre, -x + y_centre);
        printf("(%d, %d) ", x + x_centre, -y + y_centre);
        printf("(%d, %d) ", y + x_centre, x + y_centre);
        printf("(%d, %d)\n", -y + x_centre, x + y_centre);
    }
     
    int P = 1 - r;
    while (x > y)
    {
        y++;

        if (P <= 0)
            P = P + 2*y + 1;
             
        else
        {
            x--;
            P = P + 2*y - 2*x + 1;
        }
         
        if (x < y)
            break;
        
        SetPixel(game, x + x_centre, y + y_centre);
        SetPixel(game, -x + x_centre, y + y_centre);
        DrawLine(game, x + x_centre, y + y_centre, -x + x_centre, y + y_centre);

        SetPixel(game, x + x_centre, -y + y_centre);
        SetPixel(game, -x + x_centre, -y + y_centre);
        DrawLine(game, x + x_centre, -y + y_centre, -x + x_centre, -y + y_centre);
         
        if (x != y)
        {
            SetPixel(game, y + x_centre, x + y_centre);
            SetPixel(game, -y + x_centre, x + y_centre);
            DrawLine(game, y + x_centre, x + y_centre, -y + x_centre, x + y_centre);

            SetPixel(game, y + x_centre, -x + y_centre);
            SetPixel(game, -y + x_centre, -x + y_centre);
            DrawLine(game, y + x_centre, -x + y_centre, -y + x_centre, -x + y_centre);
        }
    }
}

void DrawLine(struct Game *game, int x0, int y0, int x1, int y1)
{
    bool steep = abs(y1 - y0) > abs(x1 - x0);

    if (steep)
    {
        int temp;

        temp = x0;
        x0 = y0;
        y0 = temp;
        
        temp = x1;
        x1 = y1;
        y1 = temp;
    }

    if (x0 > x1)
    {
        int temp;
        
        temp = x0;
        x0 = x1;
        x1 = temp;
        
        temp = y0;
        y0 = y1;
        y1 = temp;
    }
    
    int dx = x1-x0;
    int dy = abs(y1-y0);
    int error = dx/2;
    int ystep;
    int y = y0;

    if (y0 < y1)
    {
        ystep = 1;
    }
    else
    {
        ystep = -1;
    }
    
    for (int x = x0; x <= x1; x++)
    {
        if (steep)
        {
            SetPixel(game,y,x);
        }
        else
        {
            SetPixel(game,x,y);
        }
        error = error -dy;
        if (error < 0)
        {
            y = y + ystep;
            error = error +dx;
        }   
    }
}

