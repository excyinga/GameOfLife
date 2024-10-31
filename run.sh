#!/bin/bash

set -ex
gcc -Wall -ansi \
    -I./include/ -lSDL2 -lSDL2_ttf\
    -o game.bin src/*.c
./game.bin