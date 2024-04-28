#include "../../library/AI/target.detector.h"

bool TargetDetector::detect(vector<Rectangle> &obstacles, Vector2 enemy, Vector2 player) {
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