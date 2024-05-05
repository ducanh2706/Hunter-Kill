#include "../library/game.h"

Game::Game(const MainWindow &_mainWindow): 
    level(1), 
    mainWindow(_mainWindow),
    playerTexture{_mainWindow.getRenderer()},
    enemyTexture{_mainWindow.getRenderer()},
    backgroundTexture{_mainWindow.getRenderer()},
    bulletTexture{_mainWindow.getRenderer()},
    lightTexture{_mainWindow.getRenderer()}
    {}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////// SECTION: INIT ///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Game::checkCollision(Entity *enemy){
    for (Rectangle &obstacle : level.obstacles) {
        if (enemy->collide(obstacle)) {
            return true;
        }
    }
    return false;
}

bool Game::checkInMap(Entity *enemy){
    for (Rectangle &map : level.maps) {
        if (map.contain(Vector2(enemy->x, enemy->y))) {
            return true;
        }
    }
    return false;
}

void Game::initPlayer() {
    player = new Entity();
    player->w = PLAYER_IMG_W;
    player->h = PLAYER_IMG_H;
    do {
        player->x = random.randInt(0, 39) * TILE_SIZE;
        player->y = random.randInt(0, 23) * TILE_SIZE;
    } while (
        checkCollision(player)
    );
    player->dx = player->dy = PLAYER_SPEED;
    player->texture = &playerTexture;
    player->side = PLAYER_SIDE;
    player->health = PLAYER_INITIAL_HEALTH;
    player->w = PLAYER_IMG_W;
    player->h = PLAYER_IMG_H;
}


void Game::initEnemy() {
    for (int i = 0; i < level.numMaps; i++) {
        for (int j = 0; j < level.numOfEnemies[i]; j++) {
            Enemy *enemy = new Enemy();
            enemy->w = ENEMY_IMG_W;
            enemy->h = ENEMY_IMG_H;
            do {
                enemy->x = random.randInt((int)level.maps[i].x * TILE_SIZE, ((int)level.maps[i].u) * TILE_SIZE);
                enemy->y = random.randInt((int)level.maps[i].y * TILE_SIZE, ((int)level.maps[i].v) * TILE_SIZE);
            } while (
                checkCollision(enemy)
            );
            enemy->dx = enemy->dy = ENEMY_SPEED;
            enemy->texture = &enemyTexture;
            enemy->side = ENEMY_SIDE;
            enemy->changeSide = FPS * 3;
            enemy->isWandering = 0;
            enemy->health = 1;
            enemy->tSeek = 0;
            enemy->reload = 0;
            enemy->inRec = i;
            enemy->isChasing = false;
            enemy->solver = ContextSolver();
            enemy->obstacleAvoidance = ObstacleAvoidance();
            enemy->obstacleDetector = ObstacleDetector();
            enemy->targetDetector = TargetDetector();
            enemy->targetSeek = SeekBehavior();
            enemy->wanderingBehavior = WanderingBehavior();

            enemies.push_back(enemy); 
        }
    }
}

void Game::initBackground() {

}


void Game::initTexture() {
    playerTexture.loadFromFile(PLAYER_IMG_SOURCE);
    enemyTexture.loadFromFile(ENEMY_IMG_SOURCE);
    backgroundTexture.loadFromFile(BACKGROUND_IMG_SOURCE);
    bulletTexture.loadFromFile(BULLET_IMG_SOURCE);
    lightTexture.loadFromFile(LIGHT_IMG_SOURCE);
    lightTexture.setAlpha(128);
}

void Game::initSound() {
    playerWalking.load(WALKING_SOUND);
    playerKilled.load(PLAYER_KILLED_SOUND);
    enemyShooting.load(ENEMY_SHOOTING_SOUND);
    enemyKilled.load(ENEMY_KILLED_SOUND);
    endGame.load(END_GAME);

}

void Game::initFont() {
    mFont.load(FONT_PATH, SMALL_FONT);
}

void Game::init() {
    initSound();
    initFont();
    initTexture();
    initBackground();
    initPlayer();
    initEnemy();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////// SECTION: LOGIC //////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Game::doPlayer(int* keyboard) {
    int prev_x = player->x;
    int prev_y = player->y;

    if (keyboard[SDL_SCANCODE_LEFT]) {
        player->x -= player->dx;
    }
    else if (keyboard[SDL_SCANCODE_RIGHT]) {
        player->x += player->dx;
    }

    else if (keyboard[SDL_SCANCODE_UP]) {
        player->y -= player->dy;
    }

    else if (keyboard[SDL_SCANCODE_DOWN]) {
        player->y += player->dy;
    }

    for (auto &obstacle : level.obstacles) {
        if (player->collide(obstacle)) {
            player->x = prev_x;
            player->y = prev_y;
            break;
        }
    }
}

void Game::doEnemy() {
    for (auto &enemy : enemies) {
        if (enemy->inRange(player, IN_RADIUS)){
            /// @note: IN RANGE nhưng phải nhìn thấy mà không có vật cản -> check ray cast
            bool check = true;
            for (auto &obstacle : level.obstacles) {
                if (obstacle.intersect(Vector2(enemy->x, enemy->y), Vector2(player->x, player->y))) {
                    check = false;
                    break;
                }
            }
            if (--enemy->reload <= 0 && check){
                fireBullet(enemy);
            }
        }

        if (enemy->inRange(player, OUT_RADIUS) || --enemy->isChasing >= 0){
            // cout << "Ô vcl luôn" << endl;
            bool reached = enemySeek(enemy, Vector2(player->x, player->y), OUT_RADIUS, false);
            if (!reached)
                enemy->isChasing = FPS;
            else 
                enemy->isChasing = 0;

            enemy->isWandering = 0; 
        }
        else{
            if (--enemy->isWandering <= 0){
                if (random.randInt(0, 1) == 0){
                    Entity *nEntity = new Entity();
                    do {
                        double x = random.randFloat(-100.0, 100.0);
                        double y = random.randFloat(-sqrt(10000 - x * x), sqrt(10000 - x * x));
                        nEntity->x = enemy->x + x;
                        nEntity->y = enemy->y + y;
                        
                    } while (
                        checkCollision(nEntity) || !checkInMap(nEntity)
                    );

                    enemy->isWanderingTo = Vector2(nEntity->x, nEntity->y);
                } else {
                    Vector2 seekingPosition;
                    Entity *newEntity = new Entity();
                    newEntity->w = enemy->w;
                    newEntity->h = enemy->h;
                    do{
                        seekingPosition = enemy->wanderingBehavior.getTarget(Vector2(enemy->x, enemy->y), Vector2(enemy->dx, enemy->dy), random);
                        newEntity->x = seekingPosition.x;
                        newEntity->y = seekingPosition.y;

                    } while (!checkInMap(newEntity));
                    enemy->isWanderingTo = seekingPosition;
                }
                enemyWander(enemy, enemy->isWanderingTo, OUT_RADIUS);
                enemy->isWandering = FPS * 3;
            } else{
                bool reached = enemyWander(enemy, enemy->isWanderingTo, OUT_RADIUS);
                if (reached) {
                    enemy->isWandering = 0;
                }
            }
        }
    }
}

void Game::doKill() {
    auto ins = enemies.begin();

    while (ins != enemies.end()) {
        auto temp = ins++;
        Enemy *b = *temp;
        if (player->collide(b)) {
            delete b;
            enemies.erase(temp);
            // Alert there is an enemy killed in the region
            /*
                1. Check where is that region
                2. All of enemy gonna go to that region using A* algorithm
            */
        }
    }
}

void Game::fireBullet(Enemy *enemy) {
    Enemy *bullet = new Enemy();
    bullet->x = enemy->x;
    bullet->y = enemy->y;
    bullet->side = ENEMY_SIDE;
    bullet->texture = &bulletTexture;
    SDL_QueryTexture(bulletTexture.mTexture, NULL, NULL, &bullet->w, &bullet->h);
    bullet->health = BULLET_HEALTH;
    bullets.push_back(bullet);

    bullet->x += (enemy->w / 2) - (bullet->w / 2);
    bullet->y += (enemy->h / 2) - (bullet->h / 2);

    calcSlope(player->x + ((double)player->w / 2), player->y + ((double)player->h / 2), enemy->x, enemy->y, &bullet->dx, &bullet->dy);
    bullet->dx *= BULLET_SPEED;
    bullet->dy *= BULLET_SPEED;

    enemy->reload = FPS / 3;
}

void Game::doBullet() {
    auto ins = bullets.begin();
    
    while (ins != bullets.end()) {
        auto temp = ins++;
        Enemy *b = *temp;
        b->x += b->dx;
        b->y += b->dy;
        bool isCollide = b->collide(player);
        if (isCollide || b->x < -b->w || b->y < -b->h || b->x > SCREEN_WIDTH || b->y > SCREEN_HEIGHT || checkCollision(b)) {
            if (isCollide){
                player->health--;
            }
            b->health = 0;
            delete b;
            bullets.erase(temp);
        }
    }
}

void Game::doLogic(int *keyboard) {
    // if (player->health <= 0) exit(0);
    doPlayer(keyboard);
    doEnemy();
    doKill();
    doBullet();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////// SECTION: DRAW ///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Game::drawBackground() {
    backgroundTexture.render(0, 0);
}

void Game::drawPlayer() {
    
    if (player->health) {
        SDL_Rect dest;
        dest.x = player->x;
        dest.y = player->y;
        dest.w = PLAYER_IMG_W;
        dest.h = PLAYER_IMG_H;
        player->texture->blit(&dest);
    }
}

void Game::drawEnemy() {
    for (auto &enemy : enemies) {
        SDL_Rect dest;
        dest.x = enemy->x;
        dest.y = enemy->y;
        dest.w = ENEMY_IMG_W;
        dest.h = ENEMY_IMG_H;
        enemy->texture->blit(&dest);
        

        dest.x = enemy->x + 16;
        dest.y = enemy->y - 16;
        dest.w = 64;
        dest.h = 64;

        double angle = atan2(enemy->dy, enemy->dx);
        angle = angle * 180 / PI;

        SDL_Point *point = new SDL_Point{0, 32};
        lightTexture.blit(&dest, angle, point);
        /// @note: Cần vẽ thêm hình bán nguyệt thể hiện tầm bắn hiện tại
    }
}

void Game::drawBullet() {
    for (auto &bullet : bullets) {
        bullet->texture->render(bullet->x, bullet->y);
    }
}

void Game::drawScoreboard() {
    Texture scoreboard(mainWindow.getRenderer());
    Texture health(mainWindow.getRenderer());
    
    scoreboard.loadFromRenderedText("Score: " + std::to_string(killedEnemies), mFont, {0, 0, 0});
    scoreboard.render(SCREEN_WIDTH - scoreboard.getWidth() - 50, 0);

    health.loadFromRenderedText("Health: " + std::to_string(player->health), mFont, {0, 0, 0});
    health.render(SCREEN_WIDTH - scoreboard.getWidth() - 50, 30);
}

void Game::doDraw() {
    // if (player->health <= 0) exit(0);
    drawBackground();
    drawScoreboard();
    drawPlayer();
    drawEnemy();
    drawBullet();
}


bool Game::enemyWander(Enemy *enemy, Vector2 seekingPosition, double detectionRadius) {
    return enemySeek(enemy, seekingPosition, detectionRadius, true);
}

bool Game::enemySeek(Enemy *enemy, Vector2 seekingPosition, double detectionRadius, bool isWandering) {
    ContextSolver &solver = enemy->solver;
    ObstacleAvoidance &obstacleAvoidance = enemy->obstacleAvoidance;
    ObstacleDetector &obstacleDetector = enemy->obstacleDetector;
    TargetDetector &targetDetector = enemy->targetDetector;
    SeekBehavior &targetSeek = enemy->targetSeek;

    double danger[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    double interest[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    
    vector<Rectangle> detectedObstacles;
    obstacleDetector.detect(level.obstacles, Vector2(enemy->x, enemy->y), detectedObstacles);


    bool targetDetected = targetDetector.detect(level.obstacles, Vector2(enemy->x, enemy->y), seekingPosition, detectionRadius);
    
    obstacleAvoidance.getSteering(danger, interest, Vector2(enemy->x, enemy->y), detectedObstacles);
    double dis = (Vector2(enemy->x, enemy->y) - seekingPosition).length();
    targetSeek.getSteering(danger, interest, detectedObstacles, Vector2(enemy->x, enemy->y), seekingPosition, targetDetected || (isWandering && dis > 96));
    if (targetSeek.reachLastTarget) return true;

    Vector2 direction = solver.GetDirectionToMove(danger, interest);

    enemy->dx = direction.x;
    enemy->dy = direction.y;
    enemy->x += enemy->dx;
    enemy->y += enemy->dy;
    if (!checkInMap(enemy) || checkCollision(enemy)) return true;
    if (enemy->dx == 0 && enemy->dy == 0) return true;
    return false;
}
