#ifndef PLAYER_H
#define PLAYER_H

#include "bullet.h"
#include "entity.h"
#include "renderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>
#include <memory>

constexpr int PLAYER_SPEED{4};
constexpr int PLAYER_INITIAL_X{100};
constexpr int PLAYER_INITIAL_Y{330};

class Player : public Entity {
public:
  Player(SDL_Texture *texture, Bullet bullet_forge,
         std::list<std::unique_ptr<Bullet>> &bullets);
  ~Player() = default;
  Player(const Player &source) = delete;
  Player &operator=(const Player &source) = delete;
  Player(Player &&source) = default;
  Player &operator=(Player &&source) = default;

  void Update() override;
  void Fire();
  void StopFire();
  void Init();

  enum class Direction { kUp, kDown, kLeft, kRight, kStop };
  Direction direction = Direction::kStop;

private:
  void CheckPosition();
  void FireBullet();

  Bullet bullet_forge; // used to create other bullets
  std::list<std::unique_ptr<Bullet>> &bullets;
  bool fire{false};
  int reload;
};

#endif