#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "../library/graphics.h"
#include "../library/defs.h"
#include "../library/draw.h"
#include "../library/inputs.h"
#include "../library/game.h"

void capFrameRate(long long *then, float *remainder){
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

int main(int argc, char** argv){
    Graphics graphics;
    Input input;
    Game game;

    graphics.init();
    input.init();
    game.init(&graphics);

    long long then = SDL_GetTicks64();
    float remainder = 0;
    
    while (true){
        prepareScene(graphics.renderer);
        input.get();
        game.doLogic(&graphics, input.keyboard);
        game.doDraw(&graphics);


        presentScene(graphics.renderer);
        capFrameRate(&then, &remainder);
    }

    graphics.quit();

}