#include "application.h"

Application application = { .window = (SDL_Window *) NULL, 
                            .surface = (SDL_Surface *) NULL,
                            .font = (TTF_Font *) NULL,
                            ._is_playing = TRUE,
                            .game_screen = GAME_SCREEN_MENU};

bool grid_cells[GRID_AMOUNT * GRID_AMOUNT];