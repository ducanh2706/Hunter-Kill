#include "../../library/AI/target.seek.h"

void SeekBehavior::getSteering(double *danger, double *interest, vector<Rectangle> &obstacles, Vector2 enemy, Vector2 player, bool canSeeTarget){
    if (canSeeTarget) {
        targetPositionCached = player;
    }

    if ((targetPositionCached - enemy).length() < targetReachedThreshold){
        reachLastTarget = true;
        return;
    }

    reachLastTarget = false;

    Vector2 directionToTarget = (targetPositionCached - enemy).normalize();
    
    vector<Vector2> directions = EightDirections::directions();

    for (int i = 0; i < directions.size(); i++){
        double result = directionToTarget.dot(directions[i]);
        double valueToPutIn = result;

        if (valueToPutIn > 0 && valueToPutIn > interest[i]){
            interest[i] = valueToPutIn;
        }
    }
}