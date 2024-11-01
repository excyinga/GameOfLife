#include "application.h"

void drawingMidpoint(void)
{
    int x = 0, y = 0;
    for (; y < application.surface->h; y++)
    {
        * (((int *) application.surface->pixels) + y * application.surface->pitch 
            + application.surface->w / 2 - 1) = (int) 0xFFFF;
        * (((int *) application.surface->pixels) + y * application.surface->pitch 
            + application.surface->w / 2) = (int) 0xFFFF;
    }
    return; 
}