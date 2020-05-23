#ifndef BULLET_H
#define BULLET_H

#include "entity.h"
#include "constants.h"
#include <iostream>

class Bullet : public Entity {
public:
  Bullet(SDL_Texture *texture, int x, int y);
  ~Bullet() = default;
  Bullet(const Bullet &source) = default;
  Bullet &operator=(const Bullet &source) = default;
  Bullet(Bullet &&source) = default;
  Bullet &operator=(Bullet &&source) = default;

  void Update() override;
  void SetY(int new_y) { y = new_y; }
  void SetX(int new_x) { x = new_x; }

private:
};

#endif