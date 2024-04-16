#ifndef _TEXTURE__H
#define _TEXTURE__H

#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_image.h>
#include "vector.h"
#include <string>
#include "error.h"

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

#endif