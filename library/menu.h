#ifndef _MENU__H
#define _MENU__H

#include "font.h"
#include "defs.h"
#include "texture.h"
#include "mainwindow.h"
#include "inputs.h"
#include "music.h"
#include "state.h"
#include "game.h"
#include <SDL2/SDL.h>


#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

class Menu {
private:
    const MainWindow &mainWindow;
    Texture *background;
    Font bigFont, smallFont;
    Texture hunterKillRed;
    Texture startGreen, startWhite;
    Texture quitGreen, quitWhite;
    Texture choosenGreen, choosenWhite;
    Texture easyGreen, easyWhite;
    Texture mediumGreen, mediumWhite;
    Texture hardGreen, hardWhite;
    Texture musicGreen, musicWhite;
    Texture SFXGreen, SFXWhite;
    Texture xGreen, vGreen;
    Texture youWinGreen, youLoseRed;
    Texture playAgainWhite, playAgainGreen;


    Sound clickSound, confirmSound, denySound;

    vector<vector<Texture*>> generalItems;
    vector<vector<Texture*>> levelItems;
    vector<vector<Texture*>> settingItems;
    vector<vector<Texture*>> *currentItems;
    vector<Texture*> *currentChoosen;

public:

    int choosenLevel;
    bool useSFX;
    bool useMusic;

    Menu(const MainWindow& _mainWindow);
    void init();
    void render(State &state);
    void renderEnd(State &state);

    void logic(Input &input, State &state);
    void logicEnd(Input &input, State &state, Game &game);

};

#endif