#ifndef ALIEN_BULLET_H
#define ALIEN_BULLET_H

#include "entity.h"
#include "renderer.h"
#include <iostream>

constexpr int ALIEN_BULLET_SPEED{16};

class AlienBullet : public Entity {
public:
  AlienBullet(SDL_Texture *texture, int x, int y);
  ~AlienBullet() = default;
  AlienBullet(const AlienBullet &source) = default;
  AlienBullet &operator=(const AlienBullet &source) = default;
  AlienBullet(AlienBullet &&source) = default;
  AlienBullet &operator=(AlienBullet &&source) = default;

  void Update() override;
  void SetY(int new_y) { y = new_y; }
  void SetX(int new_x) { x = new_x; }

private:
};

#endif