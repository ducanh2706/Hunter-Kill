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
    player->direction = RIGHT;
    player->side = PLAYER_SIDE;
    player->health = PLAYER_INITIAL_HEALTH;
    player->sprite = new Sprite();
    player->sprite->init(player->texture, ASSASSIN_FRAMES, PLAYER_ORIGINAL_W, PLAYER_ORIGINAL_H);
    player->w = PLAYER_IMG_W;
    player->h = PLAYER_IMG_H;
}

void Game::initEnemy() {
    for (int i = 1; i <= ENEMIES_NUMBER; i++) {
        Entity *enemy = new Entity();
        enemy->x = random.randInt(1, SCREEN_WIDTH);
        enemy->y = random.randInt(1, SCREEN_HEIGHT);
        enemy->dx = enemy->dy = ENEMY_SPEED;
        enemy->w = ENEMY_IMG_W;
        enemy->h = ENEMY_IMG_H;
        enemy->texture = enemy_texture;
        enemy->direction = RIGHT;
        enemy->side = ENEMY_SIDE;
        enemy->changeSide = FPS * 10;
        enemy->health = 1;
        enemy->radius = IN_RADIUS;

        enemies.push_back(enemy); 
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
    if (keyboard[SDL_SCANCODE_LEFT]) {
        player->x -= player->dx;
        player->direction = LEFT;
    }
    if (keyboard[SDL_SCANCODE_RIGHT]) {
        player->x += player->dx;
        player->direction = RIGHT;
    }

    if (keyboard[SDL_SCANCODE_UP]) {
        player->y -= player->dy;
        player->direction = UP;
    }

    if (keyboard[SDL_SCANCODE_DOWN]) {
        player->y += player->dy;
        player->direction = DOWN;
    }
}

void Game::doEnemy() {
    for (auto &enemy : enemies) {
        if (enemy->inRange(player) && --enemy->reload <= 0) {
            fireBullet(enemy);
        }
        enemy->x += enemy->dx * direction_x[enemy->direction];
        enemy->y += enemy->dy * direction_y[enemy->direction];
        if (enemy->x < 0) {
            enemy->x = 0;
        }
        else if (enemy->x > SCREEN_WIDTH - enemy->w) {
            enemy->x = SCREEN_WIDTH - enemy->w;
        }
        if (enemy->y < 0) {
            enemy->y = 0;
        }
        else if (enemy->y > SCREEN_HEIGHT - enemy->h) {
            enemy->y = SCREEN_HEIGHT - enemy->h;
        }

        --enemy->changeSide;
        if (enemy->changeSide == 0) {
            int prevDirection = enemy->direction;
            enemy->direction = (Direction)random.randInt(0, 3);
            while (enemy->direction == prevDirection) {
                enemy->direction = (Direction)random.randInt(0, 3);
            }
            enemy->changeSide = FPS * 10;
        }
    }
}

void Game::doKill() {
    auto ins = enemies.begin();

    while (ins != enemies.end()) {
        auto temp = ins++;
        Entity *b = *temp;
        if (player->collide(b) && player->direction == b->direction) {
            delete b;
            enemies.erase(temp);
        }
    }
}

void Game::fireBullet(Entity *enemy) {
    Entity *bullet = new Entity();
    bullet->x = enemy->x;
    bullet->y = enemy->y;
    bullet->side = ENEMY_SIDE;
    bullet->texture = bullet_texture;
    bullet->health = BULLET_HEALTH;
    bullets.push_back(bullet);

    SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);
    bullet->x += (enemy->w / 2) - (bullet->w / 2);
    bullet->y += (enemy->h / 2) - (bullet->h / 2);

    calcSlope(player->x + ((float)player->w / 2), player->y + ((float)player->h / 2), enemy->x, enemy->y, &bullet->dx, &bullet->dy);
    bullet->dx *= BULLET_SPEED;
    bullet->dy *= BULLET_SPEED;

    enemy->reload = FPS / 3;
}

void Game::doBullet() {
    auto ins = bullets.begin();
    
    while (ins != bullets.end()) {
        auto temp = ins++;
        Entity *b = *temp;
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
        player->sprite->tick(player->direction);
        const SDL_Rect *srect = player->sprite->getCurrentClip(player->direction);
        SDL_Rect dest;
        dest.x = player->x;
        dest.y = player->y;
        dest.w = player->w;
        dest.h = player->h;
        std::cout << dest.w << std::endl;
        SDL_RenderCopy(graphics->renderer, player->texture, srect, &dest);
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


void Game::enemyWander() {

}