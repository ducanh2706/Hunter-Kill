#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

#include "font.h"
#include "defs.h"

using std::cout;
using std::endl;

struct Graphics {
    SDL_Renderer *renderer;
    SDL_Window *window;

    void logErrorAndExit(const char* msg, const char* error)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "%s: %s", msg, error);
        SDL_Quit();
    }

    void init() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
                   SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                   SDL_WINDOW_SHOWN);

        // create full screen window
        // window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);

        if (window == nullptr) 
                   logErrorAndExit("CreateWindow", SDL_GetError());

        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());
        if (TTF_Init() == -1) {
            logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ",
                             TTF_GetError());
        }


        renderer = SDL_CreateRenderer(window, -1, 
                     SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


        if (renderer == nullptr) 
             logErrorAndExit("CreateRenderer", SDL_GetError());

        

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    }

    void prepareScene() {
        SDL_RenderClear(renderer);
        // SDL_RenderCopy(renderer, background, NULL, NULL);
    }

    void presentScene() {
        SDL_RenderPresent(renderer);
    }


    SDL_Texture *loadTexture(const char *filename) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                       "Loading %s", filename);
        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL)
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                  SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

        return texture;
    }

     TTF_Font* loadFont(const char* path, int size) 
    {
        TTF_Font* gFont = TTF_OpenFont( path, size );
        if (gFont == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                           SDL_LOG_PRIORITY_ERROR, 
                           "Load font %s", TTF_GetError());
        }
        return gFont;
    }


    SDL_Texture* loadFromRenderedText(const std::string textureText, Font& f, SDL_Color textColor){
        // SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
        //                "Bun long");
        SDL_Surface* textSurface = TTF_RenderText_Solid( f.getFont(), textureText.c_str(), textColor );
        if( textSurface == nullptr ) {
            logErrorAndExit("Unable to render text surface! SDL_ttf Error: ", TTF_GetError());
            return nullptr;
        }

        SDL_Texture *mTexture = SDL_CreateTextureFromSurface(renderer, textSurface );
        if( mTexture == nullptr ) {
            logErrorAndExit("Unable to create texture from text :", SDL_GetError());
        }
        SDL_FreeSurface( textSurface );
        return mTexture;
    }

    SDL_Texture* renderText(const char* text, 
                            TTF_Font* font, SDL_Color textColor)
    {
        SDL_Surface* textSurface = 
                TTF_RenderText_Solid( font, text, textColor );
        if( textSurface == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                           SDL_LOG_PRIORITY_ERROR, 
                           "Render text surface %s", TTF_GetError());
            return nullptr;
        }

        SDL_Texture* texture = 
                SDL_CreateTextureFromSurface( renderer, textSurface );
        if( texture == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, 
                           SDL_LOG_PRIORITY_ERROR, 
                           "Create texture from text %s", SDL_GetError());
        }
        SDL_FreeSurface( textSurface );
        return texture;
    }


    void renderTexture(SDL_Texture *texture, int x, int y) {
        SDL_Rect dest;
        dest.x = x;
        dest.y = y;
        
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }

    void quit() {
        IMG_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};


#endif

