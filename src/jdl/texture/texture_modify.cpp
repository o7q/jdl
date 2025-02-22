#include "texture.hpp"

#include <SDL3/SDL.h>

// refresh the texture with the newly updated pixels
void Texture::update()
{
    void *update_pixels = &m_pixels[m_update_rect.y * m_base_width + m_update_rect.x];
    SDL_UpdateTexture(m_texture, &m_update_rect, update_pixels, m_base_width * sizeof(Uint32));
    reset_update_rect();
}

// sets a pixel of the texture with a color
void Texture::setPixel(int x, int y, Uint32 color)
{
    if (!in_bounds(x, y))
    {
        return;
    }

    const unsigned int index = y * m_base_width + x;
    m_pixels[index] = color;

    if (x < m_top_left_update_pos_x)
    {
        m_top_left_update_pos_x = x;
    }
    if (y < m_top_left_update_pos_y)
    {
        m_top_left_update_pos_y = y;
    }
    if (x > m_bottom_right_update_pos_x)
    {
        m_bottom_right_update_pos_x = x;
    }
    if (y > m_bottom_right_update_pos_y)
    {
        m_bottom_right_update_pos_y = y;
    }

    m_update_rect.x = m_top_left_update_pos_x;
    m_update_rect.y = m_top_left_update_pos_y;
    m_update_rect.w = m_bottom_right_update_pos_x - m_top_left_update_pos_x + 1;
    m_update_rect.h = m_bottom_right_update_pos_y - m_top_left_update_pos_y + 1;
}