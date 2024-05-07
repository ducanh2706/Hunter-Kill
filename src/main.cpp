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

void menuLogic(MainWindow &mainWindow, Input &input, Menu &menu, State &state, Music &backgroundMusic, long long &then, double &remainder) {
    while (state.gameState == GameState::MENU){
        backgroundMusic.play();
        mainWindow.clear();
        menu.render(state);
        mainWindow.update();

        input.get();
        menu.logic(input, state);

        
        SDL_Delay(10);
    }

    SDL_Delay(2000);
}

void gameLogic(MainWindow &mainWindow, Input &input, Game &game, State &state, Music &backgroundMusic, long long &then, double &remainder) {

    while (state.gameState == GameState::PLAYING){
        backgroundMusic.play();
        mainWindow.clear();
        input.get();

        game.doLogic(input.keyboard);
        game.doDraw();

        mainWindow.update();

        capFrameRate(&then, &remainder);
    }
}

void endLogic(MainWindow &mainWindow, Input &input, Menu &menu, Game &game, State &state, Music &backgroundMusic, long long &then, double &remainder){
    while (state.gameState == GameState::WIN || state.gameState == GameState::LOSE){
        backgroundMusic.play();
        mainWindow.clear();
        menu.renderEnd(state);
        mainWindow.update();

        input.get();
        menu.logicEnd(input, state, game);

        SDL_Delay(10);
    }
    SDL_Delay(2000);
}

int main(int argc, char** argv) {
    Input input;
    MainWindow mainWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hunter-Kill");
    input.init();


    Menu menu(mainWindow);
    menu.init();

    State state;

    Game game(mainWindow, state);
    game.init();
    
    Music backgroundMusic;
    backgroundMusic.load("./audio/Music/music.wav");
    backgroundMusic.play();


    long long then = SDL_GetTicks64();
    double remainder = 0;
    
    while (true) {
        if (state.gameState == GameState::MENU)
            menuLogic(mainWindow, input, menu, state, backgroundMusic, then, remainder);
        else if (state.gameState == GameState::PLAYING)
            gameLogic(mainWindow, input, game, state, backgroundMusic, then, remainder);
        else
            endLogic(mainWindow, input, menu, game, state, backgroundMusic, then, remainder);
    }

}

