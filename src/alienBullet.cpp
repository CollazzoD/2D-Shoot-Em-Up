#include "alienBullet.h"
#include <iostream>

AlienBullet::AlienBullet(SDL_Texture *texture, int x, int y)
    : Entity(texture, x, y, ALIEN_BULLET_SPEED) {
        dx = -ALIEN_BULLET_SPEED;
        dy = 0;
    }

void AlienBullet::Update() {
  x += dx;
  y += dy;

  if (x < 0)
    health = 0;
}