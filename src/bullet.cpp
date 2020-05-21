#include "bullet.h"
#include <iostream>

Bullet::Bullet(SDL_Texture *texture, int x, int y)
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