#include "../library/menu.h"

Menu::Menu(const MainWindow& _mainWindow):
    mainWindow(_mainWindow),
    startGreen{_mainWindow.getRenderer()},
    startWhite{_mainWindow.getRenderer()},
    quitGreen{_mainWindow.getRenderer()},
    quitWhite{_mainWindow.getRenderer()},
    choosenGreen{_mainWindow.getRenderer()},
    choosenWhite{_mainWindow.getRenderer()},
    easyGreen{_mainWindow.getRenderer()},
    easyWhite{_mainWindow.getRenderer()},
    mediumGreen{_mainWindow.getRenderer()},
    mediumWhite{_mainWindow.getRenderer()},
    hardGreen{_mainWindow.getRenderer()},
    hardWhite{_mainWindow.getRenderer()},
    musicGreen{_mainWindow.getRenderer()},
    musicWhite{_mainWindow.getRenderer()},
    SFXGreen{_mainWindow.getRenderer()},
    SFXWhite{_mainWindow.getRenderer()},
    xGreen(_mainWindow.getRenderer()),
    vGreen(_mainWindow.getRenderer())
 {
 }

void Menu::init(){
    bigFont.load(FONT_PATH, BIG_FONT);
    smallFont.load(FONT_PATH, SMALL_FONT);
    SDL_Color greenCol = {0, 0xFF, 0, 0xFF};
    SDL_Color whiteCol = {0xFF, 0xFF, 0xFF, 0xFF};

    useMusic = true;
    useSFX = true;
    choosenLevel = 0;

    startGreen.loadFromRenderedText("START", bigFont, greenCol);
    startWhite.loadFromRenderedText("START", bigFont, whiteCol);
    quitGreen.loadFromRenderedText("QUIT", bigFont, greenCol);
    quitWhite.loadFromRenderedText("QUIT", bigFont, whiteCol);
    choosenGreen.loadFromRenderedText(">", bigFont, greenCol);
    choosenWhite.loadFromRenderedText(">", bigFont, whiteCol);
    easyGreen.loadFromRenderedText("EASY", bigFont, greenCol);
    easyWhite.loadFromRenderedText("EASY", bigFont, whiteCol);
    mediumGreen.loadFromRenderedText("MEDIUM", bigFont, greenCol);
    mediumWhite.loadFromRenderedText("MEDIUM", bigFont, whiteCol);
    hardGreen.loadFromRenderedText("HARD", bigFont, greenCol);
    hardWhite.loadFromRenderedText("HARD", bigFont, whiteCol);
    musicGreen.loadFromRenderedText("MUSIC", bigFont, greenCol);
    musicWhite.loadFromRenderedText("MUSIC", bigFont, whiteCol);
    SFXGreen.loadFromRenderedText("SFX", bigFont, greenCol);
    SFXWhite.loadFromRenderedText("SFX", bigFont, whiteCol);
    xGreen.loadFromRenderedText("x", bigFont, greenCol);
    vGreen.loadFromRenderedText("v", bigFont, greenCol);


    vector<Texture*> start;
    start.emplace_back(&startGreen);
    start.emplace_back(&startWhite);

    vector<Texture*> quit;
    quit.emplace_back(&quitGreen);
    quit.emplace_back(&quitWhite);

    generalItems.emplace_back(start);
    generalItems.emplace_back(quit);

    vector<Texture*> easy;
    easy.emplace_back(&easyGreen);
    easy.emplace_back(&easyWhite);

    vector<Texture*> medium;
    medium.emplace_back(&mediumGreen);
    medium.emplace_back(&mediumWhite);

    vector<Texture*> hard;
    hard.emplace_back(&hardGreen);
    hard.emplace_back(&hardWhite);

    levelItems.emplace_back(easy);
    levelItems.emplace_back(medium);
    levelItems.emplace_back(hard);

    vector<Texture*> music;
    music.emplace_back(&musicGreen);
    music.emplace_back(&musicWhite);

    vector<Texture*> SFX;
    SFX.emplace_back(&SFXGreen);
    SFX.emplace_back(&SFXWhite);

    settingItems.emplace_back(music);
    settingItems.emplace_back(SFX);

    currentItems = &generalItems;
    currentChoosen = &((*currentItems).front());
}

void Menu::logic(Input &input, State &state){
    if (state.menuState == MenuState::GENERAL){
        if (input.keyboard[SDL_SCANCODE_RETURN]){
            if (state.generalState == GeneralState::QUIT) exit(0);
            state.menuState = MenuState::CHOOSE_LEVEL;
            currentItems = &levelItems;
            currentChoosen = &((*currentItems).front());
        } else if (input.keyboard[SDL_SCANCODE_DOWN]){
            state.generalState = static_cast<GeneralState>((static_cast<int>(state.generalState) + 1) % 2);
            currentChoosen = &((*currentItems)[state.generalState]);
        }
        else if (input.keyboard[SDL_SCANCODE_UP]){
            state.generalState = static_cast<GeneralState>((static_cast<int>(state.generalState) - 1 + 2) % 2);
            currentChoosen = &((*currentItems)[state.generalState]);
        }
    }
    else if (state.menuState == MenuState::CHOOSE_LEVEL){
        if (input.keyboard[SDL_SCANCODE_RETURN]){
            choosenLevel = state.levelState;
            state.menuState = MenuState::SETTINGS;
            currentItems = &settingItems;
            currentChoosen = &((*currentItems).front());
        } else if (input.keyboard[SDL_SCANCODE_DOWN]){
            state.levelState = static_cast<LevelState>((static_cast<int>(state.levelState) + 1) % 3);
            currentChoosen = &((*currentItems)[state.levelState]);
        }
        else if (input.keyboard[SDL_SCANCODE_UP]){
            state.levelState = static_cast<LevelState>((static_cast<int>(state.levelState) - 1 + 3) % 3);
            currentChoosen = &((*currentItems)[state.levelState]);
        }
    } else{
        if (input.keyboard[SDL_SCANCODE_RETURN]){
            // game state change from menu -> playing
            state.gameState = GameState::PLAYING;
        } else if (input.keyboard[SDL_SCANCODE_V]){
            if (state.settingState == SettingState::MUSIC) useMusic = true;
            else useSFX = true;
        } else if (input.keyboard[SDL_SCANCODE_X]){
            if (state.settingState == SettingState::MUSIC) useMusic = false;
            else useSFX = false;
        }
        else if (input.keyboard[SDL_SCANCODE_DOWN]){
            state.settingState = static_cast<SettingState>((static_cast<int>(state.settingState) + 1) % 2);
            currentChoosen = &((*currentItems)[state.settingState]);
        }
        else if (input.keyboard[SDL_SCANCODE_UP]){
            state.settingState = static_cast<SettingState>((static_cast<int>(state.settingState) - 1 + 2) % 2);
            currentChoosen = &((*currentItems)[state.settingState]);
        }
    }
    
}

void Menu::render(State &state){
    int idx = 1;

    if (state.menuState == MenuState::SETTINGS){
        cout << useMusic << " " << useSFX << endl;
        if (useMusic) vGreen.render(50, 100);
        else xGreen.render(50, 100);

        if (useSFX) vGreen.render(50, 150);
        else xGreen.render(50, 150);
        
        if (state.settingState == SettingState::MUSIC){
            musicGreen.render(100, 100);
            SFXWhite.render(100, 150);
        } else{
            musicWhite.render(100, 100);
            SFXGreen.render(100, 150);
        }
        return;

    }

    for (auto &v : *currentItems){
        if (&v == &(*currentChoosen)){
            choosenGreen.render(50, 100 + 50 * idx);
            v[0]->render(100, 100 + 50 * idx);
        }
        else{
            v[1]->render(100, 100 + 50 * idx);
        }
        ++idx;
    }

}