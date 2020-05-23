#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "entity.h"
#include "texture.h"

class Explosion : public Entity {
public:
  Explosion(Texture *texture, const float &x, const float &y, const float &dx,
            const float &dy, const int &r, const int &g, const int &b,
            const int &a)
      : Entity(texture, x, y, 0, dx, dy), r(r), g(g), b(b), a(a) {}
  int r, g, b, a;
  void Update() override;
};

#endif