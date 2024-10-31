#include <stdio.h>

#include <SDL2/SDL.h>

#include "application.h"
#include "types.h"

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        printf("SDL_Init failed\n");
        return 1;
    }
    if (!(application.window = SDL_CreateWindow("Game Of Life by Ol. K.", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN)))
    {
        printf("SDL_CreateWindow failed\n");
        return 1;
    }
    else if (!(application.surface = SDL_GetWindowSurface(application.window)))
    {
        printf("SDL_GetWindowSurface failed\n");
        return 1;
    }
    SDL_Event event;
    for (; application._is_playing;)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                application._is_playing = FALSE;
                break;
            }
        }
    }
    return 0;
}