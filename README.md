# jdl

useful abstractions for SDL.

- ## texture.hpp

  - A texture class that expands upon `SDL_Texture`, adding useful functions such as `setPixel()` and several transformation utilities
  - `texture.update()` can be used to update the pixels of the texture after a pixel operation such as `setPixel()`
