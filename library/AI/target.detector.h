#ifndef _TARGET_DETECTOR__H
#define _TARGET_DETECTOR__H

#include "../Maths/rectangle.h"
#include "../defs.h"

#include <vector>
using std::vector;

class TargetDetector {
public:
    bool detect(vector<Rectangle> &obstacles, Vector2 enemy, Vector2 player, double detectionRadius);
};

#endif