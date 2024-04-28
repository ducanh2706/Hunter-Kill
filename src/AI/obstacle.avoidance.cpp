#include "../../library/AI/obstacle.avoidance.h"

void ObstacleAvoidance::getSteering(double *danger, double *interest, Vector2 position, vector<Rectangle> &obstacles){
    for (const auto& obstacle : obstacles) {
        Vector2 directionToObstacle = obstacle.getClosestPoint(position) - position;
        double distanceToObstacle = directionToObstacle.length();


        double weight = (distanceToObstacle <= agentColliderSize) ? 1 : (radius - distanceToObstacle) / radius;

        Vector2 directionToObstacleNormalized = directionToObstacle.normalize();
    
        vector<Vector2> directions = EightDirections::directions();

        for (int i = 0; i < directions.size(); i++) {
            double result = directionToObstacleNormalized.dot(directions[i]);
            double valueToPutIn = result * weight;
            if (valueToPutIn > danger[i]) {
                danger[i] = valueToPutIn;
            }
        }
    }
}