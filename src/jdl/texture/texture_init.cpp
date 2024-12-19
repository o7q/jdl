#include "texture.hpp"

#include <cstring>

#include <SDL2/SDL.h>

// create texture from image
jdl::Texture::Texture(SDL_Renderer *renderer, SDL_Surface *surface)
{
    if (!renderer || !surface)
    {
        return;
    }

    SDL_Surface *surface_formatted = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA8888, 0);

    // init texture and format
    init(renderer, surface_formatted, surface->w, surface->h);

    // set pixeldata and pitch
    int pixel_count = base_width * base_height;
    pixels = new Uint32[pixel_count];
    std::memcpy(pixels, surface_formatted->pixels, pixel_count * sizeof(Uint32));

    SDL_FreeSurface(surface_formatted);
}

// create blank texture
jdl::Texture::Texture(SDL_Renderer *renderer, int width, int height)
{
    // create blank surface
    SDL_Surface *surface_formatted = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA8888);

    // init texture and format
    init(renderer, surface_formatted, width, height);

    // set pixeldata and pitch
    pixels = new Uint32[width * height];

    SDL_FreeSurface(surface_formatted);
}

jdl::Texture::~Texture()
{
    SDL_DestroyTexture(texture);

    if (pixels != nullptr)
    {
        delete[] pixels;
        pixels = nullptr;
    }
}

void jdl::Texture::init(SDL_Renderer *renderer, SDL_Surface *surface_formatted, int base_width, int base_height)
{
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, base_width, base_height);
    SDL_UpdateTexture(texture, NULL, surface_formatted->pixels, surface_formatted->pitch);

    this->base_width = base_width;
    this->base_height = base_height;
    width = base_width;
    height = base_height;

    transform_rect.x = -width / 2;
    transform_rect.y = -height / 2;
    transform_rect.w = width;
    transform_rect.h = height;

    crop_rect.x = 0;
    crop_rect.y = 0;
    crop_rect.w = width;
    crop_rect.h = height;

    center_point.x = width / 2;
    center_point.y = height / 2;

    reset_update_rect();
}