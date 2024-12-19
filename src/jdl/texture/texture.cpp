#include "texture.hpp"

void jdl::Texture::setPosition(int x, int y)
{
    position_x = x;
    position_y = y;

    transform_rect.x = position_x - width / 2;
    transform_rect.y = position_y - height / 2;
}

// sets the render size
void jdl::Texture::setSize(int width, int height)
{
    this->width = width;
    this->height = height;

    transform_rect.x = position_x - width / 2;
    transform_rect.y = position_y - height / 2;
    transform_rect.w = width;
    transform_rect.h = height;

    center_point.x = width / 2;
    center_point.y = height / 2;
}

void jdl::Texture::setCrop(int start_x, int start_y, int end_x, int end_y)
{
    crop_rect.x = start_x;
    crop_rect.y = start_y;
    crop_rect.w = end_x;
    crop_rect.h = end_y;
}

void jdl::Texture::setOrigin(int x, int y)
{
    center_point.x = x;
    center_point.y = y;
}

void jdl::Texture::setRotation(float rotation)
{
    this->rotation = rotation;
}