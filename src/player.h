#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "renderer.h"

class Player {
public:
  Player(Renderer& r);
  ~Player();

  Player(const Player &source) = delete;
  Player &operator=(const Player &source) = delete;
  Player(Player &&source);
  Player &operator=(Player &&source);

  int x;
  int y;
  SDL_Texture *texture;
};

#endif