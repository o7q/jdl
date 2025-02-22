#include "texture.hpp"

void Texture::reset_update_rect()
{
    m_top_left_update_pos_x = m_base_width;
    m_top_left_update_pos_y = m_base_height;
    m_bottom_right_update_pos_x = 0;
    m_bottom_right_update_pos_y = 0;
}

bool Texture::in_bounds(int x, int y) const
{
    return x < m_base_width && y < m_base_height && x >= 0 && y >= 0;
}