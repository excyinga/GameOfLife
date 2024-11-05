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