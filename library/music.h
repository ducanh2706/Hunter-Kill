#ifndef _MUSIC__H
#define _MUSIC__H

#include <SDL2_mixer/SDL_mixer.h>
#include <string>

#include "exception.h"

using std::string;

class Music {
private:
    Mix_Music *gMusic;

public:
    Music();
    Music(const string &path);
    ~Music();

    void load(const string &path);
    void play();
    void pause();
    void stop();
    void free();
    bool isPlaying();

};

class Sound {
private:
    Mix_Chunk *gChunk;

public:
    Sound();
    Sound(const string &path);
    ~Sound();

    void load(const string &path);
    void play();
    void free();

};

#endif