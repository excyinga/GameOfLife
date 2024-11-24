#include "application.h"
#include "tools.h"

bool game_start = FALSE;
bool tmp_grid[GRID_AMOUNT * GRID_AMOUNT];

extern void gameLogic(void);

void frameGrid(void)
{
    clearScreen(application.surface, 0x00);
    drawGrid(GRID_AMOUNT, 10, 10, WINDOW_W - WINDOW_W / 3 - 20, WINDOW_H - WINDOW_H / 3 - 20);
    if (game_start)
    {
        if (application.current_time_ms - application.game_logic_timer >= 500)
        {
            gameLogic();
            application.game_logic_timer = application.current_time_ms;
        }
    }
    return;
}
void gameLogic(void)
{
    int width, height = width = GRID_AMOUNT;
    int i = 0;
    int neighbours_cell_amount = 0;
    for (; i < width * height; i++)
    {
        if (i - width >= 0 && grid_cells[i - width])
            neighbours_cell_amount++;
        if (i + width < height * width && grid_cells[i + width])
            neighbours_cell_amount++;
        if (i % width != 0 && grid_cells[i - 1])
            neighbours_cell_amount++;
        if (i % width != width - 1 && grid_cells[i + 1])
            neighbours_cell_amount++;
        if (i >= width && i % width != 0 && grid_cells[i - width - 1])
            neighbours_cell_amount++;
        if (i >= width && i % width != width - 1 && grid_cells[i - width + 1])
            neighbours_cell_amount++;
        if (i < height * width - width && i % width != 0 && grid_cells[i + width - 1])
            neighbours_cell_amount++;
        if (i < height * width - width && i % width != width - 1 && grid_cells[i + width + 1])
            neighbours_cell_amount++;
        if ((neighbours_cell_amount < 2 || neighbours_cell_amount > 3) && grid_cells[i] || !grid_cells[i] && neighbours_cell_amount == 3)
            tmp_grid[i] = !grid_cells[i];
        else
            tmp_grid[i] = grid_cells[i];
        neighbours_cell_amount = 0;
    }
    for (i = 0; i < height * width; i++)
        grid_cells[i] = tmp_grid[i];
    return; 
}