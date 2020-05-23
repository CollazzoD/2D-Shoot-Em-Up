#ifndef PLAYER_H
#define PLAYER_H

#include "bullet.h"
#include "entity.h"
#include "renderer.h"
#include "constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>
#include <memory>

class Player : public Entity {
public:
  Player(Texture *texture, Texture *bullet_texture,
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

  Texture *bullet_texture; // used to create other bullets
  std::list<std::unique_ptr<Bullet>> &bullets;
  bool fire{false};
  int reload;
};

#endif