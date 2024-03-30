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

void blitRect(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *src, int x, int y);
void calcSlope(int x1, int y1, int x2, int y2, float *dx, float *dy);

// const int ASSASSIN_CLIPS[][4] = {
//     {64, 0, 32, 32},
//     {64, 32, 32, 32},
//     {64, 64, 32, 32},
//     {64, 96, 32, 32},
//     {64, 128, 32, 32},
//     {64, 160, 32, 32},
//     {64, 192, 32, 32},
//     {64, 224, 32, 32},
//     {64, 256, 32, 32},
//     {64, 288, 32, 32},
// };

struct Game{
    Entity *player;
    std::list<Entity*> enemies;
    std::list<Entity*> bullets;

    static const int ENEMIES_NUMBER = 1;
    static constexpr int direction_x[4] = {0, 0, -1, 1};
    static constexpr int direction_y[4] = {-1, 1, 0, 0};

    SDL_Texture *player_texture, *enemy_texture;
    SDL_Texture *background_texture;
    SDL_Texture *bullet_texture;

    void initPlayer(){
        player = new Entity();
        player->x = PLAYER_INIT_X;
        player->y = PLAYER_INIT_Y;
        player->dx = player->dy = PLAYER_SPEED;
        player->texture = player_texture;
        player->direction = RIGHT;
        player->side = PLAYER_SIDE;
        player->health = 1;
        player->sprite = new Sprite();
        player->sprite->init(player->texture, ASSASSIN_FRAMES, ASSASSIN_CLIPS);
        player->w = PLAYER_IMG_W;
        player->h = PLAYER_IMG_H;
    }

    void initEnemy(){
        for (int i = 1; i <= ENEMIES_NUMBER; i++){
            Entity *enemy = new Entity();
            enemy->x = randInt(1, SCREEN_WIDTH);
            enemy->y = randInt(1, SCREEN_HEIGHT);
            enemy->dx = enemy->dy = ENEMY_SPEED;
            enemy->texture = enemy_texture;
            enemy->direction = RIGHT;
            enemy->side = ENEMY_SIDE;
            enemy->changeSide = FPS * 2;
            enemy->health = 1;
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
        bullet_texture = graphics->loadTexture(BULLET_IMG_SOURCE);
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
            if (enemy->inRange(player) && --enemy->reload <= 0){
                fireBullet(enemy);
            }
            enemy->x += enemy->dx * direction_x[enemy->direction];
            enemy->y += enemy->dy * direction_y[enemy->direction];
            if (enemy->x < 0){
                enemy->x = 0;
            }
            else if (enemy->x > SCREEN_WIDTH - enemy->w){
                enemy->x = SCREEN_WIDTH - enemy->w;
            }
            if (enemy->y < 0){
                enemy->y = 0;
            }
            else if (enemy->y > SCREEN_HEIGHT - enemy->h){
                enemy->x = SCREEN_HEIGHT - enemy->h;
            }

            --enemy->changeSide;
            if (enemy->changeSide == 0){
                int prevDirection = enemy->direction;
                enemy->direction = (Direction)randInt(0, 3);
                while (enemy->direction == prevDirection) {
                    enemy->direction = (Direction)randInt(0, 3);
                }
                enemy->changeSide = FPS * 2;
            }
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

    void fireBullet(Entity *enemy){
        Entity *bullet = new Entity();
        bullet->x = enemy->x;
        bullet->y = enemy->y;
        bullet->side = ENEMY_SIDE;
        bullet->texture = bullet_texture;
        bullet->health = 1;
        bullets.push_back(bullet);

        SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);
        bullet->x += (enemy->w / 2) - (bullet->w / 2);
        bullet->y += (enemy->h / 2) - (bullet->h / 2);

        calcSlope(player->x + (player->w / 2), player->y + (player->h / 2), enemy->x, enemy->y, &bullet->dx, &bullet->dy);
        bullet->dx *= BULLET_SPEED;
        bullet->dy *= BULLET_SPEED;

        enemy->reload = FPS / 3;
    }

    void doBullet(){
        auto ins = bullets.begin();
        
        while (ins != bullets.end()){
            auto temp = ins++;
            Entity *b = *temp;
            b->x += b->dx;
            b->y += b->dy;
            // if (b->collide(player) || b->x < -b->w || b->y < -b->h || b->x > SCREEN_WIDTH || b->y > SCREEN_HEIGHT){
            //     player->health = 0;
            //     b->health = 0;
            //     delete b;
            //     bullets.erase(temp);
            // }
        }
    }

    void doLogic(Graphics *graphics, int *keyboard){
        doPlayer(keyboard);
        doEnemy();
        doKill();
        doBullet();
    }

    void drawBackground(Graphics *graphics) {
        for (int i = 0; i < SCREEN_WIDTH / BACKGROUND_IMG_W + 1; i++){
            for (int j = 0; j < SCREEN_HEIGHT / BACKGROUND_IMG_H + 1; j++){
                graphics->renderTexture(background_texture, i * BACKGROUND_IMG_W, j * BACKGROUND_IMG_H);
            }
        }
    }

    void drawPlayer(Graphics *graphics){
        
        if (player->health){
            player->sprite->tick();
            const SDL_Rect *rect = player->sprite->getCurrentClip();
            blitRect(graphics->renderer, player->texture, rect, player->x, player->y);
        }
    }

    void drawEnemy(Graphics *graphics){
        for (auto &enemy : enemies){
            graphics->renderTexture(enemy->texture, enemy->x, enemy->y);
        }
    }

    void drawBullet(Graphics *graphics){
        for (auto &bullet : bullets){
            graphics->renderTexture(bullet->texture, bullet->x, bullet->y);
        }
    }

    void doDraw(Graphics *graphics){
        drawBackground(graphics);
        drawPlayer(graphics);
        drawEnemy(graphics);
        drawBullet(graphics);
    }

};


#endif