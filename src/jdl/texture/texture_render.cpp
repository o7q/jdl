#include "texture.hpp"

#include <SDL3/SDL.h>

void renderTexture(SDL_Renderer *renderer, const Texture &texture)
{
    SDL_RenderTextureRotated(renderer,
                     texture.getSDLTexture(),
                     texture.getSDLCropRect(),
                     texture.getSDLTransformRect(),
                     texture.getRotation(),
                     texture.getSDLCenterPoint(),
                     SDL_FLIP_NONE);
}