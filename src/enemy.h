#ifndef ENEMY_H
#define ENEMY_H

#include "bullet.h"
#include "entity.h"
#include "renderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <forward_list>
#include <memory>
#include <random>

constexpr int ENEMY_RELOAD{16};
constexpr int ENEMY_MAX_SPEED{6};
constexpr int ENEMY_MIN_SPEED{2};

class Enemy : public Entity {
public:
  Enemy(SDL_Texture *texture, const int &x, const int &y, const int &speed,
        Bullet bullet_forge,
        std::forward_list<std::unique_ptr<Bullet>> &enemy_bullets);
  ~Enemy() = default;
  Enemy(const Enemy &source) = delete;
  Enemy &operator=(const Enemy &source) = delete;
  Enemy(Enemy &&source) = default;
  Enemy &operator=(Enemy &&source) = default;

  void Update() override;

private:
  void CheckPosition();
  void Fire();

  Bullet bullet_forge; // used to create other bullets
  std::forward_list<std::unique_ptr<Bullet>> &enemy_bullets;
  int reload;
};

#endif