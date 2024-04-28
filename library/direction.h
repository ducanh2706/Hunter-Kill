#ifndef _DIRECTION__H
#define _DIRECTION__H

#include <vector>
#include "Maths/vector2.h"

using std::vector;

class Direction {
public:
    static vector<Vector2> directions;
    
    Direction() {
        directions.push_back(Vector2(0, -1).normalize());
        directions.push_back(Vector2(0, 1).normalize());
        directions.push_back(Vector2(-1, 0).normalize());
        directions.push_back(Vector2(1, 0).normalize());
        directions.push_back(Vector2(1, 1).normalize());
        directions.push_back(Vector2(-1, -1).normalize());
        directions.push_back(Vector2(1, -1).normalize());
        directions.push_back(Vector2(-1, 1).normalize());
    }
};

#endif