#ifndef _VECTOR2__H
#define _VECTOR2__H

#include <math.h>
#include "../defs.h"

class Vector2 {
public:
    double x, y;

    Vector2();
    Vector2(double x, double y);

    Vector2 operator+(const Vector2& v);

    Vector2 operator-(const Vector2& v);

    Vector2 operator*(double scalar);

    double dot(const Vector2& v);

    double cross(const Vector2& v);

    double length();

    Vector2 normalize();
    Vector2 rotate(double angle);
};

#endif