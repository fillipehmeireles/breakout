#ifndef blocks__h
#define blocks__h
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "utils.h"
typedef struct Block{
    SDL_Rect rect;
    SDL_Color color;
    bool active; 
}Block;

void initBlocks(Block [MAX_BLOCKS][MAX_BLOCKS]);
void drawBlocks(SDL_Renderer*, Block [MAX_BLOCKS][MAX_BLOCKS]);
#endif
