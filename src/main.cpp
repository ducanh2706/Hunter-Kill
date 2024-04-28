#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "../library/graphics.h"
#include "../library/defs.h"
#include "../library/draw.h"
#include "../library/inputs.h"
#include "../library/game.h"
#include "../library/utils.h"

enum MenuState {
    GENERAL,
    MENU_QUIT,
    CHOOSE_LEVEL,
    SETTINGS
};

enum LevelState {
    EASY,
    MEDIUM,
    HARD
};

enum SettingState {
    BACKGROUND,
    SFX,
    RETURN,
};

enum GameState {
    MENU,
    PLAYING,
    QUIT
};

// void menuGeneralLogic(Graphics &graphics, Input &input, Game &game, long long &then, double &remainder, GameState &gameState MenuState &menuState) {
//     if (input.keyboard[SDL_SCANCODE_ESCAPE]) {
//         menuState = MenuState::QUIT;
//     } else if (input.keyboard[SDL_SCANCODE_1]) {
//         menuState = MenuState::CHOOSE_LEVEL;
//     } else if (input.keyboard[SDL_SCANCODE_2]) {
//         menuState = MenuState::SETTINGS;
//     }
// }

// void menuGeneralChooseLevel(Graphics &graphics, Input &input, Game &game, long long &then, double &remainder, GameState &gameState, MenuState &menuState) {
//     if (input.keyboard[SDL_SCANCODE_ESCAPE]) {
//         menuState = MenuState::GENERAL;
//     } else if (input.keyboard[SDL_SCANCODE_1]) {
//         game.level = LevelState::EASY;
//         menuState = MenuState::GENERAL;
//     } else if (input.keyboard[SDL_SCANCODE_2]) {
//         game.level = LevelState::MEDIUM;
//         menuState = MenuState::GENERAL;
//     } else if (input.keyboard[SDL_SCANCODE_3]) {
//         game.level = LevelState::HARD;
//         menuState = MenuState::GENERAL;
//     }

// }

// void menuGeneralSettings(Graphics &graphics, Input &input, Game &game, long long &then, double &remainder, GameState &gameState, MenuState &menuState) {
//     if (input.keyboard[SDL_SCANCODE_ESCAPE]) {
//         menuState = MenuState::GENERAL;
//     } else if (input.keyboard[SDL_SCANCODE_1]) {
//         game.setting = SettingState::BACKGROUND;
//         menuState = MenuState::GENERAL;
//     } else if (input.keyboard[SDL_SCANCODE_2]) {
//         game.setting = SettingState::SFX;
//         menuState = MenuState::GENERAL;
//     }
// }


// void menuLogic(Graphics &graphics, Input &input, Game &game, long long &then, double &remainder, GameState &gameState, MenuState &menuState) {
//     if (menuState == MenuState::GENERAL){
//         menuGeneralLogic(graphics, input, game, then, remainder, gameState, menuState);
//     } else if (menuState == MenuState::CHOOSE_LEVEL){
//         menuGeneralChooseLevel(graphics, input, game, then, remainder, gameState, menuState);
//     } else if (menuState == MenuState::SETTINGS){
//         menuGeneralSettings(graphics, input, game, then, remainder,gameState, menuState);
//     } else if (menuState == MenuState::QUIT){
//         gameState = GameState::QUIT;
//     } else{
        
//     } else if (menuState == MenuState::CHOOSE_LEVEL){

//     } else if (menuState == MenuState::SETTINGS){

//     } else if (menuState == MenuState::QUIT){
//         gameState = GameState::QUIT;
//     } else{

//     }

// }

void gameLogic(Graphics &graphics, Input &input, Game &game, long long &then, double &remainder) {
    prepareScene(graphics.renderer);
    input.get();
    game.doLogic(&graphics, input.keyboard);
    game.doDraw(&graphics);

    presentScene(graphics.renderer);
    capFrameRate(&then, &remainder);
}

int main(int argc, char** argv) {
    Graphics graphics;
    Input input;
    Game game = Game();

    GameState gameState = GameState::PLAYING;

    graphics.init();
    input.init();
    game.init(&graphics);

    long long then = SDL_GetTicks64();
    double remainder = 0;

    
    while (true) {
        if (gameState == GameState::MENU) {
            // menuLogic(graphics, input, game, then, remainder);
        } else if (gameState == GameState::PLAYING) {
            gameLogic(graphics, input, game, then, remainder);
        } else if (gameState == GameState::QUIT) {
            break;
        }
    }

    graphics.quit();

}