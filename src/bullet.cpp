#include "bullet.h"
#include <iostream>

Bullet::Bullet(Texture *texture, float x, float y)
    : Entity(texture, x, y, BULLET_SPEED, BULLET_SPEED) {}

void Bullet::Update() {
  if (health > 0) {
    x += dx;
    y += dy;

    if ((x >= kScreenWidth) || (y >= kScreenHeight))
      health = 0;
  }
}