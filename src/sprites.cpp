#include "../library/sprites.h"

Sprite::Sprite(SDL_Renderer* renderer)
    : texture{renderer},
      gRenderer{renderer}
{}

Sprite::~Sprite() {
    free();
}

void Sprite::loadFromFile(const string &path) {
    texture.loadFromFile(path);
}

#include <iostream>
using std::cout;
using std::endl;


void Sprite::init(int initY, int frames, int frameWidth, int frameHeight, int renderWidth, int renderHeight, int pauseTime) {
    mFrames = frames;
    mFrameWidth = frameWidth;
    mFrameHeight = frameHeight;
    mRenderWidth = renderWidth;
    mRenderHeight = renderHeight;
    mCurrentClip = {0, initY, mFrameWidth, mFrameHeight};
    mPauseTime = pauseTime;
    mTime = 1;
}


void Sprite::tick() {
    mTime--;
    if (mTime > 0) {
        return;
    }
    mTime = mPauseTime;
    
    mCurrentClip.x += mFrameWidth;
    if (mCurrentClip.x >= mFrameWidth * mFrames) {
        mCurrentClip.x = 0;
    }
}

void Sprite::free() {
    texture.free();
}

void Sprite::render(int x, int y){
    SDL_Rect dst = {x, y, mRenderWidth, mRenderHeight};
    texture.blit(&dst, &mCurrentClip); 
}

const SDL_Rect* Sprite::getCurrentClip() const {
    return &mCurrentClip;
}

