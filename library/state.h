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
};

class State {
public:
    MenuState menuState;
    LevelState levelState;
    SettingState settingState;
    GeneralState generalState;
    GameState gameState;

    State(MenuState _menuState, LevelState _levelState, SettingState _settingState, GeneralState _generalState, GameState _gameState):
        menuState(_menuState),
        levelState(_levelState),
        settingState(_settingState),
        generalState(_generalState),
        gameState(_gameState)
    {}
};

#endif