#ifndef _DIRECTION__H
#define _DIRECTION__H

#include <vector>
#include "vector2.h"

using std::vector;

class EightDirections {
public:
    static std::vector<Vector2> directions() {
        std::vector<Vector2> directions;
        directions.push_back(Vector2(0, -1).normalize());
        directions.push_back(Vector2(0, 1).normalize());
        directions.push_back(Vector2(-1, 0).normalize());
        directions.push_back(Vector2(1, 0).normalize());
        directions.push_back(Vector2(1, 1).normalize());
        directions.push_back(Vector2(-1, -1).normalize());
        directions.push_back(Vector2(1, -1).normalize());
        directions.push_back(Vector2(-1, 1).normalize());
        return directions;
    }
};

#endif