#ifndef _CIRCLE__H
#define _CIRCLE__H

#include <math.h>
#include <iostream>

#include "../defs.h"
#include "rectangle.h"

using std::min;
using std::max;
using std::cout;
using std::endl;

class Circle {
public:
    double x, y;
    double radius;

    Circle();
    Circle(double _x, double _y, double _radius);

    bool intersect(Rectangle &other);
};

#endif