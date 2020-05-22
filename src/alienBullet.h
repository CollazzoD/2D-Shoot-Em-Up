#ifndef ALIEN_BULLET_H
#define ALIEN_BULLET_H

#include "entity.h"
#include "renderer.h"
#include <iostream>

constexpr int ALIEN_BULLET_SPEED{8};

class AlienBullet : public Entity {
public:
  AlienBullet(SDL_Texture *texture, const int &x, const int &y);
  AlienBullet(SDL_Texture *texture, const int &x, const int &y, const float &dx, const float &dy);
  ~AlienBullet() = default;
  AlienBullet(const AlienBullet &source) = default;
  AlienBullet &operator=(const AlienBullet &source) = default;
  AlienBullet(AlienBullet &&source) = default;
  AlienBullet &operator=(AlienBullet &&source) = default;

  void Update() override;
  void SetY(const int &new_y) { y = new_y; }
  void SetX(const int &new_x) { x = new_x; }
  void SetDx(const float &new_dx ) {dx = new_dx;}
  void SetDy(const float &new_dy ) {dy = new_dy;}

private:
};

#endif