#ifndef DEBRIS_H
#define DEBRIS_H

#include "entity.h"

class Debris : public Entity {
public:
  Debris(Texture *texture, const float &x, const float &y, const float &dx,
         const float &dy, const int &health, const SDL_Rect &rect)
      : Entity(texture, x, y, 0, dx, dy, health), rect(rect) {}
  void Update() override;
  SDL_Rect GetRect() const { return rect; }

private:
  SDL_Rect rect;
};

#endif