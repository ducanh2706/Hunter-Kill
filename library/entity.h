#ifndef _ENTITY__H
#define _ENTITY__H

#include "SDL.h"
#include "defs.h"
#include "graphics.h"

enum Direction{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

struct Entity{
    float x;
    float y;
    int w;
    int h;
    float dx;
    float dy;
    int side;
    int health;

    int changeSide;
    Direction direction;

    int radius;
    int reload;

    SDL_Texture *texture;
    Sprite *sprite;

    Entity() {
        x = y = 0;
        w = h = 0;
        dx = dy = 0;
        side = 0;
        texture = NULL;

        changeSide = 120;
        direction = RIGHT;
        reload = 0;
        health = 1;
    }

    bool collide(const Entity *other) const {
        return (std::max(x, other->x) < std::min(x + w, other->x + other->w)) && (std::max(y, other->y) < std::min(y + h, other->y + other->h));
    }

    bool inRange(const Entity *player) const {
        // Calculate the angle between the opponent's direction and the player
        float angle = atan2(player->y - y, player->x - x) * 180 / PI;
        
        // Adjust angle to be in the range [0, 360)
        if (angle < 0) {
            angle += 360;
        }
        
        // Get the current opponent's direction
        int opponentDirection = (direction == UP) ? 0 :
                                (direction == DOWN) ? 180 :
                                (direction == LEFT) ? 270 :
                                (direction == RIGHT) ? 90 : 0;

        // Calculate the angle range within which the opponent can shoot (1/8 circle)
        int angleRange = 45;
        
        // Calculate the difference between the opponent's direction and the angle to the player
        int angleDifference = abs(opponentDirection - static_cast<int>(angle));
        
        // Ensure the angle difference is within the range [0, 360)
        angleDifference %= 360;

        // Check if the angle difference is within the shooting range
        float distance = sqrt((x - player->x) * (x - player->x) + (y - player->y) * (y - player->y));
    
    // Check if the distance is within the specified radius
        return (angleDifference <= angleRange || angleDifference >= 360 - angleRange);
        // && distance <= IN_RADIUS;
    }


};

#endif