#include "../library/Entity.h"

#include <iostream>

Entity::Entity() {
        x = y = 0;
        w = h = 0;
        dx = dy = 0;
        side = 0;
        health = 1;

        texture = nullptr;
        rect = nullptr;
        sprite = nullptr;
}

Entity::~Entity() {
    if (texture != nullptr) {
        delete texture;
        texture = nullptr;
    }

    if (rect != NULL) {
        delete rect;
        rect = nullptr;
    }

    if (sprite != NULL) {
        delete sprite;
        sprite = nullptr;
    }
}

bool Entity::collide(const Entity *other) const {
    return (std::max(x, other->x) < std::min(x + w, other->x + other->w)) && (std::max(y, other->y) < std::min(y + h, other->y + other->h));
}

bool Entity::collide(const Rectangle &other) const {
    return (std::max(x, other.x * TILE_SIZE) < std::min(x + w, (other.u + 1) * TILE_SIZE)) && (std::max(y, other.y * TILE_SIZE) < std::min(y + h, (other.v + 1) * TILE_SIZE));
}

double Entity::distanceToOther(const Entity *other) const {
    return sqrt((x - other->x) * (x - other->x) + (y - other->y) * (y - other->y));
}

bool Enemy::inRange(const Entity *player, int radius) const {
    double distance = distanceToOther(player);
    if (distance > radius) return false;

    double angleWithPlayer = atan2(player->y - y, player->x - x);
    double angleWithVelocity = atan2(dy, dx);

    double lowerboundRange = angleWithVelocity - PI / 4;
    double upperboundRange = angleWithVelocity + PI / 4;

    angleWithPlayer += 10 * PI;
    lowerboundRange += 10 * PI;
    upperboundRange += 10 * PI;


    if (lowerboundRange < angleWithPlayer && angleWithPlayer < upperboundRange) return true;
    return false;
}