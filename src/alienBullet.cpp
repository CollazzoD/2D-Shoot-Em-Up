#include "alienBullet.h"
#include <iostream>

AlienBullet::AlienBullet(Texture *texture, const float &x, const float &y,
                         const float &dx, const float &dy)
    : Entity(texture, x, y, ALIEN_BULLET_SPEED, dx, dy) {}

void AlienBullet::Update() {
  x += dx;
  y += dy;

  if ((x < 0) || (y < 0) || (y > kScreenHeight))
    health = 0;
}