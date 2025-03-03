# jdl (wip)

useful abstractions for SDL. ✨

---

## Texture

- A texture class that expands upon `SDL_Texture`, adding useful functions such as `setPixel()` and several transformation utilities
- `texture.update()` can be used to update the pixels of the texture after a pixel operation such as `setPixel()`

<details>
<summary><b>Usage</b></summary>

- ### Creating a texture

  From a surface

  ```c++
  SDL_Surface* image = IMG_Load("image.png");
  Texture texture(renderer, image); // you need to pass in an SDL_Renderer*
  ```

  **OR**
  
  A blank texture

  ```c++
  Texture texture(renderer, 1000, 1000);
  ```

- ### Transforming a texture

  ```c++
  texture.setPosition(windowWidth / 2, windowHeight / 2); // position at screen center
  texture.setSize(512, 512); // 512 x 512 pixels
  ```

- ### Modifying a texture

  ```c++
  texture.setPixel(100, 100, 0xFF00FFFF); // set pixel at (100, 100) to pink
  texture.update(); // update texture pixels
  ```

  With *Color*

  ```c++
  texture.setPixel(100, 100, Color(255, 0, 255, 255).hex()); // set pixel at (100, 100) to pink
  texture.update();
  ```

- ### Render using SDL

  ```c++
  SDL_RenderCopyEx(renderer,
                   texture.getSDLTexture(),
                   texture.getSDLCropRect(),
                   texture.getSDLTransformRect(),
                   texture.getRotation(),
                   texture.getSDLCenterPoint(),
                   SDL_FLIP_NONE);
  ```

  **OR**

- ### Render using Texture::renderTexture

  ```c++
  renderTexture(renderer, texture);
  ```

</details>

---

## Color

- A color structure that implements useful conversions between `RGBA` and Uint32 `hex` values

<details>
<summary><b>Usage</b></summary>

- ### Creating a color

  ```c++
  Color myColor1(255, 0, 255, 255); // specifying the alpha channel is optional
  ```

- ### Reading from a color

  ```c++
  Uint8 r = myColor1.r;
  Uint8 g = myColor1.g;
  Uint8 b = myColor1.b;
  Uint8 a = myColor1.a;

  Uint32 hex = myColor1.hex();
  ```

</details>

---

## Notes

- Every module is self-contained and doesn't require anything other than SDL to operate.
- `SDL_PIXELFORMAT_RGBA8888` is used as the pixel format for these modules.
