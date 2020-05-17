#ifndef PLAYER_H
#define PLAYER_H

#include "renderer.h"
#include "entity.h"
#include "bullet.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>

constexpr int PLAYER_SPEED{4};
constexpr int PLAYER_INITIAL_X{100};
constexpr int PLAYER_INITIAL_Y{330};

class Player : public Entity {
public:
  Player(Renderer &r);
  ~Player() = default;
  Player(const Player &source) = delete;
  Player &operator=(const Player &source) = delete;
  Player(Player &&source);
  Player &operator=(Player &&source);

  void Update() override;
  void Fire();

  enum class Direction { kUp, kDown, kLeft, kRight, kStop};
  Direction direction = Direction::kStop;

  std::unique_ptr<Bullet> bullet;
private:
  Renderer& renderer;
  void UpdatePosition() override;
  void UpdateBullet();
};

#endif