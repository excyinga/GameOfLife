#include "frame_menu.h"

#include "application.h"
#include "tools.h"

void frameMenu(void)
{
    SDL_Color button_color = {255, 0, 0};
    DrawButtonResult play_result, quit_result;
    int y = application.surface->h / 2;
    play_result = drawButton((application.surface->w) / 2,
        y,
        "Play",
        button_color);
    y += play_result.height;
    if (play_result.is_clicked)        
    {
        application.game_screen = GAME_SCREEN_MENU;
    }
    quit_result = drawButton((application.surface->w) / 2,
        y,
        "Quit",
        button_color);
    if (quit_result.is_clicked)
    {
        application._is_playing = FALSE;
    }
    return;
}