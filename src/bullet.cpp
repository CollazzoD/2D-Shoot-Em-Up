#include "bullet.h"
#include <iostream>

Bullet::Bullet(Texture *texture, float x, float y)
    : Entity(texture, x, y, BULLET_SPEED) {
  dx = BULLET_SPEED;
  dy = 0;
}

void Bullet::Update() {
  if (health > 0) {
    x += dx;
    y += dy;

    if ((x >= kScreenWidth) || (y >= kScreenHeight))
      health = 0;
  }
}