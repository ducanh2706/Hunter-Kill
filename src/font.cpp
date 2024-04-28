#include "../library/font.h"

Font::Font() {
    font = NULL;
}

Font::Font(string &path, int sz) {
    load(path, sz);
}

void Font::load(string &path, int sz) {
    free();

    font = TTF_OpenFont(path.c_str(), sz);
    if (font == NULL) {
        logErrorAndExit("Failed to load font: ", TTF_GetError());
    }
}

void Font::free() {
    if (font != nullptr)
        TTF_CloseFont(font);

    font = nullptr;
}