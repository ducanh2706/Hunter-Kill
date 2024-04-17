#include "../library/Entity.h"


Entity::Entity() {
        x = y = 0;
        w = h = 0;
        dx = dy = 0;
        side = 0;
        health = 1;

        texture = NULL;
        rect = NULL;
        sprite = NULL;

        changeSide = 120;
        direction = RIGHT;

}

bool Entity::collide(const Entity *other) const {
    return (std::max(x, other->x) < std::min(x + w, other->x + other->w)) && (std::max(y, other->y) < std::min(y + h, other->y + other->h));
}

double Entity::distanceToOther(const Entity *other) const {
    return sqrt((x - other->x) * (x - other->x) + (y - other->y) * (y - other->y));
}

bool Enemy::inRange(const Entity *player) const {
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