#ifndef _ENTITY__H
#define _ENTITY__H

#include <SDL2/SDL.h>
#include <math.h>

#include "defs.h"
#include "graphics.h"
#include "texture.h"
#include "vector.h"


class Entity{
public:

    float x, y; // position of the entity.
    int w, h; // texture size
    float dx, dy; // vector of velocity
    bool side;
    int health; /**** player: initial health. enemy: alive or killed ****/

    int changeSide;
    Direction direction;


    SDL_Rect *rect;
    SDL_Texture *texture;
    Sprite *sprite;

    Entity();

    bool collide(const Entity *other) const;
    double distanceToOther(const Entity *other) const;
};

class Enemy : public Entity {

public:
    int radius;
    int reload;
    int inRec;

    bool inRange(const Entity *player) const;
};


#endif