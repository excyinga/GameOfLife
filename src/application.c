#include "application.h"
#include "types.h"

Application application = { .window = (SDL_Window *) NULL, 
                            .surface = (SDL_Surface *) NULL,
                            ._is_playing = TRUE,
                            .game_screen = GAME_SCREEN_MENU};

