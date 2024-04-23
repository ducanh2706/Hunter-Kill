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

    obstacles.resize(66);

    obstacles = {
        Rectangle(2, 3, 2, 3),
        Rectangle(3, 3, 3, 3),
        Rectangle(4, 3, 4, 3),
        Rectangle(5, 3, 5, 3),
        Rectangle(18, 3, 18, 3),
        Rectangle(29, 3, 29, 3),
        Rectangle(2, 4, 2, 4),
        Rectangle(3, 4, 3, 4),
        Rectangle(4, 4, 4, 4),
        Rectangle(5, 4, 5, 4),
        Rectangle(18, 4, 18, 4),
        Rectangle(29, 4, 29, 4),
        Rectangle(2, 5, 2, 5),
        Rectangle(3, 5, 3, 5),
        Rectangle(4, 5, 4, 5),
        Rectangle(5, 5, 5, 5),
        Rectangle(18, 5, 18, 5),
        Rectangle(19, 5, 19, 5),
        Rectangle(20, 5, 20, 5),
        Rectangle(21, 5, 21, 5),
        Rectangle(22, 5, 22, 5),
        Rectangle(25, 5, 25, 5),
        Rectangle(26, 5, 26, 5),
        Rectangle(27, 5, 27, 5),
        Rectangle(28, 5, 28, 5),
        Rectangle(29, 5, 29, 5),
        Rectangle(5, 8, 5, 8),
        Rectangle(11, 8, 11, 8),
        Rectangle(12, 8, 12, 8),
        Rectangle(23, 8, 23, 8),
        Rectangle(24, 8, 24, 8),
        Rectangle(36, 8, 36, 8),
        Rectangle(37, 8, 37, 8),
        Rectangle(5, 9, 5, 9),
        Rectangle(11, 9, 11, 9),
        Rectangle(12, 9, 12, 9),
        Rectangle(23, 9, 23, 9),
        Rectangle(24, 9, 24, 9),
        Rectangle(36, 9, 36, 9),
        Rectangle(37, 9, 37, 9),
        Rectangle(2, 10, 2, 10),
        Rectangle(3, 10, 3, 10),
        Rectangle(4, 10, 4, 10),
        Rectangle(5, 10, 5, 10),
        Rectangle(21, 19, 21, 19),
        Rectangle(22, 19, 22, 19),
        Rectangle(23, 19, 23, 19),
        Rectangle(24, 19, 24, 19),
        Rectangle(25, 19, 25, 19),
        Rectangle(26, 19, 26, 19),
        Rectangle(27, 19, 27, 19),
        Rectangle(31, 19, 31, 19),
        Rectangle(32, 19, 32, 19),
        Rectangle(33, 19, 33, 19),
        Rectangle(34, 19, 34, 19),
        Rectangle(35, 19, 35, 19),
        Rectangle(36, 19, 36, 19),
        Rectangle(37, 19, 37, 19),
        Rectangle(27, 20, 27, 20),
        Rectangle(31, 20, 31, 20),
        Rectangle(2, 21, 2, 21),
        Rectangle(3, 21, 3, 21),
        Rectangle(10, 21, 10, 21),
        Rectangle(11, 21, 11, 21),
        Rectangle(27, 21, 27, 21),
        Rectangle(31, 21, 31, 21)
    };

    isObstacle = vector<vector<bool>>(SCREEN_WIDTH + 1, vector<bool>(SCREEN_HEIGHT + 1, 0));

    for (auto &obstacle : obstacles) {
        for (int i = obstacle.x; i <= obstacle.u; ++i) {
            for (int j = obstacle.y; j <= obstacle.v; ++j) {
                isObstacle[i][j] = 1;
            }
        }
    }

    int enemyShootingRange = 10;

}

Level::Level(int _numMaps, vector<Rectangle> _maps, vector<Rectangle> _obstacles, vector<int> _numOfEnemies, int _enemyShootingRange) {
    numMaps = _numMaps;
    maps = _maps;
    obstacles = _obstacles;
    numOfEnemies = _numOfEnemies;
    enemyShootingRange = _enemyShootingRange;
}