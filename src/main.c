#include <SDL2/SDL.h>
#include <ball.h>
#include <stdio.h>
#include "player.h"
#include "game_screen.h"
#include "blocks.h"
#include <stdbool.h>
#define FPS 60
#define FRAME_DELAY (1000 / FPS)

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error on intializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Breakout",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            W_WIDTH, W_HEIGHT,
            SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Error on creating window: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,0);
    Uint32 frameStart;
    int frameTime;
    SDL_Event e;
    int quit = 0;

    GameScreen game_screen = (GameScreen) {.screen_color = (SDL_Color){18,18,18,0}};
    GameBorder border_top = (GameBorder){.rect = (SDL_Rect){.x = 0, .y = 0, .w = W_WIDTH, .h = 1}, .border_color=game_screen.screen_color};
    GameBorder border_bottom = (GameBorder){.rect = (SDL_Rect){.x = 0, .y = W_HEIGHT - 1, .w = W_WIDTH, .h = 1}, .border_color=game_screen.screen_color};
    GameBorder border_left = (GameBorder){.rect = (SDL_Rect){.x = 0, .y = 0, .w = 1, .h = W_HEIGHT}, .border_color=game_screen.screen_color};
    GameBorder border_right = (GameBorder){.rect = (SDL_Rect){.x = W_WIDTH - 1, .y = 0, .w = 1, .h = W_HEIGHT}, .border_color=game_screen.screen_color};
    GameBorders game_borders = {border_top, border_bottom, border_left, border_right};
    bool key_left_pressed, key_right_pressed = false;

    Player p = (Player){.color=(SDL_Color){255,255,255,255},.step = 10,.rect=(SDL_Rect){.x = (W_WIDTH / 2) - 30, .y = (W_HEIGHT - 10) - 10, .w = 50, .h = 10}};
    Block blocks[MAX_BLOCKS][MAX_BLOCKS];
    Ball b = (Ball){.step_x = 3, .rect=(SDL_Rect){.x = p.rect.x, .y = p.rect.y - 50, .w = 10, .h=10},.step_y = 5, .color=p.color, .active = true};
    initBlocks(blocks);
    while (!quit) {
        frameStart = SDL_GetTicks();
        SET_RENDER_DRAW_COLOR(renderer,game_screen.screen_color);
        SDL_RenderClear(renderer);

        while (SDL_PollEvent(&e) != 0) {
            switch(e.type){
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym)
                    {
                        case SDLK_LEFT:
                            key_left_pressed = true;
                            break;
                        case SDLK_RIGHT:
                            key_right_pressed = true;
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    key_left_pressed = false;
                    key_right_pressed = false;
                    break;
                case SDL_QUIT :
                    quit = 1;
                    break;
            }
        }
        if(!checkPlayerBorderCollision(p, border_left) && key_left_pressed)
            movePlayer(&p,SDLK_LEFT);
        else if(!checkPlayerBorderCollision(p, border_right) && key_right_pressed)
            movePlayer(&p,SDLK_RIGHT);


        drawBall(renderer,&b);
        drawPlayer(renderer,&p);
        drawBorders(renderer,game_borders);
        drawBlocks(renderer,blocks);
        updateBall(&b, &p, &game_borders, blocks);
        SDL_RenderPresent(renderer);
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_DELAY) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

