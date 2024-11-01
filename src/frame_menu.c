#include "application.h"

extern void drawingMidpoint(void);

void frameMenu(void)
{
    drawingMidpoint();
    SDL_Surface * text_surface = TTF_RenderText_Solid(application.font, "Play", (SDL_Color) {255, 0, 0});
    SDL_BlitSurface(text_surface, NULL, application.surface, 
                    (SDL_Rect *) & (SDL_Rect) {(application.surface->w - text_surface->w) / 2,
                    application.surface->h / 2 - text_surface->h,
                    application.surface->w,
                    application.surface->h});
    return;
}