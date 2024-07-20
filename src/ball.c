#include "ball.h"
#include <assert.h>
#include <utils.h>
#include <SDL2/SDL_rect.h>

void drawBall(SDL_Renderer *renderer, Ball *b)
{
    assert(b != NULL);
    if(b->active)
    {
        SET_RENDER_DRAW_COLOR(renderer,b->color);
        SDL_RenderFillRect(renderer, &b->rect);
    }
}

void updateBall(Ball *b, Player *p, GameBorders *game_borders, Block blocks [MAX_BLOCKS][MAX_BLOCKS])
{
    if(!b->active)
        return;

    if(SDL_HasIntersection(&b->rect,&p->rect))
    {
        b->step_y = - b->step_y;
    }

    if(SDL_HasIntersection(&b->rect,&game_borders->border_top.rect))
    {
        b->step_y = - b->step_y;
    }

    if(SDL_HasIntersection(&b->rect,&game_borders->border_left.rect))
    {
        b->step_x = - b->step_x;
    }

    if(SDL_HasIntersection(&b->rect,&game_borders->border_right.rect))
    {
        b->step_x = - b->step_x;
    }


    for(int i = 0; i < MAX_BLOCKS; i++)
    {
        for(int j = 0; j < MAX_BLOCKS; j++)
        {
            if(!blocks[i][j].active) continue;

            if(SDL_HasIntersection(&(b->rect),&blocks[i][j].rect))
            {
                b->step_y = - b->step_y;
                blocks[i][j].active = false;
                b->color = blocks[i][j].color;
                p->color = blocks[i][j].color;
                game_borders->border_top.border_color = blocks[i][j].color;
                game_borders->border_left.border_color = blocks[i][j].color;
                game_borders->border_right.border_color = blocks[i][j].color;
                game_borders->border_bottom.border_color = blocks[i][j].color;
                break;
            }
        }
    }

    b->rect.y += b->step_y;
    b->rect.x += b->step_x;
}
