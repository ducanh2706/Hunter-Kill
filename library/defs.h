#ifndef _DEFS__H
#define _DEFS__H

#include <math.h>
#include <iostream>

#define WINDOW_TITLE "Assassin Hunter"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 760

#define MAX_KEYBOARD_KEYS 350
#define FPS 60

#define MAP_SIZE_X 2000
#define MAP_SIZE_Y 2000

#define PLAYER_IMG_SOURCE "./resources/FBI_walk_cycle.png"
#define ENEMY_IMG_SOURCE "./resources/Opponent.png"
#define BACKGROUND_IMG_SOURCE "./resources/EasyMap.png"
#define BULLET_IMG_SOURCE "./resources/Bullet.png"

#define BACKGROUND_IMG_W 64
#define BACKGROUND_IMG_H 64

#define PLAYER_IMG_W 64
#define PLAYER_IMG_H 64
#define PLAYER_ORIGINAL_W 64
#define PLAYER_ORIGINAL_H 64

#define ENEMY_IMG_W 32
#define ENEMY_IMG_H 32

#define ENEMY_SPEED 1
#define PLAYER_SPEED 1
#define BULLET_SPEED 20

#define ENEMY_SIDE 1
#define PLAYER_SIDE 0

#define PLAYER_INIT_X 100
#define PLAYER_INIT_Y 100

#define PLAYER_INITIAL_HEALTH 10

#define BULLET_HEALTH 1


#define IN_RADIUS 10000
#define PI acos(-1)

#define ASSASSIN_SPRITE_FILE = "./resources/Assassin.png"

// #define ASSASSIN_FRAMES 10
// const int ASSASSIN_CLIPS[10][4] = {
//     {0, 64, 32, 32},
//     {32, 64, 32, 32},
//     {64, 64, 32, 32},
//     {96, 64, 32, 32},
//     {128, 64, 32, 32},
//     {160, 64, 32, 32},
//     {192, 64, 32, 32},
//     {224, 64, 32, 32},
//     {256, 64, 32, 32},
//     {288, 64, 32, 32},
// };

#define ASSASSIN_FRAMES 9




#endif