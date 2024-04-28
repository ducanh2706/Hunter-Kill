#include "../library/game.h"

Game::Game(): level(1) {

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////// SECTION: INIT ///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Game::initPlayer() {
    player = new Entity();
    player->x = PLAYER_INIT_X;
    player->y = PLAYER_INIT_Y;
    player->w = PLAYER_IMG_W;
    player->h = PLAYER_IMG_H;
    player->dx = player->dy = PLAYER_SPEED;
    player->texture = player_texture;
    // player->direction = RIGHT;
    player->side = PLAYER_SIDE;
    player->health = PLAYER_INITIAL_HEALTH;
    player->w = PLAYER_IMG_W;
    player->h = PLAYER_IMG_H;
}

void Game::initEnemy() {
    for (int i = 0; i < level.numMaps; i++) {
        for (int j = 0; j < level.numOfEnemies[i]; j++) {
            Enemy *enemy = new Enemy();
            enemy->x = random.randInt((int)level.maps[i].x * TILE_SIZE, ((int)level.maps[i].u) * TILE_SIZE);
            enemy->y = random.randInt((int)level.maps[i].y * TILE_SIZE, ((int)level.maps[i].v) * TILE_SIZE);
            enemy->dx = enemy->dy = ENEMY_SPEED;
            enemy->w = ENEMY_IMG_W;
            enemy->h = ENEMY_IMG_H;
            enemy->texture = enemy_texture;
            // enemy->direction = RIGHT;
            enemy->side = ENEMY_SIDE;
            enemy->changeSide = FPS * 3;
            enemy->health = 1;
            enemy->tSeek = 0;
            enemy->radius = IN_RADIUS;
            enemy->reload = 0;
            enemy->inRec = i;
            enemy->isChasing = false;
            enemy->solver = ContextSolver();
            enemy->obstacleAvoidance = ObstacleAvoidance();
            enemy->obstacleDetector = ObstacleDetector();
            enemy->targetDetector = TargetDetector();
            enemy->targetSeek = SeekBehavior();

            enemies.push_back(enemy); 
        }
    }
}

void Game::initBackground(Graphics *graphics) {

}


void Game::initTexture(Graphics *graphics) {
    player_texture = graphics->loadTexture(PLAYER_IMG_SOURCE);
    enemy_texture = graphics->loadTexture(ENEMY_IMG_SOURCE);
    background_texture = graphics->loadTexture(BACKGROUND_IMG_SOURCE);
    bullet_texture = graphics->loadTexture(BULLET_IMG_SOURCE);
}

void Game::init(Graphics *graphics) {
    initTexture(graphics);
    initBackground(graphics);
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
        // player->direction = LEFT;
    }
    else if (keyboard[SDL_SCANCODE_RIGHT]) {
        player->x += player->dx;
        // player->direction = RIGHT;
    }

    else if (keyboard[SDL_SCANCODE_UP]) {
        player->y -= player->dy;
        // player->direction = UP;
    }

    else if (keyboard[SDL_SCANCODE_DOWN]) {
        player->y += player->dy;
        // player->direction = DOWN;
    }

    for (auto &obstacle : level.obstacles) {
        // std::cout << obstacle.x << " " << obstacle.y << " " << obstacle.u << " " << obstacle.v << " " << obstacle.w << " " << obstacle.h << std::endl;
        if (player->collide(obstacle)) {
            player->x = prev_x;
            player->y = prev_y;
            break;
        }
    }
}

void Game::doEnemy() {
    for (auto &enemy : enemies) {
        enemySeek(enemy);
        // if (enemy->distanceToOther(player) > FIND_RADIUS){
        //     // wandering
        // } else if (enemy->inRange(player)){
        //     // attacking
        // }
        // else{
        //     // seeking
        // }
        // enemy->x += enemy->dx * direction_x[enemy->direction];
        // enemy->y += enemy->dy * direction_y[enemy->direction];
        // if (enemy->x < 0) {
        //     enemy->x = 0;
        // }
        // else if (enemy->x > SCREEN_WIDTH - enemy->w) {
        //     enemy->x = SCREEN_WIDTH - enemy->w;
        // }
        // if (enemy->y < 0) {
        //     enemy->y = 0;
        // }
        // else if (enemy->y > SCREEN_HEIGHT - enemy->h) {
        //     enemy->y = SCREEN_HEIGHT - enemy->h;
        // }

        // --enemy->changeSide;
        // if (enemy->changeSide == 0) {
        //     int prevDirection = enemy->direction;
        //     enemy->direction = (Direction)random.randInt(0, 3);
        //     while (enemy->direction == prevDirection) {
        //         enemy->direction = (Direction)random.randInt(0, 3);
        //     }
        //     enemy->changeSide = FPS * 3;
        // }


        
    }
}

void Game::doKill() {
    auto ins = enemies.begin();

    while (ins != enemies.end()) {
        auto temp = ins++;
        Enemy *b = *temp;
        if (player->collide(b)) {
            // delete b;
            // enemies.erase(temp);
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
    bullet->texture = bullet_texture;
    bullet->health = BULLET_HEALTH;
    bullets.push_back(bullet);

    SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);
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
        // if (b->collide(player) || b->x < -b->w || b->y < -b->h || b->x > SCREEN_WIDTH || b->y > SCREEN_HEIGHT) {
        //     player->health = 0;
        //     b->health = 0;
        //     delete b;
        //     bullets.erase(temp);
        // }
    }
}

void Game::doLogic(Graphics *graphics, int *keyboard) {
    doPlayer(keyboard);
    doEnemy();
    doKill();
    doBullet();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////// SECTION: DRAW ///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Game::drawBackground(Graphics *graphics) {
    graphics->renderTexture(background_texture, 0, 0);
}

void Game::drawPlayer(Graphics *graphics) {
    
    if (player->health) {
        // player->sprite->tick(player->direction);
        // const SDL_Rect *srect = player->sprite->getCurrentClip(player->direction);
        // SDL_Rect dest;
        // dest.x = player->x;
        // dest.y = player->y;
        // dest.w = player->w;
        // dest.h = player->h;
        // SDL_RenderCopy(graphics->renderer, player->texture, srect, &dest);
        // graphics->renderTexture(player->texture, player->x, player->y);
        SDL_Rect dest;
        dest.x = player->x;
        dest.y = player->y;
        dest.w = ENEMY_IMG_W;
        dest.h = ENEMY_IMG_H;
        SDL_RenderCopy(graphics->renderer, player->texture, NULL, &dest);
    }
}

void Game::drawEnemy(Graphics *graphics) {
    for (auto &enemy : enemies) {
        SDL_Rect dest;
        dest.x = enemy->x;
        dest.y = enemy->y;
        dest.w = ENEMY_IMG_W;
        dest.h = ENEMY_IMG_H;
        SDL_RenderCopy(graphics->renderer, enemy->texture, NULL, &dest);
    }
}

void Game::drawBullet(Graphics *graphics) {
    for (auto &bullet : bullets) {
        graphics->renderTexture(bullet->texture, bullet->x, bullet->y);
    }
}

void Game::doDraw(Graphics *graphics) {
    drawBackground(graphics);
    drawPlayer(graphics);
    drawEnemy(graphics);
    drawBullet(graphics);
}


void Game::enemyWander(Enemy *enemy) {
}

void Game::enemyChase(Enemy *enemy) {

}

void Game::enemySeek(Enemy *enemy) {
    ContextSolver &solver = enemy->solver;
    ObstacleAvoidance &obstacleAvoidance = enemy->obstacleAvoidance;
    ObstacleDetector &obstacleDetector = enemy->obstacleDetector;
    TargetDetector &targetDetector = enemy->targetDetector;
    SeekBehavior &targetSeek = enemy->targetSeek;

    double danger[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    double interest[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    
    vector<Rectangle> detectedObstacles;
    obstacleDetector.detect(level.obstacles, Vector2(enemy->x, enemy->y), detectedObstacles);


    // cout << "Enemy position: " << enemy->x << " " << enemy->y << endl;

    // for (auto &v : detectedObstacles) {
    //     cout << "Detected obstacle: " << v.x << " " << v.y << " " << v.u << " " << v.v << endl;
    // }
    
    // cout << endl;

    bool targetDetected = targetDetector.detect(level.obstacles, Vector2(enemy->x, enemy->y), Vector2(player->x, player->y));
    
    obstacleAvoidance.getSteering(danger, interest, Vector2(enemy->x, enemy->y), detectedObstacles);

    cout << "Target detected: " << std::boolalpha << targetDetected << endl;
    cout << "Danger: ";
    for (auto v : danger) cout << v << " ";
    cout << endl;
    targetSeek.getSteering(danger, interest, detectedObstacles, Vector2(enemy->x, enemy->y), Vector2(player->x, player->y), targetDetected);
    cout << "Interest: ";
    for (auto v : interest) cout << v << " ";
    cout << endl;
    Vector2 direction = solver.GetDirectionToMove(danger, interest);

    enemy->x += direction.x;
    enemy->y += direction.y;

    cout << direction.x << " " << direction.y << " " << enemy->x << " " << enemy->y << endl;
    if (enemy->x == 0 && enemy->y == 0){
        exit(0);
    }
}
