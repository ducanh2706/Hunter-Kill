// struct Game {
//     Entity *player;
//     std::list<Entity*> enemies;
//     std::list<Entity*> bullets;

//     static const int ENEMIES_NUMBER = 1;
//     static constexpr int direction_x[4] = {0, 0, -1, 1};
//     static constexpr int direction_y[4] = {-1, 1, 0, 0};

//     SDL_Texture *player_texture, *enemy_texture;
//     SDL_Texture *background_texture;
//     SDL_Texture *bullet_texture;
//     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     ///////// SECTION: INIT ///////////////////////////////////////////////////////////////////////////////////////
//     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     void initPlayer() {
//         player = new Entity();
//         player->x = PLAYER_INIT_X;
//         player->y = PLAYER_INIT_Y;
//         player->w = PLAYER_IMG_W;
//         player->h = PLAYER_IMG_H;
//         player->dx = player->dy = PLAYER_SPEED;
//         player->texture = player_texture;
//         player->direction = RIGHT;
//         player->side = PLAYER_SIDE;
//         player->health = PLAYER_INITIAL_HEALTH;
//         player->sprite = new Sprite();
//         player->sprite->init(player->texture, ASSASSIN_FRAMES, PLAYER_ORIGINAL_W, PLAYER_ORIGINAL_H);
//         player->w = PLAYER_IMG_W;
//         player->h = PLAYER_IMG_H;
//     }

//     void initEnemy() {
//         for (int i = 1; i <= ENEMIES_NUMBER; i++) {
//             Entity *enemy = new Entity();
//             enemy->x = randInt(1, SCREEN_WIDTH);
//             enemy->y = randInt(1, SCREEN_HEIGHT);
//             enemy->dx = enemy->dy = ENEMY_SPEED;
//             enemy->w = ENEMY_IMG_W;
//             enemy->h = ENEMY_IMG_H;
//             enemy->texture = enemy_texture;
//             enemy->direction = RIGHT;
//             enemy->side = ENEMY_SIDE;
//             enemy->changeSide = FPS * 2;
//             enemy->health = 1;
//             enemy->radius = IN_RADIUS;

//             enemies.push_back(enemy); 
//         }
//     }

//     void initBackground(Graphics *graphics) {

//     }


//     void initTexture(Graphics *graphics) {
//         player_texture = graphics->loadTexture(PLAYER_IMG_SOURCE);
//         enemy_texture = graphics->loadTexture(ENEMY_IMG_SOURCE);
//         background_texture = graphics->loadTexture(BACKGROUND_IMG_SOURCE);
//         bullet_texture = graphics->loadTexture(BULLET_IMG_SOURCE);
//     }

//     void init(Graphics *graphics) {
//         initTexture(graphics);
//         initBackground(graphics);
//         initPlayer();
//         initEnemy();
//     }

//     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     ///////// SECTION: LOGIC //////////////////////////////////////////////////////////////////////////////////////
//     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     void doPlayer(int* keyboard) {
//         if (keyboard[SDL_SCANCODE_LEFT]) {
//             player->x -= player->dx;
//             player->direction = LEFT;
//         }
//         if (keyboard[SDL_SCANCODE_RIGHT]) {
//             player->x += player->dx;
//             player->direction = RIGHT;
//         }

//         if (keyboard[SDL_SCANCODE_UP]) {
//             player->y -= player->dy;
//             player->direction = UP;
//         }

//         if (keyboard[SDL_SCANCODE_DOWN]) {
//             player->y += player->dy;
//             player->direction = DOWN;
//         }
//     }

//     void doEnemy() {
//         for (auto &enemy : enemies) {
//             if (enemy->inRange(player) && --enemy->reload <= 0) {
//                 fireBullet(enemy);
//             }
//             enemy->x += enemy->dx * direction_x[enemy->direction];
//             enemy->y += enemy->dy * direction_y[enemy->direction];
//             if (enemy->x < 0) {
//                 enemy->x = 0;
//             }
//             else if (enemy->x > SCREEN_WIDTH - enemy->w) {
//                 enemy->x = SCREEN_WIDTH - enemy->w;
//             }
//             if (enemy->y < 0) {
//                 enemy->y = 0;
//             }
//             else if (enemy->y > SCREEN_HEIGHT - enemy->h) {
//                 enemy->y = SCREEN_HEIGHT - enemy->h;
//             }
//             // std::cout << enemy->x << " " << enemy->x << " " << enemy->w << " " << enemy->h << std::endl;
//             --enemy->changeSide;
//             if (enemy->changeSide == 0) {
//                 int prevDirection = enemy->direction;
//                 enemy->direction = (Direction)randInt(0, 3);
//                 while (enemy->direction == prevDirection) {
//                     enemy->direction = (Direction)randInt(0, 3);
//                 }
//                 enemy->changeSide = FPS * 2;
//             }
//         }
//     }

//     void doKill() {
//         auto ins = enemies.begin();

//         while (ins != enemies.end()) {
//             auto temp = ins++;
//             Entity *b = *temp;
//             if (player->collide(b) && player->direction == b->direction) {
//                 delete b;
//                 enemies.erase(temp);
//             }
//         }
//     }

//     void fireBullet(Entity *enemy) {
//         Entity *bullet = new Entity();
//         bullet->x = enemy->x;
//         bullet->y = enemy->y;
//         bullet->side = ENEMY_SIDE;
//         bullet->texture = bullet_texture;
//         bullet->health = BULLET_HEALTH;
//         bullets.push_back(bullet);

//         SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);
//         bullet->x += (enemy->w / 2) - (bullet->w / 2);
//         bullet->y += (enemy->h / 2) - (bullet->h / 2);

//         calcSlope(player->x + ((double)player->w / 2), player->y + ((double)player->h / 2), enemy->x, enemy->y, &bullet->dx, &bullet->dy);
//         bullet->dx *= BULLET_SPEED;
//         bullet->dy *= BULLET_SPEED;

//         enemy->reload = FPS / 3;
//     }

//     void doBullet() {
//         auto ins = bullets.begin();
        
//         while (ins != bullets.end()) {
//             auto temp = ins++;
//             Entity *b = *temp;
//             b->x += b->dx;
//             b->y += b->dy;
//             // if (b->collide(player) || b->x < -b->w || b->y < -b->h || b->x > SCREEN_WIDTH || b->y > SCREEN_HEIGHT) {
//             //     player->health = 0;
//             //     b->health = 0;
//             //     delete b;
//             //     bullets.erase(temp);
//             // }
//         }
//     }

//     void doLogic(Graphics *graphics, int *keyboard) {
//         doPlayer(keyboard);
//         doEnemy();
//         doKill();
//         doBullet();
//     }

//     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     ///////// SECTION: DRAW ///////////////////////////////////////////////////////////////////////////////////////
//     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     void drawBackground(Graphics *graphics) {
//         graphics->renderTexture(background_texture, 0, 0);
//     }

//     void drawPlayer(Graphics *graphics) {
        
//         if (player->health) {
//             player->sprite->tick(player->direction);
//             const SDL_Rect *srect = player->sprite->getCurrentClip(player->direction);
//             // blitRect(graphics->renderer, player->texture, rect, player->x, player->y);
//             // graphics->renderTexture(player->texture, player->x, player->y);
//             std::cout << "Player position is: (" << player->x << ", " << player->y << ")" << std::endl;
//             SDL_Rect dest;
//             dest.x = player->x;
//             dest.y = player->y;
//             dest.w = player->w;
//             dest.h = player->h;
//             std::cout << dest.w << std::endl;
//             SDL_RenderCopy(graphics->renderer, player->texture, srect, &dest);
//         }
//     }

//     void drawEnemy(Graphics *graphics) {
//         for (auto &enemy : enemies) {
//             SDL_Rect dest;
//             dest.x = enemy->x;
//             dest.y = enemy->y;
//             dest.w = ENEMY_IMG_W;
//             dest.h = ENEMY_IMG_H;
//             SDL_RenderCopy(graphics->renderer, enemy->texture, NULL, &dest);
//         }
//     }

//     void drawBullet(Graphics *graphics) {
//         for (auto &bullet : bullets) {
//             graphics->renderTexture(bullet->texture, bullet->x, bullet->y);
//         }
//     }

//     void doDraw(Graphics *graphics) {
//         drawBackground(graphics);
//         drawPlayer(graphics);
//         drawEnemy(graphics);
//         drawBullet(graphics);
//     }
// };