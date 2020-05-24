#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "entity.h"
#include "texture.h"

/*
 * Class Explosion is an Entity which handles the explosion animation that occur when an enemy dies
 */
class Explosion : public Entity {
public:
  Explosion(Texture *texture, const float &x, const float &y, const float &dx,
            const float &dy, const int &r, const int &g, const int &b,
            const int &a);
  int r, g, b, a;
  void Update() override;
};

#endif