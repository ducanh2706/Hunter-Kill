#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "../library/graphics.h"
#include "../library/defs.h"
#include "../library/draw.h"
#include "../library/inputs.h"
#include "../library/game.h"
#include "../library/utils.h"
#include "../library/menu.h"

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


void menuLogic(Graphics &graphics, MainWindow &mainWindow, Input &input, Game &game, long long &then, double &remainder, Menu &menu,  GameState &gameState, MenuState &menuState) {
    // if (menuState == MenuState::GENERAL){
    //     menuGeneralLogic(graphics, input, game, then, remainder, gameState, menuState);
    // } else if (menuState == MenuState::CHOOSE_LEVEL){
    //     menuGeneralChooseLevel(graphics, input, game, then, remainder, gameState, menuState);
    // } else if (menuState == MenuState::SETTINGS){
    //     menuGeneralSettings(graphics, input, game, then, remainder,gameState, menuState);
    // } else if (menuState == MenuState::QUIT){
    //     gameState = GameState::QUIT;
    // } else{
        
    // } else if (menuState == MenuState::CHOOSE_LEVEL){

    // } else if (menuState == MenuState::SETTINGS){

    // } else if (menuState == MenuState::QUIT){
    //     gameState = GameState::QUIT;
    // } else{

    // }
    // while (true){
    //     cout << "Hello" << endl;
    //     input.get();
    //     graphics.prepareScene();
    //     // prepareScene(graphics.renderer);
    //     // prepareScene(graphics.renderer);
    //     menu.render(graphics);
    //     // presentScene(graphics.renderer);
    //     // presentScene(graphics.renderer);
    //     graphics.presentScene();
    //     SDL_Delay(100);
    // }


    // graphics.prepareScene();

    mainWindow.clear();

    menu.render(graphics);

    mainWindow.update();

    // graphics.presentScene();
    while (true){
        input.get();
        SDL_Delay(100);
    }

}

void gameLogic(Graphics &graphics, Input &input, Game &game, long long &then, double &remainder) {

    while (true){
        prepareScene(graphics.renderer);
        input.get();
        game.doLogic(&graphics, input.keyboard);
        game.doDraw(&graphics);

        presentScene(graphics.renderer);
        capFrameRate(&then, &remainder);
    }
}

int main(int argc, char** argv) {
    Graphics graphics;
    Input input;
    Game game = Game();


    graphics.init();
    input.init();
    game.init(&graphics);
        
    MainWindow mainWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hunter-Kill");

    Menu menu(mainWindow);
    menu.init(graphics);

    GameState gameState = GameState::MENU;
    MenuState menuState = MenuState::GENERAL;

    long long then = SDL_GetTicks64();
    double remainder = 0;
    

    while (true) {
        if (gameState == GameState::MENU)
            menuLogic(graphics, mainWindow, input, game, then, remainder, menu, gameState, menuState);
        // } else if (gameState == GameState::PLAYING) {
        //     gameLogic(graphics, input, game, then, remainder);
        // } else if (gameState == GameState::QUIT) {
        //     break;
        // }
    }

    graphics.quit();

}