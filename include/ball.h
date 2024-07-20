#ifndef ball__h
#define ball__h

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "game_screen.h"
#include "player.h"
#include "utils.h"
#include "blocks.h"

typedef struct Ball {
    SDL_Rect rect;
    int step_y;
    int step_x;
    SDL_Color color;
    bool active;
} Ball;

void drawBall(SDL_Renderer * renderer, Ball *b);
void updateBall(Ball *b, Player *p, GameBorders *game_borders, Block [MAX_BLOCKS][MAX_BLOCKS]);
void checkBallOut(Ball *b);
#endif
