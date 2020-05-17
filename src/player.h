#ifndef PLAYER_H
#define PLAYER_H

#include "renderer.h"
#include "entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Player : public Entity {
public:
  enum class Direction { kUp, kDown, kLeft, kRight, kStop};

  Player(Renderer &r);
  ~Player();

  Player(const Player &source) = delete;
  Player &operator=(const Player &source) = delete;
  Player(Player &&source);
  Player &operator=(Player &&source);

  void Update();

  Direction direction = Direction::kStop;

  

private:
  void UpdatePosition() override;
  int texture_width, texture_height;
};

#endif