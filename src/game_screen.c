#include "game_screen.h"


void drawBorders(SDL_Renderer *renderer, GameBorders game_borders)
{
    SET_RENDER_DRAW_COLOR(renderer,game_borders.border_top.border_color);
    SDL_RenderFillRect(renderer, &game_borders.border_top.rect);
    SET_RENDER_DRAW_COLOR(renderer,game_borders.border_top.border_color);
    SDL_RenderFillRect(renderer, &game_borders.border_bottom.rect);

    SET_RENDER_DRAW_COLOR(renderer,game_borders.border_top.border_color);
    SDL_RenderFillRect(renderer, &game_borders.border_left.rect);

    SET_RENDER_DRAW_COLOR(renderer,game_borders.border_top.border_color);
    SDL_RenderFillRect(renderer, &game_borders.border_right.rect);
}
