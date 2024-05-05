#ifndef _RECTANGLE__H
#define _RECTANGLE__H

#include <math.h>
#include <algorithm>

#include "vector2.h"
#include "../defs.h"

class Rectangle {
public:
    double x, y;
    double u, v;
    double w, h;

    Rectangle();
    Rectangle(double _x, double _y, double _u, double _v);

    bool inMap(double _x, double _y) const;
    bool intersect(Vector2 position, Vector2 direction);
    bool contain(Vector2 point);
    Vector2 getClosestPoint(Vector2 position) const;
};

#endif