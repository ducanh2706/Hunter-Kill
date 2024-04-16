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
        Rectangle(2, 1, 12, 8),
        Rectangle(13, 4, 19, 5),
        Rectangle(20, 1, 22, 12),
        Rectangle(7, 9, 10, 16),
        Rectangle(2, 17, 10, 30),
        Rectangle(7, 31, 10, 38),
        Rectangle(11, 27, 17, 28),
        Rectangle(18, 20, 22, 38)
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