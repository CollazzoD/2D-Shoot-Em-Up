#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "renderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

constexpr int PLAYER_SPEED{4};
constexpr int PLAYER_INITIAL_X{100};
constexpr int PLAYER_INITIAL_Y{330};

class Player : public Entity {
public:
  Player(SDL_Texture *texture);
  ~Player() = default;
  Player(const Player &source) = delete;
  Player &operator=(const Player &source) = delete;
  Player(Player &&source) = default;
  Player &operator=(Player &&source) = default;

  void Update() override;

  enum class Direction { kUp, kDown, kLeft, kRight, kStop };
  Direction direction = Direction::kStop;

private:
  void UpdatePosition();
};

#endif