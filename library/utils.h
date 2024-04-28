#ifndef _UTILS__H
#define _UTILS__H

#include <SDL2/SDL.h>

void capFrameRate(long long *then, double *remainder);
void calcSlope(double x1, double y1, double x2, double y2, double *dx, double *dy);
void blitRect(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *src, int x, int y);
bool outOfMap(double x, double y, int w, int h);

#endif