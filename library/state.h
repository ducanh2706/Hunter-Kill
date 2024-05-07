#ifndef _STATE_H_
#define _STATE_H_

enum MenuState {
    GENERAL,
    CHOOSE_LEVEL,
    SETTINGS
};

enum LevelState {
    EASY,
    MEDIUM,
    HARD
};

enum SettingState {
    MUSIC,
    SFX,
};

enum GeneralState {
    START,
    QUIT
};

enum GameState {
    MENU,
    PLAYING,
    WIN,
    LOSE
};

enum EndState {
    PLAY_AGAIN,
    QUIT_GAME
};


class State {
public:
    MenuState menuState;
    LevelState levelState;
    SettingState settingState;
    GeneralState generalState;
    GameState gameState;
    EndState endState;

    State(): menuState(MenuState::GENERAL), levelState(LevelState::EASY), settingState(SettingState::MUSIC), generalState(GeneralState::START), gameState(GameState::MENU), endState(EndState::PLAY_AGAIN) {}
};

#endif