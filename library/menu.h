#ifndef _MENU__H
#define _MENU__H

#include "font.h"
#include "defs.h"
#include "graphics.h"
#include "texture.h"
#include "mainwindow.h"
#include <SDL2/SDL.h>


#include <iostream>
using std::cout;
using std::endl;


class Menu {
private:
    const MainWindow &mainWindow;
    Font mFont;
    Texture start;
    Texture quit;

public:

    Menu(const MainWindow& _mainWindow);
    void init(Graphics &graphics);
    void render(Graphics &graphics);

};

#endif