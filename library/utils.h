#ifndef _UTILS__H
#define _UTILS__H

#include <SDL2/SDL.h>

void capFrameRate(long long *then, float *remainder);
void calcSlope(float x1, float y1, float x2, float y2, float *dx, float *dy);
void blitRect(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *src, int x, int y);
bool outOfMap(float x, float y, int w, int h);
#endif