#ifndef ALIEN_BULLET_H
#define ALIEN_BULLET_H

#include "entity.h"
#include "constants.h"
#include "texture.h"
#include <iostream>

class AlienBullet : public Entity {
public:
  AlienBullet(Texture *texture, const float &x, const float &y, const float &dx, const float &dy);
  ~AlienBullet() = default;
  AlienBullet(const AlienBullet &source) = default;
  AlienBullet &operator=(const AlienBullet &source) = default;
  AlienBullet(AlienBullet &&source) = default;
  AlienBullet &operator=(AlienBullet &&source) = default;

  void Update() override;
  
private:
};

#endif