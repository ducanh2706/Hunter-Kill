#include <math.h>

#include "../library/utils.h"
#include "../library/defs.h"

void calcSlope(float x1, float y1, float x2, float y2, float *dx, float *dy) {
	double steps = std::max(std::abs(x1 - x2), std::abs(y1 - y2));

	if (steps == 0)
	{
		*dx = *dy = 0;
		return;
	}

	*dx = (x1 - x2);
	*dx /= steps;

	*dy = (y1 - y2);
	*dy /= steps;
}

void blitRect(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *src, int x, int y) {
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = src->w;
	dest.h = src->h;

	SDL_RenderCopy(renderer, texture, src, &dest);
}

void capFrameRate(long long *then, float *remainder) {
	long wait, frameTime;

	wait = 16 + *remainder;

	*remainder -= (int)*remainder;

	frameTime = SDL_GetTicks() - *then;

	wait -= frameTime;

	if (wait < 1)
	{
		wait = 1;
	}

	SDL_Delay(wait);

	*remainder += 0.667;

	*then = SDL_GetTicks();
}

bool outOfMap(float x, float y, int w, int h) {
	return x < 0 || y < 0 || x + w > SCREEN_WIDTH || y + h > SCREEN_HEIGHT;
}