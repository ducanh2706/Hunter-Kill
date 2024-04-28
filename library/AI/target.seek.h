#ifndef _TARGET_SEEK__H
#define _TARGET_SEEK__H

#include <vector>

#include "../Maths/rectangle.h"
#include "../Maths/vector2.h"
#include "../Maths/8directions.h"

class SeekBehavior {
private:
    double targetReachedThreshold = 32;
    bool reachLastTarget = true;
    Vector2 targetPositionCached;

public:
    void getSteering(double *danger, double *interest, vector<Rectangle> &obstacles, Vector2 enemy, Vector2 player, bool canSeeTarget);
};

#endif