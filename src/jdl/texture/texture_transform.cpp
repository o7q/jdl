#include "texture.hpp"

#include <iostream>

void jdl::Texture::setPosition(int x, int y)
{
    pos_x = x;
    pos_y = y;

    update_sdl_transforms();
}

// sets the render size
void jdl::Texture::setSize(int width, int height)
{
    prev_width = this->width;
    prev_height = this->height;

    this->width = width;
    this->height = height;

    update_sdl_transforms();
}

void jdl::Texture::setCrop(int start_x, int start_y, int end_x, int end_y)
{
    crop_start_pos_x = start_x;
    crop_start_pos_y = start_y;
    crop_end_pos_x = end_x;
    crop_end_pos_y = end_y;

    update_sdl_transforms();
}

void jdl::Texture::setOrigin(int x, int y)
{
    center_pos_x = x;
    center_pos_y = y;

    update_sdl_transforms();
}

void jdl::Texture::setRotation(float rotation)
{
    this->rotation = rotation;
}

void jdl::Texture::update_sdl_transforms()
{
    // transform the texture by its -size/2 to make it appear properly centered
    transform_rect.x = pos_x - width / 2;
    transform_rect.y = pos_y - height / 2;
    transform_rect.w = width;
    transform_rect.h = height;

    // set crop rectangles
    crop_rect.x = crop_start_pos_x;
    crop_rect.y = crop_start_pos_y;
    crop_rect.w = crop_end_pos_x;
    crop_rect.h = crop_end_pos_y;

    // set and offset the point by the size/2 to account for the center
    // we multiply the point by size/prev_size to ensure the center is visually preserved
    center_point.x = (width / (float)prev_width) * center_pos_x + width / 2;
    center_point.y = (height / (float)prev_height) * center_pos_y + height / 2;
}