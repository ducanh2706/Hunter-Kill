#ifndef _GAME__H
#define _GAME__H

#include <SDL2/SDL.h>
#include <SDL2/SDL_scancode.h>
#include <list>
#include <iostream>
#include <chrono>
#include <random>


#include "entity.h"
#include "utils.h"
#include "defs.h"
#include "level.h"
#include "mainwindow.h"
#include "texture.h"
#include "font.h"
#include "music.h"

#include "Maths/random.h"
#include "Maths/vector2.h"

#include "AI/context.solver.h"
#include "AI/obstacle.avoidance.h"
#include "AI/obstacle.detector.h"
#include "AI/target.detector.h"
#include "AI/target.seek.h"

using std::cout;
using std::endl;


class Game {
public:
    const MainWindow &mainWindow;
    Level level;
    Entity *player;
    std::list<Enemy*> enemies;
    std::list<Enemy*> bullets;
    
    Sound playerWalking, playerKilled;
    Sound enemyShooting, enemyKilled;
    Sound endGame;

    RandomGenerator random;
    Font mFont;
    int killedEnemies = 0;


    static const int ENEMIES_NUMBER = 1;
    static constexpr int direction_x[4] = {0, 0, -1, 1};
    static constexpr int direction_y[4] = {-1, 1, 0, 0};

    // SDL_Texture *player_texture, *enemy_texture;
    // SDL_Texture *background_texture;
    // SDL_Texture *bullet_texture;


    Texture playerTexture, enemyTexture, backgroundTexture, bulletTexture;
    Texture lightTexture;


    Game(const MainWindow &_mainWindow);

    void initSound();
    void initFont();
    void initPlayer();
    void initEnemy();
    void initBackground();
    void initTexture();
    void init();

    bool checkCollision(Entity *enemy);
    bool checkInMap(Entity *enemy);

    void doPlayer(int* keyboard);
    void doEnemy();
    void doKill();
    void fireBullet(Enemy *enemy);
    void doBullet();
    void doLogic(int *keyboard);

    void drawScoreboard();
    void drawBackground();
    void drawPlayer();
    void drawEnemy();
    void drawBullet();
    void doDraw();

    bool enemySeek(Enemy *enemy, Vector2 seekPosition, double detectionRadius, bool isWandering);
    bool enemyWander(Enemy *enemy, Vector2 seekPosition, double detectionRadius);
};

#endif