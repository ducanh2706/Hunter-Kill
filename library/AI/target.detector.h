#ifndef _TARGET_DETECTOR__H
#define _TARGET_DETECTOR__H

#include "../Maths/rectangle.h"
#include "../entity.h"
#include "../defs.h"

#include <vector>

class TargetDetector {
private:
    double detectionRadius = 500;
public:
    bool detect(vector<Rectangle> &obstacles, Vector2 enemy, Vector2 player) {
        if ((player - enemy).length() > detectionRadius) {
            return false;
        }

        Vector2 direction = (player - enemy).normalize();
        for (auto &obstacle : obstacles) {
            if (obstacle.intersect(enemy, player)) {
                return false;
            }
        }
        return true;
    }
};

#endif