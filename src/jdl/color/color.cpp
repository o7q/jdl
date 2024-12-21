#include "color.hpp"

jdl::Color::Color(Uint32 hex)
{
    pf = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
    set(hex);
}

jdl::Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    pf = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
    set(r, g, b, a);
}

jdl::Color::Color(Uint8 c)
{
    pf = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
    set(c, c, c, 255);
}

jdl::Color::~Color()
{
    SDL_FreeFormat(pf);
}

void jdl::Color::set(Uint32 hex)
{
    this->hex_color = hex;
    SDL_GetRGBA(hex, pf, &rgba_r, &rgba_g, &rgba_b, &rgba_a);
}

void jdl::Color::set(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    this->rgba_r = r;
    this->rgba_g = g;
    this->rgba_b = b;
    this->rgba_a = a;
    hex_color = SDL_MapRGBA(pf, r, g, b, a);
}