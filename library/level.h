#ifndef _LEVEL__H
#define _LEVEL__H

#include <vector>

using std::vector;

class Rectangle {
public:
    double x, y;
    double u, v;
    double w, h;

    Rectangle();
    Rectangle(double _x, double _y, double _u, double _v);

    bool inMap(double _x, double _y) const;
};

class Level {
public:
    vector<Rectangle> maps;
    vector<vector<Rectangle>> obstacles;
    int numMaps;

    vector<int> numOfEnemies;
    int enemyShootingRange;

    Level(int _level);
    Level(int _numsMaps, vector<Rectangle> _maps, vector<vector<Rectangle>> _obstacles, vector<int> _numOfEnemies, int _enemyShootingRange);
};

#endif