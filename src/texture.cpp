// #include "../library/texture.h"

// void Sprite::init(SDL_Texture* _texture, int frames, int width, int height) {
//     direction = RIGHT;
//     texture = _texture;
//     counter = 0;

//     SDL_Rect clip;
//     for (int j = 0; j < 4; j++){
//         for (int i = 0; i < frames; i++) {
//             clip.y = j * width;
//             clip.x = i * height;
//             clip.w = width;
//             clip.h = height;
//             clips[j].push_back(clip);
//         }
//     }
// }


// void Sprite::tick(Direction _direction) {
//     if (direction != _direction) {
//         direction = _direction;
//         currentFrame = 0;
//     }
//     else {
//         ++counter;
//         if (counter % (FPS / 10) == 0)
//             currentFrame = (currentFrame + 1) % clips[_direction].size();
//     }
    
// }

// const SDL_Rect* Sprite::getCurrentClip(Direction _direction) const {
//     return &(clips[_direction][currentFrame]);
// }

// // Texture::Texture(SDL_Renderer* _renderer)
// //     : texture(nullptr), renderer(_renderer), width(0), height(0) {}

// // Texture::~Texture() {
// //     free();
// // }

// // void Texture::load(const std::string fileName) {
// //     free();

// //     texture = IMG_LoadTexture(renderer, fileName.c_str());

// //     if (texture == nullptr){
// //         logErrorAndExit("Can't create texture of " + fileName, SDL_GetError());
// //     }

// //     SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
// // }

// // void Texture::free() {
// //     if (texture != nullptr){
// //         SDL_DestroyTexture(texture);
// //         texture = nullptr;
// //         width = height = 0;
// //     }
// // }

// // int Texture::getWidth() const {
// //     return width;
// // }

// // int Texture::getHeight() const {
// //     return height;
// // }

#include <SDL_image.h>
#include <SDL_ttf.h>

#include "../library/texture.h"
#include "../library/exception.h"
#include <iostream>
using std::cout;
using std::endl;


Texture::Texture(SDL_Renderer* renderer)
    : mTexture{nullptr},
      gRenderer{renderer},
      mWidth{0}, mHeight{0}
{}

Texture::~Texture()
{
    free();
}

void Texture::loadFromFile( const std::string& path )
{
    free();

    mTexture = IMG_LoadTexture(gRenderer, path.c_str());
    if( mTexture == nullptr ) {
        logErrorAndExit(("Unable to create texture from " + path).c_str(), SDL_GetError());
    }
    SDL_QueryTexture(mTexture, NULL, NULL, &mWidth, &mHeight);
}

void Texture::loadFromRenderedText( const std::string& textureText, Font& f, SDL_Color textColor )
{
    free();

    SDL_Surface* textSurface = TTF_RenderText_Solid( f.getFont(), textureText.c_str(), textColor );
    if( textSurface == nullptr ) {
        logErrorAndExit("Unable to render text surface! SDL_ttf Error: ", TTF_GetError());
    }

    mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
    if( mTexture == nullptr ) {
        logErrorAndExit("Unable to create texture from text :", SDL_GetError());
    }

    mWidth = textSurface->w;
    mHeight = textSurface->h;

    SDL_FreeSurface( textSurface );
}

void Texture::free()
{
    if( mTexture != nullptr ) {
        SDL_DestroyTexture( mTexture );
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void Texture::setBlendMode( SDL_BlendMode blending )
{
    SDL_SetTextureBlendMode( mTexture, blending );
}

void Texture::setAlpha( Uint8 alpha )
{
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void Texture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    
    if( clip != nullptr )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

void Texture::blit(SDL_Rect* dst) {
    SDL_RenderCopy(gRenderer, mTexture, NULL, dst);
}