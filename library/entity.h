#ifndef _ENTITY__H
#define _ENTITY__H

#include <SDL2/SDL.h>
#include <math.h>

#include "defs.h"
#include "texture.h"
#include "sprites.h"

#include "Maths/rectangle.h"
#include "Maths/vector2.h"

#include "AI/context.solver.h"
#include "AI/obstacle.avoidance.h"
#include "AI/Obstacle.detector.h"
#include "AI/target.detector.h"
#include "AI/context.wandering.h"
#include "AI/target.seek.h"

using std::pair;
using std::vector;


class Entity{
public:
    double x, y; // position of the entity.
    int w, h; // texture size
    double dx, dy; // vector of velocity
    bool side;
    int health; /**** player: initial health. enemy: alive or killed ****/

    SDL_Rect *rect;
    Texture *texture;
    Sprite *sprite;

    Entity();

    bool collide(const Entity *other) const;
    bool collide(const Rectangle &other) const;
    double distanceToOther(const Entity *other) const;
};

class Enemy : public Entity {
public:
    int reload;
    int inRec;
    int isChasing;
    int tSeek;
    int isWandering;
    bool killed;
    Vector2 isWanderingTo;
    vector<pair<int, int>> path;
    ContextSolver solver;
    ObstacleAvoidance obstacleAvoidance;
    ObstacleDetector obstacleDetector;
    TargetDetector targetDetector;
    WanderingBehavior wanderingBehavior;
    SeekBehavior targetSeek;

    bool inRange(const Entity *player, int radius) const;
};


#endif