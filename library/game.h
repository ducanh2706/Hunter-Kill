#ifndef _GAME__H
#define _GAME__H

#include <list>
#include <iostream>
#include <chrono>
#include <random>

#include "entity.h"
#include "utils.h"
#include "defs.h"
#include "SDL.h"
#include "SDL_scancode.h"
#include "random.h"
#include "level.h"

struct Game {
    Level level;
    Entity *player;
    std::list<Entity*> enemies;
    std::list<Entity*> bullets;
    RandomGenerator random;

    static const int ENEMIES_NUMBER = 1;
    static constexpr int direction_x[4] = {0, 0, -1, 1};
    static constexpr int direction_y[4] = {-1, 1, 0, 0};

    SDL_Texture *player_texture, *enemy_texture;
    SDL_Texture *background_texture;
    SDL_Texture *bullet_texture;

    Game();

    void initPlayer();
    void initEnemy();
    void initBackground(Graphics *graphics);
    void initTexture(Graphics *graphics);
    void init(Graphics *graphics);

    void doPlayer(int* keyboard);
    void doEnemy();
    void doKill();
    void fireBullet(Entity *enemy);
    void doBullet();
    void doLogic(Graphics *graphics, int *keyboard);

    void drawBackground(Graphics *graphics);
    void drawPlayer(Graphics *graphics);
    void drawEnemy(Graphics *graphics);
    void drawBullet(Graphics *graphics);
    void doDraw(Graphics *graphics);

    void enemySeek();
    void enemyWander();
    void enemyChase();
};

#endif