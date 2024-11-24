#ifndef _APP_H_
#define _APP_H_
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "types.h"

#define WINDOW_W    1280
#define WINDOW_H    720
#define GRID_AMOUNT 25

typedef struct StApplication Application;

typedef enum EnGameScreen GameScreen;

enum EnGameScreen
{
    GAME_SCREEN_MENU,
    GAME_SCREEN_GRID
};

struct StApplication                     
{
    SDL_Window * window;
    SDL_Surface * surface;
    TTF_Font * font;
    GameScreen game_screen;
    int mouse_x, mouse_y;
    bool _is_playing;
    bool is_click;
    unsigned int current_time_ms;
    unsigned int game_logic_timer;
};

extern Application application;

extern bool grid_cells[GRID_AMOUNT * GRID_AMOUNT];

#endif