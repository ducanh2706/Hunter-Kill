#ifndef _GAME__H
#define _GAME__H

#include "entity.h"
#include "SDL.h"
#include "SDL_scancode.h"

#include <list>
#include <iostream>
#include <chrono>
#include <random>

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template<class T>
T randInt(T l, T r){
    std::uniform_int_distribution<T> distribution(l, r);
    return distribution(rng);
}

template<class T>
T randFloat(T l, T r){
    std::uniform_real_distribution<T> distribution(l, r);
    return distribution(rng);
}

void blitRect(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *src, int x, int y);

struct Game{
    Entity *player;
    std::list<Entity*> enemies;

    static const int ENEMIES_NUMBER = 3;
    static constexpr int direction_x[4] = {0, 0, -1, 1};
    static constexpr int direction_y[4] = {-1, 1, 0, 0};

    SDL_Texture *player_texture, *enemy_texture;


    SDL_Texture *background_texture;

    void initPlayer(){
        player = new Entity();
        player->x = player->y = 200;
        player->dx = player->dy = PLAYER_SPEED;
        player->texture = player_texture;
        player->direction = RIGHT;
        SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
    }

    void initEnemy(){
        for (int i = 1; i <= ENEMIES_NUMBER; i++){
            Entity *enemy = new Entity();
            enemy->x = randInt(1, SCREEN_WIDTH);
            enemy->y = randInt(1, SCREEN_HEIGHT);
            std::cout << enemy->x << " " << enemy->y << std::endl;
            enemy->dx = enemy->dy = ENEMY_SPEED;
            enemy->texture = enemy_texture;
            enemy->direction = RIGHT;
            SDL_QueryTexture(enemy->texture, NULL, NULL, &enemy->w, &enemy->h);
            enemies.push_back(enemy); 
        }
    }

    void initBackground(Graphics *graphics){
    }


    void initTexture(Graphics *graphics){
        player_texture = graphics->loadTexture(PLAYER_IMG_SOURCE);
        enemy_texture = graphics->loadTexture(ENEMY_IMG_SOURCE);
        background_texture = graphics->loadTexture(BACKGROUND_IMG_SOURCE);
    }

    void init(Graphics *graphics){
        initTexture(graphics);
        initBackground(graphics);
        initPlayer();
        initEnemy();
    }

    void doPlayer(int* keyboard){
        if (keyboard[SDL_SCANCODE_LEFT]){
            player->x -= player->dx;
            player->direction = LEFT;
        }
        if (keyboard[SDL_SCANCODE_RIGHT]){
            player->x += player->dx;
            player->direction = RIGHT;
        }

        if (keyboard[SDL_SCANCODE_UP]){
            player->y -= player->dy;
            player->direction = UP;
        }

        if (keyboard[SDL_SCANCODE_DOWN]){
            player->y += player->dy;
            player->direction = DOWN;
        }
    }

    void doEnemy(){
        for (auto &enemy : enemies){
            --enemy->side;
            if (enemy->side == 0){
                int prevDirection = enemy->direction;
                enemy->direction = (Direction)randInt(0, 3);
                while (enemy->direction == prevDirection) {
                    enemy->direction = (Direction)randInt(0, 3);
                }
                enemy->side = FPS * 2;
            }
            enemy->x += enemy->dx * direction_x[enemy->direction];
            enemy->y += enemy->dy * direction_y[enemy->direction];
        }
    }

    void doKill(){
        auto ins = enemies.begin();

        while (ins != enemies.end()){
            auto temp = ins++;
            Entity *b = *temp;
            if (player->collide(b) && player->direction == b->direction){
                delete b;
                enemies.erase(temp);
            }
        }
    }

    void doLogic(Graphics *graphics, int *keyboard){
        doPlayer(keyboard);
        doEnemy();
        doKill();
    }

    void drawBackground(Graphics *graphics) {
        for (int i = 0; i < SCREEN_WIDTH / BACKGROUND_IMG_W + 1; i++){
            for (int j = 0; j < SCREEN_HEIGHT / BACKGROUND_IMG_H + 1; j++){
                graphics->renderTexture(background_texture, i * BACKGROUND_IMG_W, j * BACKGROUND_IMG_H);
            }
        }
    }

    void doDraw(Graphics *graphics){
        // drawBackground(graphics);
        graphics->renderTexture(player->texture, player->x, player->y);
        for (auto &enemy : enemies){
            graphics->renderTexture(enemy->texture, enemy->x, enemy->y);
        }
    }

};


#endif