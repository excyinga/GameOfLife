#include <stdio.h>

#include "application.h"
#include "frame_menu.h"
#include "frame_grid.h"
#include "tools.h"
#include "types.h"

int main(int, char **)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        printf("SDL_Init failed\n");
        return 1;
    }
    else if (TTF_Init())
    {
        printf("TTF_Init failed\n");
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
    else if (!(application.font = TTF_OpenFont("./resources/font.ttf", 36)))
    {
        printf("Failed to load font! TTF_Error: %s\n", TTF_GetError());
        return 1;
    }
    SDL_Event event;
    int x, y;
    for (; application._is_playing;)
    {
        application.current_time_ms = SDL_GetTicks();
        application.is_click = FALSE;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                application._is_playing = FALSE;
                break;
            }
            else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) /* ??? */
            {
                application.is_click = TRUE;
            }
            else if (event.type == SDL_KEYDOWN && application.game_screen == GAME_SCREEN_GRID)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    application.game_screen = GAME_SCREEN_MENU;
                    int i = 0;
                    for (; i < GRID_AMOUNT * GRID_AMOUNT; i++)
                    {
                        grid_cells[i] = tmp_grid[i] = 0;
                    }
                    game_start = FALSE;
                }
                else if (event.key.keysym.sym == SDLK_RETURN)
                    game_start = !game_start;
            }
        }
        SDL_GetMouseState(&x, &y);
        application.mouse_x = x;
        application.mouse_y = y;
        SDL_FillRect(application.surface, NULL, 0);
        if (application.game_screen == GAME_SCREEN_MENU)
        {
            frameMenu();
        }
        else
        {
            frameGrid();
        }
        SDL_UpdateWindowSurface(application.window);
    }
    return 0;
}