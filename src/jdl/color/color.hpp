#pragma once

#include <SDL2/SDL.h>

namespace jdl
{
    struct Color
    {
        Color() = default;
        Color(Uint32 color);
        Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        ~Color();

        Uint8 r() { return rgba_r; }
        Uint8 g() { return rgba_g; }
        Uint8 b() { return rgba_b; }
        Uint8 a() { return rgba_a; }
        Uint32 hex() { return hex_color; }

    private:
        Uint32 hex_color = 0x00000000;
        Uint8 rgba_r = 0, rgba_g = 0, rgba_b = 0, rgba_a = 0;

        SDL_PixelFormat *pf = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
    };
}