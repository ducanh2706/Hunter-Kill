#include "../../library/AI/obstacle.detector.h"

void ObstacleDetector::detect(vector<Rectangle> &obstacles, Vector2 position, vector<Rectangle> &detectedObstacles) {
    for (auto &obstacle : obstacles) {
        if (Circle(position.x, position.y, detectionRadius).intersect(obstacle)) {
            detectedObstacles.push_back(obstacle);
        }
    }
}