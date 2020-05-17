#ifndef PLAYER_H
#define PLAYER_H

#include "renderer.h"
#include "entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

constexpr int PLAYER_SPEED{4};
constexpr int PLAYER_INITIAL_X{100};
constexpr int PLAYER_INITIAL_Y{330};

class Player : public Entity {
public:
  enum class Direction { kUp, kDown, kLeft, kRight, kStop};

  Player(Renderer &r);
  ~Player();
  Player(const Player &source) = delete;
  Player &operator=(const Player &source) = delete;
  Player(Player &&source);
  Player &operator=(Player &&source);

  void Update() override;

  Direction direction = Direction::kStop;
  
private:
  void UpdatePosition() override;
  int texture_width, texture_height;
};

#endif