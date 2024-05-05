#include "../../library/AI/context.wandering.h"

#include <iostream>
using namespace std;

Vector2 WanderingBehavior::getTarget(Vector2 position, Vector2 direction, RandomGenerator &random) {
    Vector2 circlePos = position + direction.normalize() * ringDistance;
    Vector2 target = position + Vector2(ringRadius, 0).rotate(random.randFloat(0.0, 180.0));
    return target;
}