#include "../../library/AI/target.detector.h"

bool TargetDetector::detect(vector<Rectangle> &obstacles, Vector2 enemy, Vector2 player, double detectionRadius) {
    enemy.x += TILE_SIZE / 2;
    enemy.y += TILE_SIZE / 2;

    player.x += TILE_SIZE / 2;  
    player.y += TILE_SIZE / 2;

    /// @note: Cần check player cũng có trong tầm nhìn hay không
    ////////// Mỗi enemy sẽ có 1 vùng có thể nhìn được (tầm 1/4 hình tròn)

    if ((player - enemy).length() > detectionRadius) {
        return false;
    }

    Vector2 direction = (player - enemy).normalize();
    for (auto &obstacle : obstacles) {
        if (obstacle.intersect(enemy, player)) {
            return false;
        }
    }
    return true;
}