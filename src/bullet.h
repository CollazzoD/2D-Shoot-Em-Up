#ifndef BULLET_H
#define BULLET_H

#include "entity.h"
#include "constants.h"
#include "texture.h"
#include <iostream>

class Bullet : public Entity {
public:
  Bullet(Texture *texture, float x, float y);
  ~Bullet() = default;
  Bullet(const Bullet &source) = default;
  Bullet &operator=(const Bullet &source) = default;
  Bullet(Bullet &&source) = default;
  Bullet &operator=(Bullet &&source) = default;

  void Update() override;
private:
};

#endif