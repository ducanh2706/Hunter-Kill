// #include "../library/entity.h"

// Enemy::Enemy(SDL_Renderer* _renderer) : Entity(_renderer) {}

// double Enemy::getRadius() const {
//     return radius;
// }

// int Enemy::getReload() const {
//     return reload;
// }

// void Enemy::setRadius(double _radius) {
//     radius = _radius;
// }

// void Enemy::setReload(int _reload) {
//     reload = _reload;
// }

// bool Enemy::inRange(const Player &player) const {
//     /***
//      * LEFT: (radius, 3PI/4 to 5PI/4)
//      * RIGHT: (radius, 7PI/4 to PI/4)
//      * UP: (radius, 5PI/4 to 7PI/4)
//      * DOWN: (radius, PI/4 to 3PI/4)
//     */

//     const double RANGE_LOWER_BOUND[4] = {5 * PI / 4, PI / 4, 3 * PI / 4, 7 * PI / 4};
//     const double RANGE_UPPER_BOUND[4] = {7 * PI / 4, 3 * PI / 4, 5 * PI / 4, PI / 4};

//     Vector vec = player.getPosition() - getPosition();

//     float angle = atan2(vec.getY(), vec.getX());
//     if (angle < 0) angle += 2 * PI;

//     double distance = vec.length();
//     if (distance > radius) return false;
//     if (getDirection() == Direction::RIGHT) return (0 <= angle && angle <= PI / 4) || (7 * PI / 4 <= angle && angle <= 2 * PI);
//     return RANGE_LOWER_BOUND[getDirection()] <= angle && angle <= RANGE_UPPER_BOUND[getDirection()]; 
// }
