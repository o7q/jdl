# jdl

✨ useful abstractions for SDL. \
**Every module is self-contained and doesn't require anything other than SDL to operate.*

- ## texture.hpp

  - A texture class that expands upon `SDL_Texture`, adding useful functions such as `setPixel()` and several transformation utilities
  - `texture.update()` can be used to update the pixels of the texture after a pixel operation such as `setPixel()`

- ## color.hpp

  - A color structure that implements useful conversions between `RGBA` and Uint32 `hex` values
