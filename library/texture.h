#ifndef _TEXTURE__H
#define _TEXTURE__H

#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_image.h>
#include <string>
#include <vector>

#include "vector.h"
#include "error.h"
#include "defs.h"

using std::vector;

class Texture {
private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int width, height;

public:
    Texture(SDL_Renderer* renderer);
    ~Texture();

    void load(const std::string fileName);
    void free();
    void render(Vector position);

    int getWidth() const;
    int getHeight() const;

};

class Sprite {
public:

    SDL_Texture* texture;
    std::vector<SDL_Rect> clips[4];
    Direction direction;

    int currentFrame = 0;
    int counter = 0;

    void init(SDL_Texture* _texture, int frames, int width, int height);
    void tick(Direction _direction);
    const SDL_Rect* getCurrentClip(Direction _direction) const;
};



#endif