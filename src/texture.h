#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>

class Texture {
public:
  Texture(SDL_Texture *texture) : texture(texture){
    SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
  };
  ~Texture() { SDL_DestroyTexture(texture); };
  SDL_Texture *GetTexture() const { return texture; }

  int GetTextureWidth() const { return texture_width; }
  int GetTextureHeight() const { return texture_height; }

private:
  SDL_Texture *texture;
  int texture_width;
  int texture_height;
};

#endif