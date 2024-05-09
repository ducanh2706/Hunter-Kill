#ifndef _FONT__H
#define _FONT__H

#include <SDL2_ttf/SDL_ttf.h>
#include <string>

#include "exception.h"

using std::string;

class Font {
private:
    TTF_Font *font;
public:

    Font();
    Font(string path, int sz);
    ~Font();

    TTF_Font* getFont() const;
    void load(string path, int sz);
    void free();
    


};

#endif