#include "texture.hpp"

#include <SDL2/SDL.h>

void jdl::renderTexture(SDL_Renderer *renderer, const Texture &texture)
{
    SDL_RenderCopyEx(renderer,
                     texture.getSDLTexture(),
                     texture.getSDLCropRect(),
                     texture.getSDLTransformRect(),
                     texture.getRotation(),
                     texture.getSDLCenterPoint(),
                     SDL_FLIP_NONE);
}