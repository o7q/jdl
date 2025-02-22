#pragma once

#include <SDL3/SDL.h>

class Texture;
void renderTexture(SDL_Renderer *renderer, const Texture &texture);

class Texture
{
public:
    Texture(SDL_Renderer *renderer, SDL_Surface *surface);
    Texture(SDL_Renderer *renderer, int width, int height);
    ~Texture();

    Texture(const Texture &other) = delete;

    void update();

    void setPosition(int x, int y);
    void setSize(int width, int height);
    void setCrop(int start_x, int start_y, int end_x, int end_y);
    void setOrigin(int x, int y);
    void setRotation(float rotation);
    void setPixel(int x, int y, Uint32 color);

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    // gets the original image width
    int getBaseWidth() const { return m_base_width; }
    // gets the original image height
    int getBaseHeight() const { return m_base_height; }
    float getRotation() const { return m_rotation; }
    Uint32 getPixel(int x, int y) const { return in_bounds(x, y) ? m_pixels[y * m_base_width + x] : 0x00000000; }

    SDL_Texture *getSDLTexture() const { return m_texture; }
    const SDL_FRect *getSDLTransformRect() const { return &m_transform_rect; }
    const SDL_FRect *getSDLCropRect() const { return &m_crop_rect; }
    const SDL_FPoint *getSDLCenterPoint() const { return &m_center_point; }

private:
    void init_transforms();

    bool in_bounds(int x, int y) const;
    
    void update_sdl_transforms();
    void reset_update_rect();

private:
    int m_base_width = 0;
    int m_base_height = 0;

    int m_pos_x = 0;
    int m_pos_y = 0;

    int m_width = 0;
    int m_height = 0;
    int m_prev_width = 0;
    int m_prev_height = 0;

    int m_center_pos_x = 0;
    int m_center_pos_y = 0;

    int m_crop_start_pos_x = 0;
    int m_crop_start_pos_y = 0;
    int m_crop_end_pos_x = 0;
    int m_crop_end_pos_y = 0;

    float m_rotation = 0.0f;

    SDL_FRect m_transform_rect;
    SDL_FRect m_crop_rect;
    SDL_FPoint m_center_point;

    SDL_Texture *m_texture = nullptr;
    Uint32 *m_pixels = nullptr;

    int m_top_left_update_pos_x = 0;
    int m_top_left_update_pos_y = 0;
    int m_bottom_right_update_pos_x = 0;
    int m_bottom_right_update_pos_y = 0;
    SDL_Rect m_update_rect;
};