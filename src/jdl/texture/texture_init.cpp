#include "texture.hpp"

#include <cstring>

#include <SDL3/SDL.h>

// create texture from image
Texture::Texture(SDL_Renderer *renderer, SDL_Surface *surface)
{
    if (!renderer || !surface)
    {
        return;
    }

    SDL_Surface *formatted = SDL_ConvertSurface(surface, SDL_PIXELFORMAT_RGBA8888);
    m_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, formatted->w, formatted->h);

    const unsigned int pixel_count = formatted->w * formatted->h;
    m_pixels = new Uint32[pixel_count];
    std::memcpy(m_pixels, formatted->pixels, pixel_count * sizeof(Uint32));

    SDL_UpdateTexture(m_texture, NULL, formatted->pixels, formatted->pitch);

    m_base_width = formatted->w;
    m_base_height = formatted->h;

    init_transforms();

    SDL_DestroySurface(formatted);
}

// create blank texture
Texture::Texture(SDL_Renderer *renderer, int width, int height)
{
    m_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);

    m_pixels = new Uint32[width * height];
    for (int i = 0; i < width * height; ++i)
        m_pixels[i] = 0xFFFFFFFF;

    SDL_UpdateTexture(m_texture, NULL, m_pixels, width * sizeof(Uint32));

    m_base_width = width;
    m_base_height = height;

    init_transforms();
}

Texture::~Texture()
{
    SDL_DestroyTexture(m_texture);

    if (m_pixels != nullptr)
    {
        delete[] m_pixels;
        m_pixels = nullptr;
    }
}

void Texture::init_transforms()
{
    m_pos_x = -m_width / 2;
    m_pos_y = -m_height / 2;

    m_width = m_base_width;
    m_height = m_base_height;
    m_prev_width = m_base_width;
    m_prev_height = m_base_height;

    m_crop_start_pos_x = 0;
    m_crop_start_pos_y = 0;
    m_crop_end_pos_x = m_base_width;
    m_crop_end_pos_y = m_base_height;

    m_center_pos_x = m_base_width / 2;
    m_center_pos_y = m_base_height / 2;

    update_sdl_transforms();
    reset_update_rect();
}