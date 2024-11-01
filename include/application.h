#ifndef _APP_H_
#define _APP_H_
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "types.h"

#define WINDOW_W    1280
#define WINDOW_H    720

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
    bool _is_playing;
    GameScreen game_screen;
};

extern Application application;

#endif