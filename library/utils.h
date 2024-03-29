#ifndef _UTILS__H
#define _UTILS__H

#include <SDL2/SDL2.h>

void capFrameRate(long long *then, float *remainder);
void calcSlope(int x1, int y1, int x2, int y2, float *dx, float *dy);
void blitRect(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *src, int x, int y);

#endif