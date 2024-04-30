#ifndef _TEXTURE__H
#define _TEXTURE__H

#include <SDL2/SDL.h>
#include <string>

#include "font.h"

class Texture {
public:
    Texture(SDL_Renderer* renderer);
    ~Texture();
    Texture(const Texture& other) = delete;
    Texture& operator=(const Texture& other) = delete;

    void loadFromFile( const std::string& path );
    void loadFromRenderedText(const std::string& textureText, Font& f, SDL_Color textColor );
    void free();
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    void setBlendMode( SDL_BlendMode blending );
    void setAlpha( Uint8 alpha );
    void render( int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE );
    void blit(SDL_Rect* dest);
    int getWidth() const {return mWidth; }
    int getHeight() const {return mHeight;}

public:
    SDL_Texture* mTexture;
    SDL_Renderer* gRenderer;

    int mWidth = 0;
    int mHeight = 0;
};

#endif // TEXTURE_H
