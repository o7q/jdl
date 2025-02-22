#include "jdl.hpp"

#include <SDL3/SDL.h>

int main()
{
    SDL_Window *window = SDL_CreateWindow("test", 1280, 720, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    jdl::Texture texture(renderer, 100, 100);

    texture.setPosition(100, 100);

    texture.setPixel(20, 20, jdl::Color(255, 0, 0, 255).hex());
    texture.update();

    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                running = false;
                break;
            }
        }

        SDL_RenderClear(renderer);
        jdl::renderTexture(renderer, texture);
        SDL_RenderPresent(renderer);
    }
}