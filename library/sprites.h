#ifndef _SPRITE__H
#define _SPRITE__h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "texture.h"

class Sprite {
private:
    Texture texture;
    SDL_Renderer *gRenderer;
    int mFrames;
    int mFrameWidth, mFrameHeight;
    int mRenderWidth, mRenderHeight;
    SDL_Rect mCurrentClip;
    int mPauseTime;
    int mTime;
    int mGap;

public:
    Sprite(SDL_Renderer* renderer);
    ~Sprite();

    void loadFromFile(const string &path);
    void init(int initY, int frames, int gap, int frameWidth, int frameHeight, int renderWidth, int renderHeight, int pauseTime);
    void tick();
    void render(int x, int y);
    const SDL_Rect* getCurrentClip() const;
    void free();
};




#endif