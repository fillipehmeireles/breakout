#include "blocks.h"


void initBlocks(Block blocks[MAX_BLOCKS][MAX_BLOCKS])
{
    int border_l = 15;
    int border_t = 40;
    for(int i = 0; i < MAX_BLOCKS; i++)
    {
        for (int j = 0; j < MAX_BLOCKS; j++)
        {
            blocks[i][j].rect = (SDL_Rect){.x =  (border_l + 60) * (j+1), .y = border_t * (i+1), .w = 30, .h = 10};
            blocks[i][j].color = (SDL_Color){219 * (i+1),19 * (j+1),56 *( (i + 1)/2),0};
            blocks[i][j].active = true;
        }
    }
}


void drawBlocks(SDL_Renderer* renderer, Block blocks[MAX_BLOCKS][MAX_BLOCKS])
{
    for(int i = 0; i < MAX_BLOCKS; i++)
    {
        for (int j = 0; j < MAX_BLOCKS; j++)
        {
            if(blocks[i][j].active)
            {
                SET_RENDER_DRAW_COLOR(renderer,blocks[i][j].color);
                SDL_RenderFillRect(renderer, &blocks[i][j].rect);
            }
        }
    }
}

