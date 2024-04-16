#ifndef _VECTOR__H
#define _VECTOR__H

#include <math.h>

class Vector{
private:
    double x, y;
public:

    Vector();
    Vector(double _x, double _y);
    Vector(Vector &other);

    double getX() const;
    double getY() const;

    void setX(double _x);
    void setY(double _y);

    Vector operator+ (const Vector &other) const;
    Vector operator- (const Vector &other) const;
    Vector operator* (double k) const;
    double dot(const Vector &other) const;
    double cross(const Vector &other) const;
    double length() const;
    double distance(const Vector &other) const;
    Vector normalize() const;
    Vector rotate(double angle) const;
};

#endif