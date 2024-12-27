#include "texture.hpp"

#include <SDL2/SDL.h>

void jdl::Texture::init_surface_create_fill(SDL_Surface *surface, int width, int height, Uint32 color)
{
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = width;
    rect.h = height;
    SDL_FillRect(surface, &rect, color);
}

void jdl::Texture::init_surface_create_circle(SDL_Surface *surface, int width, int height, Uint32 color)
{
    Uint32 *pixels = (Uint32 *)surface->pixels;

    const float radius_squared = 0.25f;
    const float half_width = width / 2.0f;
    const float half_height = height / 2.0f;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            float coord_x = (x - half_width) / width;
            float coord_y = (y - half_height) / height;

            if (coord_x * coord_x + coord_y * coord_y <= radius_squared)
            {
                pixels[y * width + x] = color;
            }
        }
    }
}