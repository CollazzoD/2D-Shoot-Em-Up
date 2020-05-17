#include "bullet.h"
#include <iostream>

Bullet::Bullet(Renderer &r, int x, int y)
    : Entity(r, "../gfx/playerBullet.png", x, y, BULLET_SPEED) {
        dx = BULLET_SPEED;
        dy = 0;
    }

void Bullet::Update() {
  UpdatePosition();
}

void Bullet::UpdatePosition() {
  x += dx;
  y += dy;

  if ((x >= kScreenWidth) || (y >= kScreenHeight))
    health = 0;
}