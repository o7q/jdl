# jdl (wip)

✨ useful abstractions for SDL. \
**Every module is self-contained and doesn't require anything other than SDL to operate.*

## jdl::Texture

- A texture class that expands upon `SDL_Texture`, adding useful functions such as `setPixel()` and several transformation utilities
- `texture.update()` can be used to update the pixels of the texture after a pixel operation such as `setPixel()`

- ### Creating a texture

  From a surface

  ```c++
  SDL_Surface *image = IMG_Load("image.png");
  jdl::Texture texture(renderer, image);
  ```

  **OR**
  
  A blank texture

  ```c++
  SDL_Surface *image = IMG_Load("image.png");
  jdl::Texture texture(renderer, 1000, 1000);
  ```

- ### Transforming a texture

  ```c++
  texture.setPosition(windowWidth / 2, windowHeight / 2);
  texture.setSize(512, 512);
  ```

- ### Modifying a texture

  ```c++
  texture.setPixel(100, 100, 0xFF00FFFF); // set pixel at (100, 100) to pink
  ```

  With *jdl::Color*

  ```c++
  texture.setPixel(100, 100, jdl::Color(255, 0, 255).hex()); // set pixel at (100, 100) to pink
  ```

- ### Rendering a texture with SDL

  ```c++
  SDL_RenderCopyEx(renderer,
                   texture.getSDLTexture(),
                   texture.getSDLCropRect(),
                   texture.getSDLTransformRect(),
                   texture.getRotation(),
                   texture.getSDLCenterPoint(),
                   SDL_FLIP_NONE);
  ```

## jdl::Color

- A color structure that implements useful conversions between `RGBA` and Uint32 `hex` values

- ### Creating a color

  ```c++
  jdl::Color myColor1(255, 0, 255, 255); // specifying the alpha channel is optional

  jdl::Color myColor2(0xFF00FFFF);
  ```

- ### Updating/setting a color

  ```c++
  myColor1.set(255, 255, 0, 255);
  myColor1.set(0xFFFF00FF);
  ```

- ### Reading from a color

  ```c++
  Uint8 r = myColor1.r();
  Uint8 g = myColor1.g();
  Uint8 b = myColor1.b();
  Uint8 a = myColor1.a();

  Uint32 hex = myColor1.hex();
  ```
