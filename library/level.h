#ifndef _LEVEL__H
#define _LEVEL__H

#include <vector>
#include <list>

#include "entity.h"
#include "Maths/rectangle.h"

using std::vector;
using std::list;

class Level {
public:
    vector<Rectangle> maps;
    vector<Rectangle> obstacles;
    vector<vector<bool>> isObstacle;
    int numMaps;

    vector<int> numOfEnemies;
    
    int enemyShootingRange;

    Level();
    Level(int _numsMaps, vector<Rectangle> _maps, vector<Rectangle> _obstacles, vector<int> _numOfEnemies, int _enemyShootingRange);
};

#endif