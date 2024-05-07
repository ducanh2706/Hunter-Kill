#include "../library/menu.h"

Menu::Menu(const MainWindow& _mainWindow):
    mainWindow(_mainWindow),
    hunterKillRed{_mainWindow.getRenderer()},
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
    vGreen(_mainWindow.getRenderer()),
    youWinGreen(_mainWindow.getRenderer()),
    youLoseRed(_mainWindow.getRenderer()),
    playAgainGreen(_mainWindow.getRenderer()),
    playAgainWhite(_mainWindow.getRenderer())
 {
 }

void Menu::init(){
    clickSound.load(CLICK_SOUND_PATH);
    confirmSound.load(CONFIRM_SOUND_PATH);
    denySound.load(DENY_SOUND_PATH);

    bigFont.load(FONT_PATH, BIG_FONT);
    smallFont.load(FONT_PATH, SMALL_FONT);
    SDL_Color greenCol = {0, 0xFF, 0, 0xFF};
    SDL_Color whiteCol = {0xFF, 0xFF, 0xFF, 0xFF};
    SDL_Color redCol = {0xFF, 0, 0, 0xFF};

    useMusic = true;
    useSFX = true;
    choosenLevel = 0;
    background = new Texture(mainWindow.getRenderer());
    background->loadFromFile(MENU_BACKGROUND_IMG_SOURCE);
    hunterKillRed.loadFromRenderedText("HUNTER KILL", bigFont, redCol);
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
    youWinGreen.loadFromRenderedText("YOU WIN !!!", bigFont, greenCol);
    youLoseRed.loadFromRenderedText("YOU LOSE !!!", bigFont, redCol);
    playAgainGreen.loadFromRenderedText("AGAIN", bigFont, greenCol);
    playAgainWhite.loadFromRenderedText("AGAIN", bigFont, whiteCol);


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
            SDL_Delay(200);
        } else if (input.keyboard[SDL_SCANCODE_DOWN]){
            clickSound.play();
            state.generalState = static_cast<GeneralState>((static_cast<int>(state.generalState) + 1) % 2);
            currentChoosen = &((*currentItems)[state.generalState]);
            SDL_Delay(200);
        }
        else if (input.keyboard[SDL_SCANCODE_UP]){
            clickSound.play();
            state.generalState = static_cast<GeneralState>((static_cast<int>(state.generalState) - 1 + 2) % 2);
            currentChoosen = &((*currentItems)[state.generalState]);
            SDL_Delay(200);
        }

    }
    else if (state.menuState == MenuState::CHOOSE_LEVEL){
        if (input.keyboard[SDL_SCANCODE_RETURN]){
            choosenLevel = state.levelState;
            state.menuState = MenuState::SETTINGS;
            currentItems = &settingItems;
            currentChoosen = &((*currentItems).front());
            SDL_Delay(200);
        } else if (input.keyboard[SDL_SCANCODE_DOWN]){
            clickSound.play();
            state.levelState = static_cast<LevelState>((static_cast<int>(state.levelState) + 1) % 3);
            currentChoosen = &((*currentItems)[state.levelState]);
            SDL_Delay(200);
        }
        else if (input.keyboard[SDL_SCANCODE_UP]){
            clickSound.play();
            state.levelState = static_cast<LevelState>((static_cast<int>(state.levelState) - 1 + 3) % 3);
            currentChoosen = &((*currentItems)[state.levelState]);
            SDL_Delay(200);
        }
    } else{
        if (input.keyboard[SDL_SCANCODE_RETURN]){
            state.gameState = GameState::PLAYING;
        } else if (input.keyboard[SDL_SCANCODE_V]){
            confirmSound.play();
            if (state.settingState == SettingState::MUSIC) useMusic = true;
            else useSFX = true;
            SDL_Delay(200);
        } else if (input.keyboard[SDL_SCANCODE_X]){
            denySound.play();
            if (state.settingState == SettingState::MUSIC) useMusic = false;
            else useSFX = false;
            SDL_Delay(200);
        }
        else if (input.keyboard[SDL_SCANCODE_DOWN]){
            clickSound.play();
            state.settingState = static_cast<SettingState>((static_cast<int>(state.settingState) + 1) % 2);
            currentChoosen = &((*currentItems)[state.settingState]);
            SDL_Delay(200);
        }
        else if (input.keyboard[SDL_SCANCODE_UP]){
            clickSound.play();
            state.settingState = static_cast<SettingState>((static_cast<int>(state.settingState) - 1 + 2) % 2);
            currentChoosen = &((*currentItems)[state.settingState]);
            SDL_Delay(200);
        }
    }
    
}

void Menu::logicEnd(Input &input, State &state, Game &game){
    if (input.keyboard[SDL_SCANCODE_RETURN]){
        if (state.endState == EndState::QUIT_GAME) exit(0);
        state.gameState = GameState::PLAYING;
        game.init();
    } else if (input.keyboard[SDL_SCANCODE_UP]){
        clickSound.play();
        state.endState = static_cast<EndState>((static_cast<int>(state.endState) - 1 + 2) % 2);
        SDL_Delay(200);
    } else if (input.keyboard[SDL_SCANCODE_DOWN]){
        clickSound.play();
        state.endState = static_cast<EndState>((static_cast<int>(state.endState) + 1) % 2);
        SDL_Delay(200);
    }
}

#define BUTTON_X 500
#define POS_X 550
#define POS_Y 300
#define MARGIN_Y 50

void Menu::renderEnd(State &state){
    SDL_Rect screenBackgroundRender = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    background->blit(&screenBackgroundRender);

    if (state.gameState == GameState::WIN){
        youWinGreen.render(SCREEN_WIDTH / 2 - youWinGreen.getWidth() / 2, SCREEN_HEIGHT / 2 - youWinGreen.getHeight() / 2 - 100);
    } else{
        youLoseRed.render(SCREEN_WIDTH / 2 - youLoseRed.getWidth() / 2, SCREEN_HEIGHT / 2 - youLoseRed.getHeight() / 2 - 100);
    }

    if (state.endState == EndState::PLAY_AGAIN){
        choosenGreen.render(BUTTON_X, POS_Y + MARGIN_Y);
        playAgainGreen.render(POS_X, POS_Y + MARGIN_Y);
        quitWhite.render(POS_X, POS_Y + MARGIN_Y * 2);
    } else{
        playAgainWhite.render(POS_X, POS_Y + MARGIN_Y);
        choosenGreen.render(BUTTON_X, POS_Y + MARGIN_Y * 2);
        quitGreen.render(POS_X, POS_Y + MARGIN_Y * 2);
    }
}

void Menu::render(State &state){
    SDL_Rect screenBackgroundRender = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    background->blit(&screenBackgroundRender);

    hunterKillRed.render(SCREEN_WIDTH / 2 - hunterKillRed.getWidth() / 2, SCREEN_HEIGHT / 2 - hunterKillRed.getHeight() / 2 - 100);  


    if (state.menuState == MenuState::SETTINGS){
        if (useMusic) vGreen.render(BUTTON_X, POS_Y + MARGIN_Y);
        else xGreen.render(BUTTON_X, POS_Y + MARGIN_Y);

        if (useSFX) vGreen.render(BUTTON_X, POS_Y + MARGIN_Y * 2);
        else xGreen.render(BUTTON_X, POS_Y + MARGIN_Y * 2);
        
        if (state.settingState == SettingState::MUSIC){
            musicGreen.render(POS_X, POS_Y + MARGIN_Y);
            SFXWhite.render(POS_X, POS_Y + MARGIN_Y * 2);
        } else{
            musicWhite.render(POS_X, POS_Y + MARGIN_Y);
            SFXGreen.render(POS_X, POS_Y + MARGIN_Y * 2);
        }
        return;

    }

    int index = 1;
    for (auto &v : *currentItems){
        if (&v == &(*currentChoosen)){
            choosenGreen.render(BUTTON_X, POS_Y + MARGIN_Y * index);
            v[0]->render(POS_X, POS_Y + MARGIN_Y * index);
        }
        else{
            v[1]->render(POS_X, POS_Y + MARGIN_Y * index);
        }
        index++;
    }

}