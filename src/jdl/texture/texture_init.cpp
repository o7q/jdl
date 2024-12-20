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

    if (!surface_formatted)
    {
        return;
    }

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

    pos_x = -width / 2;
    pos_y = -height / 2;

    width = base_width;
    height = base_height;
    prev_width = base_width;
    prev_height = base_height;

    crop_start_pos_x = 0;
    crop_start_pos_y = 0;
    crop_end_pos_x = base_width;
    crop_end_pos_y = base_height;

    center_pos_x = base_width / 2;
    center_pos_y = base_height / 2;

    update_sdl_transforms();

    reset_update_rect();
}