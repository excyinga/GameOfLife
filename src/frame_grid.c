#include "application.h"
#include "tools.h"

void frameGrid(void)
{
    clearScreen(application.surface, 0x00);
    drawGrid(GRID_AMOUNT);
    return;
}