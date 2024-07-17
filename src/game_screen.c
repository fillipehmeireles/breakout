#include "game_screen.h"


void drawBorders(SDL_Renderer *renderer, GameBorder *borders[], int borders_c)
{
    for(int i = 0; i < borders_c; i++)
    {
        SET_RENDER_DRAW_COLOR(renderer,borders[i]->border_color);
        SDL_RenderFillRect(renderer, &borders[i]->rect);

    }
}
