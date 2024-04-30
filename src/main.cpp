#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "../library/graphics.h"
#include "../library/defs.h"
#include "../library/draw.h"
#include "../library/inputs.h"
#include "../library/game.h"
#include "../library/utils.h"
#include "../library/menu.h"
#include "../library/mainwindow.h"
#include "../library/state.h"

void menuLogic(MainWindow &mainWindow, Input &input, Menu &menu, State &state, long long &then, double &remainder) {
    while (true){
        input.get();
        mainWindow.clear();

        menu.logic(input, state);
        menu.render(state);

        mainWindow.update();
        // capFrameRate(&then, &remainder);
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
    menu.init();

    GeneralState generalState = GeneralState::START;
    GameState gameState = GameState::MENU;
    MenuState menuState = MenuState::GENERAL;
    SettingState settingState = SettingState::MUSIC;
    LevelState levelState = LevelState::EASY;
    State state = State(menuState, levelState, settingState, generalState, gameState);

    long long then = SDL_GetTicks64();
    double remainder = 0;
    

    // gameLogic(graphics, input, game, then, remainder); 

    while (true) {
        if (state.gameState == GameState::MENU)
            menuLogic(mainWindow, input, menu, state, then, remainder);
        else if (state.gameState == GameState::PLAYING)
            gameLogic(graphics, input, game, then, remainder);
        else
            break;
    }

    graphics.quit();

}