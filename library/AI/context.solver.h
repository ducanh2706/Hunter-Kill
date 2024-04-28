#ifndef _CONTEXT_SOLVER__H
#define _CONTEXT_SOLVER__H

#include <vector>
#include <algorithm>

#include "../Maths/vector2.h"

using std::vector;
class ContextSolver {
public: 
    Vector2 GetDirectionToMove(double *danger, double *interest){
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
            interest[i] = std::clamp(interest[i] - danger[i], 0.0, 1.0);
        }

        Vector2 result;
        for (int i = 0; i < directions.size(); i++){
            result = result + directions[i] * interest[i];
        }
        return result.normalize();
    }
};

#endif