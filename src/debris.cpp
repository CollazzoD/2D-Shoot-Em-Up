#include "debris.h"

Debris::Debris(Texture *texture, const float &x, const float &y,
               const float &dx, const float &dy, const int &health,
               const SDL_Rect &rect)
    : Entity(texture, x, y, 0, dx, dy, health), rect(rect) {}

void Debris::Update() {
  x += dx;
  y += dy;
  dy += 0.5;
  health--;
}