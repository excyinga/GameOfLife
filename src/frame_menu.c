#include <SDL2/SDL_ttf.h>

#include "application.h"
#include "types.h"

void frameMenu()
{
    if (!TTF_Init())
    {
        printf("TTF_Init failed\n");
        application._is_playing = FALSE;
        return;
    }
    application.font = TTF_OpenFont("./resoutces/font.ttf", 24);
    if (application.font == NULL) 
    {
        printf("Failed to load font! TTF_Error: %s\n", TTF_GetError());
        application._is_playing = FALSE;
        return;
    }
    application.surface = SDL_GetWindowSurface(application.window);
    return;
}