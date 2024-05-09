#ifndef _OBSTACLE_DETECTOR__H
#define _OBSTACLE_DETECTOR__H

#include <vector>
#include <iostream>

#include "../Maths/rectangle.h"
#include "../Maths/vector2.h"
#include "../Maths/circle.h"

using std::vector;

class ObstacleDetector {
private:
    double detectionRadius = 64;
public:
    void detect(vector<Rectangle> &obstacles, Vector2 position, vector<Rectangle> &detectedObstacles);
};

#endif