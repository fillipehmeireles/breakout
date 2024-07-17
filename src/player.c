#include "player.h"

void drawPlayer(SDL_Renderer * renderer, Player *p)
{
    SDL_SetRenderDrawColor(renderer, 255,255, 255, 255);
    SDL_RenderFillRect(renderer, &p->rect);
}

void movePlayer(Player *p,SDL_Keycode direction)
{
    if(direction == SDLK_RIGHT)
    {
        p->rect.x += p->step;
    }else if(direction == SDLK_LEFT)
    {
        p->rect.x -= p->step;
    }
}

bool checkPlayerBorderCollision(Player p, GameBorder border)
{
    bool collision = false;
    if(border.rect.x == 0) 
    {
        if(p.rect.x <= border.rect.x + border.rect.w )
        {
            collision = true;
        }
    }else {
        if(p.rect.x >= border.rect.x - p.rect.w )
        {
            collision = true;
        }
    }
    return collision;
}
