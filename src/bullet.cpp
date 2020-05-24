#include "bullet.h"
#include <iostream>

Bullet::Bullet(Texture *texture, const float &x, const float &y)
    : Entity(texture, x, y, BULLET_SPEED, BULLET_SPEED) {}

void Bullet::Update() {
  if (health > 0) {
    x += dx;
    y += dy;

    if ((x >= kScreenWidth) || (y >= kScreenHeight))
      health = 0;
  }
}