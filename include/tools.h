#pragma once

#include <SDL2/SDL.h>

#include "types.h"

typedef struct DrawButtonResult DrawButtonResult;

struct DrawButtonResult
{
    bool is_clicked;
    int x, y, width, height;
};

DrawButtonResult drawButton(int x, int y, char * text, SDL_Color color, bool centered, int number_in_order);
void drawGrid(int grid_amount, int start_x, int start_y, int width_in_pixels, int height_in_pixels);
void clearScreen(SDL_Surface * surface, int color);
void drawRect(SDL_Surface * surface, SDL_Rect rect, int color);
bool IsInRect(SDL_Rect rect, int x, int y);
