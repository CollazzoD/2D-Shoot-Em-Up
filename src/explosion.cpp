#include "explosion.h"

Explosion::Explosion(Texture *texture, const float &x, const float &y,
                     const float &dx, const float &dy, const int &r,
                     const int &g, const int &b, const int &a)
    : Entity(texture, x, y, 0, dx, dy), r(r), g(g), b(b), a(a) {}

void Explosion::Update() {
  x += dx;
  y += dy;
  a--;

  if (a <= 0)
    health = 0;
}