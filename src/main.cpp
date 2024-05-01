#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "../library/defs.h"
#include "../library/draw.h"
#include "../library/inputs.h"
#include "../library/game.h"
#include "../library/utils.h"
#include "../library/menu.h"
#include "../library/mainwindow.h"
#include "../library/state.h"

void menuLogic(MainWindow &mainWindow, Input &input, Menu &menu, State &state, long long &then, double &remainder) {
    while (state.gameState == GameState::MENU){
        mainWindow.clear();
        menu.render(state);
        mainWindow.update();

        input.get();
        menu.logic(input, state);

        
        SDL_Delay(10);
    }

    SDL_Delay(2000);
}

void gameLogic(MainWindow &mainWindow, Input &input, Game &game, long long &then, double &remainder) {

    while (true){
        mainWindow.clear();
        input.get();

        game.doLogic(input.keyboard);
        game.doDraw();

        mainWindow.update();

        capFrameRate(&then, &remainder);
    }
}

int main(int argc, char** argv) {
    Input input;
    MainWindow mainWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hunter-Kill");
    input.init();


    Menu menu(mainWindow);
    menu.init();

    Game game(mainWindow);
    game.init();
    
    State state;

    long long then = SDL_GetTicks64();
    double remainder = 0;
    
    while (true) {
        if (state.gameState == GameState::MENU)
            menuLogic(mainWindow, input, menu, state, then, remainder);
        else if (state.gameState == GameState::PLAYING)
            gameLogic(mainWindow, input, game, then, remainder);
        else
            break;
    }

}