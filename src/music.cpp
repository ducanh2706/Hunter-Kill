#include "../library/music.h"

Music::Music() {}

Music::Music(const string &path) {
    load(path);
}

Music::~Music() {
    stop();
}

void Music::load(const string &path) {
    gMusic = Mix_LoadMUS(path.c_str());
    if (gMusic == nullptr) {
        logErrorAndExit(("Can't load music of " + path).c_str(), Mix_GetError());
    }
}

void Music::play() {
    if (gMusic == nullptr){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Music is not loaded");
    }

    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(gMusic, -1);
    } else if (Mix_PausedMusic() == 1){
        Mix_ResumeMusic();
    }
}

void Music::pause() {
    if (Mix_PlayingMusic() == 1){
        Mix_PauseMusic();
    }
}

void Music::stop() {
    pause();
    Mix_RewindMusic();
}

void Music::free() {
    if (gMusic != nullptr){
        Mix_FreeMusic(gMusic);
    }
}

Sound::Sound() {}

Sound::Sound(const string &path) {
    load(path);
}

Sound::~Sound() {
    free();
}

void Sound::load(const string &path) {
    gChunk = Mix_LoadWAV(path.c_str());
    if (gChunk == nullptr) {
        logErrorAndExit(("Can't load sound of " + path).c_str(), Mix_GetError());
    }
}

void Sound::play() {
    if (gChunk == nullptr){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Sound is not loaded");
    }

    Mix_PlayChannel(-1, gChunk, 0);
}

void Sound::free() {
    if (gChunk != nullptr){
        Mix_FreeChunk(gChunk);
    }
}