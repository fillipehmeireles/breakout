#ifndef player__h
#define player__h
#include <SDL2/SDL.h>
#include "game_screen.h"
#include <stdbool.h>

#include "utils.h"

typedef struct Player {
    SDL_Rect rect; 
    int step;
    SDL_Color color;
} Player;

bool checkPlayerBorderCollision(Player p, GameBorder border);
void drawPlayer(SDL_Renderer * renderer, Player *p);
void movePlayer(Player* p, SDL_Keycode direction);
#endif
