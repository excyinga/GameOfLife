#include "application.h"

void drawMidpoint(void)
{
    int y = 0, x = 0;
    for (; y < application.surface->h; y++)
    {
        * (((int *) application.surface->pixels) + y * application.surface->w + application.surface->w / 2 - 1) = 0xFFFFFF;
        * (((int *) application.surface->pixels) + y * application.surface->w + application.surface->w / 2) = 0xFFFFFF;
    }
    for (; x < application.surface->w; x++)
    {
        * (((int *) application.surface->pixels) + application.surface->h / 2 * application.surface->w + x) = 0xFFFFFF;
        * (((int *) application.surface->pixels) + (application.surface->h / 2 - 1) * application.surface->w + x) = 0xFFFFFF;
    }
    return; 
}
void drawOutlineOfSurface(SDL_Rect rect, SDL_Color color)
{
    int x = 0;
    for (; x < rect.w; x++)
    {
        ((int *) application.surface->pixels)[application.surface->pitch / 4 * rect.y + rect.x + x] = * (int *) &color;
        ((int *) application.surface->pixels)[application.surface->pitch / 4 * (rect.y + rect.h - 1) + rect.x + x] = * (int *) &color;
    }
    return;
}