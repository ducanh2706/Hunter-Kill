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
#define X_TILE_SIZE 40
#define Y_TILE_SIZE 24

#define MAP_SIZE_X 2000
#define MAP_SIZE_Y 2000

#define BACKGROUND_IMG_SOURCE "./resources/map.png"
#define BULLET_IMG_SOURCE "./resources/Bullet.png"
#define LIGHT_IMG_SOURCE "./resources/light.png"
#define PLAYER_SWORD_IMG_SOURCE "./resources/player/sword.png"
#define PLAYER_WALKING_SOURCE "./resources/player/knight.png"
#define PLAYER_SWORD_EFFECT_SOURCE "./resources/player/slash.png"
#define MENU_BACKGROUND_IMG_SOURCE "./resources/menuBackground.jpg"
#define ENEMY_WALKING_SOURCE "./resources/Enemy/enemy.png"


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


#define ENEMY_INITIAL_HEALTH 10

#define NUM_ENEMY_WALKING_SPRITE 6
#define ENEMY_WALKING_ORIGINAL_SPRITE_SIZE 32
#define ENEMY_WALKING_RENDER_SPRITE_SIZE 32
#define DELAY_ENEMY_WALKING_SPRITE 10

#define PLAYER_WALKING_ORIGINAL_SPRITE_SIZE 16
#define PLAYER_WALKING_RENDER_SPRITE_SIZE 32
#define NUM_PLAYER_WALKING_SPRITE 6
#define DELAY_PLAYER_WALKING_SPRITE 10

#define SWORD_EFFECT_ORIGINAL_SPRITE_SIZE 16
#define SWORD_EFFECT_RENDER_SPRITE_SIZE 16
#define NUM_SWORD_EFFECT_SPRITE 3
#define DELAY_SWORD_EFFECT_SPRITE 5

#define SWORD_MARGIN_X 10
#define SWORD_MARGIN_Y 10

#define LIGHT_IMG_W 64
#define LIGHT_IMG_H 64
#define LIGHT_MARGIN_X 16
#define LIGHT_MARGIN_Y 16
#define MIDDLE_LIGHT_X 0
#define MIDDLE_LIGHT_Y 32
#define SCORE_BOARD_MARGIN_X 50

#define HEALTH_Y 30
#define SCORE_Y 0

#define IGNORE_DISTANCE 96

#define LIGHT_TEXTURE_OPACITY 128

#define RANGE_ENEMY_WANDER 100.0

#define NUM_OF_OBSTACLES 587

#define IN_RADIUS 128
#define OUT_RADIUS 256
#define PI acos(-1)

#define ASSASSIN_SPRITE_FILE = "./resources/Assassin.png"

#define ASSASSIN_FRAMES 9



#endif