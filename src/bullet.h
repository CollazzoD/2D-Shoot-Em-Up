#ifndef BULLET_H
#define BULLET_H

#include "entity.h"
#include "renderer.h"

constexpr int BULLET_SPEED{16};

class Bullet : public Entity {
public:
  Bullet(Renderer &r, int x, int y);
  ~Bullet() = default;
  Bullet(const Bullet &source) = delete;
  Bullet &operator=(const Bullet &source) = delete;
  Bullet(Bullet &&source) = default;
  Bullet &operator=(Bullet &&source) = default;

  void Update() override;

private:
  void UpdatePosition() override;
};

#endif