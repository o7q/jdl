#include "texture.hpp"

#include <SDL2/SDL.h>

void jdl::Texture::update()
{
    void *update_pixels = &pixels[update_rect.y * base_width + update_rect.x];
    SDL_UpdateTexture(texture, &update_rect, update_pixels, base_width * sizeof(Uint32));
    reset_update_rect();
}

void jdl::Texture::setPixel(int x, int y, int r, int g, int b, int a)
{
    if (x >= base_width || y >= base_height || x < 0 || y < 0)
    {
        return;
    }

    const unsigned int index = y * base_width + x;
    pixels[index] = SDL_MapRGBA(pf, r, g, b, a);

    if (x < top_left_update_position_x)
    {
        top_left_update_position_x = x;
    }
    if (y < top_left_update_position_y)
    {
        top_left_update_position_y = y;
    }
    if (x > bottom_right_update_position_x)
    {
        bottom_right_update_position_x = x;
    }
    if (y > bottom_right_update_position_y)
    {
        bottom_right_update_position_y = y;
    }

    update_rect.x = top_left_update_position_x;
    update_rect.y = top_left_update_position_y;
    update_rect.w = bottom_right_update_position_x - top_left_update_position_x + 1;
    update_rect.h = bottom_right_update_position_y - top_left_update_position_y + 1;
}