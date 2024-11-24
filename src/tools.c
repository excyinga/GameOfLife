#include "tools.h"

#include "application.h"

SDL_Color BLACK = {0, 0, 0};
int RED = 0xFF0000;

void drawMidpoint(void)
{
    int y = 0, x = 0;
    for (; y < application.surface->h; y++)
    {
        * (((int *) application.surface->pixels) + y * application.surface->w + application.surface->w / 2 - 1) = 0xFFFFFF;
        * (((int *) application.surface->pixels) + y * application.surface->w + application.surface->w / 2) = 0xFFFFFF;
    }
    for (; x < application.surface->w; x++)
    {
        * (((int *) application.surface->pixels) + application.surface->h / 2 * application.surface->w + x) = 0xFFFFFF;
        * (((int *) application.surface->pixels) + (application.surface->h / 2 - 1) * application.surface->w + x) = 0xFFFFFF;
    }
    return; 
}
void drawOutlineOfSurface(SDL_Rect rect, SDL_Color color)
{
    int x = 0;
    int int_color = color.r << 16 | color.g << 8 | color.b;
    for (; x < rect.w; x++)
    {
        ((int *) application.surface->pixels)[application.surface->pitch / 4 * rect.y + rect.x + x] = int_color;
        ((int *) application.surface->pixels)[application.surface->pitch / 4 * (rect.y + rect.h - 1) + rect.x + x] = int_color;
    }
    int y = 0;
    for (; y < rect.h; y++)
    {
        ((int *) application.surface->pixels)[application.surface->pitch / 4 * (y + rect.y) + rect.x] = int_color;
        ((int *) application.surface->pixels)[application.surface->pitch / 4 * (y + rect.y) + rect.x + rect.w - 1] = int_color;
    }
    return;
}
DrawButtonResult drawButton(int x, int y, char * text, SDL_Color color, bool centered, int number_in_order)
{
    SDL_Surface * text_surface = TTF_RenderText_Solid(application.font, text, color);
    SDL_Rect rect = {x, y, text_surface->w, text_surface->h};
    if (centered)
    {
        rect.x -= text_surface->w / 2;
        rect.y += number_in_order * text_surface->h;
    }
    SDL_BlitSurface(text_surface, NULL, application.surface, &rect);
    DrawButtonResult result;
    result.x = rect.x;
    result.y = rect.y;
    result.width = rect.w;
    result.height = rect.h;
    SDL_FreeSurface(text_surface); 
    if (application.is_click && IsInRect(rect, application.mouse_x, application.mouse_y))
    {
        result.is_clicked = TRUE;
    }
    else
    {
        result.is_clicked = FALSE;
    }
    return result;
}
void setPixel(int x, int y, int color, SDL_Surface * surface)
{
    if (x < 0 || x > surface->w || y < 0 || y > surface->h)
    {
        return;
    }
    ((int *) surface->pixels)[surface->pitch / 4 * y + x] = color;
    return;
}
void drawGrid(int grid_amount)
{
    int cell_width = application.surface->w / grid_amount;
    int cell_height = application.surface->h / grid_amount;
    for (int cell_index = 0; cell_index <= grid_amount; cell_index++)
    {
        for (int y = 0; y < application.surface->h; y++)
        {
            if (cell_index == grid_amount)
            {
                setPixel(cell_width * cell_index - 1, y, 0xFFFFFF, application.surface);
            }
            else
            {
                setPixel(cell_width * cell_index, y, 0xFFFFFF, application.surface);
            }
        }
    }
    for (int cell_index = 0; cell_index <= grid_amount; cell_index++)
    {
        for (int x = 0; x < application.surface->w; x++)
        {
            if (cell_index == grid_amount)
            {
                setPixel(x, cell_height * cell_index - 1, 0xFFFFFF, application.surface);
            }
            else
            {
                setPixel(x, cell_height * cell_index, 0xFFFFFF, application.surface);
            }
        }
    }
    SDL_Rect rect;
    for (int cell_y = 0; cell_y < grid_amount; cell_y++)
    {
        for (int cell_x = 0; cell_x < grid_amount; cell_x++)
        {
            rect = (SDL_Rect) {cell_x * cell_width + 1, cell_y * cell_height + 1, cell_width - 1, cell_height - 1};
            if (IsInRect(rect, application.mouse_x, application.mouse_y) && application.is_click)
            {
                printf("Before grid_cells[cell_y * grid_amount + cell_x]: %d\n", grid_cells[cell_y * grid_amount + cell_x]);
                grid_cells[cell_y * grid_amount + cell_x] = !grid_cells[cell_y * grid_amount + cell_x]; 
                printf("After grid_cells[cell_y * grid_amount + cell_x]: %d\n", grid_cells[cell_y * grid_amount + cell_x]);
            }
            if (grid_cells[cell_y * grid_amount + cell_x])
            {
                drawRect(application.surface, rect, RED);
            }
        }
    }
    return;
}
void clearScreen(SDL_Surface * surface, int color)
{
    for (int x = 0; x < surface->w * surface->h; x++)
        ((int *) surface->pixels)[x] = color;
    return;
}
bool IsInRect(SDL_Rect rect, int x, int y)
{
    if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
        return TRUE;
    else
        return FALSE;
}
void drawRect(SDL_Surface * surface, SDL_Rect rect, int color)
{
    for (int y = rect.y; y < rect.y + rect.h; y++)
    {
        for (int x = rect.x; x < rect.x + rect.w; x++)
        {
            setPixel(x, y, color, surface);
        }
    }
    return;
}