#ifndef _OBSTACLE_DETECTOR__H
#define _OBSTACLE_DETECTOR__H

#include <vector>
#include <iostream>

#include "../Maths/rectangle.h"
#include "../Maths/vector2.h"
#include "../Maths/circle.h"

using std::cout;
using std::endl;

class ObstacleDetector {
private:
    double detectionRadius = 100;
public:
    void detect(vector<Rectangle> &obstacles, Vector2 position, vector<Rectangle> &detectedObstacles) {
        // check hình chữ nhật giao với đường tròn
        for (auto &obstacle : obstacles) {
            if (Circle(position.x, position.y, detectionRadius).intersect(obstacle)) {
                detectedObstacles.push_back(obstacle);
            }
        }
    }
};

#endif