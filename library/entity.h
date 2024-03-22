#ifndef _ENTITY__H
#define _ENTITY__H

#include "SDL.h"

enum Direction{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

struct Entity{
    double x;
    double y;
    int w;
    int h;
    double dx;
    double dy;

    int side;
    Direction direction;
    SDL_Texture *texture;

    Entity() {
        x = y = 0;
        w = h = 0;
        dx = dy = 0;
        texture = NULL;

        side = 120;
        direction = RIGHT;

    }

    bool collide(const Entity *other) const {
        return (std::max(x, other->x) < std::min(x + w, other->x + other->w)) && (std::max(y, other->y) < std::min(y + h, other->y + other->h));
    }
};

#endif