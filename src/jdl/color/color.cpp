#include "color.hpp"

jdl::Color::Color(Uint32 color)
{
    this->hex_color = color;
    SDL_GetRGBA(color, pf, &rgba_r, &rgba_g, &rgba_b, &rgba_a);
}

jdl::Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    this->rgba_r = r;
    this->rgba_g = g;
    this->rgba_b = b;
    this->rgba_a = a;
    hex_color = SDL_MapRGBA(pf, rgba_r, rgba_g, rgba_b, rgba_a);
}

jdl::Color::~Color()
{
    SDL_FreeFormat(pf);
}