#include "../library/menu.h"

Menu::Menu(const MainWindow& _mainWindow):
    mainWindow(_mainWindow),
    start{_mainWindow.getRenderer()},
    quit{_mainWindow.getRenderer()}
 {}

void Menu::init(Graphics &graphics){
    mFont.load(FONT_PATH, BIG_FONT);
    start.loadFromRenderedText("START", mFont, SDL_Color{0xFF,0,0,0xFF});
}

void Menu::render(Graphics &graphics){
    start.render(SCREEN_WIDTH/2 - start.getWidth()/2, SCREEN_HEIGHT/2 - start.getHeight()/2);
}