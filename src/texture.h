#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>

class Texture {
public:
  Texture(SDL_Texture *texture) : texture(texture){};
  ~Texture() { SDL_DestroyTexture(texture); };
  SDL_Texture *GetTexture() const { return texture; }

private:
  SDL_Texture *texture;
};

#endif