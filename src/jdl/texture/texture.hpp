#pragma once

#include <SDL2/SDL.h>

namespace jdl
{
    class Texture
    {
    public:
        // create blank texture
        Texture(SDL_Renderer *renderer, SDL_Surface *surface);

        // create blank texture
        Texture(SDL_Renderer *renderer, int width, int height);

        ~Texture();

        void update();

        void setPosition(int x, int y);
        void setSize(int width, int height);
        void setCrop(int start_x, int start_y, int end_x, int end_y);
        void setOrigin(int x, int y);
        void setRotation(float rotation);
        void setPixel(int x, int y, Uint32 color);

        int getWidth() const { return width; }
        int getHeight() const { return height; }
        int getBaseWidth() const { return base_width; }
        int getBaseHeight() const { return base_height; }
        float getRotation() const { return rotation; }
        Uint32 getPixel(int x, int y) { return in_bounds(x, y) ? pixels[y * base_width + x] : 0x00000000; }

        SDL_Texture *getSDLTexture() const { return texture; }
        const SDL_Rect *getSDLTransformRect() const { return &transform_rect; }
        const SDL_Rect *getSDLCropRect() const { return &crop_rect; }
        const SDL_Point *getSDLCenterPoint() const { return &center_point; }

    private:
        void init(SDL_Renderer *renderer, SDL_Surface *surface_temp, int width, int height);

        SDL_Surface *convert_surface(SDL_Surface *surface_temp);
        void reset_update_rect();
        bool in_bounds(int x, int y);

    private:
        int base_width = 0;
        int base_height = 0;

        int position_x = 0;
        int position_y = 0;

        int width = 0;
        int height = 0;

        float rotation = 0.0f;

        SDL_Rect transform_rect;
        SDL_Rect crop_rect;
        SDL_Point center_point;

        SDL_Texture *texture = nullptr;
        Uint32 *pixels = nullptr;

        int top_left_update_position_x = 0;
        int top_left_update_position_y = 0;

        int bottom_right_update_position_x = 0;
        int bottom_right_update_position_y = 0;

        SDL_Rect update_rect;

        SDL_PixelFormat *pf = nullptr;
    };
}