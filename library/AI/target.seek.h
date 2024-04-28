#ifndef _TARGET_SEEK__H
#define _TARGET_SEEK__H

#include <vector>

#include "../Maths/rectangle.h"
#include "../Maths/vector2.h"

class SeekBehavior {
private:
    double targetReachedThreshold = 32;
    bool reachLastTarget = true;
    Vector2 targetPositionCached;

public:
    void getSteering(double *danger, double *interest, vector<Rectangle> &obstacles, Vector2 enemy, Vector2 player, bool canSeeTarget){
        if (reachLastTarget) {

        }

        if (canSeeTarget) {
            targetPositionCached = player;
        }
        else{
            cout << "Cached: " << targetPositionCached.x << " " << targetPositionCached.y << endl;
            cout << "??????" << endl;
            cout << "??????" << endl;
            cout << "??????" << endl;cout << "??????" << endl;
            cout << "??????" << endl;cout << "??????" << endl;
            cout << "??????" << endl;cout << "??????" << endl;cout << "??????" << endl;
        }

        if ((targetPositionCached - enemy).length() < targetReachedThreshold){
            reachLastTarget = true;
            return;
        }

        reachLastTarget = false;

        Vector2 directionToTarget = (targetPositionCached - enemy).normalize();
        
        vector<Vector2> directions;
        directions.push_back(Vector2(0, -1).normalize());
        directions.push_back(Vector2(0, 1).normalize());
        directions.push_back(Vector2(-1, 0).normalize());
        directions.push_back(Vector2(1, 0).normalize());
        directions.push_back(Vector2(1, 1).normalize());
        directions.push_back(Vector2(-1, -1).normalize());
        directions.push_back(Vector2(1, -1).normalize());
        directions.push_back(Vector2(-1, 1).normalize());

        for (int i = 0; i < directions.size(); i++){
            double result = directionToTarget.dot(directions[i]);
            double valueToPutIn = result;

            if (valueToPutIn > 0 && valueToPutIn > interest[i]){
                interest[i] = valueToPutIn;
            }
        }
    }
};

#endif