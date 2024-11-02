#include "tools.h"

#include "application.h"

SDL_Color BLACK = {0, 0, 0};

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
    int int_color = color.r << 16 | color.g << 8 | color.b;
    for (; x < rect.w; x++)
    {
        ((int *) application.surface->pixels)[application.surface->pitch / 4 * rect.y + rect.x + x] = int_color;
        ((int *) application.surface->pixels)[application.surface->pitch / 4 * (rect.y + rect.h - 1) + rect.x + x] = int_color;
    }
    int y = 0;
    for (; y < rect.h; y++)
    {
        ((int *) application.surface->pixels)[application.surface->pitch / 4 * (y + rect.y) + rect.x] = int_color;
        ((int *) application.surface->pixels)[application.surface->pitch / 4 * (y + rect.y) + rect.x + rect.w - 1] = int_color;
    }
    return;
}
DrawButtonResult drawButton(int x, int y, char * text, SDL_Color color)
{
    SDL_Surface * text_surface = TTF_RenderText_Solid(application.font, text, color);
    SDL_Rect rect = {x, y, text_surface->w, text_surface->h};
    SDL_BlitSurface(text_surface, NULL, application.surface, &rect);
    DrawButtonResult result;
    result.x = rect.x;
    result.y = rect.y;
    result.width = rect.w;
    result.height = rect.h;
    SDL_FreeSurface(text_surface); 
    if (application.is_click &&
        application.mouse_x >= rect.x && application.mouse_x <= rect.x + rect.w &&
        application.mouse_y >= rect.y && application.mouse_y <= rect.y + rect.h)
    {
        result.is_clicked = TRUE;
    }
    else
    {
        result.is_clicked = FALSE;
    }
    return result;
}