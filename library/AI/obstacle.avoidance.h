#ifndef _OBSTACLE_AVOIDANCE__H
#define _OBSTACLE_AVOIDANCE__H

#include <iostream>

#include "../defs.h"

#include "../Maths/rectangle.h"
#include "../Maths/vector2.h"
#include "../Maths/8directions.h"

using std::cout;
using std::endl;
class ObstacleAvoidance {
private:
    double radius = 64;
    double agentColliderSize = 16;

public:
    void getSteering(double *danger, double *interest, Vector2 position, vector<Rectangle> &obstacles);
};

#endif