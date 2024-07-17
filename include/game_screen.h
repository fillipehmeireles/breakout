#ifndef game_screen__h
#define game_screen__h

#include <SDL2/SDL.h>
#define W_WIDTH 640
#define W_HEIGHT 480

#define SET_RENDER_DRAW_COLOR(renderer, color) SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a)

typedef struct GameScreen {
    SDL_Color screen_color;
} GameScreen;

typedef struct GameBorder{
    SDL_Rect rect;
    SDL_Color border_color;
}GameBorder;

typedef struct GameStats {
    char ** score;
} GameStats;
void drawBorders(SDL_Renderer *renderer, GameBorder *borders[], int borders_c);
#endif
