#ifndef _OBSTACLE_AVOIDANCE__H
#define _OBSTACLE_AVOIDANCE__H

#include <iostream>

#include "../Maths/rectangle.h"
#include "../Maths/vector2.h"
#include "../Maths/8directions.h"

using std::cout;
using std::endl;
class ObstacleAvoidance {
private:
    double radius = 96;
    double agentColliderSize = 64;

public:
    void getSteering(double *danger, double *interest, Vector2 position, vector<Rectangle> &obstacles);
};

#endif