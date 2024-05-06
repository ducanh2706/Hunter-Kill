#ifndef _DEFS__H
#define _DEFS__H

#include <math.h>
#include <iostream>


#define WINDOW_TITLE "Assassin Hunter"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 760

#define FONT_PATH "./fonts/EnterCommand.ttf"
#define BIG_FONT 100
#define SMALL_FONT 60


#define MAX_KEYBOARD_KEYS 350
#define FPS 60

#define TILE_SIZE 32

#define MAP_SIZE_X 2000
#define MAP_SIZE_Y 2000

#define PLAYER_IMG_SOURCE "./resources/Gunner.png"
#define ENEMY_IMG_SOURCE "./resources/Opponent.png"
#define BACKGROUND_IMG_SOURCE "./resources/map.png"
#define BULLET_IMG_SOURCE "./resources/Bullet.png"
#define LIGHT_IMG_SOURCE "./resources/light.png"
#define PLAYER_WALKING_SOURCE "./resources/player/walk.png"
#define MENU_BACKGROUND_IMG_SOURCE "./resources/menuBackground2.jpg"


#define WALKING_SOUND "./audio/SFX/player/walking.ogg"
#define ENEMY_KILLED_SOUND "./audio/SFX/enemy/killed.wav"
#define PLAYER_KILLED_SOUND "./audio/SFX/player/killed.wav"
#define ENEMY_SHOOTING_SOUND "./audio/SFX/enemy/shooting.wav"
#define END_GAME "./audio/SFX/player/endgame.wav"
#define CLICK_SOUND_PATH "./audio/SFX/menu/click.wav"
#define CONFIRM_SOUND_PATH "./audio/SFX/menu/confirm.wav"
#define DENY_SOUND_PATH "./audio/SFX/menu/deny.wav"


#define BACKGROUND_IMG_W 64
#define BACKGROUND_IMG_H 64

#define PLAYER_IMG_W 32
#define PLAYER_IMG_H 32
#define PLAYER_ORIGINAL_W 32
#define PLAYER_ORIGINAL_H 32

#define ENEMY_IMG_W 32
#define ENEMY_IMG_H 32

#define ENEMY_SPEED 1
#define PLAYER_SPEED 4
#define BULLET_SPEED 4

#define ENEMY_SIDE 1
#define PLAYER_SIDE 0

#define PLAYER_INIT_X 200
#define PLAYER_INIT_Y 200

#define PLAYER_INITIAL_HEALTH 10

#define BULLET_HEALTH 1


#define IN_RADIUS 128
#define OUT_RADIUS 256
#define PI acos(-1)

#define ASSASSIN_SPRITE_FILE = "./resources/Assassin.png"

#define ASSASSIN_FRAMES 9



#endif