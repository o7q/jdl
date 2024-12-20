#include "texture.hpp"

#include <SDL2/SDL.h>

void jdl::Texture::reset_update_rect()
{
    top_left_update_pos_x = base_width;
    top_left_update_pos_y = base_height;
    bottom_right_update_pos_x = 0;
    bottom_right_update_pos_y = 0;
}

bool jdl::Texture::in_bounds(int x, int y)
{
    return x < base_width && y < base_height && x >= 0 && y >= 0;
}