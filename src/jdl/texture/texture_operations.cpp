#include "texture.hpp"

#include <SDL2/SDL.h>

// refresh the texture with the newly updated pixels
void jdl::Texture::update()
{
    void *update_pixels = &pixels[update_rect.y * base_width + update_rect.x];
    SDL_UpdateTexture(texture, &update_rect, update_pixels, base_width * sizeof(Uint32));
    reset_update_rect();
}

// sets a pixel of the texture with a color
void jdl::Texture::setPixel(int x, int y, Uint32 color)
{
    if (!in_bounds(x, y))
    {
        return;
    }

    const unsigned int index = y * base_width + x;
    pixels[index] = color;

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