#ifndef _DEFS__H
#define _DEFS__H

#define WINDOW_TITLE "Hunter Assassin"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 768

#define MAX_KEYBOARD_KEYS 350
#define FPS 60

#define MAP_SIZE_X 2000
#define MAP_SIZE_Y 2000

#define PLAYER_IMG_SOURCE "./resources/mainAss.png"
#define ENEMY_IMG_SOURCE "./resources/oppo.png"
#define BACKGROUND_IMG_SOURCE "./resources/atlas3.png"
#define BULLET_IMG_SOURCE "./resources/bullet.png"

#define BACKGROUND_IMG_W 64
#define BACKGROUND_IMG_H 64

#define PLAYER_IMG_W 32
#define PLAYER_IMG_H 32

#define ENEMY_SPEED 1
#define PLAYER_SPEED 4
#define BULLET_SPEED 4

#define ENEMY_SIDE 1
#define PLAYER_SIDE 0

#define PLAYER_INIT_X 100
#define PLAYER_INIT_Y 100


#define IN_RADIUS 10000
#define PI 3.14159265

#define ASSASSIN_SPRITE_FILE = "./resources/mainAss.png"
#define ASSASSIN_FRAMES 10
const int ASSASSIN_CLIPS[10][4] = {
    {0, 64, 32, 32},
    {32, 64, 32, 32},
    {64, 64, 32, 32},
    {96, 64, 32, 32},
    {128, 64, 32, 32},
    {160, 64, 32, 32},
    {192, 64, 32, 32},
    {224, 64, 32, 32},
    {256, 64, 32, 32},
    {288, 64, 32, 32},
};

#endif