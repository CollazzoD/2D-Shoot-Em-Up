#include "explosion.h"

void Explosion::Update() {
  x += dx;
  y += dy;
  a--;

  if (a <= 0)
    health = 0;
}