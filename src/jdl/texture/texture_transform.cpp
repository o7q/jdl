#include "texture.hpp"

void Texture::setPosition(int x, int y)
{
    m_pos_x = x;
    m_pos_y = y;

    update_sdl_transforms();
}

// sets the render size
void Texture::setSize(int width, int height)
{
    m_prev_width = m_width;
    m_prev_height = m_height;

    m_width = width;
    m_height = height;

    update_sdl_transforms();
}

void Texture::setCrop(int start_x, int start_y, int end_x, int end_y)
{
    m_crop_start_pos_x = start_x;
    m_crop_start_pos_y = start_y;
    m_crop_end_pos_x = end_x;
    m_crop_end_pos_y = end_y;

    update_sdl_transforms();
}

void Texture::setOrigin(int x, int y)
{
    m_center_pos_x = x;
    m_center_pos_y = y;

    update_sdl_transforms();
}

void Texture::setRotation(float rotation)
{
    m_rotation = rotation;
}

void Texture::update_sdl_transforms()
{
    // transform the texture by its -size/2 to make it appear properly centered
    m_transform_rect.x = m_pos_x - m_width / 2;
    m_transform_rect.y = m_pos_y - m_height / 2;
    m_transform_rect.w = m_width;
    m_transform_rect.h = m_height;

    // set crop rectangles
    m_crop_rect.x = m_crop_start_pos_x;
    m_crop_rect.y = m_crop_start_pos_y;
    m_crop_rect.w = m_crop_end_pos_x;
    m_crop_rect.h = m_crop_end_pos_y;

    // multiply the point by size/prev_size to ensure the center is visually preserved
    m_center_point.x = (m_width / static_cast<float>(m_prev_width)) * m_center_pos_x;
    m_center_point.y = (m_height / static_cast<float>(m_prev_height)) * m_center_pos_y;
}