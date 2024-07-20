#include "ball.h"
#include <assert.h>
#include <utils.h>

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

    if(b->rect.y == p->rect.y && (b->rect.x >= p->rect.x - b->rect.w && b->rect.x <= p->rect.x + p->rect.w))
    {
        b->step_y = - b->step_y;
    }

    if(b->rect.y == game_borders->border_top.rect.y)
    {
        b->step_y = - b->step_y;
    }

    if(b->rect.x >= game_borders->border_right.rect.x && b->rect.y >= game_borders->border_right.rect.y)
    {
        b->step_x = - b->step_x;
    }

    if(b->rect.x <= game_borders->border_left.rect.x && b->rect.y >= game_borders->border_left.rect.y)
    {
        b->step_x = - b->step_x;
    }


    for(int i = 0; i < MAX_BLOCKS; i++)
    {
        for(int j = 0; j < MAX_BLOCKS; j++)
        {
            if(!blocks[i][j].active) continue;

            if(b->rect.y == blocks[i][j].rect.y && (b->rect.x >= blocks[i][j].rect.x && b->rect.x <= blocks[i][j].rect.x + blocks[i][j].rect.w))
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
