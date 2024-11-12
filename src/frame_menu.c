#include "frame_menu.h"

#include "application.h"
#include "tools.h"

void frameMenu(void)
{
    clearScreen(application.surface, 0x00);
    SDL_Color button_color = {255, 0, 0};
    DrawButtonResult play_result, quit_result;
    int y = application.surface->h / 2;
    int x = application.surface->w / 2;
    play_result = drawButton(x, y, "Play", button_color, TRUE, -1);
    if (play_result.is_clicked)
    {
        application.game_screen = GAME_SCREEN_GRID;
    }
    quit_result = drawButton(x, y, "Quit", button_color, TRUE, 0);
    if (quit_result.is_clicked)
    {
        application._is_playing = FALSE;
    }
    return;
}