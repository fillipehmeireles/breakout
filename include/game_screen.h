#ifndef game_screen__h
#define game_screen__h

#include <SDL2/SDL.h>
#define W_WIDTH 640
#define W_HEIGHT 480

#include "utils.h"
typedef struct GameScreen {
    SDL_Color screen_color;
} GameScreen;

typedef struct GameBorder{
    SDL_Rect rect;
    SDL_Color border_color;
}GameBorder;

typedef struct GameBorders{
    GameBorder border_top;
    GameBorder border_bottom;
    GameBorder border_left;
    GameBorder border_right;
} GameBorders;

typedef struct GameStats {
    char ** score;
} GameStats;
void drawBorders(SDL_Renderer *renderer, GameBorders game_borders);
#endif
