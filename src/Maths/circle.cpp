#include "../../library/Maths/circle.h"

Circle::Circle(): x(0), y(0), radius(0) {}
Circle::Circle(double _x, double _y, double _radius): x(_x), y(_y), radius(_radius) {}

bool Circle::intersect(Rectangle &other) {
    double xx = max(other.x * TILE_SIZE, min((other.u + 1) * TILE_SIZE, x));
    double yy = max(other.y * TILE_SIZE, min((other.v + 1) * TILE_SIZE, y));
    double xD = x - other.x * TILE_SIZE;
    double yD = y - other.y * TILE_SIZE;
    return (xD * xD + yD * yD) <= (radius * radius);
}