#include "../library/Entity.h"

#include <iostream>

using std::cout;
using std::endl;

Entity::Entity() {
        x = y = 0;
        w = h = 0;
        dx = dy = 0;
        side = 0;
        health = 1;

        texture = NULL;
        rect = NULL;

        changeSide = 120;
        // direction = RIGHT;

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
    // const double RANGE_LOWER_BOUND[4] = {5 * PI / 4, PI / 4, 3 * PI / 4, 7 * PI / 4};
    // const double RANGE_UPPER_BOUND[4] = {7 * PI / 4, 3 * PI / 4, 5 * PI / 4, PI / 4};
    // if (direction == RIGHT) return (0 <= angle && angle <= PI / 4) || (7 * PI / 4 <= angle && angle <= 2 * PI);
    // return RANGE_LOWER_BOUND[direction] <= angle && angle <= RANGE_UPPER_BOUND[direction]; 

    double distance = distanceToOther(player);
    if (distance > radius) return false;



    double angleWithPlayer = atan2(player->y - y, player->x - x);
    double angleWithVelocity = atan2(dy, dx);

    double lowerboundRange = angleWithVelocity - PI / 4;
    double upperboundRange = angleWithVelocity + PI / 4;

    angleWithPlayer += 10 * PI;
    lowerboundRange += 10 * PI;
    upperboundRange += 10 * PI;

    // cout << "angleWithPlayer: " << angleWithPlayer << endl;
    // cout << "angleWithVelocity: " << angleWithVelocity << endl;
    // cout << "lowerboundRange: " << lowerboundRange << endl;
    // cout << "upperboundRange: " << upperboundRange << endl;
    // cout << endl;


    if (lowerboundRange < angleWithPlayer && angleWithPlayer < upperboundRange) return true;
    return false;

  

    return true; 
}