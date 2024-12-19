#include "texture.hpp"

#include <SDL2/SDL.h>

SDL_Surface *jdl::Texture::convert_surface(SDL_Surface *surface_temp)
{
    SDL_Surface *surface_formatted = SDL_ConvertSurfaceFormat(surface_temp, SDL_PIXELFORMAT_RGBA8888, 0);
    return surface_formatted;
}

void jdl::Texture::reset_update_rect()
{
    top_left_update_position_x = base_width;
    top_left_update_position_y = base_height;
    bottom_right_update_position_x = 0;
    bottom_right_update_position_y = 0;
}

bool jdl::Texture::in_bounds(int x, int y)
{
    return x < base_width && y < base_height && x >= 0 && y >= 0;
}