#ifndef _ENTITY__H
#define _ENTITY__H

#include "SDL.h"
#include "defs.h"
#include "graphics.h"
#include "texture.h"
#include "vector.h"
#include <math.h>
#include <SDL2/SDL.h>

enum Direction{
    UP = 0,
    LEFT = 1,
    DOWN = 2,
    RIGHT = 3,
    UP_LEFT = 4,
    UP_RIGHT = 5,
    DOWN_LEFT = 6,
    DOWN_RIGHT = 7
};

struct Sprite {
    SDL_Texture* texture;
    std::vector<SDL_Rect> clips[4];
    int currentFrame = 0;
    int counter = 0;
    Direction direction;

    void init(SDL_Texture* _texture, int frames, int width, int height) {
        direction = RIGHT;
        texture = _texture;
        counter = 0;

        SDL_Rect clip;
        for (int j = 0; j < 4; j++){
            for (int i = 0; i < frames; i++) {
                clip.y = j * width;
                clip.x = i * height;
                clip.w = width;
                clip.h = height;
                clips[j].push_back(clip);
            }
        }
    }


    void tick(Direction _direction) {
        std::cout << _direction << std::endl;
        if (direction != _direction) {
            direction = _direction;
            currentFrame = 0;
        }
        else {
            ++counter;
            if (counter % (FPS / 10) == 0)
                currentFrame = (currentFrame + 1) % clips[_direction].size();
        }
        
    }

    const SDL_Rect* getCurrentClip(Direction _direction) const {
        return &(clips[_direction][currentFrame]);
    }
};



// class Entity {
// private:
//     Vector position;
//     Vector velocity;
//     Vector acceleration;

//     Texture texture;
//     Sprite sprite;
//     Direction direction;

//     bool side;
//     int health;

// public:
//     Entity(SDL_Renderer* _renderer);

//     const Vector& getPosition() const;
//     const Vector& getVelocity() const;
//     const Vector& getAcceleration() const;
//     bool getSide() const;
//     int getHealth() const;
//     Texture getTexture() const;
//     Sprite getSprite() const;
//     Direction getDirection() const;

//     double getTextureWidth() const;
//     double getTextureHeight() const;

//     void setPosition(Vector _position);
//     void setVelocity(Vector _velocity);
//     void setAcceleration(Vector _acceleration);
//     void setSide(bool _side);
//     void setHealth(int _health);
//     void setTexture(Texture _texture);
//     void setSprite(Sprite _sprite);
//     void setDirection(Direction _direction);
//     bool collide(const Entity &other) const;
// };

// class Player : public Entity {
// public:
//     Player(SDL_Renderer* _renderer);
// };

// class Enemy : public Entity {
// private:
//     double radius;
//     int reload;

// public:
//     Enemy(SDL_Renderer* _renderer);
//     double getRadius() const;
//     int getReload() const;

//     void setRadius(double _radius);
//     void setReload(int _reload);

//     bool inRange(const Player &player) const;
// };

// class Bullet : public Entity {
// public:
//     Bullet(SDL_Renderer* _renderer);
// };


struct Entity{
    float x;
    float y;
    int w;
    int h;
    float dx;
    float dy;
    bool side;
    int health;

    int changeSide;
    Direction direction;

    int radius;
    int reload;

    SDL_Rect *rect;
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

    double distanceToOther(const Entity *other) const {
        return sqrt((x - other->x) * (x - other->x) + (y - other->y) * (y - other->y));
    }

    bool inRange(const Entity *player) const {
        /***
         * LEFT: (radius, 3PI/4 to 5PI/4)
         * RIGHT: (radius, 7PI/4 to PI/4)
         * UP: (radius, 5PI/4 to 7PI/4)
         * DOWN: (radius, PI/4 to 3PI/4)
        */

       const double RANGE_LOWER_BOUND[4] = {5 * PI / 4, PI / 4, 3 * PI / 4, 7 * PI / 4};
       const double RANGE_UPPER_BOUND[4] = {7 * PI / 4, 3 * PI / 4, 5 * PI / 4, PI / 4};

        float angle = atan2(player->y - y, player->x - x);
        if (angle < 0) angle += 2 * PI;

        double distance = distanceToOther(player);
        if (distance > radius) return false;
        if (direction == RIGHT) return (0 <= angle && angle <= PI / 4) || (7 * PI / 4 <= angle && angle <= 2 * PI);
        return RANGE_LOWER_BOUND[direction] <= angle && angle <= RANGE_UPPER_BOUND[direction];    
    }


};


#endif