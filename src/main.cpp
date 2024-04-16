#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "../library/graphics.h"
#include "../library/defs.h"
#include "../library/draw.h"
#include "../library/inputs.h"
#include "../library/game.h"
#include "../library/utils.h"

int main(int argc, char** argv) {
    Graphics graphics;
    Input input;
    Game game;

    graphics.init();
    input.init();
    game.init(&graphics);

    long long then = SDL_GetTicks64();
    float remainder = 0;

    
    while (true) {
        prepareScene(graphics.renderer);
        input.get();
        game.doLogic(&graphics, input.keyboard);
        game.doDraw(&graphics);

        presentScene(graphics.renderer);
        capFrameRate(&then, &remainder);
    }

    graphics.quit();

}