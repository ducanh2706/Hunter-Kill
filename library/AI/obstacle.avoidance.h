#ifndef _OBSTACLE_AVOIDANCE__H
#define _OBSTACLE_AVOIDANCE__H

#include <iostream>

#include "../Maths/rectangle.h"
#include "../Maths/vector2.h"

using std::cout;
using std::endl;
class ObstacleAvoidance {
private:
    double radius = 96;
    double agentColliderSize = 64;

public:
    void getSteering(double *danger, double *interest, Vector2 position, vector<Rectangle> &obstacles){
        for (const auto& obstacle : obstacles) {
            // cout << "Point Find: " << obstacle.getClosestPoint(position).x << " " << obstacle.getClosestPoint(position).y << endl;
            Vector2 directionToObstacle = obstacle.getClosestPoint(position) - position;
            double distanceToObstacle = directionToObstacle.length();
            // cout << "Distance is: " << distanceToObstacle << endl;

            // Calculate weight based on the distance Enemy<--->Obstacle
            double weight = (distanceToObstacle <= agentColliderSize) ? 1 : (radius - distanceToObstacle) / radius;

            Vector2 directionToObstacleNormalized = directionToObstacle.normalize();
            

            // // Add obstacle parameters to the danger array
            vector<Vector2> directions;
            directions.push_back(Vector2(0, -1).normalize());
            directions.push_back(Vector2(0, 1).normalize());
            directions.push_back(Vector2(-1, 0).normalize());
            directions.push_back(Vector2(1, 0).normalize());
            directions.push_back(Vector2(1, 1).normalize());
            directions.push_back(Vector2(-1, -1).normalize());
            directions.push_back(Vector2(1, -1).normalize());
            directions.push_back(Vector2(-1, 1).normalize());

            for (int i = 0; i < directions.size(); i++) {
                double result = directionToObstacleNormalized.dot(directions[i]);
                // cout << directionToObstacleNormalized.x << " " << directionToObstacleNormalized.y << endl;
                // cout << directions[i].x << " " << directions[i].y << " " << weight << endl;

                double valueToPutIn = result * weight;
                assert(valueToPutIn <= 1.0);

                // Override value only if it is higher than the current one stored in the danger array
                if (valueToPutIn > danger[i]) {
                    danger[i] = valueToPutIn;
                }
            }
        }
    }
};

#endif