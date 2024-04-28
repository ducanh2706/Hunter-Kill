#ifndef _TARGET_DETECTOR__H
#define _TARGET_DETECTOR__H

#include "../Maths/rectangle.h"
#include "../defs.h"

#include <vector>
using std::vector;

class TargetDetector {
private:
    double detectionRadius = 500;
public:
    bool detect(vector<Rectangle> &obstacles, Vector2 enemy, Vector2 player);
};

#endif