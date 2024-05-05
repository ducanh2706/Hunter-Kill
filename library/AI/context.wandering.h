#ifndef _WANDERING_BEHAVIOR__H
#define _WANDERING_BEHAVIOR__H


#include <vector>
#include <algorithm>

#include "../Maths/vector2.h"
#include "../Maths/8directions.h"
#include "../Maths/random.h"

class WanderingBehavior {
private:
    double ringDistance = 50;
    double ringRadius = 30;

public:
    Vector2 getTarget(Vector2 position, Vector2 direction, RandomGenerator &random);
};

#endif