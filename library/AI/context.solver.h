#ifndef _CONTEXT_SOLVER__H
#define _CONTEXT_SOLVER__H

#include <vector>
#include <algorithm>

#include "../Maths/vector2.h"
#include "../Maths/8directions.h"

using std::vector;

class ContextSolver {
public: 
    Vector2 GetDirectionToMove(double *danger, double *interest);
};

#endif