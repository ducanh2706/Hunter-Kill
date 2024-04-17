#include "../library/level.h"


Rectangle::Rectangle() {
    x = y = u = v = w = h = 0;
}

Rectangle::Rectangle(double _x, double _y, double _u, double _v) {
    x = _x;
    y = _y;
    u = _u;
    v = _v;
    w = u - x;
    h = v - y;
}

bool Rectangle::inMap(double _x, double _y) const {
    return x <= _x && _x <= u && y <= _y && _y <= v;
}

Level::Level(int _level) {
    numMaps = 8;
    maps.resize(8);
    maps = {
        Rectangle(1, 2, 8, 12),
        Rectangle(4, 13, 5, 19),
        Rectangle(1, 20, 12, 22),
        Rectangle(9, 7, 16, 10),
        Rectangle(17, 2, 30, 10),
        Rectangle(31, 7, 38, 10),
        Rectangle(27, 11, 28, 17),
        Rectangle(20, 18, 38, 22)
    };

    numOfEnemies.resize(8);
    numOfEnemies = {2, 2, 2, 2, 2, 2, 2, 2};
    int enemyShootingRange = 10;

}

Level::Level(int _numMaps, vector<Rectangle> _maps, vector<vector<Rectangle>> _obstacles, vector<int> _numOfEnemies, int _enemyShootingRange) {
    numMaps = _numMaps;
    maps = _maps;
    obstacles = _obstacles;
    numOfEnemies = _numOfEnemies;
    enemyShootingRange = _enemyShootingRange;
}